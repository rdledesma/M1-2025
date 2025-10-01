#include <stdio.h>
#define TM 30
#define MAX 5  // número máximo de autos

typedef char tCadena[TM];

// Definir struct Automovil
typedef struct {
	tCadena marca;
	tCadena modelo;
	int anio;
} Automovil;

// ----- Prototipos -----
void leeCad(tCadena cad, int tam);
void mostrarAuto(Automovil a);
void mostrarTodos(Automovil autos[], int n);
void cargarAuto(Automovil autos[], int *n);
void editarAuto(Automovil autos[], int n);
void eliminarAuto(Automovil autos[], int *n);
void menuAutos(Automovil autos[], int *n);

// ----- MAIN -----
int main() {
	Automovil autos[MAX];
	int n = 0; // cantidad de autos cargados
	
	menuAutos(autos, &n);
	
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

void mostrarAuto(Automovil a) {
	printf("Marca: %s, Modelo: %s, Año: %d\n", a.marca, a.modelo, a.anio);
}

void mostrarTodos(Automovil autos[], int n) {
	int i;
	for(i = 0; i < n; i++) {
		printf("[%d] ", i);
		mostrarAuto(autos[i]);
	}
}



void cargarAuto(Automovil autos[], int *n) {
	if(*n < MAX) {
		printf("Ingrese marca: "); //Acaso esto no se podría modularizar mejor?
		leeCad(autos[*n].marca, TM);
		printf("Ingrese modelo: ");
		leeCad(autos[*n].modelo, TM);
		printf("Ingrese año: ");
		scanf("%d", &autos[*n].anio);
		getchar(); // limpiar buffer
		(*n)++;
		
	}
	else{
		printf("No se pueden cargar más autos.\n");
	}
	
}

void editarAuto(Automovil autos[], int n) {
	int idxEdit;
	
	if(n == 0) {
		printf("No hay autos para editar.\n");
	}
	else{
		printf("Ingrese indice del auto a editar (0-%d): ", n-1);
		scanf("%d", &idxEdit);
		getchar(); // limpiar buffer
		if(idxEdit < 0 || idxEdit >= n) {
			printf("Indice invalido.\n");
		}
		else{
			printf("Editar marca: ");
			leeCad(autos[idxEdit].marca, TM);
			printf("Editar modelo: ");
			leeCad(autos[idxEdit].modelo, TM);
			printf("Editar año: ");
			scanf("%d", &autos[idxEdit].anio);
			getchar(); // limpiar buffer
		}
		
	}
	
	
}

void eliminarAuto(Automovil autos[], int *n) {
	int idxDel, i;
	if(*n == 0) {
		printf("No hay autos para eliminar.\n");
	}
	else{
		
		printf("Ingrese indice del auto a eliminar (0-%d): ", *n-1);
		scanf("%d", &idxDel);
		getchar(); // limpiar buffer
		if(idxDel < 0 || idxDel >= *n) {
			printf("Indice invalido.\n");
		}
		else{
			for(i = idxDel; i < *n - 1; i++) {
				autos[i] = autos[i+1];
			}
			(*n)--;
			printf("Auto eliminado.\n");	
		}
		
	}
	
}

// ----- Función del menú modularizado -----
void menuAutos(Automovil autos[], int *n) {
	int opcion;
	do {
		printf("\n--- MENU ---\n");
		printf("1. Cargar un auto\n");
		printf("2. Mostrar todos los autos\n");
		printf("3. Editar un auto\n");
		printf("4. Eliminar un auto\n");
		printf("0. Salir\n");
		printf("Ingrese opcion: ");
		scanf("%d", &opcion);
		getchar(); // limpiar buffer
		
		switch(opcion) {
		case 1:
			cargarAuto(autos, n);
			break;
		case 2:
			if(*n == 0)
				printf("No hay autos cargados.\n");
			else
				mostrarTodos(autos, *n);
			break;
		case 3:
			editarAuto(autos, *n);
			break;
		case 4:
			eliminarAuto(autos, n);
			break;
		case 0:
			printf("Saliendo...\n");
			break;
		default:
			printf("Opcion invalida.\n");
		}
	} while(opcion != 0);
}
