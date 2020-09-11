#ifndef TREENODE_HPP
#define TREENODE_HPP

#include "Object.hpp"
#include <string>
#include <vector>

using namespace std;

class TreeNode : public Object{
    private:
        string tag;
        TreeNode* parent;
        vector<TreeNode*> children;
    public:
        TreeNode();
        TreeNode(string, TreeNode*);
        ~TreeNode();
        void setChildren(vector<TreeNode*>);
        vector<TreeNode*> getChildren();
        void addChild(TreeNode*);
        TreeNode* getChild(int);
        void setParent(TreeNode*);
        TreeNode* getParent();
        void setTag(string);
        string getTag();
        bool equals(Object*);
        string toString();
};
#endif

/*
    //anula()
    //si no esta vacio
        //for i = 1 to n
            //delete nodos[i]
        delete nodos
        raiz = NULL

    //destructor de TreeNode
    //si tiene hijos
        //for i = 1 to hijos.size
            hijos[i].padre = NULL
            hijos[i] = NULL
        delete hijos;
        delete padre
        
*/