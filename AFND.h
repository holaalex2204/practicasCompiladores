
#ifndef AFND_H
#define AFND_H
#include "NodoAS.h"
#include "NodoAFND.h"
struct bloque {
	NodoAFND* ini;
	NodoAFND* fin;
};
class AFND
{
	public:
	
	explicit AFND(NodoAS* pos);
	~AFND();
	bloque procesaPos(NodoAS* pos);
	bloque thompson;
	void imprime();
	private:
	int estados;
	
	bloque creaSimbolo(char a);
	bloque creaConcatenacion(bloque izq, bloque der);
	bloque creaOr(bloque izq, bloque der);
	bloque creaCerraduraEstrella(bloque centro);
	bloque creaCerraduraPositiva(bloque centro);
	void numera(Nodo* pos);
	void imprimeTransiciones(Nodo* pos);
};

#endif
