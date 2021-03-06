
#ifndef AFD_H
#define AFD_H
#include "AFND.h"
#include "NodoAFD.h"
class AFD
{
	public:
	
	explicit AFD(AFND* th, std::list<char> s);
	~AFD();
	void imprime();
private:
	AFND* thompson;
	std::list<NodoAFD> nodosGenerados;
	NodoAFD* contiene(NodoAFD* pa);
	std::list<char> simbolos;
	void busca(Nodo* pa,char simbolo, NodoAFD* visitados);
	void buscaEpsilons(NodoAFD* estadoPorEpsilonear);
};

#endif
