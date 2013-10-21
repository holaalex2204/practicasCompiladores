#ifndef ORAS_H
#define ORAS_H
#include "NodoAS.h"
class OrAS: public NodoAS
{
	public:
	explicit OrAS();
	~OrAS();
	bool esOperacion();
	bool esAnulable();
	bool esSimbolo();
	char obtenValor();
	NodoAS* obtenIzq();
	NodoAS* obtenDer();
	void agregaIzq(NodoAS* n);
	void agregaDer(NodoAS* n);
	void calculaPrimeros();
	void calculaUltimos();
};
#endif
