#include "Nodo.h"
#include <iostream>

Nodo::Nodo()
{
}
Nodo::~Nodo()
{
	
}
void Nodo::agregarTransicion(char simbolo,Nodo* destino)
{
	transiciones.insert(transiciones.end(),Transicion(simbolo,destino));
}
void Nodo::quitarTransicion(int i)
{
	std::list<Transicion>::iterator it=transiciones.begin();
	advance( it,(i));
	transiciones.erase(it);
}
int Nodo::cuentaTransiciones()
{
	return transiciones.size();
}
Transicion* Nodo::obtenTransicion(int i)
{
	std::list<Transicion>::iterator it=transiciones.begin();
	advance( it,(i));
	return &(*it);
}
void Nodo::setIdentificador(int i)
{
	identificador = i;
}
int Nodo::getIdentificador()
{
	return identificador;
}
void Nodo::quitarTransicion(char simbolo,Nodo* destino)
{
	for (std::list<Transicion>::iterator it=transiciones.begin() ; it != transiciones.end(); ++it){
		if (it->obtenSimbolo()==simbolo && it->obtenDestino()==destino) {
			transiciones.erase(it);
			break;
		}
	}
}

