#include <stdio.h>
#include "Sensor.h"


int main(){
	
	Sensor s1, s2;
	
	s1 = crearSensor();
	mostrarSensor(s1);
	
	s2 = crearSensor();
	mostrarSensor(s2);
	
	actualizaSensor(&s1);
	printf("Mostrando s1 actualizado \n");
	mostrarSensor(s1);
	
	
	printf("Indicando si s1 está encendido: %d \n ", estaEncendido(s1));
	
	
	printf("El resultado de la comparacion entre s1 y s2 dice %d",compararSensor(s1, s2));
	
	
		
	return 0;
}
