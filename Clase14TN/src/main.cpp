#include <iostream>
#include "Clase14TN.h"
using namespace std;
using namespace AlgoritmosOrdenamiento;

int* ObtenerSubArray(int *arr,int inicio,int fin){

	int indiceSubArray = 0;
	int *subArray = new int[fin-inicio+1];

	for(int indiceArray = inicio;indiceArray < fin+1;indiceArray++){
		subArray[indiceSubArray] = arr[indiceArray];
		indiceSubArray++;
	}
	return subArray;
}



void MostrarArray(int *arr,int n){
	for(int i = 0 ;i<n;i++){
		cout << arr[i] << " ";
	}
}

int main(){

	int v[] = {1,14,89,1001,2000,3000};
	MostrarArray(v,6);
	//cout << endl <<  BusquedaBinaria(v,2,111);
	//cout << endl <<  BusquedaBinariaRaul(v,2,1);dd
	cout << endl <<  BusquedaBinariaRefactor(v,6,7000);

	return 0;
}
