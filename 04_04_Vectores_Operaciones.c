#include <stdio.h>
#define MAX 20  // No poner ; despu�s del #define

// Prototipos
void cargarArreglo(int v[], int *n);
void mostrarArreglo(int v[], int n);
int validaTam(int n);
void insertarFinal(int v[], int *n, int valor);
void insertarInicio(int v[], int *n, int valor);

int main() {
	int A[MAX];
	int N = 0; // tama�o inicial del arreglo
	int opcion, valor;
	
	do {
		printf("\n--- Men� ---\n");
		printf("1. Cargar arreglo\n");
		printf("2. Mostrar arreglo\n");
		printf("3. Insertar al final\n");
		printf("4. Insertar al inicio\n");
		printf("0. Salir\n");
		printf("Opci�n: ");
		scanf("%d", &opcion);
		
		switch(opcion) {
		case 1:
			cargarArreglo(A, &N);
			break;
		case 2:
			mostrarArreglo(A, N);
			break;
		case 3:
			printf("Ingrese el valor a insertar al final: ");
			scanf("%d", &valor);
			insertarFinal(A, &N, valor);
			break;
		case 4:
			printf("Ingrese el valor a insertar al inicio: ");
			scanf("%d", &valor);
			insertarInicio(A, &N, valor);
			break;
		case 0:
			printf("Saliendo...\n");
			break;
		default:
			printf("Opci�n inv�lida.\n");
		}
	} while(opcion != 0);
	
	return 0;
}

// ---------------- Funciones ----------------

void cargarArreglo(int v[], int *n) {
	int i;
	printf("Ingrese la cantidad de elementos (max %d): ", MAX);
	scanf("%d", n);
	
	if (*n > 0 &&  *n < MAX) {
		for (i = 0; i < *n; i++) {
			printf("v[%d] = ", i);
			scanf("%d", &v[i]);
		}
	}
	else{
		printf("Cantidad invalida");
		*n = 0;
	}
	
	
}

void mostrarArreglo(int v[], int n) {
	if (n == 0) {
		printf("El arreglo est� vac�o.\n");
		return;
	}
	printf("Arreglo: ");
	for (int i = 0; i < n; i++) {
		printf("%d ", v[i]);
	}
	printf("\n");
}

int validaTam(int n){
	int aux;
	if (n < MAX)
		aux = 1;
	else
		aux=0;
	return aux;
}


void insertarFinal(int v[], int *n, int valor) {
	
	if(validaTam(*n)){
		v[*n] = valor;
		(*n)++;
		printf("Elemento insertado al final.\n");
	}
	else
		printf("No se puede insertar, arreglo lleno.\n");
	
}

void insertarInicio(int v[], int *n, int valor) {
	int i;
	if(validaTam(*n)){
		// mover todos los elementos un lugar a la derecha
		for (i = *n; i > 0; i--) {
			v[i] = v[i-1];
		}
		v[0] = valor;
		(*n)++;
		printf("Elemento insertado al inicio.\n");
		
	}
	else
		printf("No se puede insertar, arreglo lleno.\n");
	
	
}
