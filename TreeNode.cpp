#include "TreeNode.hpp"
#include <iostream>

TreeNode::TreeNode(){
    parent = nullptr;
}

TreeNode::TreeNode(string nTag, TreeNode* nParent){
    tag = nTag;
    parent = nParent;
}

TreeNode::~TreeNode(){
    if(children.size() != 0){
        for(int i = 0;i < children.size();i++){
            delete children[i];
        }
    }
    children.clear();
    parent = nullptr;
    delete parent;
}

//Método que asigna a nChildren a la lista de hijos del nodo
void TreeNode::setChildren(vector<TreeNode*> nChildren){
    children = nChildren;
}

//Método que devuelve la lista de hijos del nodo
vector<TreeNode*> TreeNode::getChildren(){
    return children;
}

//Método que agrega el nodo nChild a la lista de hijos
void TreeNode::addChild(TreeNode* nChild){
    nChild->setParent(this);
    children.push_back(nChild);
}

//Método que regresa el hijo p de la lista de nodos
TreeNode* TreeNode::getChild(int p){
    return children[p];
}

//Método que asigna a node como el padre del nodo
void TreeNode::setParent(TreeNode* node){
    parent = node;
}

//Método que retorna el padre del nodo
TreeNode* TreeNode::getParent(){
    return parent;
}

//Método que asigna a nTag cómo la etiqueta del nodo
void TreeNode::setTag(string nTag){
    tag = nTag;
}

//Método que retorna la etiqueta del nodo
string TreeNode::getTag(){
    return tag;
}

//Método que devuelve verdadero si el nodo x es igual a this
bool TreeNode::equals(Object* x){
    if(dynamic_cast<TreeNode*>(x)){
        return this->getTag() == dynamic_cast<TreeNode*>(x)->getTag() && this->getChildren() == dynamic_cast<TreeNode*>(x)->getChildren();
    }
    return false; 
}

string TreeNode::toString(){
    
}
