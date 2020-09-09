#include <iostream>
#include <fstream>

using namespace std;

//Método que valida que la entrada es del tipo de dato correcto (entero)
int validInput() {
	int input;
	cin >> input;
	while (cin.fail()) {
		cin.clear();
		cin.ignore();
		cout << "Este campo requiere un número entero. Ingréselo nuevamente: ";
		cin >> input;
	}
	return input;
}

//Método que muestra los menú del programa
void showMenu(int x) {
	switch (x) {
		case 1: {//Muestra el menú principal
			cout << "Menú Principal\n1. Algoritmos sobre Árboles\n2. Algoritmos sobre Grafos\n3. Salir" << endl;
			break;
		}
		case 2: {//Muestra las opciones de los árboles
			cout << "Algoritmos sobre Árboles\n1. Leer árbol de un archivo\n2. Imprimir recorrido preorder\n3. Imprimir recorrido in order\n4. Imprimir recorrido postorder\n5. Codificador de Huffman\n6. Decodificador de Huffman\n7. Regresar al Menú Principal" << endl;
			break;
		}
		case 3: {//Muestra las opciones de los grafos
			cout << "Algoritmos sobre Grafos\n1. Leer grafo de un archivo\n2. Prim\n3. Kruskal\n4. Floyd\n5. Regresar al Menú principal" << endl;
			break;
		}
	}
	cout << endl;
}

//Método que ejecuta las opciones de árboles
void TreeOptions() {
	int opcion = 0;
	do {
		showMenu(2);
		opcion = validInput();
		switch (opcion) {
			case 1: {//Leer árbol de un archivo
				break;
			}
			case 2: {//Imprimir preorder
				break;
			}
			case 3: {//Imprimir in order
				break;
			}
			case 4: {//Imprimir postorder
				break;
			}
			case 5: {//Codificador de Huffman
				break;
			}
			case 6: {//Decodificador de Huffman
				break;
			}
			case 7: {//Regresar al menú principal
				break;
			}
			default: {
				cout << "La opción ingresada no es válida." << endl;
			}
		}
	} while (opcion != 7);
}

//Método que ejecuta las opciones de grafos
void GraphOptions() {
	int opcion = 0;
	do {
		showMenu(3);
		opcion = validInput();
		switch (opcion) {
			case 1: {//Leer grafo de un archivo
				break;
			}
			case 2: {//Prim
				break;
			}
			case 3: {//Kruskal
				break;
			}
			case 4: {//Floyd
				break;
			}
			case 5: {//Regresar al menú principal
				break;
			}
			default: {
				cout << "La opción ingresada no es válida." << endl;
			}
		}
	} while (opcion != 5);
}

//Método que ejecuta las opciones del menú principal
void menuOptions(int x) {
	switch (x) {
		case 1: {//Opciones árboles
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
			cout << "La opción ingresada no es válida." << endl;
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