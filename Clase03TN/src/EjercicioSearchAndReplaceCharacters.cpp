//============================================================================
// Name        : Clase03TN.cpp
// Author      : 
// Version     :
// Copyright   : Funciones para hacer search & replace en cadenas.
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstring>
using namespace std;

// Pre : @texto y @subtexto son cad de caracteres.
// Post: Return true si @subTexto está en @texto , sino false.
bool ContieneSubTexto(char texto[] , char subTexto[]);

// Pre : @texto,@textoBusqueda y @texotReemplazo son cad de caractes.
//       Dimension de @texto es suficiente para realizar los reemplazos
// Post: Reemplaza apariciones de @texto en @textoBusqueda por @textoReemplazo
void Reemplazar(char texto[], char textoBusqueda[],char textoReemplazo[]);

// Pre -
// Post : Retorna true si el @caracter está en @texto , de lo contrario false.
int BuscarCaracter(char texto[], char caracter);

int main() {

	char nombre[] =  {'s','s','a'};
	char letra = 'q';
	cout << BuscarCaracter(nombre,letra);

	return 0;
}

void Reemplazar(char texto[], char textoBusqueda[],char textoReemplazo[]){

}
bool ContieneSubTexto(char texto[] , char subTexto[]){

}
// Implementación de busqueda secuencial en cadena de caracteres.
int BuscarCaracter(char texto[], char caracter){

	unsigned int pos;

	for(pos=0;pos<strlen(texto);pos++){
		if(texto[pos] == caracter){
			return pos;
		}
	}
	return -1;
}

