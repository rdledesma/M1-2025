#include <stdio.h>
#include <string.h>

#define TM 30
#define MAX 5  // número máximo de personas

typedef char tCadena[TM];

// Definir struct Persona
typedef struct {
	tCadena nombre;
	int edad;
	float altura;
} Persona;

typedef Persona Personas[MAX];

// ----- Prototipos -----
void leeCad(tCadena cad, int tam);
Persona cargarPersona(void);
void mostrarPersona(Persona p);
void cargarPersonasOrdenada(Personas l, int *tam);

// ----- MAIN -----
int main() {
	Persona p;
	Personas personas;  // \u2705 No hace falta poner [MAX] porque ya lo define el typedef
	int n = 0;           // \u2705 Inicializamos cantidad en 0
	
	printf("Carga de una persona (prueba individual):\n");
	p = cargarPersona();
	mostrarPersona(p); // Verificamos que la carga y muestra de una Persona está OK
	
	printf("\nCarga de lista ordenada:\n");
	cargarPersonasOrdenada(personas, &n);
	
	printf("\n--- LISTA FINAL ORDENADA POR EDAD ---\n");
	for (int i = 0; i < n; i++)
		mostrarPersona(personas[i]);
	
	return 0;
}

// ----- FUNCIONES -----

void leeCad(tCadena cad, int tam) {
	int j = 0;
	char c = getchar();
	while (c != EOF && c != '\n' && j < tam - 1) {
		cad[j++] = c;
		c = getchar();
	}
	cad[j] = '\0';
	while (c != EOF && c != '\n')
		c = getchar();
}

Persona cargarPersona(void) {
	Persona nue;
	
	printf("\nCargando Persona\n");
	printf("Nombre: ");
	leeCad(nue.nombre, TM);
	printf("Edad: ");
	scanf("%d", &nue.edad);
	printf("Altura: ");
	scanf("%f", &nue.altura);
	getchar(); // limpiar buffer
	
	return nue;
}

void mostrarPersona(Persona p) {
	printf("Nombre: %s | Edad: %d | Altura: %.2f\n", p.nombre, p.edad, p.altura);
}

void cargarPersonasOrdenada(Personas l, int *tam) {
	int i, k;
	Persona nuevo;
	
	printf("\nIngrese la cantidad de personas que desea cargar (máx %d): ", MAX);
	scanf("%d", tam);
	getchar(); // limpiar buffer
	
	// \u2705 Cargar la primera persona directamente
	if (*tam > 0) {
		printf("\n--- Persona 1 ---\n");
		l[0] = cargarPersona();
	}
	
	// \u2705 Desde la segunda en adelante, insertar ordenado
	for (k = 1; k < *tam; k++) {
		printf("\n--- Persona %d ---\n", k + 1);
		nuevo = cargarPersona();
		i = k - 1;
		
		// Insertar ordenado por edad (de menor a mayor)
		while (i >= 0 && l[i].edad > nuevo.edad) {
			l[i + 1] = l[i]; // desplazamos a la derecha
			i--;
		}
		
		l[i + 1] = nuevo; // insertamos en posición correcta
	}
}
