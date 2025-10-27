#include <stdio.h>
#include "Persona.h"


Persona crearPersona(){
	Persona nue;
	//getchar(); //ustedes deben usar fflush
	printf("Nombre: ");
	leeCad(nue.nombre, MAX_CAD);
	printf("DNI: ");
	scanf("%ld", &nue.DNI);
	printf("Edad: ");
	scanf("%d", &nue.edad);
	getchar();
	return nue;
		  
}

void mostrarPersona(Persona p){
	mostrar(p.nombre);
	printf("%ld ", p.DNI);
	printf("%d", p.edad);
	
}

int comparaEdad(Persona p1, Persona p2){
	int res;
	
	if (p1.edad == p2.edad)
		res = 0;
	else if (p1.edad > p2.edad)
		res = 1;
	else
		res = -1;
		
	return res;
}

int comparaDNI(Persona p1, Persona p2){
	int res;
	
	if (p1.DNI == p2.DNI)
	res = 0;
	else if (p1.DNI > p2.DNI)
		res = 1;
	else
		res = -1;
	return res;
}
