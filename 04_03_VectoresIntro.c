#include <stdio.h>
#define MAX 50   // tamaño del vector

// Prototipos
void cargarVector(int v[], int * n);
void mostrarVector(int v[], int n);
int sumaVector(int v[], int n);
float promedioVector(int v[], int n);
//int maximoVector(int v[], int n, int *pos);
//int minimoVector(int v[], int n, int *pos);
//int buscarElemento(int v[], int n, int x);
//void ordenarBurbuja(int v[], int n);

int main() {
	int A[MAX], N;
	int suma, max, min, posMax, posMin;
	float promedio;
	
	// 1) Cargar
	cargarVector(A, &N);
	
	// 2) Mostrar
	printf("\nElementos del vector A:\n");
	mostrarVector(A, N);
	
	// 3) Suma y promedio
	suma = sumaVector(A, N);
	promedio = promedioVector(A, N);
	printf("\nSuma = %d, Promedio = %.2f\n", suma, promedio);
	
	
	// 4) Máximo y mínimo
	//max = maximoVector(A, N, &posMax);
	//min = minimoVector(A, N, &posMin);
	//printf("Máximo = %d en posición %d\n", max, posMax);
	//printf("Mínimo = %d en posición %d\n", min, posMin);
	
	// 5) Búsqueda
	//int x;
	//printf("\nIngrese un número a buscar en el vector: ");
	//scanf("%d", &x);
	
	//int pos = buscarElemento(A, N, x);
	//if (pos != -1)
	//	printf("Número %d encontrado en la posición %d\n", x, pos);
	//else
	//	printf("Número %d no se encuentra en el vector.\n", x);
	
	// 6) Ordenar
	//ordenarBurbuja(A, N);
	
	//printf("\nVector ordenado en forma ascendente:\n");
	//mostrarVector(A, N);
	
	return 0;
}

// ----------------- Funciones -----------------

void cargarVector(int v[], int * n) {
	int i;
	printf("\nIngrega el tamaño N:");
	scanf("%d", n);
	
	printf("Carga del vector de %d enteros:\n", *n);
	for (i = 0; i < *n; i++) {
		printf("v[%d] = ", i);
		scanf("%d", &v[i]);
	}
}

void mostrarVector(int v[], int n) {
	for (int i = 0; i < n; i++) {
		printf("%d ", v[i]);
	}
	printf("\n");
}

int sumaVector(int v[], int n) {
	int suma = 0;
	for (int i = 0; i < n; i++) {
		suma += v[i];
	}
	return suma;
}

float promedioVector(int v[], int n) {
	float res;
	res = sumaVector(v, n) / n;
	
	return res;
}

int maximoVector(int v[], int n, int *pos) {
	int max = v[0];
	*pos = 0;
	for (int i = 1; i < n; i++) {
		if (v[i] > max) {
			max = v[i];
			*pos = i;
		}
	}
	return max;
}

int minimoVector(int v[], int n, int *pos) {
	int min = v[0];
	*pos = 0;
	for (int i = 1; i < n; i++) {
		if (v[i] < min) {
			min = v[i];
			*pos = i;
		}
	}
	return min;
}

int buscarElemento(int v[], int n, int x) {
	for (int i = 0; i < n; i++) {
		if (v[i] == x)
			return i;  // devuelve la posición
	}
	return -1; // no encontrado
}

void ordenarBurbuja(int v[], int n) {
	int j, i;
	for (j = 0; j < n - 1; j++) {
		for (i = 0; i < n - j - 1; i++) {
			if (v[i] > v[i + 1]) {
				int aux = v[i];
				v[i] = v[i + 1];
				v[i + 1] = aux;
			}
		}
	}
}
