#include <stdio.h>
#define TM 50
typedef char tCadena[TM];

/* Un registro (o struct) es un tipo de dato 
que agrupa diferentes variables 	bajo un mismo nombre.
Se usa para representar entidades complejas que tienen varios atributos. */

struct Persona {  
	tCadena nombre;
	int edad;
	float altura;
};  /*struct Persona define un nuevo tipo compuesto.*/

void leeCad(tCadena, int);

int main() {
	struct Persona p1;   /*p1 es una variable de tipo struct Persona.*/
	
	printf("Ingrese nombre: ");
	leeCad(p1.nombre, TM);   /*Se accede a sus campos con el operador punto (.)*/
	printf("Ingrese edad: ");
	scanf("%d", &p1.edad);
	printf("Ingrese altura: ");
	scanf("%f", &p1.altura);
	
	printf("\nDatos:\n");
	printf("Nombre: %s\nEdad: %d\nAltura: %.2f\n", p1.nombre, p1.edad, p1.altura);
	return 0;
}


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
