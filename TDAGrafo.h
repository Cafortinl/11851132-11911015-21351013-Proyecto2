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

    int** matrizAD();
    void listaAD(vector<Arista>);
    void prim();
    int** floyd();
    void kruskal();
    void printMatriz(int**);
    bool equals(Object*);
    string toString();



    ~TDAGrafo();
private:
    vector<Arista>aristas;
    int** matrizAristas;
    int cantAristas;


    
};

