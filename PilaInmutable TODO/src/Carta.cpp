#include "Carta.h"
#include <iostream>
using std::string;
using std::cout;
using TDACarta::Carta;

struct TDACarta::Carta{
	int valor;
	string palo;
};
Carta* TDACarta::CrearCarta(string palo,int valor){
	Carta* nuevaCarta  = new Carta;
	nuevaCarta->palo = palo;
	nuevaCarta->valor = valor;
	return nuevaCarta;
}
void TDACarta::MostrarCarta(const Carta* carta){
	cout << carta->palo << " , " << carta->valor << "\n";
}
