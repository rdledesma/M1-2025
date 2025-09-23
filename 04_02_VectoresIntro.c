#include <stdio.h>

#define N 5   // tamaño fijo Pensar en porqué debo usar una Macro??
#define K 100
int main() {
	int A[N];
	int i;
	int B[K], M, x, bandera;
	
	
	printf("Cargar un vector de %d enteros:\n", N);
	for (i = 0; i < N; i++) {
		printf("A[%d] = ", i);
		scanf("%d", &A[i]);
	}
	
	printf("\nVector cargado:\n");
	for (i = 0; i < N; i++) {
		printf("%d ", A[i]);
	}
	printf("\n");
	
	
	bandera = 1;
	M = 0;
	//carga usando un centinela o bandera de control
	while (bandera & (M<K)) {
		printf("Presione 1 para cargar 0 para no cargar mas\n");
		scanf("%d", &bandera);
		if(bandera){
			printf("B[%d] = ", M);
			scanf("%d", &x);
			B[M] = x;
			M++;
		}
	
	
	}
	printf("\n");
	for (i = 0; i < M; i++) {
		printf("%d ", B[i]);
	}
	
	
	
	return 0;
}
