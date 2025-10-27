#include <stdio.h>
#include "Personas.h"


int main(){
	Personas lista;
	
	
	lista = inicializarLista();
	
	insertarMuchos(&lista);
	
	ordenarDosCriterios(lista);
	
	mostrarPersonas(lista);
	return 0;
}
