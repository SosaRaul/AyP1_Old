#include<iostream>
using std::string;

namespace TDACarta{

	struct Carta;
	Carta* CrearCarta(string palo,int valor);
	void MostrarCarta(const Carta* carta);
}
