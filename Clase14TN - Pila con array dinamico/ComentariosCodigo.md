En la funcion Apilar, en un principio redimensionamos cada vez que se llena el vector. Y siempre redimensionamos por un lugar más por lo que cada vez que apilamos nos cuesta O(N) ya que redimensionar hace una copia de los elementos que estaban antes en la pila .

Entonces luego de llegar a la capacidad de la pila cada apilado cuesta O(N).
Si hacemos que en cada redimensionamiento se agrande en un factor del doble por ejemplo evitamos ese problema.

Por ejemplo entonces :
Supongamos que capacidadActual = 100  
Apilamos 100 veces.  
Apilamos una vez O(N) [Se redimensiona al doble]  
Apilamos una vez O(1)  
Apilamos una vez O(1)  
.  
.  
.  
.  
x100 apiladas  
Apilamos una vez O(N) [Se redimensiona al doble]  
y así .... Vemos que se amortigua.  

El problema es que si por algún motivo en la pila se producen muchas operaciones de desapilar y antes se apilo por encima de la capacidad puede que nos quedemos con un vector con un tamanio muy grande y pocos elementos , es decir la complejidad espacial sería malísima.

Para solucionar este problema la solución es llamar a la función dimensionar también en Desapilar().
De esta manera el comportamiento de Redimensionar() debería ser tal que pueda redimensionar para abajo y para arriba.¿Qué tanto hacia abajo? ,un critero puede ser que si la capacidadActual del array es mayor al doble de la cantidadItems , entonces debamos redimensionar para abajo (hasta la mitad de la capacidad que tenia en ese momento).

Obs : En desapilar notar que no se libera memoria al desapilar un item. Esto es porque al desapilar
simplemente devolvemos ese elemento. En la posición donde estaba no hacemos nada, cuando se apile uno nuevo lo va a sobreescribir. Para esto es fundamental que lo que no tenemos que olvidar es disminuir en una unidad la cima al desapilar.

#### Análisis del peor caso de Apilar y Desapilar, usando Redimensionar.


Notar que al redimensionar a la mitad , redimensionamos al valor justo para que la capacidad coincida con la cantidad de items del array.  

Por ejemplo si vamos apilando en el momento que la capacidadActual > cantidadDeItems*2 , ahí redimensionamos de manera que la nueva capacidad es justamente cantidadDeItems.  
El problema de esto es que si tenemos una situación como esta.


Supongamos capacidadActual (inicial) = 400 y cantidadDeItems (inicial) = 0

- Apilamos 399 veces  
- Apilamos 1 vez . (Se redimensiona al doble de la capacidadActual) [capacidadActual = 800].  
- Desapilamos 1 vez , cantidadDeItems = 399 , capacidadActuall = 800 , 800 > 399*2 (798). 
Ahora se cumple la condición de espacio al pedo, redimensionamos para abajo , a la cantidad mínima para que entren los items, es decir ahora será capacidadActual = 399 y cantidadDeItems = 399
- Apilamos 1 vez, nuevamente estamos a 1 de llenarla . Redimensionamos para arriba al doble.
- Desapilamos 1 vez, nuevamente se cumple la condición de espacio al pedo pues en este momento es cantidadDeItems = 398 y capacidadActual = 800 , 800 > 398*2

O sea que al final en esta condición las operaciones tuvieron el siguiente costo
- Del apilado 1 al 399 O(1)
- Apilado O(N)
- Desapilado O(N)
- Apilado O(N)
- Desapilado O(N)

En esta situacion la mayoria de las operaciones serían de O(N).  
¿Cómo amortiguar esto?. Se puede pensar en que cuando redimensionemos hacia abajo no lo hagamos al tamaño justo , sino que dejemos un cierto espacio extra : 1/4 de la capacidad en ese momento.

Entonces nuevaCapacidad = capacidadActual/2 + 1/4cantidadDeItems  
O bien , nuevaCapacidad = cantidadDeItems + cantidadDeItems/2  
Ejemplo : capacidadActual = 400 , cantidadDeItems = 199*2 = 398.  
Entonces capacidadActual > cantidadDeItems*2   
Usando este ultimo criterio al redimensionar para abajo la nuevaCapacidad será : 
nuevaCapacidad = 398 + 398/2 = 298.  
Haciendo esto y simulándolo se ve que la mayoría de las veces las operaciones de Apilar() y Desapilar() se harán en O(1).


TODO => Implementar una pila inmutable , mirar diapositivas de sedgewick

Obs : En c++ no vamos a poder por ejemplo en el main usar un tipo de dato que haya sido declarado en un .h con forward declaration. Si queremos acceder a un miembro de un struct declarado de esa manera lo que debermos hacer será justamente crear una función que acceda al struct y lo inicialize. Luego en el main usamos esa función y no hacemos esa inicialización manual.

