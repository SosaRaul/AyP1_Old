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

int BuscarTexto(char texto[],char textoBusqueda[]);


int main() {

	char texto[] = "stucabatrk";
	char subTexto[] = "caa";
	cout << BuscarTexto(texto,subTexto);

	return 0;
}

void Reemplazar(char texto[], char textoBusqueda[],char textoReemplazo[]){

}
bool ContieneSubTexto(char texto[] , char subTexto[]){

	unsigned int indiceTexto = 0, indiceSubtexto = 0;

	while(indiceTexto < strlen(texto) && indiceSubtexto < strlen(subTexto)){
		if(texto[indiceTexto] == subTexto[indiceSubtexto]){
			indiceSubtexto++;
		}
		indiceTexto++;
	}
	if(indiceSubtexto == strlen(subTexto)-1){
		return true;
	}
	else{
		return false;
	}

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

int BuscarTexto(char texto[],char textoBusqueda[]){

	unsigned int indiceTexto = 0, indiceTextoBusqueda = 0;

	while(indiceTexto < strlen(texto) && indiceTextoBusqueda < strlen(textoBusqueda)){
		if(texto[indiceTexto] == textoBusqueda[indiceTextoBusqueda]){
			indiceTextoBusqueda++;
		}
		indiceTexto++;
	}

	if(indiceTextoBusqueda == strlen(textoBusqueda)-1){
		return indiceTexto-strlen(textoBusqueda);
	}
	else{
		return -1;
	}

}
