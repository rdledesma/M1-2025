#ifndef PERSONAS_H
#define PERSONAS_H
#include "Personas.h"
#include "Persona.h"
#define MAX_PER 10


typedef struct{
	Persona lista [MAX_PER];
	int n;
} Personas;


Personas inicializarLista();
void insertarUno(Personas *, Persona);
void insertarMuchos(Personas *);

void ordenarDosCriterios(Personas);
void mostrarPersonas(Personas);



#endif
