#include "NodoAFD.h"
#include <iostream>
NodoAFD::NodoAFD()
{
	identificador = 0;
}
NodoAFD::~NodoAFD()
{
	
}
bool NodoAFD::contiene(NodoAFND* n)
{
	std::list<NodoAFND>::iterator it;
	for (it=nodosContenidos.begin(); it!=nodosContenidos.end(); ++it)
		if (n->getIdentificador()==it->getIdentificador()) {
			return true;
		}
	return false;
}
int NodoAFD::tamano()
{
	return nodosContenidos.size();
}
NodoAFND* NodoAFD::obtenElemento(int n)
{
	std::list<NodoAFND>::iterator it=nodosContenidos.begin();
	advance( it,(n));
	return &(*it);
}
void NodoAFD::ordena()
{
	nodosContenidos.sort(Nodo::sortFunc);
}
void NodoAFD::agrega(NodoAFND* ob)
{
	nodosContenidos.push_back(*ob);
}

