#include "ConcatAS.h"
ConcatAS::ConcatAS():
	NodoAS()
	{

	}
ConcatAS::~ConcatAS()
{
	
}
bool ConcatAS::esOperacion()
{
	return true;
}
bool ConcatAS:: esAnulable()
{
	return true;
}
bool ConcatAS:: esSimbolo()
{
	return false;
}
char ConcatAS::obtenValor()
{
	return '.';
}
NodoAS* ConcatAS::obtenIzq()
{
	return hijoIzq;
}
NodoAS* ConcatAS::obtenDer()
{
	return hijoDer;
}
void ConcatAS::agregaIzq(NodoAS* n)
{
	hijoIzq = n;
}
void ConcatAS::agregaDer(NodoAS* n)
{
	hijoDer = n;
}



