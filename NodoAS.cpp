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
void NodoAS::asignaIndice(int n)
{
	
}
void NodoAS::calculaPrimeros()
{
	primeros.clear();
	obtenIzq()->calculaPrimeros();
	std::set<int> myset = obtenIzq()->obtenPrimeros();
	for (std::set<int>::iterator it=myset.begin(); it!=myset.end(); ++it)
	{
		primeros.insert(*it);
	}
}
std::set<int> NodoAS::obtenPrimeros()
{
	return primeros;
}
void NodoAS::calculaUltimos()
{
	
}
std::set<int> NodoAS::obtenUltimos()
{
	return ultimos;
}
void NodoAS::calculaSiguientes()
{
	if (obtenIzq()!=0) {
		obtenIzq()->calculaSiguientes();
	}
	if (obtenDer()!=0) {
		obtenDer()->calculaSiguientes();
	}
}
std::set<int> NodoAS::obtenSiguientes()
{
	return siguientes;
}
