#ifndef SIMBOLOAS_H
#define SIMBOLOAS_H
#include "NodoAS.h"
class SimboloAS:public NodoAS
{
	public:
	explicit SimboloAS(char a);
	~SimboloAS();
	bool esOperacion();
	bool esAnulable();
	bool esSimbolo();
	char obtenValor();
	NodoAS* obtenIzq();
	NodoAS* obtenDer();
	void agregaIzq(NodoAS* n);
	void agregaDer(NodoAS* n);
};
#endif
