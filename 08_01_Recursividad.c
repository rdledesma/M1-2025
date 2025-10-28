#include <stdio.h>

/*
La recursividad significa la cualidad de repetirse y se aplica cuando un proceso se define a sí mismo,
 descomponiendo un problema en subproblemas más pequeños de la misma naturaleza hasta llegar a uno trivial. 
Su origen etimológico está en el latín "recurrere" ("volver atrás"), 
mientras que su historia se remonta a conceptos matemáticos como los axiomas de Peano y fractales, 
y es fundamental en la lingüística y la programación para crear estructuras complejas a partir de reglas simples. 
Significado

General: La recursividad es la capacidad de identificar un patrón y usarlo para
 generar estructuras infinitas o resolver un problema mediante la repetición de 
un proceso aplicado a versiones más pequeñas de sí mismo.

En Programación: Una función recursiva se llama a sí misma para resolver 
un problema, dividiéndolo hasta alcanzar un caso base que puede resolverse directamente.
En Lingüística: Es la capacidad de insertar una frase o elemento dentro de otro
 del mismo tipo, lo que permite generar un número ilimitado 
de enunciados a partir de elementos limitados. 

Origen
La palabra proviene del latín "recursus", que significa 
"carrera hacia atrás" o "regreso", y la cualidad "-dad", de ahí "cualidad de repetirse"
*/


/*La recursividad es una técnica de programación en la que una función se llama a sí misma directa o indirectamente,
 para resolver un problema dividiéndolo en subproblemas más pequeños.
	
En otras palabras: un problema grande se resuelve repitiendo el mismo proceso sobre instancias más pequeñas del mismo tipo.
	
Requisitos esenciales
	
	Toda función recursiva necesita:
	
		Caso base (condición de parada): cuando se alcanza una condición que detiene las llamadas recursivas.
	
		Llamada recursiva: la función se invoca a sí misma con valores más simples o más cercanos al caso base.
*/


/*
tipo nombre_funcion(parámetros) {
	if (condición_de_parada)
		return valor_simple;
	else
		return nombre_funcion(parámetros_modificados);
}*/

void cuentaRegresiva(int);

void funcionA(int n);
void funcionB(int n);


int calculaProducto(int, int );

int main(int argc, char *argv[]) {
	
	//cuentaRegresiva(10);
	
	printf("%d",calculaProducto(20,10));
	
	return 0;
}


void cuentaRegresiva(int n) {
	if (n == 0)
		printf("¡Despegue!\n");
	else {
		printf("%d\n", n);
		cuentaRegresiva(n - 1);
	}
}




/*Cada vez que una función se llama a sí misma:

Se crea una nueva copia de sus variables locales y parámetros.

Se guarda el punto de retorno en la pila de ejecución.

Cuando termina, la función devuelve el control a la anterior.*/

int factorial(int n) {
	if (n == 0) return 1;
	return n * factorial(n - 1);
}

/*

factorial(3)
-> 3 * factorial(2)
	-> 2 * factorial(1)
		->1 * factorial(0)
			->1
Resultado = 3 * 2 * 1 * 1 = 6
*/


int suma(int n) {
	if (n == 0) return 0;
	return n + suma(n - 1);
}

int potencia(int base, int exp) {
	if (exp == 0) return 1;
	return base * potencia(base, exp - 1);
}

/*\u26a0\ufe0f Este ejemplo muestra una de las debilidades: repite muchos cálculos innecesarios (ineficiencia). */
int fibonacci(int n) {
	if (n == 0) return 0;
	if (n == 1) return 1;
	return fibonacci(n - 1) + fibonacci(n - 2);
}



/*Ejemplo de recursividad indirecta*/
void funcionA(int n) {
	if (n > 0) {
		printf("A: %d\n", n);
		funcionB(n - 1);
	}
}

void funcionB(int n) {
	if (n > 0) {
		printf("B: %d\n", n);
		funcionA(n / 2);
	}
}

/*Calcular el producto de los números entre 1 y N.*/
int calculaProducto(int j, int k){
	if(j == 1){
		return k;
	}
	else{
		return k + calculaProducto(j-1, k);
	}
}
	
/*Determinar si un número es palíndromo recursivamente.*/

