#ifndef PERSONA_H
#define PERSONA_H
#include "cadena.h"

typedef struct{
	cadena nombre;
	int edad;
	long DNI;
}Persona;


Persona crearPersona();
void mostrarPersona(Persona);

int comparaEdad(Persona, Persona);
int comparaDNI(Persona, Persona);
#endif
