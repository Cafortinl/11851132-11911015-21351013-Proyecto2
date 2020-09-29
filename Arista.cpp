#include "Arista.h"
#include <string>
using namespace std;


Arista::Arista() {
	origen = 0;
	direccion = 0;
	peso = 0;
}
Arista::Arista(int dorigen, int ddireccion, int dpeso) {
	origen = dorigen;
	direccion = ddireccion;
	peso = dpeso;

}

int Arista::getOrigen() {
	return origen;
}
int Arista::getDireccion() {
	return direccion;
}
int Arista::getPeso() {
	return peso;
}
void Arista::setOrigen(int dorigen) {
	origen = dorigen;
}
void Arista::setDireccion(int ddireccion) {
	direccion = ddireccion;
}
void Arista::setPeso(int dpeso) {
	peso = dpeso; 
}
string Arista::toString(){
	string ret = "";
	ret += to_string(origen);
	ret += ",";
	ret += to_string(direccion);
	ret += ";";
	ret += to_string(peso);
	ret += "  ";

	return ret;
}
bool Arista::equals(Object*lol) {
	return true;
}

Arista::~Arista() {

}
