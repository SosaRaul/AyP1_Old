#### Agenda 
 Punteros a función.
- Funciones de alto orden
- Relación entre comportamiento polimórfico y código clausurado ante cambios.

Análisis de algoritmos (1era parte)

***
#### Punteros a función
El Objetivo de un puntero a función es convertir las funciones en variables.

```cpp
		T (*name_function) (list_parameters);
		// T = type of return value.
		// list_parameters have to include type
```
 Pero es un molesto así que podemos usar typedef para mejorarlo.
 
```cpp
	typedef T (*alias) (list_parameters);
```
Para aplicar esto se usó el TDA Tanque donde se creo una función Map(lista,funcionAplicacion).
Luego a cada funcion del TDA se la modificó para que use Map, de manera tal que el procesamiento secuencial que se repetia en Vaciar(),Llenar(),Mostrar() solo se haga en Map(),y la especialización de la función sea la instancia a pasar como parámetro.

Min 46 plantea ejercicio.

***

POO ->pilares fundamentales :
- Polimorfismo
- Encapsulamiento (ocultamiento de la información) . Bajo acoplamiento y alta cohesión.
- Herencia

#### Código con omportamiento polimórfico.
Una bloque tiene comportamiento polimórfico cuando su comportamiento cambia según la instancia (en este caso la instancia es la función pasada por parámetro).La postcondición de la función cambia seǵun la instancia que se pase de otra función.

#### Código clausurado ante cambios.
Código que no se ve afectado por cambios , no será necesario modificarlo al pasarle distintas instancias como parámetros.**El objetivo del comportamiento polimórfico es generar código clausurado ante cambios**.

#### Función de alto orden
Toda función que recibe como parámetro otra función se llama **función de alto órden** , y en general a ese estilo de programación se conoce como *programación de alto órden*.

Todos estos conceptos se ven en la función siguiente.

```cpp
void UndavListaTanques::Map(ListaTanques* Lista,TipoFuncionMap funcionAplicacion){
	Nodo* iterador = lista->primero;
	while(iterador!=NULL){
		funcionAplicacion(iterador->item);
		iterador = iterador->siguiente;
	}
}	
# Map : nombre en gral para referirse a funciones que transforman cosas.
# Reduce : función que toma a una colección de elementos y lo reduce a un escalar.
```
**Función Map()** : nombre en gral para referirse a funciones que transforman cosas.

**Función Reduce()** : función que toma a una colección de elementos y lo reduce a un escalar.

*Nota :* cuando queremos devolver un puntero pero no sabemos a que tipo de dato devolvemos puntero a void (*void)

[Quedó en minuto](https://youtu.be/UoUgeMslNgc?t=3643)

1:15 segunda parte de clase.

#### Análisis de algoritmos.

El orden de crecimiento de cualquier algoritmos cae en algunos de estos casos, ordenados desde el que crece más lento al más rápido.
- Constante O(1)
- Logarítmico O(log N)
- Lineal O(N)
- Linealrítmico O(N log N)
- Cuadrático O(N²)
- Cúbica O(N³)
- Exponencial. (2^N)
- Factorial (N!)

Para las mediciones en tiempo de ejecución debemos tomar elementos independientes: 
- El algoritmo
- Los datos de entrada.

Los elementos dependientes son el S.O , ram , procesador ,etc.


**Programación dinámica** : cuando usamos un *memorizador o buffer* o *cache* para guardar el resultado de una operación que necesitaríamos de otra manera hacerla repetidas veces.

Para solucionar problemas de performance tenemos que encontrar el cuello de botella con una herramienta de profiling para ver donde está y descubrir que orden de crecimiento tiene. 
