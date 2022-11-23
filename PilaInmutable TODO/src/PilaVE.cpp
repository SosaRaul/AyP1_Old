#include "PilaVE.h"
using TDAPilaVE::Pila;
const int capacidadPila = 100 ;

struct TDAPilaVE::Pila{
	Carta** items;
	int cima;
};


Pila* TDAPilaVE::Crear(Carta* item){
	Pila* nuevaPila = new Pila;
	nuevaPila->cima = -1;
	return nuevaPila;
}

void TDAPilaVE::Apilar(Pila* pila,Carta* item){

}

