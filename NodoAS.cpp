#include "NodoAS.h"
NodoAS::NodoAS()
	{
		hijoIzq = 0;
		hijoDer = 0;
	}
NodoAS::~NodoAS()
{
	if (hijoIzq != 0) {
		hijoIzq->~NodoAS();
	}
	if (hijoDer != 0) {
		hijoDer->~NodoAS();
	}	
}
bool NodoAS::esOperacion()
{
	return true;
}
bool NodoAS::esAnulable()
{
	return true;
}
bool NodoAS::esSimbolo()
{
	return true;
}
char NodoAS::obtenValor()
{
	return valor;
}
NodoAS* NodoAS::obtenIzq()
{
	return 0;
}
NodoAS* NodoAS::obtenDer()
{
	return 0;
}
void NodoAS::agregaIzq(NodoAS* n)
{
}
void NodoAS::agregaDer(NodoAS* n)
{
}

