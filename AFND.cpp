#include "AFND.h"
#include <iostream>
AFND::AFND(NodoAS* pos)
{
	thompson = procesaPos(pos);
	
	estados = 0;
	
	numera(thompson.ini);
	
}
AFND::~AFND()
{
	
}
bloque AFND::procesaPos(NodoAS* pos)
{
	if (pos->obtenValor()=='*') {
		return creaCerraduraEstrella(procesaPos(pos->obtenIzq()));
	}
	if (pos->obtenValor()=='+') {
		return creaCerraduraPositiva(procesaPos(pos->obtenIzq()));
	}
	if (pos->obtenValor()=='|') {
		return creaOr(procesaPos(pos->obtenIzq()),procesaPos(pos->obtenDer()) );
	}
	if (pos->obtenValor()=='.') {
		return creaConcatenacion(procesaPos(pos->obtenIzq()),procesaPos(pos->obtenDer()) );
	}
	return creaSimbolo(pos->obtenValor());
}
bloque AFND::creaSimbolo(char a)
{
	bloque aux;
	aux.ini = new NodoAFND();
	aux.fin = new NodoAFND();
	aux.ini->agregarTransicion(a,aux.fin);
	//std::cout << "Cree el simbolo " << a << std::endl;
	return aux;
}
bloque AFND::creaConcatenacion(bloque izq, bloque der)
{
	bloque aux;
	Transicion* t;
	aux.ini = izq.ini;
	aux.fin = der.fin;
	for (int  i = 0 ; i<der.ini->cuentaTransiciones(); i++) {
		t =der.ini->obtenTransicion(i);
		izq.fin->agregarTransicion(t->obtenSimbolo(),t->obtenDestino());
	}
	der.ini->~NodoAFND();
	//std::cout << "Cree la concatenacion" << std::endl;
	return aux;
}
bloque AFND::creaOr(bloque izq, bloque der)
{
	bloque aux;
	aux.ini = new NodoAFND();
	aux.fin = new NodoAFND();
	aux.ini->agregarTransicion('e',izq.ini);
	aux.ini->agregarTransicion('e',der.ini);
	izq.fin->agregarTransicion('e',aux.fin);
	der.fin->agregarTransicion('e',aux.fin);
	return aux;
}
bloque AFND::creaCerraduraEstrella(bloque centro)
{
	bloque aux;
	aux.ini = new NodoAFND();
	aux.fin = new NodoAFND();
	aux.ini->agregarTransicion('e',centro.ini);
	centro.fin->agregarTransicion('e',aux.fin);
	centro.fin->agregarTransicion('e',centro.ini);
	aux.ini->agregarTransicion('e',aux.fin);
	return aux;
}
bloque AFND::creaCerraduraPositiva(bloque centro)
{
	bloque aux;
	aux.ini = new NodoAFND();
	aux.fin = new NodoAFND();
	aux.ini->agregarTransicion('e',centro.ini);
	centro.fin->agregarTransicion('e',aux.fin);
	centro.fin->agregarTransicion('e',centro.ini);
	return aux;
}
void AFND::numera(Nodo* pos)
{
	if (pos->getIdentificador()==0) {
		pos->setIdentificador(++estados);
		for (int  i = 0 ; i<pos->cuentaTransiciones(); i++) {
			numera(pos->obtenTransicion(i)->obtenDestino());
		}
	}
	
}
void AFND::imprime()
{
	std::cout << "El AFND de Thompson tiene las siguientes características:"  << std::endl;
	std::cout << "\tNumero de estados: " << estados << std::endl;
	std::cout << "\tEstado Inicial: " << thompson.ini->getIdentificador() << std::endl;
	std::cout << "\tEstado Final: " << thompson.fin->getIdentificador() << std::endl;
	imprimeTransiciones(thompson.ini);
}
void AFND::imprimeTransiciones(Nodo* pos)
{
	Transicion* t;
	for (int  i = 0 ; i<pos->cuentaTransiciones(); i++) {
		t =pos->obtenTransicion(i);
		std::cout << "\tCamino de " << pos->getIdentificador() << " a " << t->obtenDestino()->getIdentificador() << " con el símbolo " << t->obtenSimbolo() << std::endl;
	}
	for (int  i = 0 ; i<pos->cuentaTransiciones(); i++) {
		t =pos->obtenTransicion(i);
		if (pos->getIdentificador() < t->obtenDestino()->getIdentificador()) {
			imprimeTransiciones(t->obtenDestino());
		}
	}
}
