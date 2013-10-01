#ifndef CERRADURAESTAS_H
#define CERRADURAESTAS_H 
#include "NodoAs.h"
class CerraduraEstAS: public NodoAS
{
	public:
	explicit CerraduraEstAS();
	~CerraduraEstAS();
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
