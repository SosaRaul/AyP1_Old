#include "Clase14TN.h"
#include <iostream>
using namespace std;


// Implementacion propia. Difiere en que tomo como condicion de corte el largo del subArray y si se encontro el buscado.
int AlgoritmosOrdenamiento::BusquedaBinariaRaul(int *arr,int n,int valorBuscado){
	int indiceInicio = 0,indiceFin = n-1;
	int indiceCentral = indiceInicio + (indiceFin - indiceInicio)/2;
	int largoSubArray = (indiceFin-indiceInicio)+1;

	while(largoSubArray > 0 && arr[indiceCentral] != valorBuscado){
		valorBuscado > arr[indiceCentral] ? indiceInicio = indiceCentral+1 : indiceFin = indiceCentral -1;
		indiceCentral = indiceInicio + (indiceFin - indiceInicio)/2;
		largoSubArray = (indiceFin-indiceInicio)+1;
	}
	return indiceInicio > indiceFin ? -1 : indiceCentral;
}
// Implementacion del algoritmo en el libro de  Joyanes Aguilar
int AlgoritmosOrdenamiento::BusquedaBinaria(int *v,int n,int buscado){
	int primero = 0 , ultimo = n-1 , central;
	bool encontrado = false;

	while(primero <= ultimo && encontrado == false){
		central = primero + (ultimo - primero)/2;
		if(buscado == v[central]){
			encontrado = true;
		}else if(buscado > v[central]){
			primero = central+1;
		}else{
			ultimo = central-1;
		}
	}
	return encontrado ? central : -1;
}

int AlgoritmosOrdenamiento::BusquedaBinariaRefactor(int *v,int n,int buscado){
	int primero = 0 , ultimo = n-1 , central = (primero + ultimo)/2;

	while(primero <= ultimo && v[central] != buscado){
		buscado > v[central] ? primero = central+1 : ultimo = central-1;
		central = ultimo + (ultimo-primero)/2;
	}
	return primero > ultimo ? -1  : central;
}
