#include <stdio.h>
#include <stdlib.h>

#define TM 50   // Constante de ejemplo (por consistencia con tu estilo)

// ======================================
// ESTRUCTURAS Y DEFINICIONES
// ======================================

typedef struct Nodo {
	int dato;           // Dato que guarda el nodo
	struct Nodo *sig;   // Puntero al siguiente nodo
} Nodo;

typedef Nodo* Lista;     // Una lista es un puntero al primer nodo

// ======================================
// PROTOTIPOS DE FUNCIONES
// ======================================

void inicializarLista(Lista *L);
Nodo* crearNodo(int valor);
void insertarInicio(Lista *L, int valor);
void insertarFinal(Lista *L, int valor);
void insertarOrdenado(Lista *L, int valor);
void eliminarPorValor(Lista *L, int valor);
void editarPorPosicion(Lista L, int posicion, int nuevoValor);
void eliminarLista(Lista *L);
void mostrarLista(Lista L);

// ======================================
// FUNCIONES
// ======================================

// Inicializa la lista vacía
void inicializarLista(Lista *L) {
	*L = NULL;
}

// Crea un nodo dinámicamente con malloc
Nodo* crearNodo(int valor) {
	Nodo *nuevo = (Nodo*) malloc(sizeof(Nodo));
	if (nuevo == NULL) {
		printf("Error: no se pudo asignar memoria.\n");
		exit(1);
	}
	nuevo->dato = valor;
	nuevo->sig = NULL;
	return nuevo;
}

// Inserta un elemento al inicio de la lista
void insertarInicio(Lista *L, int valor) {
	Nodo *nuevo = crearNodo(valor);
	nuevo->sig = *L;
	*L = nuevo;
}

// Inserta un elemento al final de la lista
void insertarFinal(Lista *L, int valor) {
	Nodo *nuevo = crearNodo(valor);
	
	if (*L == NULL) {
		*L = nuevo;
	} else {
		Nodo *aux = *L;
		while (aux->sig != NULL) {
			aux = aux->sig;
		}
		aux->sig = nuevo;
	}
}

// Inserta un elemento en orden ascendente
void insertarOrdenado(Lista *L, int valor) {
	Nodo *nuevo = crearNodo(valor);
	
	// Caso 1: lista vacía o el nuevo valor es menor que el primero
	if (*L == NULL || valor < (*L)->dato) {
		nuevo->sig = *L;
		*L = nuevo;
		return;
	}
	
	// Caso 2: buscar la posición adecuada
	Nodo *aux = *L;
	while (aux->sig != NULL && aux->sig->dato < valor) {
		aux = aux->sig;
	}
	
	nuevo->sig = aux->sig;
	aux->sig = nuevo;
}

// Elimina un nodo por su valor
void eliminarPorValor(Lista *L, int valor) {
	if (*L == NULL) {
		printf("La lista está vacía.\n");
		return;
	}
	
	Nodo *actual = *L;
	Nodo *anterior = NULL;
	
	while (actual != NULL && actual->dato != valor) {
		anterior = actual;
		actual = actual->sig;
	}
	
	if (actual == NULL) {
		printf("Valor %d no encontrado en la lista.\n", valor);
		return;
	}
	
	if (anterior == NULL) {
		// Se elimina el primero
		*L = actual->sig;
	} else {
		anterior->sig = actual->sig;
	}
	
	free(actual);
	printf("Valor %d eliminado correctamente.\n", valor);
}

// Edita el valor de un nodo según su posición (0 = primero)
void editarPorPosicion(Lista L, int posicion, int nuevoValor) {
	Nodo *aux = L;
	int i = 0;
	
	while (aux != NULL && i < posicion) {
		aux = aux->sig;
		i++;
	}
	
	if (aux == NULL) {
		printf("Posición fuera de rango.\n");
		return;
	}
	
	aux->dato = nuevoValor;
	printf("Nodo en posición %d actualizado a %d.\n", posicion, nuevoValor);
}

// Muestra todos los elementos de la lista
void mostrarLista(Lista L) {
	Nodo *aux = L;
	printf("Lista: ");
	while (aux != NULL) {
		printf("%d -> ", aux->dato);
		aux = aux->sig;
	}
	printf("NULL\n");
}

// Libera toda la memoria de la lista
void eliminarLista(Lista *L) {
	Nodo *aux;
	while (*L != NULL) {
		aux = *L;
		*L = (*L)->sig;
		free(aux);
	}
	printf("Lista eliminada completamente.\n");
}

// ======================================
// FUNCIÓN PRINCIPAL: DEMOSTRACIÓN
// ======================================

int main() {
	Lista L;
	L = NULL;
	
	// Inserciones
	insertarInicio(&L, 5);
	insertarInicio(&L, 2);
	insertarFinal(&L, 8);
	insertarOrdenado(&L, 6);
	insertarOrdenado(&L, 1);
	mostrarLista(L);
	
	// Eliminación
	eliminarPorValor(&L, 2);
	mostrarLista(L);
	
	// Edición
	editarPorPosicion(L, 2, 10);
	mostrarLista(L);
	
	// Eliminar toda la lista
	eliminarLista(&L);
	mostrarLista(L);
	
	return 0;
}
