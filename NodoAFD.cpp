#include "NodoAFD.h"
#include <iostream>
#include <set>
NodoAFD::NodoAFD()
{
	identificador = 0;
}
NodoAFD::~NodoAFD()
{
	
}
bool NodoAFD::contiene(Nodo* n)
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
void NodoAFD::agrega(Nodo* ob)
{
	if (contiene(ob)) {
		return;
	}
	nodosContenidos.push_back(*ob);
}
bool NodoAFD::operator== (Nodo& param)
{
	std::list<Nodo>::iterator it;
	std::list<Nodo>::iterator it2;
	if (param.tamano() != this->tamano()) { // checa si tienen diferente tamaño
		return false;
	}
	for (it=nodosContenidos.begin(), it2 =param.nodosContenidos.begin(); it!=nodosContenidos.end(); ++it, ++it2)
		if (it2->getIdentificador()!=it->getIdentificador()) {
			return false;
		}
	return true;
}
