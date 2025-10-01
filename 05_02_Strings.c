#include <stdio.h>
#define TM 20
typedef char tCadena[TM];


/*

La función leeCad() permite leer una cadena desde el teclado de forma segura,
evitando problemas como:

Desbordes de buffer (escribir más caracteres de los que caben en la variable).

Lectura parcial de frases con espacios (a diferencia de scanf("%s", ...)). */


// función leeCad definida aquí
void leeCad(tCadena cad, int tam) {
	int j; // contador de caracteres
	char c; // variable temporal para leer cada carácter
	j = 0;
	c = getchar();  //lee un caracter desde el teclado
	while (c != EOF && c != '\n' && j < tam - 1) {     //Condiciones: c != EOF no se ha terminado la entrada. c != '\n' 
														//no se ha presionado Enter. 	j < tam - 1 \ evita que se escriba más allá del tamaño del arreglo.
														//Importante: tam - 1 porque necesitamos reservar espacio para el carácter nulo \0 que indica el final de la cadena.
		cad[j] = c;  // guardar el carácter en el arreglo
		j++;
		c = getchar();  //lee un caracter desde el teclado
	}
	cad[j] = '\0';  
	while (c != EOF && c != '\n')   //Si la cadena ingresada es más larga que tam-1, los caracteres sobrantes quedan en el teclado. Este bucle los descarta, evitando que afecten la próxima lectura.
		c = getchar();
}

int main() {
	tCadena frase;
	
	printf("Ingrese una frase: ");
	leeCad(frase, TM);  // leer cadena de forma segura
	
	printf("La frase ingresada es: %s\n", frase);
	
	// mostrar carácter por carácter
	printf("Mostrando caracteres:\n");
	for(int i = 0; frase[i] != '\0'; i++) {
		printf("%c ", frase[i]);
	}
	printf("\n");
	
	return 0;
}
