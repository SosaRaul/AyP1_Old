#include <iostream>
#include "PilaVD.h"
#include "Carta.h"
using namespace TDAPilaVD;
using namespace TDACarta;

int main(){

	Pila* miPila = Crear();

	Carta* miCarta1 = CrearCarta("basto",10);
	Carta* miCarta2 = CrearCarta("copa",4);
	Carta* miCarta3 = CrearCarta("oro",1);
	Carta* miCarta4 = CrearCarta("espada",7);

	Apilar(miPila,miCarta1);
	Apilar(miPila,miCarta2);
	Apilar(miPila,miCarta3);
	Apilar(miPila,miCarta4);

	MostrarPila(miPila);


	return 0;
}
