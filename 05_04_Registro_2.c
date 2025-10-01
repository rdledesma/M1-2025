#include <stdio.h>

// Definir un registro para un punto
typedef struct {  // Crea un tipo llamado Punto. Dentro están dos campos: x, y.
	int x;
	int y;
} Punto;

int main() {
	// Declarar variables de tipo Punto
	Punto p1, p2;
	Punto suma;
	
	
	// Asignar valores
	p1.x = 5;
	p1.y = 10;
	
	p2.x = -3;
	p2.y = 7;
	
	// Mostrar los datos
	printf("Punto 1: (%d, %d)\n", p1.x, p1.y);
	printf("Punto 2: (%d, %d)\n", p2.x, p2.y);
	
	// Sumar coordenadas

	suma.x = p1.x + p2.x;
	suma.y = p1.y + p2.y;
	printf("Suma de puntos: (%d, %d)\n", suma.x, suma.y);  //p1 y p2 son variables de tipo Punto. Si no usamos typedef, tendríamos que escribir struct Punto p1;
	
	return 0;
}
