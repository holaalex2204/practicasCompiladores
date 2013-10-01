#ifndef NODOAS_H
#define NODOAS_H
class NodoAS
{
	public:
		explicit NodoAS();
		~NodoAS();
		virtual bool esOperacion();
		virtual bool esAnulable();
		virtual bool esSimbolo();
		virtual char obtenValor();
		virtual NodoAS* obtenIzq();
		virtual NodoAS* obtenDer();
		virtual void agregaIzq(NodoAS* n);
		virtual void agregaDer(NodoAS* n);
	protected:
		char valor;	
		NodoAS* hijoIzq;
		NodoAS* hijoDer;
};
#endif
