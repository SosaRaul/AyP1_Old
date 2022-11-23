#include "Carta.h"
using TDACarta::Carta;

namespace TDAPilaVD{

	struct Pila;
	Pila* Crear();
	void Apilar(Pila* pila,Carta* item);
	Carta* Desapilar(Pila* pila);
	int EstaVacia(const Pila* pila);
	void MostrarPila(const Pila* pila);

}
