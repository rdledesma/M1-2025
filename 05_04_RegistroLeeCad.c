#include <stdio.h>
#define TM 30

typedef char tCadena[TM];

// Función para leer cadena de forma segura
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

// Definir el tipo Alumno usando typedef y struct
typedef struct {
	tCadena dni;
	tCadena apellido;
	tCadena nombre;
	tCadena fechaNacimiento; // aaaammdd
} Alumno;

int main() {
	Alumno alumno;
	
	printf("Ingrese DNI: ");
	leeCad(alumno.dni, TM);
	
	printf("Ingrese Apellido: ");
	leeCad(alumno.apellido, TM);
	
	printf("Ingrese Nombre: ");
	leeCad(alumno.nombre, TM);
	
	printf("Ingrese Fecha de Nacimiento (aaaammdd): ");
	leeCad(alumno.fechaNacimiento, TM);
	
	// Mostrar los datos
	printf("\nDatos del alumno:\n");
	printf("DNI: %s\n", alumno.dni);
	printf("Apellido: %s\n", alumno.apellido);
	printf("Nombre: %s\n", alumno.nombre);
	printf("Fecha de Nacimiento: %s\n", alumno.fechaNacimiento);
	
	return 0;
}
