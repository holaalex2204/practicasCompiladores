#include "CerraduraPosAS.h"
CerraduraPosAS::CerraduraPosAS():
	NodoAS()
	{

	}
CerraduraPosAS::~CerraduraPosAS()
{
	
}
bool CerraduraPosAS::esOperacion()
{
	return true;
}
bool CerraduraPosAS:: esAnulable()
{
	return hijoIzq->esAnulable();
}
bool CerraduraPosAS:: esSimbolo()
{
	return false;
}
char CerraduraPosAS::obtenValor()
{
	return '+';
}
NodoAS* CerraduraPosAS::obtenIzq()
{
	return hijoIzq;
}
NodoAS* CerraduraPosAS::obtenDer()
{
	return 0;
}
void CerraduraPosAS::agregaIzq(NodoAS* n)
{
	hijoIzq = n;
}
void CerraduraPosAS::agregaDer(NodoAS* n)
{
		//no puede tener hijo derecho
}
void CerraduraPosAS::calculaUltimos()
{
	ultimos.clear();
	obtenIzq()->calculaUltimos();
	std::set<int> myset = obtenIzq()->obtenUltimos();
	for (std::set<int>::iterator it=myset.begin(); it!=myset.end(); ++it)
	{
		ultimos.insert(*it);
	}
}

