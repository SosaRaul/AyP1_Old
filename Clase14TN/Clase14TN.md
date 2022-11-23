### Agenda 
Análisis de algoritmos (2 da parte)
-    Casos de estudio
-    Algoritmos de ordenamiento.

La pila es es una estructura de datos pensada para poner y sacar elementos , cuya característica es la forma que tiene de sacar y poner : LIFO

En las Pilas , el orden de crecimiento de las operaciones de Apilar() y Desapilar() es constante , y justamente esa es la gracia.

La implementación de la Pila con vectores dinámicos , nos da que Apilar() y Desapilar() es de órden O(N). 

En las Colas , Encolar() y Desencolar() son de órden constante.


Trade-off => Ventajas y desventajas de algo.

Podemos implementarlas con listas o vectores. La diferencia está en la complejidad espacial de cada caso. Con vectores dinámicos es mejor.

**Amortiguar** : Hacer que lo más costoso en un algún algoritmo se llame la menor cantidad de veces

Loitering : Tener una referencia que lógicamente existe pero no se usa (dejar algo colgado al pedo).

El análisis del órden de crecimiento de la búsqueda binaria está bien explicado en joyanes.

¿Tiene sentido ordenar un vector para luego poder usar en él búsqueda binaria?
SI! , porque el ordenamiento, si bien puede ser de $O(n^2)$ o en el mejor de los casos O(nlog(n))
*solo se hace una vez* , pero luego hacemos muchas búsquedas!! . Un ejemplo son los índices de las bases de datos que mantienen las tablas ordenadas.