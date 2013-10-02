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
	bool contiene(NodoAFND* n);
	int tamano();
	void ordena();
	void agrega(NodoAFND* ob);
	NodoAFND* obtenElemento(int n);
	private:
		//AFD conjunto;
	std::list<NodoAFND> nodosContenidos;
	
	
};
#endif
