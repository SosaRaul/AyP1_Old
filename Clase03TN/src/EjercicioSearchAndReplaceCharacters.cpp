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

	char texto[] = "hola como andas juan andas bien";
	char textoBusqueda[] = "andas";
	char textoReemplazo[] = "raul";

	cout << "texto : " << texto  << endl;
	cout << "textoBusqueda : " << textoBusqueda << endl;
	cout << "textoReemplazo : " << textoReemplazo << endl;
	Reemplazar(texto,textoBusqueda,textoReemplazo);
	cout << "Texto luego del reemplazo : " << texto << endl;


	return 0;
}
// Esta implementación solo reemplaza, teniendo en cuenta una única coincidencia
// TODO : Mejorarla para que reemplace todas las coincidencias.
void Reemplazar(char texto[], char textoBusqueda[],char textoReemplazo[]){

	int indiceComienzo = BuscarTexto(texto,textoBusqueda);

	unsigned int indiceTextoReemplazo = 0;

	if(indiceComienzo != -1){
		for(indiceTextoReemplazo = 0 ; indiceTextoReemplazo < strlen(textoReemplazo);indiceTextoReemplazo++){
			texto[indiceComienzo] = textoReemplazo[indiceTextoReemplazo];
			indiceComienzo++;

		}
	}
	else{
		cout << "No se encontró el texto de búsqueda!! " << endl;
	}
}
bool ContieneSubTexto(char texto[] , char subTexto[]){

	unsigned int indiceTexto = 0, indiceSubtexto = 0 , contadorCoincidencias = 0 ;

	while(indiceTexto < strlen(texto) && indiceSubtexto < strlen(subTexto)){
		if(texto[indiceTexto] == subTexto[indiceSubtexto]){
			indiceSubtexto++;
			contadorCoincidencias++;
		}
		else{
			contadorCoincidencias = 0;
			indiceSubtexto = 0;
		}
		indiceTexto++;
	}

	if(contadorCoincidencias == strlen(subTexto)){
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

	unsigned int indiceTexto = 0, indiceTextoBusqueda = 0, contadorCoincidencias = 0;

	while(indiceTexto < strlen(texto) && indiceTextoBusqueda < strlen(textoBusqueda)){

		if(texto[indiceTexto] == textoBusqueda[indiceTextoBusqueda]){
			indiceTextoBusqueda++;
			contadorCoincidencias++;

		}
		else{
			contadorCoincidencias = 0;
			indiceTextoBusqueda = 0;
		}

		indiceTexto++;

	}
	if(contadorCoincidencias == strlen(textoBusqueda)){
		return indiceTexto-strlen(textoBusqueda);
	}
	else{
		return -1;
	}

}
