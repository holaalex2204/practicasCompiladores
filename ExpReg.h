#ifndef EXPREG_H
#define EXPREG_H
#include <string>
#include "ArbolSintactico.h"
#include "AFND.h"
class ExpReg
{
	public:
		explicit ExpReg(std::string expresion);
		~ExpReg();
		ArbolSintactico* obtenArbolSintactico();
	private:
	std::string cadena; //expresionregular
	bool esConcatenable(char a, char b);
	ArbolSintactico* arbolS;
	AFND* thompson;
	void crearArbolSintactico(int ini, int fin, NodoAS* papi); // crea el arbol sintactico usando como parámetro un rango pendiente de generar en la cadena asi como la posicion en el arbol en la que quedo.
};
#endif
