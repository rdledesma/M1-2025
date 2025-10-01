#include <stdio.h>

/*
typedef crea un alias para un tipo de dato existente.

No crea variables, solo un nuevo nombre para un tipo.

Ayuda a que el c�digo sea m�s legible y f�cil de modificar, 
pero ojo, esto tambien puede ser un problema,
por ejemplo a los ojos del debuger esto sigue siendo el dato original
*/


typedef unsigned long int ulong; // ulong ser� un alias de unsigned long int


int main(int argc, char *argv[]) {
	
	ulong edad;  // equivalente a "unsigned long int edad;"
	edad = 25;   // asignaci�n despu�s de declarar
	printf("Edad: %lu\n", edad);
	
	return 0;
	
	
}
	
