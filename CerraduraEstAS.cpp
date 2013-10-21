#include "CerraduraEstAS.h"
CerraduraEstAS::CerraduraEstAS():
	NodoAS()
	{

	}
CerraduraEstAS::~CerraduraEstAS()
{
	
}
bool CerraduraEstAS::esOperacion()
{
	return true;
}
bool CerraduraEstAS:: esAnulable()
{
	return true;
}
bool CerraduraEstAS:: esSimbolo()
{
	return false;
}
char CerraduraEstAS::obtenValor()
{
	return '*';
}
NodoAS* CerraduraEstAS::obtenIzq()
{
	return hijoIzq;
}
NodoAS* CerraduraEstAS::obtenDer()
{
	return 0;
}
void CerraduraEstAS::agregaIzq(NodoAS* n)
{
	hijoIzq = n;
}
void CerraduraEstAS::agregaDer(NodoAS* n)
{
		//no puede tener hijo derecho
}
void CerraduraEstAS::calculaUltimos()
{
	ultimos.clear();
	obtenIzq()->calculaUltimos();
	std::set<int> myset = obtenIzq()->obtenUltimos();
	for (std::set<int>::iterator it=myset.begin(); it!=myset.end(); ++it)
	{
		ultimos.insert(*it);
	}
}



