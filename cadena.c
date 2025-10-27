#include <stdio.h>
#include "cadena.h"


void leeCad(cadena cad, int tam){
	int j;
	char c;
	j = 0;
	c = getchar();
	while(c!= EOF && c!='\n' && j<tam -1){
		cad[j]= c;
		j++;
		c = getchar();
	}
	
	cad[j]= '\0';
	
	while(c!= EOF && c!='\n'){
		c = getchar();
	}
}


void mostrar(cadena c){
	printf("%s ",c);
}
