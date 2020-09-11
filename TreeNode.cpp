#include "TreeNode.hpp"

TreeNode::TreeNode(){
}

TreeNode::TreeNode(string nTag, TreeNode* nParent){
    tag = nTag;
    parent = nParent;
}

TreeNode::~TreeNode(){

}

void TreeNode::setChildren(vector<TreeNode*> nChildren){
    children = nChildren;
}

vector<TreeNode*> TreeNode::getChildren(){
    return children;
}

void TreeNode::addChild(TreeNode* nChild){
    children.push_back(nChild);
}

TreeNode* TreeNode::getChild(int p){
    return children[p];
}

void TreeNode::setParent(TreeNode* node){
    parent = node;
}

TreeNode* TreeNode::getParent(){
    return parent;
}

void TreeNode::setTag(string nTag){
    tag = nTag;
}

string TreeNode::getTag(){
    return tag;
}

bool TreeNode::equals(Object* x){
    
}

string TreeNode::toString(){
    
}
