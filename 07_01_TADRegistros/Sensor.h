#ifndef PERSONA_H
#define PERSONA_H


typedef struct{
	
}Sensor;

Sensor crearSensor();
void mostrarSensor(Sensor);
int compararSensor(Sensor, Sensor);
int estaEncendido(Sensor);
void actualizaSensor(Sensor *);
#endif
