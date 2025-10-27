#include <stdio.h>
#include "Personas.h"
#include "Persona.h"

// Inicializa la lista de personas vacía
Personas inicializarLista() {
	Personas p;
	p.n = 0;
	return p;
}

// Inserta una persona en la lista (si hay espacio)
void insertarUno(Personas *lista, Persona per) {
	if (lista->n < MAX_PER) {
		lista->lista[lista->n] = per;
		lista->n++;
	} else {
		printf("\u26a0\ufe0f No se pueden insertar más personas. Lista llena.\n");
	}
}

// Permite insertar varias personas hasta llenar la lista o que el usuario decida parar
void insertarMuchos(Personas *lista) {
	Persona nueva;
	char opcion;
	do {
		if (lista->n >= MAX_PER) {
			printf("\nLista llena. No se pueden agregar más personas.\n");
			break;
		}
		
		nueva = crearPersona();
		insertarUno(lista, nueva);
		
		printf("¿Desea ingresar otra persona? (s/n): ");
		scanf(" %c", &opcion);
		getchar();
	} while (opcion == 's' || opcion == 'S');
}

// Ordena la lista de personas por edad (ascendente) y si hay empate, por DNI (ascendente)
void ordenarDosCriterios(Personas lista) {
	int i, j, cmpEdad;
	Persona aux;
	
	for (i = 0; i < lista.n - 1; i++) {
		for (j = i + 1; j < lista.n; j++) {
			// Comparar primero por edad
			cmpEdad = comparaEdad(lista.lista[i], lista.lista[j]);
			
			// Si edades iguales, comparar por DNI
			if (cmpEdad == 0) {
				int cmpDNI = comparaDNI(lista.lista[i], lista.lista[j]);
				if (cmpDNI > 0) {
					aux = lista.lista[i];
					lista.lista[i] = lista.lista[j];
					lista.lista[j] = aux;
				}
			} else if (cmpEdad > 0) {
				aux = lista.lista[i];
				lista.lista[i] = lista.lista[j];
				lista.lista[j] = aux;
			}
		}
	}
	
	printf("\n Lista ordenada por edad y DNI.\n");
}

// Muestra todas las personas de la lista
void mostrarPersonas(Personas lista) {
	printf("\n--- Lista de Personas (%d) ---\n", lista.n);
	for (int i = 0; i < lista.n; i++) {
		printf("\nPersona #%d:\n", i + 1);
		mostrarPersona(lista.lista[i]);
	}
	printf("-------------------------------\n");
}
