#include "TDAGrafo.h"
#include<iostream>
#include <climits>
using namespace std;

TDAGrafo::TDAGrafo() {

}
TDAGrafo::TDAGrafo(int cant, vector<Arista>aristasDadas) {
	cantAristas = cant;
	aristas = aristasDadas;
}

int** TDAGrafo::matrizAD() {
	if (aristas.size()==NULL) {
		cout << "No hay aristas";
	}else{
		int** matriz;
		matriz = new int* [cantAristas];
		for (int i = 0; i < cantAristas; i++)
		{
			matriz[i] = new int[cantAristas];
		}
		//int** matriz = new int[cantAristas];
		for (int i = 0; i < aristas.size();i++) {
			int k = (aristas.at(i)).getOrigen();
			int j = (aristas.at(i)).getDireccion();
			matriz[k][j] = (aristas.at(i)).getPeso();
		}
		//check this before
		matrizAristas = matriz;
	}
	return matrizAristas;
}
void TDAGrafo::listaAD(vector<Arista>) {

}
void TDAGrafo::prim() {
	/*vector<Arista>pesosbajos=aristas;
	//for (int i = 0; i < aristas.size(); i++) {
		//Arista arista= Arista();
	for (int i = 0; i < aristas.size() - 1; i++) {
		for (int j = 0; j < aristas.size() - i - 1; j++) {
			if (pesosbajos.at(j).getPeso() > pesosbajos.at(j + 1).getPeso()) {
				//swap a la forma de bubblesort
				int temp_origen= pesosbajos.at(j).getOrigen();
				int temp_direccion = pesosbajos.at(j).getDireccion();
				int temp_peso = pesosbajos.at(j).getPeso();

				pesosbajos.at(j).setOrigen(pesosbajos.at(j + 1).getOrigen());
				pesosbajos.at(j).setDireccion(pesosbajos.at(j + 1).getDireccion());
				pesosbajos.at(j).setPeso(pesosbajos.at(j + 1).getPeso());

				pesosbajos.at(j + 1).setOrigen(temp_origen);
				pesosbajos.at(j + 1).setDireccion(temp_direccion);
				pesosbajos.at(j + 1).setPeso(temp_peso);
			}
		}
	}
	vector<Arista>ConjuntoS;
	vector<int>visitados;
	int cont = 0;
	while (ConjuntoS.size()==0) {
		if (pesosbajos.at(cont).getDireccion() != -1 || pesosbajos.at(cont).getPeso() != 0) {
			ConjuntoS.push_back(pesosbajos.at(cont));
			visitados.push_back(pesosbajos.at(cont).getOrigen());
			visitados.push_back(pesosbajos.at(cont).getDireccion());
		}
		else {
			cont++;
		}
	}
	for (int i = 0; i < visitados.size();i++) {
		if (pesosbajos.at(cont).getOrigen()) {

		}
	}*/
	vector<Arista*> cs;
	int vertice = 0;
	//bool visit[cantAristas];
	vector<bool>visit;
	//int aux[cantAristas];
	vector<int>aux;
	int cont = 0;
	for (int i = 0; i < cantAristas; i++) {
		visit[i] = false;
		aux[i] = matrizAristas[0][i];
	}
	visit[vertice] = true;

	while (cont < cantAristas) {
		int minimum = INT32_MAX;
		int pos = -1;
		//Buscando la arista más pequeña en aux
		for (int i = 0; i < cantAristas; i++) {
			if (aux[i] < minimum && !visit[i]) {
				minimum = aux[i];
				pos = i;
			}
		}
		if (pos > -1) {
			visit[pos] = true;
			Arista* temp = new Arista(vertice, pos, aux[pos]);
			cs.push_back(temp);
			cont++;
			//Actualizando aux
			for (int i = 0; i < cantAristas; i++) {
				if (!visit[i]) {
					aux[i] = min(aux[i], matrizAristas[pos][i]);
				}
			}
			vertice = pos;
		}
	}
	

}
int** TDAGrafo::floyd() {
	int** matrizFloyd;
	matrizFloyd = new int*[cantAristas];
	for (int i = 0; i < cantAristas; i++)
	{
		matrizFloyd[i] = new int[cantAristas];
	}
	for (int k = 0; k <cantAristas;k++) {
		for (int i = 0; i <cantAristas;i++) {
			for (int j = 0; j <cantAristas;j++) {
				
				if (matrizAristas[i][j]> matrizAristas[i][k]+matrizAristas[k][j]) {
					matrizAristas[i][j] = matrizAristas[i][k] + matrizAristas[k][j];
				}
				//else {
					//matrizAristas[i][j] = matrizAristas[i][j];
				//}
			}
		}
	}
	return matrizAristas;
}
void TDAGrafo::kruskal() {

}
void TDAGrafo::printMatriz(int**matriz) {
	for (int i = 0; i < cantAristas; i++) {
		for (int j = 0; j < cantAristas; j++) {
			if (matriz[i][j]==1000) {
				cout << "[+-] ";
			}
			else {
				cout << "[" + to_string(matriz[i][j]) + "] ";
			}
			
		}
		cout << endl;
	}
}
bool TDAGrafo::equals(Object*) {
	return true;
}
string TDAGrafo::toString() {
	string cat = " ";
	return cat;
}
TDAGrafo::~TDAGrafo() {

}
