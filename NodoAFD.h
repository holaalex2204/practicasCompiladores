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
	NodoAFND* obtenElemento(int n);
	bool operator== (Nodo& param);
	private:
	std::list<NodoAFND> nodosContenidos;
};
#endif
