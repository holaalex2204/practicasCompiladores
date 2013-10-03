#include "AFD.h"
#include <iostream>
AFD::AFD(AFND* th, std::list<char> s)
{
	thompson = th;
}
AFD::~AFD()
{
	
}
void AFD::imprime()
{
	
}
NodoAFD* AFD::contiene(NodoAFD pa)
{
	std::list<NodoAFD>::iterator it;
	for (it=nodosGenerados.begin(); it!=nodosGenerados.end(); ++it)
	{
		if (it->operator==(pa)) {
			return &(*it);
		}
	}
	return 0;
}
NodoAFD* AFD::busca(NodoAFD* pa,char simbolo, NodoAFD* visitados )
{
	
}
NodoAFD* AFD::generaEstados(NodoAFD* pa,char simbolo)
{
	NodoAFD* temp = new NodoAFD();
	for (int i = 0; i<pa->tamano(); i++) {
		busca(pa->obtenElemento(i),simbolo,temp);
	}
}