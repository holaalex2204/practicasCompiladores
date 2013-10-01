#include "NodoAFND.h"

NodoAFND::NodoAFND()
{
	identificador = 0;
}
NodoAFND::~NodoAFND()
{
	
}
void NodoAFND::agregarTransicion(char simbolo,Nodo* destino)
{
	for (std::list<Transicion>::iterator it=transiciones.begin() ; it != transiciones.end() & simbolo!='e'; ++it)
		if (it->obtenSimbolo()==simbolo) {
				return;
		}
	transiciones.insert(transiciones.end(),Transicion(simbolo,destino));
}

