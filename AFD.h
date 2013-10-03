
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
	NodoAFD* contiene(NodoAFD pa);
	NodoAFD* generaEstados(NodoAFD* pa,char simbolo);
	std::list<char> simbolos;
	busca(NodoAFD* pa,char simbolo, NodoAFD* visitados);
};

#endif
