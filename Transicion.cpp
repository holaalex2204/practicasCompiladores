#include "Transicion.h"
#include <iostream>
Transicion::Transicion(char simbol, Nodo* destin)
{
	simbolo= simbol;
	destino = destin;
	std::cout << 1 ;
}
Transicion::Transicion(Nodo* destin)
{
	destino = destin;
}
Transicion::~Transicion()
{
	
}
Nodo* Transicion::obtenDestino()
{
	return destino;
}
char Transicion::obtenSimbolo()
{
	return simbolo;
}