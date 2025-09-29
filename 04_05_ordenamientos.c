#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 10

int  generaAleatorio(int);
void cargarAleatorio(int [], int);
void mostrarVector(int [], int );



void ordenarSeleccion(int [], int);
void ordenarInsersion(int [], int);

	

int main(int argc, char *argv[]) {
	
	int v[MAX];
	int n;
	n = 10;
	
	
	srand(time(NULL));
	cargarAleatorio(v, n);
	mostrarVector(v,n);
	
	printf("\nordenado\n");
	ordenarInsersion(v,n);
	mostrarVector(v,n);
	
	
	
	return 0;
}


int generaAleatorio(int k){
	int num;
	num = rand() % k+1;
	
	return num;
}
	
void cargarAleatorio(int v[], int n){
	int i;
	for (i=0; i<n; i++){
		v[i] = generaAleatorio(10);
	}
}

void mostrarVector(int v[], int n){
	int i;
	printf("[");
	for (i=0; i<n; i++){
		printf(" %d ", v[i]); 
	}
	printf("]");
}

	
	
	
void ordenarSeleccion(int v [], int n){
	int i, j, aux;
	
	for(i =0; i<n; i++){
		for (j = i+1; j<n; j++){
			if(v[i]<v[j]){
				aux  = v[i];
				v[i] = v[j];
				v[j] = aux;
			}
		}
	}
}

	
	
void ordenarInsersion(int v [], int n){
	int i, j, key;
	for (i=1; i<n; i++){
		key = v[i];
		
		j = i-1;
		while(j>=0 && v[j]> key){
			v[j+1] = v[j];
				j--;
		}
		v[j+1] = key;
		
	}
}
	
