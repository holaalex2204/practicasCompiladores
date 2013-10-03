#include "AFD.h"
#include <iostream>
AFD::AFD(AFND* th, std::list<char> s)
{
	thompson = th;
}
AFD::~AFD()
{
	
}
void AFD::imprime()
{
	
}
NodoAFD* AFD::contiene(NodoAFD pa)
{
	std::list<NodoAFD>::iterator it;
	for (it=nodosGenerados.begin(); it!=nodosGenerados.end(); ++it)
	{
		if (it->operator==(pa)) {
			return &(*it);
		}
	}
	return 0;
}
void AFD::busca(NodoAFND* pa,char simbolo, NodoAFD* visitados )
{
	for (int i = 0; i<pa->cuentaTransiciones(); i++) {
		if (pa->obtenTransicion(i)->obtenSimbolo()==simbolo) {
			if (!visitados->contiene(pa->obtenTransicion(i)->obtenDestino())) // checa si no se ha visitado ese elemento
			{
				visitados->agrega(pa->obtenTransicion(i)->obtenDestino());
				busca(pa->obtenTransicion(i)->obtenDestino(),simbolo,visitados);
			}
		}
	}
}
NodoAFD* AFD::generaEstados(NodoAFD* pa,char simbolo)
{
	NodoAFD* temp = new NodoAFD();
	for (int i = 0; i<pa->tamano(); i++) {
		busca(pa->obtenElemento(i),simbolo,temp);
	}
	for (int i = 0; i<temp->tamano(); i++) {
		busca(temp->obtenElemento(i),'e',temp); //busca con epsilons a partir de los eodos generados
	}
	if (contiene(temp)) //checa si el edo generado ya existe
	{
		return contiene(temp);
	}
	else
	{
		nodosGenerados.insert(nodosGenerados.end(),*temp);
	}
}