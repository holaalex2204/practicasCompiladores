#ifndef NODO_H
#define NODO_H
#include <list>
#include "Transicion.h"
class Transicion;
class Nodo
{
	public:
	explicit Nodo();
	~Nodo();	
	virtual void agregarTransicion(char simbolo,Nodo* destino);
	void quitarTransicion(int i);
	int cuentaTransiciones();
	Transicion* obtenTransicion(int i);
	void setIdentificador(int i);
	int getIdentificador();
	void quitarTransicion(char simbolo, Nodo* destino);
	static bool sortFunc(const Nodo& s1, const Nodo& s2)
	{
		return (s1.identificador < s2.identificador);
	}
	protected:
	int identificador;
	std::list<Transicion> transiciones;
};

#endif
