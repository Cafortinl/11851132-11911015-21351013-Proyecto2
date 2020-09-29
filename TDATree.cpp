#include "TDATree.hpp"
#include <iostream>

using namespace std;

//Carlos Fortín

TDATree::TDATree(){
    root = nullptr;
}

TDATree::TDATree(string t){
    root = new TreeNode(t, nullptr);
    nodes.push_back(root);
}

TDATree::~TDATree(){
    delete root;
    nodes.clear();
}

//Método que retorna el padre del nodo en la posición p
TreeNode *TDATree::getParent(int p){
    return nodes[p]->getParent();
}

//Método que regresa el hijo de más a la izquierda del nodo n, si no tiene regresa null
TreeNode* TDATree::getLefmosttChild(TreeNode* n){
    int p = -1;
    for(int i = 0;i < nodes.size();i++){//Encontrando el índice de n
        if(n->equals(nodes[i])){
            p = i;
            break;
        }
    }
    if(p > -1){//Si se encontró el n
        if(nodes[p]->getChildren().size() != 0)
            return nodes[p]->getChild(0);
        else
            return nullptr;
    }else
        return nullptr;
}

//Método que regresa el hijo que le sigue al nodo n, si no tiene regresa null
TreeNode* TDATree::getNextChild(TreeNode* n){
    TreeNode* temp = nullptr;
    for(TreeNode* t : nodes){//Encontrando n y haciendo que temp apunte al padre de temp
        if(t->equals(n)){
            temp = n->getParent();
            break;
        }
    }
    if(temp){//Si se encontró n
        int i = 0;
        for(TreeNode* x : temp->getChildren()){
            if(x->equals(n)){
                if(i+1 <= temp->getChildren().size())//Revisando si n no es el último hijo de temp
                    return temp->getChild(i+1);
            }
            i++;
        }
    }
    return nullptr;
}

//Método que regresa la etiqueta del nodo en la posición p
string TDATree::getTag(int p){
    return nodes[p]->getTag();
}

//Método que retorna un árbol con etiqueta tag y como hijos los elementos de children
void TDATree::create(string tag, vector<TDATree*> children){
    TDATree* nTree = new TDATree(tag);//Creando un nuevo árbol
    if(children.size() > 0){//Recorriendo la lista de árboles que serán hijos de nNode
        for(int i = 0;i < children.size();i++){
            children[i]->getRoot()->setParent(nTree->getRoot());
            nTree->getRoot()->addChild(children[i]->getRoot());//Agregando la raiz de children[i] a los hijos de nTree
            if(children[i]->getNodes().size() != 0)//Revisando si children[i] tiene nodos en su lista de nodos
               nTree->addNodes(children[i]->getNodes());//Agregando la lista de nodos de children[i] a la lista de nodos de nTree
            else
                nTree->addNode(children[i]->getRoot());//Agregando la raiz de children[i] a la lista de nodos de nTree
        }
    }
    root = nTree->getRoot();//Igualando la raiz del árbol actual a la de nTree
    nodes = nTree->getNodes();//Igualando la lista de nodos del árbol actual a la de nTree
}

//Método que elimina todos los elementos del árbol, dejandolo como un árbol nulo
void TDATree::clear(){
    delete root;
    nodes.clear();
    root = nullptr;
}

bool TDATree::equals(Object *){
    return false;
}

string TDATree::toString(){
    return root->getTag();
}

//Método que retorna la raiz del árbol
TreeNode* TDATree::getRoot(){
    return root;
}

//Método que retorna la lista de nodos del árbol
vector<TreeNode*> TDATree::getNodes(){
    return nodes;
}

//Método que agrega un nodo n a la lista de nodos del árbol
void TDATree::addNode(TreeNode* n){
    nodes.push_back(n);
}

//Método que agrega una lista de nodos n a la lista de nodos del árbol
void TDATree::addNodes(vector<TreeNode*> n){
    nodes.insert(nodes.end(), n.begin(), n.end());
}