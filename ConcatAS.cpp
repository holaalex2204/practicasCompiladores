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
	return (obtenIzq()->esAnulable() && obtenDer()->esAnulable());
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
void ConcatAS::calculaPrimeros()
{
	primeros.clear();
	obtenIzq()->calculaPrimeros();
	obtenDer()->calculaPrimeros();
	std::set<int> myset = obtenIzq()->obtenPrimeros();
	for (std::set<int>::iterator it=myset.begin(); it!=myset.end(); ++it)
	{
		primeros.insert(*it);
	}	
	if (obtenIzq()->esAnulable()) {
		myset.clear();
		myset = obtenDer()->obtenPrimeros();
		for (std::set<int>::iterator it=myset.begin(); it!=myset.end(); ++it)
		{
			primeros.insert(*it);
		}
	}
}
void ConcatAS::calculaUltimos()
{
	ultimos.clear();
	obtenIzq()->calculaUltimos();
	obtenDer()->calculaUltimos();
	std::set<int> myset;
	if (obtenDer()->esAnulable()) {
		myset = obtenIzq()->obtenUltimos();
		for (std::set<int>::iterator it=myset.begin(); it!=myset.end(); ++it)
		{
			ultimos.insert(*it);
		}
		myset.clear();
	}
	myset = obtenDer()->obtenUltimos();
	for (std::set<int>::iterator it=myset.begin(); it!=myset.end(); ++it)
	{
		ultimos.insert(*it);
	}
}
void ConcatAS::calculaSiguientes()
{
	obtenIzq()->calculaSiguientes();
	obtenDer()->calculaSiguientes();
	std::set<int> myset;
	siguientes.clear();
	myset = obtenDer()->obtenPrimeros();
	for (std::set<int>::iterator it=myset.begin(); it!=myset.end(); ++it)
	{
		siguientes.insert(*it);
	}
}




