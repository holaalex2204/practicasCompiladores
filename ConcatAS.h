#ifndef CONCATAS_H
#define CONCATAS_H
#include "NodoAS.h"
class ConcatAS:public NodoAS
{
	public:
	explicit ConcatAS();
	~ConcatAS();
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
	void calculaSiguientes();
};
#endif
