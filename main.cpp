#include <iostream>
#include "ArbolSintactico.h"
#include "ExpReg.h"
#include <string.h>
using namespace std;
int main()
{
	string entrada;
	ExpReg* expresion;
	while (1) {
		cout << "Ingresa una expresión regular" << endl;
		getline(cin,entrada);
		expresion = new ExpReg(entrada);
		cout << "El arbol sintáctico es el siguiente: (hijoizq)papa(hijoderecho)" << endl;
		expresion->obtenArbolSintactico()->imprime(expresion->obtenArbolSintactico()->obtenRaiz());
		cout << endl;
		expresion->obtenArbolSintactico()->imprimeAnulabilidad(expresion->obtenArbolSintactico()->obtenRaiz());
		cout << endl;
		expresion->~ExpReg();
	}
	 
	return 0;
}
