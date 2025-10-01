#include <stdio.h>

// Definir un struct para un punto
struct Punto {
	int x;
	int y;
};

int main() {
	// Declarar variables de tipo struct Punto
	struct Punto p1, p2;
	
	// Asignar valores
	p1.x = 5;
	p1.y = 10;
	
	p2.x = -3;
	p2.y = 7;
	
	// Mostrar los datos
	printf("Punto 1: (%d, %d)\n", p1.x, p1.y);
	printf("Punto 2: (%d, %d)\n", p2.x, p2.y);
	
	// Sumar coordenadas
	struct Punto suma;
	suma.x = p1.x + p2.x;
	suma.y = p1.y + p2.y;
	printf("Suma de puntos: (%d, %d)\n", suma.x, suma.y);
	
	return 0;
}
