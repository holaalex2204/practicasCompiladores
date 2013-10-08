#include "AFD.h"
#include <iostream>
AFD::AFD(AFND* th, std::list<char> s)
{
	thompson = th;
	NodoAFD* temp = new NodoAFD();
	temp->agrega(th->thompson.ini);
	buscaEpsilons(temp);
	nodosGenerados.push_back(*temp);
	std::list<NodoAFD>::iterator it;
	std::list<char>::iterator simb;
	for (it=nodosGenerados.begin(); it!=nodosGenerados.end(); ++it)
	{
		for (simb=s.begin(); simb!=s.end(); ++simb)
		{
			temp = new NodoAFD();
			for (int i = 0; i< it->tamano(); i++) {
				busca(it->obtenElemento(i),*simb,temp);
			}
			buscaEpsilons(temp);
			if (temp->tamano()>0) {
				if (contiene(temp) == 0) {
					temp->setIdentificador(nodosGenerados.size());
					nodosGenerados.push_back(*temp);
				}
				else
				{
					temp = contiene(temp);
				}
				it->agregarTransicion(*simb,temp);
			}
		}
	}
}
AFD::~AFD()
{
	
}
void AFD::imprime()
{
	std::list<NodoAFD>::iterator it;
	std::cout << "AFD GENERADO CON ALGORITMO DE CONJUNTOS" << std::endl;
	for (it=nodosGenerados.begin(); it!=nodosGenerados.end(); ++it)
	{
		std::cout << "INFO NODO " << it->getIdentificador() << std::endl;
		for (int i = 0; i< it->cuentaTransiciones(); i++) {
			std::cout << "\tTransicion a " << it->obtenTransicion(i)->obtenDestino()->getIdentificador() << " con " << it->obtenTransicion(i)->obtenSimbolo()<< std::endl;
		}
		if (it->contiene(thompson->thompson.fin)) {
			std::cout << "\tEste nodo es final" << std::endl;
		}
		std::cout << "\tLos elementos de este nodo son:";
		for (int  i = 0 ; i< it->tamano(); i++) {
			std::cout << " " << it->obtenElemento(i)->getIdentificador();
		}
		std:: cout << std::endl;
	}
}
NodoAFD* AFD::contiene(NodoAFD* pa)
{
	std::list<NodoAFD>::iterator it;
	for (it=nodosGenerados.begin(); it!=nodosGenerados.end(); ++it)
	{
		if (it->operator==(*pa)) {
			return &(*it);
		}
	}
	return 0;
}
void AFD::busca(Nodo* pa,char simbolo, NodoAFD* visitados )
{
	for (int i = 0; i<pa->cuentaTransiciones(); i++) {
		if (pa->obtenTransicion(i)->obtenSimbolo()==simbolo)
		{
			if (visitados->contiene(pa->obtenTransicion(i)->obtenDestino())==0) // checa si no se ha visitado ese elemento
			{
				visitados->agrega(pa->obtenTransicion(i)->obtenDestino());
			}
		}
	}
}
void AFD::buscaEpsilons(NodoAFD* estadoPorEpsilonear)
{
	for (int i = 0; i<estadoPorEpsilonear->tamano(); i++) {
		busca(estadoPorEpsilonear->obtenElemento(i),'e',estadoPorEpsilonear);
	}
}