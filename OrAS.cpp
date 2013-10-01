#include "OrAS.h"
OrAS::OrAS():
	NodoAS()
	{
		valor = '|';
	}
OrAS::~OrAS()
{
	
}
bool OrAS::esOperacion()
{
	return true;
}
bool OrAS:: esAnulable()
{
	return true;
}
bool OrAS:: esSimbolo()
{
	return false;
}
char OrAS::obtenValor()
{
	return '|';
}
NodoAS* OrAS::obtenIzq()
{
	return hijoIzq;
}
NodoAS* OrAS::obtenDer()
{
	return hijoDer;
}
void OrAS::agregaIzq(NodoAS* n)
{
	hijoIzq = n;
}
void OrAS::agregaDer(NodoAS* n)
{
	hijoDer = n;
}



