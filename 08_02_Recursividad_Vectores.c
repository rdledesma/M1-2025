#include <stdio.h>
#define MAX 30

typedef struct{
	int lista [MAX];
	int n;
}Enteros;


Enteros inicializaLista();

void cargaRecursivo(Enteros *, int);
void cargarLista(Enteros *);

void mostrarLista(Enteros);
void muestraRecursivo(Enteros);
void muestraIterativo(Enteros);

void insertarElemento(Enteros *, int, int);
void insertarRecursivo(Enteros *, int, int , int);

void eliminarElemento(Enteros *, int);
void eliminarRecursivo(Enteros *, int , int );

int main(int argc, char *argv[]) {
	
	Enteros lista;
	
	lista = inicializaLista();
	
	cargarLista(&lista);
	mostrarLista(lista);
	
	//printf("\nIterativa: ");
	//muestraIterativo(lista);
	
	// Ejemplos de uso de los nuevos módulos
	//insertarElemento(&lista, 1, 99);  // insertar 99 en la posición 1
	//printf("\nDespués de insertar: ");
	//muestraIterativo(lista);
	
	//modificarElemento(&lista, 2, 55); // modificar posición 2 con 55
	//printf("\nDespués de modificar: ");
	//muestraIterativo(lista);
	
	
	
	eliminarElemento(&lista, 3);       // eliminar posición 3
	printf("\nDespués de eliminar: ");
	
	
	//insertarElemento(&lista, 2, 44);
	
	muestraIterativo(lista);
	
	return 0;
}


Enteros inicializaLista(){
	Enteros l;
	l.n = 0;
	return l;
}
	
void cargaRecursivo(Enteros* l, int tam){
	if(tam >0){
		cargaRecursivo(l, tam-1);
		l->n ++ ;
		scanf("%d",&l->lista[tam]);
	}
}
	
void cargarLista(Enteros *l){
	int tam;
	tam = 3;
cargaRecursivo(l,tam);
}

void muestraRecursivo(Enteros l){
	if(l.n > 0){
		printf("%d ", l.lista[l.n]);
		l.n --;
		muestraRecursivo(l);
	}
}

void mostrarLista(Enteros l){
	if(l.n == 0)
		printf("lista vacia \n");
	else
		muestraRecursivo(l);
}

void muestraIterativo(Enteros l){
	int i;
	for(i=1; i<=l.n; i++){
		printf("%d " ,l.lista[i]); 
	}
}

// Inserta un elemento x en la posición p (1-indexado)
void insertarRecursivo(Enteros *l, int p, int x, int i){
	if(i < p) {
		// Base: llegamos a la posición p, colocamos el elemento
		l->lista[p] = x;
		l->n++;
		return;
	} else {
		// Mover el elemento actual hacia la derecha
		l->lista[i+1] = l->lista[i];
		insertarRecursivo(l, p, x, i-1);
	}
}
	
	
void insertarElemento(Enteros *l, int p, int x){
	if(l->n >= MAX || (p < 1 || p > l->n + 1)){
		printf("\nLista llena, o posicion invalida.\n");
	}
	else{
		insertarRecursivo(l, p, x, l->n);  // Comenzamos desde el último elemento
	}
}


// Elimina un elemento de la posición p de forma recursiva
void eliminarRecursivo(Enteros *l, int p, int i){
	if(i >= l->n){
		// Base: llegamos al último elemento, solo reducimos el tamaño
		l->n--;
	} else {
		// Mover el siguiente elemento hacia la izquierda
		l->lista[i] = l->lista[i+1];
		eliminarRecursivo(l, p, i+1);
	}
}
		

void eliminarElemento(Enteros *l, int p){
	if(l->n == 0 || (p < 1 || p > l->n)){
		printf("\nLista vacía o posicion invalida \n");
	}
	else{
		eliminarRecursivo(l, p, p);
	}
}
