#include "ExpReg.h"
#include <iostream>
#include "ConcatAS.h"
#include "OrAS.h"
#include "SimboloAS.h"
#include "CerraduraEstAS.h"
#include "CerraduraPosAS.h"
ExpReg::ExpReg(std::string expresion)
{
	cadena.append(expresion,0,1);
	for (unsigned long i = 1 ; i<expresion.size(); i++) {
		if (esConcatenable(cadena.at((cadena.size()-1)), expresion.at(i))) {
			cadena.append(".");
			cadena.append(expresion,i,1);
		}
		else
		{			
			cadena.append(expresion,i,1);
		}
	}
	std::cout << "La cadena con signos de concatenación es: "<< cadena << std::endl;
	arbolS = new ArbolSintactico();
	crearArbolSintactico(0,cadena.size()-1,arbolS->obtenRaiz());
	thompson = new AFND(arbolS->obtenRaiz()->obtenIzq());
	thompson->imprime();
	obtenSimbolos();
	conjuntos = new AFD(thompson,simbolos);
	conjuntos->imprime();
}
ExpReg::~ExpReg()
{
}
bool ExpReg::esConcatenable(char a,char b)
{
	if (a == '|' | a=='.' | a=='(' |b==')' | b=='|' | b=='.') {
		return false;
	}
	if ((b=='*' | b =='+')) {
		return false;
	}
	return true;
}
void ExpReg::crearArbolSintactico(int ini, int fin, NodoAS* papi)
{
		//Jerarquía de operaciones: | , . , (*/+)
	int nivel = 0;
	int aux1 =0;
	int aux2 = 0;
	if (ini == fin) { //es un simbolo
		if (papi->obtenIzq()==0) {
			papi->agregaIzq(new SimboloAS(cadena.at(ini)));
		}
		else
		{
			papi->agregaDer(new SimboloAS(cadena.at(ini)));
		}
		return;
	}
		// INICIA BUSQUEDA DE UN OR
	for (int i = fin ; i>=ini; i--) {
		if (cadena.compare(i,1,")")==0) {
			nivel++;
		}
		if (cadena.compare(i,1,"(")==0) {
			nivel--;
		}
		if (nivel==0 && cadena.compare(i,1,"|")==0) {
			if (papi->obtenIzq()==0) {
				papi->agregaIzq(new OrAS());
				aux1 = ini;
				aux2 = i-1;
				if (cadena.compare(aux1,1,"(")==0) {
					aux1= aux1+1;
				}
				if (cadena.compare(aux2,1,")") ==0){
					aux2 = aux2-1;
				}
				crearArbolSintactico(aux1,aux2,papi->obtenIzq());
				aux1 = i+1;
				aux2 = fin;
				if (cadena.compare(aux1,1,"(")==0) {
					aux1= aux1+1;
				}
				if (cadena.compare(aux2,1,")")==0) {
					aux2 = aux2-1;
				}
				crearArbolSintactico(aux1,aux2,papi->obtenIzq());
				return;
			}
			else
			{
				papi->agregaDer(new OrAS());
				aux1 = ini;
				aux2 = i-1;
				if (cadena.compare(aux1,1,"(")==0) {
					aux1= aux1+1;
				}
				if (cadena.compare(aux2,1,")")==0) {
					aux2 = aux2-1;
				}
				crearArbolSintactico(aux1,aux2,papi->obtenDer());
				aux1 = i+1;
				aux2 = fin;
				if (cadena.compare(aux1,1,"(")==0) {
					aux1= aux1+1;
				}
				if (cadena.compare(aux2,1,")")==0) {
					aux2 = aux2-1;
				}
				crearArbolSintactico(aux1,aux2,papi->obtenDer());
				return;
			}
		}
	}
		//FINALIZA BUSQUEDA DE UN OR
		//INICIA BUSQUEDA DE UNA CONCATENACION
	for (int i = fin ; i>=ini; i--) {
		if (cadena.compare(i,1,")")==0) {
			nivel++;
		}
		if (cadena.compare(i,1,"(")==0) {
			nivel--;
		}
		if (nivel==0 && cadena.compare(i,1,".")==0) {
			if (papi->obtenIzq()==0) {
				papi->agregaIzq(new ConcatAS());
				aux1 = ini;
				aux2 = i-1;
				if (cadena.compare(aux1,1,"(")==0) {
					aux1= aux1+1;
				}
				if (cadena.compare(aux2,1,")") ==0){
					aux2 = aux2-1;
				}
				crearArbolSintactico(aux1,aux2,papi->obtenIzq());
				aux1 = i+1;
				aux2 = fin;
				if (cadena.compare(aux1,1,"(")==0) {
					aux1= aux1+1;
				}
				if (cadena.compare(aux2,1,")")==0) {
					aux2 = aux2-1;
				}
				crearArbolSintactico(aux1,aux2,papi->obtenIzq());
				return;
			}
			else
			{
				papi->agregaDer(new ConcatAS());
				aux1 = ini;
				aux2 = i-1;
				if (cadena.compare(aux1,1,"(")==0) {
					aux1= aux1+1;
				}
				if (cadena.compare(aux2,1,")")==0) {
					aux2 = aux2-1;
				}
				crearArbolSintactico(aux1,aux2,papi->obtenDer());
				aux1 = i+1;
				aux2 = fin;
				if (cadena.compare(aux1,1,"(")==0) {
					aux1= aux1+1;
				}
				if (cadena.compare(aux2,1,")")==0) {
					aux2 = aux2-1;
				}
				crearArbolSintactico(aux1,aux2,papi->obtenDer());
				return;
			}
		}
	}		//FINALIZA BUSCA CONCATENACION
		//INICIA BUSCA + O *
	for (int i = fin ; i>=ini; i--) {
		if (cadena.compare(i,1,")")==0) {
			nivel++;
		}
		if (cadena.compare(i,1,"(")==0) {
			nivel--;
		}
		if (nivel==0 && (cadena.compare(i,1,"*")==0|cadena.compare(i,1,"+")==0)) {
			if (papi->obtenIzq()==0) {
				if (cadena.compare(i,1,"*")==0) {
					papi->agregaIzq(new CerraduraEstAS());
				}
				else
				{
					papi->agregaIzq(new CerraduraPosAS());
				}
				aux1 = ini;
				aux2 = i-1;
				if (cadena.compare(aux1,1,"(")==0) {
					aux1= aux1+1;
				}
				if (cadena.compare(aux2,1,")")==0) {
					aux2 = aux2-1;
				}
				crearArbolSintactico(aux1,aux2,papi->obtenIzq());
				return;
			}
			else
			{
				if (cadena.compare(i,1,"*")==0) {
					papi->agregaDer(new CerraduraEstAS());
				}
				else
				{
					papi->agregaDer(new CerraduraPosAS());
				}
				aux1 = ini;
				aux2 = i-1;
				if (cadena.compare(aux1,1,"(")==0) {
					aux1= aux1+1;
				}
				if (cadena.compare(aux2,1,")")==0) {
					aux2 = aux2-1;
				}
				crearArbolSintactico(aux1,aux2,papi->obtenDer());
				return;
			}
		}
	}
		//Finaliza la busqueda de + O *	
}
ArbolSintactico* ExpReg::obtenArbolSintactico()
{
	return arbolS;
}
void ExpReg::obtenSimbolos()
{
	simbolos.push_back('a');
	simbolos.push_back('b');
		//simbolos.push_back('c');
}


