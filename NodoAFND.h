#ifndef NODOAFND_H
#define NODOAFND_H
#include "Nodo.h"
class NodoAFND: public Nodo
{
	public:
	explicit NodoAFND();
	~NodoAFND();
	void agregarTransicion(char simbolo,Nodo* destino);
	private:
	
};
#endif
