#include <stdio.h>
#include <string.h>  // Para usar strlen, strcat, strcmp
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

int main() {
	tCadena frase1, frase2, resultado;
	int i;
	
	// Leer primera cadena
	printf("Ingrese la primera frase: ");
	leeCad(frase1, TM);
	
	// Leer segunda cadena
	printf("Ingrese la segunda frase: ");
	leeCad(frase2, TM);
	
	// Mostrar ambas cadenas
	printf("\nFrase 1: %s\n", frase1);
	printf("Frase 2: %s\n", frase2);
	
	// Longitud de la primera cadena
	printf("Longitud de la primera frase: %lu\n", strlen(frase1));
	
	// Concatenar ambas cadenas en resultado
	strcpy(resultado, frase1);   // copiar frase1 a resultado
	strcat(resultado, " ");       // agregar un espacio
	strcat(resultado, frase2);   // agregar frase2
	printf("Concatenación: %s\n", resultado);
	
	// Comparar cadenas
	if(strcmp(frase1, frase2) == 0) {
		printf("Las frases son iguales\n");
	} else {
		printf("Las frases son diferentes\n");
	}
	
	// Mostrar carácter por carácter de la concatenación
	printf("Mostrando caracteres de la concatenación:\n");
	for(i = 0; resultado[i] != '\0'; i++) {
		printf("%c ", resultado[i]);
	}
	printf("\n");
	
	return 0;
}
