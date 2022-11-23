#include "Carta.h"
#include "PilaVD.h"
#include <iostream>
const int capacidadPorDefecto = 100;
using TDACarta::Carta;
using TDAPilaVD::Pila;
using namespace std;

struct TDAPilaVD::Pila{
	/* Vector de cartas.A Carta lo trato como puntero, y ademas necesito un puntero al primero elemento
	   del vector , por eso es que terminamos con un doble puntero.
	*/
	Carta** items;
	int cantidadDeItems;
	int capacidadActual;
	int posicionCima;
};

TDAPilaVD::Pila* TDAPilaVD::Crear(){
	Pila* pila = new Pila;
	pila->cantidadDeItems = 0;
	pila->capacidadActual = capacidadPorDefecto;
	pila->items = new Carta*[capacidadPorDefecto];
	pila->posicionCima = -1;
	return pila;
}

void Redimensionar(Pila* pila,int nuevaCapacidad){
// Lo que quiero redimesionar es solo el array, no la pila.
// No olvidarse de la referencia al array original, tenerla para luego poder borrarlo.
	Carta** itemsRedimensionados = new Carta*[nuevaCapacidad];
	// Ahora copiar todo lo que que tenia antes la pila en la nueva.
	for(int i=0;i < nuevaCapacidad && i < pila->cantidadDeItems;++i){
		itemsRedimensionados[i] = pila->items[i];
	}
	// Ahora bien , siempre que la pila NO ESTE VACIA (lo que implica que hay algun item en el array)
	if(!EstaVacia(pila)){
		delete[] pila->items;
	}
	// Luego , hago que el array nuevo sea el que tenga pila ahora.
	pila->items = itemsRedimensionados;
	pila->cantidadDeItems = nuevaCapacidad; //??
	pila->capacidadActual = nuevaCapacidad;
	// Actualizo la cantidad de items que tiene ahora.

}
// Una pila esta vacia , si en la estructura de datos que la representa no hay elementos.
// Si considerara que esta vacia para pila == nullptr, seria en realidad que no existe pila.
int TDAPilaVD::EstaVacia(const Pila* pila){
	return pila->cantidadDeItems == 0 ;
}
// Este metodo apila de a una unidad por vez.
// Pre: Pila debe existir
// Post: Agrega un elemento a la pila.
void TDAPilaVD::Apilar(Pila* pila,Carta* item){

	// Si el elemento a apilar va a llenar la pila, hay que redimensionarla.
	if(pila->capacidadActual == pila->cantidadDeItems+1){
		// Redimensiono por el doble para poder amortiguar el costo de las prox apiladas.
		int nuevaCapacidad = pila->capacidadActual*2;
		Redimensionar(pila,nuevaCapacidad);
	}
	// Una vez hecho el redimensionamiento si fuese necesario ya podemos apilar.
	// Incremento la cima , ya que en ese indice es donde va a quedar el elemento.
	++pila->posicionCima;//pila->posicionCima = pila->posicionCima+1;
	// coloco el item (carta)
	pila->items[pila->posicionCima] = item;
	pila->cantidadDeItems++;

}
Carta* TDAPilaVD::Desapilar(Pila* pila){
	Carta* item = nullptr;
	if(!EstaVacia(pila)){
		// Guardo el item a sacar
		item = pila->items[pila->posicionCima];
		// Ahora la cima es el indice del anterior
		pila->posicionCima--;
		// Ahora chequeo la capacidadActual para  mantener la pila sin capacidad al pedo.
		// Si la capacidad es > items*2, bajo la capacidad a la mitad.
		if(pila->capacidadActual > pila->cantidadDeItems*2){
			int nuevaCapacidad = pila->cantidadDeItems + pila->cantidadDeItems/2;
			Redimensionar(pila,nuevaCapacidad);
		}
	}
	return item; // Notar que si estaba vacia devuelve null.
}
void TDAPilaVD::MostrarPila(const Pila* pila){
	for(int i = 0;i<pila->cantidadDeItems;i++){
		MostrarCarta(pila->items[i]);
	}
}
