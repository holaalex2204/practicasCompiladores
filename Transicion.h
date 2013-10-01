#ifndef TRANSICION_H
#define TRANSICION_H
#include "Nodo.h"
class Nodo;
class Transicion
{
	public:
	explicit Transicion(char simbol, Nodo* destin);
	explicit Transicion(Nodo* destino);
	~Transicion();
	Nodo* obtenDestino();
	char obtenSimbolo();
	private:
	Nodo* destino;
	char simbolo;
};
#endif
