#pragma once
#include "Object.hpp"
#include "Arista.h"
#include <vector>
#include <iostream>
#include<string>
using namespace std;
class TDAGrafo :public Object
{
public:
    TDAGrafo();
    TDAGrafo(int, vector<Arista>);

    int** matrizAD(vector<Arista>);
    void listaAD(vector<Arista>);
    void prim(vector<Arista>);
    int** floyd(int**);
    void kruskal(vector<Arista>);
    void printMatriz(int**);
    bool equals(Object*);
    string toString();



    ~TDAGrafo();
private:
    vector<Arista>aristas;
    int** matrizAristas;
    int cantAristas;


    
};

