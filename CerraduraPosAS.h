#ifndef CERRADURAPOSAS_H
#define CERRADURAPOSAS_H
#include "NodoAS.h"
class CerraduraPosAS:public NodoAS
{
	public:
	explicit CerraduraPosAS();
	~CerraduraPosAS();
	bool esOperacion();
	bool esAnulable();
	bool esSimbolo();
	char obtenValor();
	NodoAS* obtenIzq();
	NodoAS* obtenDer();
	void agregaIzq(NodoAS* n);
	void agregaDer(NodoAS* n);
	void calculaUltimos();
};
#endif
