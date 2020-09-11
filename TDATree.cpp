#include "TDATree.hpp"
#include <iostream>

using namespace std;

TDATree::TDATree(){
    root = nullptr;
}

TDATree::~TDATree(){

}

TreeNode *TDATree::getParent(int p){
    return nodes[p]->getParent();
}

TreeNode *TDATree::getLefmosttChild(int p){
    return nodes[p]->getChild(0);
}

TreeNode* TDATree::getNextChild(TreeNode* n){
    TreeNode* temp;
    for(TreeNode* t : nodes){
        if(t->equals(n)){
            temp = n->getParent();
            break;
        }
    }
    int i = 0;
    for(TreeNode* x : temp->getChildren()){
        if(x->equals(n)){
            i++;
            return temp->getChild(i);
        }
    }
}

string TDATree::getTag(int p){
    return nodes[p]->getTag();
}

TreeNode* TDATree::create(string tag, vector<TreeNode*> children){
    TreeNode* nNode = new TreeNode;
    nNode->setTag(tag);
    if(children.size() > 0){
        for(int i = 0;i < children.size();i++){
            nNode->addChild(children[i]);
            nodes.insert(nodes.end(), children[i]->getChildren().begin(), children[i]->getChildren().end());
        }
    }
    return nNode;
}

void TDATree::clear(){

}

void TDATree::print(TreeNode* v){
    TreeNode* temp = v;
    if(temp->getChildren().size() > 0){
        for(int i = 0;i < temp->getChildren().size();i++){
            print(temp->getChild(i));
        }
    }
    cout << temp->getTag();
}

bool TDATree::equals(Object *){

}

string TDATree::toString(){

}

TreeNode* TDATree::getRoot(){
    return root;
}