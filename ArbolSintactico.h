#ifndef ARBOLSINTACTICO_H
#define ARBOLSINTACTICO_H
#include "NodoAS.h"
class ArbolSintactico
{
	public:
		explicit ArbolSintactico();
		
		~ArbolSintactico();
		NodoAS* obtenRaiz();
	void imprime(NodoAS* pos);//imprime los valroes del arbol en preorden
		//aqui van a ir muchas operaciones pero despues en otras practicas
	private:
		NodoAS* raiz;
};
#endif
