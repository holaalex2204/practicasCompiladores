
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
	NodoAFD* generaEstados(NodoAFND* pa,char simbolo);
	std::list<char> simbolos;
	void busca(NodoAFND* pa,char simbolo, NodoAFD* visitados );
};

#endif
