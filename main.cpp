#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "TDATree.hpp"
#include "TDAGrafo.h"
#include "Arista.h"
#include<sstream>
#include <climits>

using namespace std;

//M�todo que imprime el �rbol en orden posterior
void postOrder(TreeNode* n) {
	for (int i = 0; i < n->getChildren().size(); i++) {//Procesando los hijos de n
		postOrder(n->getChild(i));
		cout << ',';
	}
	cout << n->getTag();//Imprimiendo n
}

//M�todo que imprime el �rbol en orden sim�trico
void inOrder(TreeNode* n) {
	if (n->getChildren().size() != 0) {//Procesando el hijo de la izquierda de n si existe
		inOrder(n->getChild(0));
		cout << ',';
	}
	cout << n->getTag();//Imprimiendo n
	for (int i = 1; i < n->getChildren().size(); i++) {//Procesando los hermanos de n
		cout << ',';
		inOrder(n->getChild(i));
	}
}

//M�todo que imprime el �rbol en orden previo
void preOrder(TreeNode* n) {
	cout << n->getTag();//Imprimir n
	if (n->getChildren().size() != 0) {//Validando si n tiene hijos
		for (int i = 0; i < n->getChildren().size(); i++) {//Procesando los hijos de n
			cout << ',';
			TreeNode* t = n->getChild(i);
			preOrder(t);
			t = nullptr;
			delete t;//Liberando memoria
		}
	}
}


//M�todo que revisa si un string es un string vac�o
bool isEmpty(string x) {
	for (int i = 0; i < x.size(); i++) {
		if (x[i] != '\t')
			return false;
	}
	return true;
}

//M�todo que retorna un vector de string con las etiquetas que se encuentran en un string
vector<string> returnTags(string x) {
	vector<string> texto;
	int pos = 0;
	for (int i = 0; i < x.size(); i++) {
		if (x[i] == ',') {
			texto.push_back(x.substr(pos, i - pos));
			pos = i + 1;
		}
	}
	if (x.substr(pos, x.size() - pos) != "")
		texto.push_back(x.substr(pos, x.size() - pos));
	return texto;
}

//M�todo que valida que la entrada es del tipo de dato correcto (entero)
int validInput() {
	int input;
	cin >> input;
	while (cin.fail()) {
		cin.clear();
		cin.ignore();
		cout << "Este campo requiere un n�mero entero. Ingr�selo nuevamente: ";
		cin >> input;
	}
	return input;
}

//M�todo que muestra los men� del programa
void showMenu(int x) {
	switch (x) {
		case 1: {//Muestra el men� principal
			cout << "Men� Principal\n1. Algoritmos sobre �rboles\n2. Algoritmos sobre Grafos\n3. Salir" << endl;
			break;
		}
		case 2: {//Muestra las opciones de los �rboles
			cout << "Algoritmos sobre �rboles\n1. Leer �rbol de un archivo\n2. Imprimir recorrido preorder\n3. Imprimir recorrido in order\n4. Imprimir recorrido postorder\n5. Codificador de Huffman\n6. Decodificador de Huffman\n7. Regresar al Men� Principal" << endl;
			break;
		}
		case 3: {//Muestra las opciones de los grafos
			cout << "Algoritmos sobre Grafos\n1. Leer grafo de un archivo\n2. Prim\n3. Kruskal\n4. Floyd\n5. Regresar al Men� principal" << endl;
			break;
		}
	}
	cout << endl;
}

//M�todo que ejecuta las opciones de �rboles
void TreeOptions() {
	TDATree* tree = nullptr;
	int opcion = 0;
	do {
		showMenu(2);
		opcion = validInput();
		switch (opcion) {
			case 1: {//Leer �rbol de un archivo
				ifstream file;
				string nombre, linea;
				int times;
				vector<string> lineas;//Vector que contiene las l�neas del archivo
				vector<TDATree*> arboles;//Vector que contiene los �rboles formados
				cout << "Ingrese el nombre del archivo en el que est� guardado el �rbol (no es necesario agregarle la extensi�n): ";
				cin.ignore();
				getline(cin, nombre);
				file.open(nombre + ".txt", ios::in);
				if (file) {//Si se tuvo �xito al abrir el archivo
					cout << "El archivo se abri� exit�samente" << endl;
					getline(file, linea, '\n');
					times = stoi(linea);//Determinando el n�mero de lineas que se debem leer
					for (int j = 0; j < times; j++) {
						getline(file, linea, '\n');
						if (isEmpty(linea))//Revisando si la linea est� vac�a
							linea = "";
						lineas.push_back(linea);//Agregando la l�nea al vector de l�neas
					}
					file.close();
					for (int i = lineas.size() - 1; i >= 0; i--) {//Creando los �rboles
						if (lineas[i] != "") {//Revisando si la linea no est� vac�a
							TDATree* tr = nullptr;//Puntero a TDATree que servir� para agregar �rboles al vector de �rboles
							vector<TDATree*> aux;//Vector de �rboles auxiliares. Se manda como argumento para el m�todo crea
							for (int j = 0; j < returnTags(lineas[i]).size(); j++) {//Creando los �rboles que se formar�n parte del �rbol
								bool exists = false;//Bool que revisa si el tag del �rbol creado ya existe
								if (arboles.size() != 0) {
									for (int k = 0; k < arboles.size(); k++) {
										if (arboles[k]->getRoot()->getTag() == returnTags(lineas[i])[j]) {//Revisando si ya existe un �rbol con la etiqueta dada
											tr = arboles[k];//Igualando tr al �rbol que tiene la etiqueta dada
											exists = true;
											arboles.erase(arboles.begin() + k);
											break;
										}
									}
								}
								if (!exists)//Si no existe un �rbol con la etiqueta dada
									tr = new TDATree(returnTags(lineas[i])[j]);//tr ser� un nuevo �rbol
								aux.push_back(tr);//Agregando tr al vector auxiliar
							}
							tr = new TDATree;//tr es un nuevo �rbol para poder agregarle los �rboles del vector aux
							tr->create(to_string(i), aux);//Agregando los vectores en aux como hijos de tr
							arboles.push_back(tr);//Agregando tr a arboles
						}
					}
					tree = arboles[0];
					arboles.clear();
				}
				else
					cout << "No se pudo abrir el archivo" << endl;
				break;
			}
			case 2: {//Imprimir preorder
				if (tree) {
					preOrder(tree->getRoot());
					cout << endl;
				}
				else
					cout << "No ha abierto ningun �rbol" << endl;
				break;
			}
			case 3: {//Imprimir in order
				if (tree) {
					inOrder(tree->getRoot());
					cout << endl;
				}else
					cout << "No ha abierto ningun �rbol" << endl;
				break;
			}
			case 4: {//Imprimir postorder
				if (tree) {
					postOrder(tree->getRoot());
					cout << endl;
				}else
					cout << "No ha abierto ningun �rbol" << endl;
				break;
			}
			case 5: {//Codificador de Huffman
				break;
			}
			case 6: {//Decodificador de Huffman
				break;
			}
			case 7: {//Regresar al men� principal
				break;
			}
			default: {
				cout << "La opci�n ingresada no es v�lida." << endl;
			}
		}
		cout << endl;
	} while (opcion != 7);
	delete tree;
}

//M�todo que ejecuta las opciones de grafos
void GraphOptions() {
	int opcion = 0;
	TDAGrafo grafo = TDAGrafo();
	vector<Arista>aristas;
	int cantAristas = 0;
	//TDAGrafo grafo = TDAGrafo();
	do {
		showMenu(3);
		opcion = validInput();
		switch (opcion) {
			case 1: {//Leer grafo de un archivo
				ifstream file;
				string nombre, linea;
				
				
				vector<string>lineas;
				vector<string>numeros;

				cout << "Ingrese el nombre del archivo: " << endl;
				getline(cin, nombre);
				getline(cin, nombre);
				file.open(nombre + ".txt", ios::in);
				if (file) {
					cout << "Se ha encontrado y abierto el archivo." << endl;
					getline(file, linea, '\n');
					cantAristas = stoi(linea);
					for (int j = 0; j < cantAristas; j++) {
						getline(file, linea, '\n');
						if (isEmpty(linea))//Revisando si la linea est� vac�a
							linea = "";
						lineas.push_back(linea);//Agregando la l�nea al vector de l�neas
					}
					file.close();
				}else {
					cout << "Archivo no encontrado" << endl;
				}
				//cout << "SIZE:" << lineas.size()<<endl;
				for (int i = 0; i < lineas.size();i++) {
					string frag = lineas.at(i);
					//cout << i<<"   "<<frag<<endl;
					istringstream ss(frag);
					string token;
					int cont = 0;
					while (getline(ss,token,';')) {
						//numeros.push_back(token);
						istringstream ss2(token);
						string numerosseparados;
						while (getline(ss2, numerosseparados, ',')) {
							numeros.push_back(numerosseparados);
						}
						Arista arista = Arista();
						arista.setOrigen(i);
						if (stoi(numeros[0])==-1 && stoi(numeros[1])==-1) {
							arista.setDireccion(i);
							arista.setPeso(0);//numeros[1]
						}
						else if (stoi(numeros[0]) == -1 && stoi(numeros[1]) == 0) {
							arista.setDireccion(cont);
							arista.setPeso(1000);
						}
						else {
							arista.setDireccion(stoi(numeros[0]));
							arista.setPeso(stoi(numeros[1]));
						}
						aristas.push_back(arista);
						numeros.clear();
						if (cont== cantAristas-1) {
							cont = 0;
						}
						else {
							cont++;
						}
					}	
				}
				//cout << "SIZE YA TU SABES: " << aristas.size() << endl;
				//for (int i = 0; i < aristas.size(); i++){
					//cout << aristas[i].toString() << endl;
				//}
				grafo = TDAGrafo(cantAristas, aristas);
			
				cout << "Grafo cargado exitosamente!!!!!"<<endl;

				break;
			}
			case 2: {//Prim
				int** matrizAD = grafo.matrizAD(aristas);
				grafo.printMatriz(matrizAD);
				cout << endl;
				cout << endl;
				grafo.prim(matrizAD);
				break;
			}
			case 3: {//Kruskal
				grafo.listaAD(aristas);
				cout << endl;
				cout << endl;
				grafo.kruskal(aristas);
				break;
			}
			case 4: {//Floyd
				int** matrizAD=grafo.matrizAD(aristas);
				cout << "La matriz de adyacencia es:"<<endl;
				grafo.printMatriz(matrizAD);
				cout << endl;
				cout << endl;
				cout << "La matriz de floyd es: " << endl;
				int** matrizfloyd = grafo.floyd(matrizAD);
				grafo.printMatriz(matrizfloyd);


				break;
			}
			case 5: {//Regresar al men� principal
				break;
			}
			default: {
				cout << "La opci�n ingresada no es v�lida." << endl;
			}
		}
	} while (opcion != 5);
}

//M�todo que ejecuta las opciones del men� principal
void menuOptions(int x) {
	switch (x) {
		case 1: {//Opciones �rboles
			TreeOptions();
			break;
		}
		case 2: {//Opciones grafos
			GraphOptions();
			break;
		}
		case 3: {//Salir del programa
			break;
		}
		default: {
			cout << "La opci�n ingresada no es v�lida." << endl;
			break;
		}
	}
}

int main() {
	int opcion = 0;
	do {
		showMenu(1);
		opcion = validInput();
		menuOptions(opcion);
	} while (opcion != 3);
	cout << "Fin del programa." << endl;
	return 0;
}