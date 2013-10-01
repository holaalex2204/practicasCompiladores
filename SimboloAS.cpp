#include "SimboloAS.h"
SimboloAS::SimboloAS(char a):
	NodoAS()
	{
		valor = a;
	}
SimboloAS::~SimboloAS()
{
	
}
bool SimboloAS::esOperacion()
{
	return false;
}
bool SimboloAS:: esAnulable()
{
	return false;
}
bool SimboloAS:: esSimbolo()
{
	return true;
}
char SimboloAS::obtenValor()
{
	return valor;
}
NodoAS* SimboloAS::obtenIzq()
{
	return 0;
}
NodoAS* SimboloAS::obtenDer()
{
	return 0;
}
void SimboloAS::agregaIzq(NodoAS* n)
{
	return; // NO SE AGREGA
}
void SimboloAS::agregaDer(NodoAS* n)
{
	return; // NO SE AGREGA
}


