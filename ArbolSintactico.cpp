#include "ArbolSintactico.h"
#include "ConcatAS.h"
#include "OrAS.h"
#include "SimboloAS.h"
#include "CerraduraEstAS.h"
#include "CerraduraPosAS.h"
#include <iostream>
ArbolSintactico::ArbolSintactico()
{
	raiz = dynamic_cast<NodoAS*>(new ConcatAS());
	raiz->agregaDer(( dynamic_cast<NodoAS*>(new SimboloAS('#'))));	
}
ArbolSintactico::~ArbolSintactico()
{
		//raiz->~NodoAS();
}
NodoAS* ArbolSintactico::obtenRaiz()
{
	return raiz;
}
void ArbolSintactico::imprime(NodoAS* pos)
{
	
	if (pos->obtenIzq()!=0) {
		std::cout << "(";
		imprime(pos->obtenIzq());
		std::cout << ")";
	}	
	
	std::cout << pos->obtenValor() << " ";
	
	if (pos->obtenDer()!=0) {
		std::cout << "(";
		imprime(pos->obtenDer());
		std::cout << ")";
	}
	
	
}




