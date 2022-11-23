#ifndef SRC_PILAVE_H_
#define SRC_PILAVE_H_

// Interfaz para una Pila Inmutable.
#include "Carta.h"
using TDACarta::Carta;


namespace TDAPilaVE{

	struct Pila;
	// Pre : item es Dato valido.
	// Post: Retorna una pila vacia.
	Pila* Crear(Carta* item);
	void Apilar(Pila* pila,Carta* item);


}




#endif /* SRC_PILAVE_H_ */
