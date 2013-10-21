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
	return (obtenIzq()->esAnulable()&& obtenDer()->esAnulable());
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
void OrAS::calculaPrimeros()
{
	primeros.clear();
	obtenIzq()->calculaPrimeros();
	std::set<int> myset = obtenIzq()->obtenPrimeros();
	for (std::set<int>::iterator it=myset.begin(); it!=myset.end(); ++it)
	{
		primeros.insert(*it);
	}
	myset.clear();
	obtenDer()->calculaPrimeros();
	myset = obtenDer()->obtenPrimeros();
	for (std::set<int>::iterator it=myset.begin(); it!=myset.end(); ++it)
	{
		primeros.insert(*it);
	}
}
void OrAS::calculaUltimos()
{
	ultimos.clear();
	obtenIzq()->calculaUltimos();
	obtenDer()->calculaUltimos();
	std::set<int> myset;
	myset = obtenIzq()->obtenUltimos();
	for (std::set<int>::iterator it=myset.begin(); it!=myset.end(); ++it)
	{
		ultimos.insert(*it);
	}
	myset.clear();
	myset = obtenDer()->obtenUltimos();
	for (std::set<int>::iterator it=myset.begin(); it!=myset.end(); ++it)
	{
		ultimos.insert(*it);
	}
}