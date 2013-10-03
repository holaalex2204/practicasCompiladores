
#ifndef AFD_H
#define AFD_H
#include "AFND.h"
#include "NodoAFD.h"
class AFD
{
	public:
	
	explicit AFD(bloque th, std::list<char> s);
	~AFD();
	void imprime();
private:
	bloque thompson;
	std::list<NodoAFD> nodosGenerados;
	NodoAFD* contiene(NodoAFD pa);
	NodoAFD* generaEstados(NodoAFD* pa,char simbolo);
	std::list<char> simbolos;	
};

#endif
