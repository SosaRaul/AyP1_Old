#include <iostream>
#include "Clase13.h"
using namespace std;
using namespace PunterosAFuncion;

int main(){

	//int (*funcion)(int,int);
	// Al puntero "funcion" le asigna la direccion de memoria de Suma()
	// typedef para ponerle un alias a la declaracion de tipo que es complicada
	typedef int (*funcionDosOperandos)(int,int);

	funcionDosOperandos misFunciones[2] = {Suma,Resta};

	cout << misFunciones[1](10,20);

	return 0;
}


