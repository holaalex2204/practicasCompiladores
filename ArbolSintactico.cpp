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
	indice = 0;
}
ArbolSintactico::~ArbolSintactico()
{
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
void ArbolSintactico::imprimeAnulabilidad(NodoAS* pos)
{
	if (pos->obtenIzq()!=0) {
		std::cout << "(";
		imprimeAnulabilidad(pos->obtenIzq());
		std::cout << ")";
	}
	std::cout << std::endl<< pos->obtenValor();
	std::set<int> myset = pos->obtenSiguientes();
	for (std::set<int>::iterator it=myset.begin(); it!=myset.end(); ++it)
	{
		std::cout << *it << ", ";
	}
	std::cout << std::endl;
	if (pos->obtenDer()!=0) {
		std::cout << "(";
		imprimeAnulabilidad(pos->obtenDer());
		std::cout << ")";
	}
}
void ArbolSintactico::asignaIndices(NodoAS* pos)
{
	if (pos->obtenIzq()!=0) {
		asignaIndices(pos->obtenIzq());
	}
	if (pos->esSimbolo()) {
		pos->asignaIndice(++indice);
	}
	if (pos->obtenDer()!=0) {
		asignaIndices(pos->obtenDer());
	}
}
void ArbolSintactico::calculaPrimeros()
{
	raiz->calculaPrimeros();
}
void ArbolSintactico::calculaUltimos()
{
	raiz->calculaUltimos();
}
void ArbolSintactico::calculaSiguientes()
{
	raiz->calculaSiguientes();
}



