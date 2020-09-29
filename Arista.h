#pragma once
#include "Object.hpp"
#include <string>
using namespace std;

class Arista :
    public Object
{

public:
    Arista();
    Arista(int, int, int);
    ~Arista();

    int getOrigen();
    int getDireccion();
    int getPeso();
    void setOrigen(int);
    void setDireccion(int);
    void setPeso(int);
    string toString();
    bool equals(Object*);
    

private:
    int origen;
    int direccion;
    int peso;
};

