#include <stdio.h>

/*
La recursividad significa la cualidad de repetirse y se aplica cuando un proceso se define a s� mismo,
 descomponiendo un problema en subproblemas m�s peque�os de la misma naturaleza hasta llegar a uno trivial. 
Su origen etimol�gico est� en el lat�n "recurrere" ("volver atr�s"), 
mientras que su historia se remonta a conceptos matem�ticos como los axiomas de Peano y fractales, 
y es fundamental en la ling��stica y la programaci�n para crear estructuras complejas a partir de reglas simples. 
Significado

General: La recursividad es la capacidad de identificar un patr�n y usarlo para
 generar estructuras infinitas o resolver un problema mediante la repetici�n de 
un proceso aplicado a versiones m�s peque�as de s� mismo.

En Programaci�n: Una funci�n recursiva se llama a s� misma para resolver 
un problema, dividi�ndolo hasta alcanzar un caso base que puede resolverse directamente.
En Ling��stica: Es la capacidad de insertar una frase o elemento dentro de otro
 del mismo tipo, lo que permite generar un n�mero ilimitado 
de enunciados a partir de elementos limitados. 

Origen
La palabra proviene del lat�n "recursus", que significa 
"carrera hacia atr�s" o "regreso", y la cualidad "-dad", de ah� "cualidad de repetirse"
*/


/*La recursividad es una t�cnica de programaci�n en la que una funci�n se llama a s� misma directa o indirectamente,
 para resolver un problema dividi�ndolo en subproblemas m�s peque�os.
	
En otras palabras: un problema grande se resuelve repitiendo el mismo proceso sobre instancias m�s peque�as del mismo tipo.
	
Requisitos esenciales
	
	Toda funci�n recursiva necesita:
	
		Caso base (condici�n de parada): cuando se alcanza una condici�n que detiene las llamadas recursivas.
	
		Llamada recursiva: la funci�n se invoca a s� misma con valores m�s simples o m�s cercanos al caso base.
*/


/*
tipo nombre_funcion(par�metros) {
	if (condici�n_de_parada)
		return valor_simple;
	else
		return nombre_funcion(par�metros_modificados);
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
		printf("�Despegue!\n");
	else {
		printf("%d\n", n);
		cuentaRegresiva(n - 1);
	}
}




/*Cada vez que una funci�n se llama a s� misma:

Se crea una nueva copia de sus variables locales y par�metros.

Se guarda el punto de retorno en la pila de ejecuci�n.

Cuando termina, la funci�n devuelve el control a la anterior.*/

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

/*\u26a0\ufe0f Este ejemplo muestra una de las debilidades: repite muchos c�lculos innecesarios (ineficiencia). */
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

/*Calcular el producto de los n�meros entre 1 y N.*/
int calculaProducto(int j, int k){
	if(j == 1){
		return k;
	}
	else{
		return k + calculaProducto(j-1, k);
	}
}
	
/*Determinar si un n�mero es pal�ndromo recursivamente.*/

