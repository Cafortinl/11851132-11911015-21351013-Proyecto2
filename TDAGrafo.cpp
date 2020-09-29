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
// creador de matrices adyacentes
int** TDAGrafo::matrizAD(vector<Arista>aristas) {
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
		
		return matriz;
	}
	
}
void TDAGrafo::listaAD(vector<Arista>aristasdadas) {//metodo para crear una lista de adyacencia y print
	cout << "SIZE: " << aristasdadas.size()<<endl;
	vector<vector<Arista>>listaAD;
	vector<Arista>temp;
	int origentemp=0;
	for (int i = 0; i <aristasdadas.size();i++) {
		if(origentemp== aristasdadas[i].getOrigen()){
			temp.push_back(aristasdadas[i]);
		}else if(origentemp!=aristasdadas[i].getOrigen()){
			origentemp++;
			listaAD.push_back(temp);
			temp.clear();
			temp.push_back(aristasdadas[i]);
			
		}
	}
	listaAD.push_back(temp);
	temp.clear();
	for (int i = 0; i <listaAD.size();i++) {
		cout << i << " : ";
		for (int j = 0; j < listaAD[i].size(); j++) {
			cout << listaAD[i][j].toString();
		}
		cout << endl;
	}
	
}
void TDAGrafo::prim(vector<Arista>aristas) {//metodo para hacer el algoritmo de prim mediante matriz de adyacencia
	vector<Arista>pesosbajos=aristas;
	//Bubblesort para poder conseguir un vector de menores a mayores
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
	//vector para conjunto solucion
	vector<Arista>ConjuntoS;
	vector<int>visitados;
	int cont = 0;
	for (int i = 0; i < pesosbajos.size();i++) {
		//recorremos el vector bubblesorted para poder hacer los pesos 0 y que se pueda hacer 
		if (pesosbajos[i].getOrigen() == pesosbajos[i].getDireccion()) {
			//si esta en la diagonal principal que su peso sea 0
			ConjuntoS.push_back(pesosbajos[i]);

		}else if (visitados.size()==0) {
			//si es el primer visitado que se presentase anadira a los visitados el origen y la direccion
			ConjuntoS.push_back(pesosbajos[i]);
			visitados.push_back(pesosbajos.at(cont).getOrigen());
			visitados.push_back(pesosbajos.at(cont).getDireccion());

		}else if (visitados.size() == cantAristas) {
			//si ya hay suficientes visitados
			pesosbajos[i].setPeso(0);
			ConjuntoS.push_back(pesosbajos[i]);
		}
		else if (visitados.size()>0) {
			bool origen = false;
			bool direccion = false;
			for (int j = 0; j < visitados.size();j++) {
				if (pesosbajos[i].getOrigen() == visitados[j]) {
					origen = true;
				}
				if (pesosbajos[i].getDireccion()==visitados[j]) {
					direccion = true;
				}
			}
			if (origen==true && direccion==true) {
				pesosbajos[i].setPeso(0);
				ConjuntoS.push_back(pesosbajos[i]);

			}else {
				ConjuntoS.push_back(pesosbajos[i]);
				if (origen==true) {
					
					visitados.push_back(pesosbajos[i].getDireccion());
				}
				else if (direccion==true) {
					visitados.push_back(pesosbajos[i].getOrigen());
				}
				if (direccion == false && origen == false) {
					visitados.push_back(pesosbajos[i].getDireccion());
				}

			}
		}
		
	}
	int** matrizConjunto = matrizAD(ConjuntoS);
	printMatriz(matrizConjunto);
	
}
int** TDAGrafo::floyd(int** matrizdada) {//metodo para hacer el algoritmo de floyd mediante matriz de adyancencia
	int** matrizFloyd;
	matrizFloyd = new int*[cantAristas];
	for (int i = 0; i < cantAristas; i++)
	{
		matrizFloyd[i] = new int[cantAristas];
	}
	for (int k = 0; k <cantAristas;k++) {
		for (int i = 0; i <cantAristas;i++) {
			for (int j = 0; j <cantAristas;j++) {
				
				if (matrizdada[i][j]> matrizdada[i][k]+matrizdada[k][j]) {
					matrizdada[i][j] = matrizdada[i][k] + matrizdada[k][j];
				}
				//else {
					//matrizAristas[i][j] = matrizAristas[i][j];
				//}
			}
		}
	}
	return matrizdada;
}
void TDAGrafo::kruskal(vector<Arista>aristasdadas) {//metodo para hacer el algoritmo de kruskal mediante matriz de adyacencia
	vector<Arista>pesosbajos = aristasdadas;
	//Bubblesort para poder conseguir un vector de menores a mayores
	for (int i = 0; i < aristasdadas.size() - 1; i++) {
		for (int j = 0; j < aristasdadas.size() - i - 1; j++) {
			if (pesosbajos.at(j).getPeso() > pesosbajos.at(j + 1).getPeso()) {
				//swap a la forma de bubblesort
				int temp_origen = pesosbajos.at(j).getOrigen();
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
	//vector para conjunto solucion
	vector<Arista>ConjuntoS;
	vector<int>visitados;
	int cont = 0;
	for (int i = 0; i < pesosbajos.size(); i++) {
		//recorremos el vector bubblesorted para poder hacer los pesos 0 y que se pueda hacer 
		if (pesosbajos[i].getOrigen() == pesosbajos[i].getDireccion()) {
			//si esta en la diagonal principal que su peso sea 0
			ConjuntoS.push_back(pesosbajos[i]);

		}
		else if (visitados.size() == 0) {
			//si es el primer visitado que se presentase anadira a los visitados el origen y la direccion
			ConjuntoS.push_back(pesosbajos[i]);
			visitados.push_back(pesosbajos.at(cont).getOrigen());
			visitados.push_back(pesosbajos.at(cont).getDireccion());

		}
		else if (visitados.size() == cantAristas) {
			//si ya hay suficientes visitados
			pesosbajos[i].setPeso(0);
			ConjuntoS.push_back(pesosbajos[i]);
		}
		else if (visitados.size() > 0) {
			bool origen = false;
			bool direccion = false;
			for (int j = 0; j < visitados.size(); j++) {
				if (pesosbajos[i].getOrigen() == visitados[j]) {
					origen = true;
				}
				if (pesosbajos[i].getDireccion() == visitados[j]) {
					direccion = true;
				}
			}
			if (origen == true && direccion == true) {
				pesosbajos[i].setPeso(0);
				ConjuntoS.push_back(pesosbajos[i]);

			}
			else {
				ConjuntoS.push_back(pesosbajos[i]);
				if (origen == true) {

					visitados.push_back(pesosbajos[i].getDireccion());
				}
				else if (direccion == true) {
					visitados.push_back(pesosbajos[i].getOrigen());
				}
				if (direccion == false && origen == false) {
					visitados.push_back(pesosbajos[i].getDireccion());
				}

			}
		}

	}

	//creara un vector de vectores para hacer una lista de adyacencia y print de un solo
	vector<vector<Arista>>vectorkruskal;
	vector<Arista>temp;
	for (int i = 0; i < cantAristas;i++) {
		for (int j = 0; j < ConjuntoS.size();j++) {
			if (i== ConjuntoS[j].getOrigen() && ConjuntoS[j].getPeso()>0) {
				temp.push_back(ConjuntoS[j]);
			}
		}
		vectorkruskal.push_back(temp);
		temp.clear();
	}
	for (int i = 0; i < vectorkruskal.size(); i++) {
		cout << i << " : ";
		for (int j = 0; j < vectorkruskal[i].size(); j++) {
			cout << vectorkruskal[i][j].toString();
		}
		cout << endl;
	}
}

void TDAGrafo::printMatriz(int**matriz) {//metodo para poder hacer el print de una matriz 
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
