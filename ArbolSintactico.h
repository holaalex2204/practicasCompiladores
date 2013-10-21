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
		void imprimeAnulabilidad(NodoAS* pos);
		void asignaIndices(NodoAS* pos);
		void calculaPrimeros();
		void calculaUltimos();
		void calculaSiguientes();		
	private:
		int indice;
		NodoAS* raiz;
};
#endif
