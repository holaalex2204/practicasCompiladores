#ifndef NODOAFD_H
#define NODOAFD_H
#include "Nodo.h"
#include "NodoAFND.h"
#include <list>
	//class AFD;
class NodoAFD: public Nodo
{
	public:
	explicit NodoAFD();
	~NodoAFD();
	bool contiene(Nodo* n);
	int tamano();
	void ordena();
	void agrega(Nodo* ob);
	Nodo* obtenElemento(int n);
	bool operator== (NodoAFD& param);
	private:
	std::list<Nodo> nodosContenidos;
};
#endif
