#ifndef NODOAS_H
#define NODOAS_H
#include <set>
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
		virtual void asignaIndice(int n);
		virtual void calculaPrimeros();
		std::set<int> obtenPrimeros();
		virtual void calculaUltimos();
		std::set<int> obtenUltimos();
		virtual void calculaSiguientes();
		std::set<int> obtenSiguientes();
	protected:
		char valor;	
		NodoAS* hijoIzq;
		NodoAS* hijoDer;
		std::set<int> primeros;
		std::set<int> ultimos;
		std::set<int> siguientes;
};
#endif
