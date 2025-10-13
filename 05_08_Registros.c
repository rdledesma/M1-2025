#include <stdio.h>
#define MAX_CAD 100
#define MAX_LIS 50

typedef char tCad[MAX_CAD];

typedef struct {
	long DNI;
	tCad ApeNom;
	int curso;
} Alumno;

typedef struct {
	Alumno list[MAX_LIS];
	int n;
} Alumnos;

void limpiarBuffer(void);
void leeCad(tCad cad, int n);
Alumno creaUno(void);
void muestraUno(Alumno a);


Alumnos inicializaLista();
void muestraLista();
void agregaUno(Alumnos* , Alumno);
void cargaLista(Alumnos * );
void burbuja(Alumnos *l);

int main(void) {
	Alumnos lis;
	Alumno aux;
	
	
	aux = creaUno();
	muestraUno(aux);
	
	lis = inicializaLista();
	
	agregaUno(&lis, aux); 	 
	agregaUno(&lis, creaUno()); 	 

	muestraLista(lis);

	
	cargaLista(&lis);
	burbuja(&lis);
	muestraLista(lis);
	
	return 0;
}

void limpiarBuffer(void) {
	int c;
	while ((c = getchar()) != '\n' && c != EOF);
}

void leeCad(tCad cad, int n) {
	int i = 0;
	char c;
	while ((c = getchar()) != '\n' && c != EOF && i < n - 1) {
		cad[i++] = c;
	}
	cad[i] = '\0';
}

Alumno creaUno(void) {
	Alumno nue;
	
	
	printf("\nIngrese Apellido y Nombre: ");
	leeCad(nue.ApeNom, MAX_CAD);
	
	
	printf("\nIngrese DNI: ");
	scanf("%ld", &nue.DNI);
	limpiarBuffer();  
	
	printf("\nIngrese curso \n[1] Folclore \n[2] Español \n[3] Contemporáneo: ");
	scanf("%d", &nue.curso);
	limpiarBuffer();  // limpiar buffer ANTES de leer texto
	
	return nue;
}

void muestraUno(Alumno a) {
	printf("\nDNI: %ld\n", a.DNI);
	printf("Nombre: %s\n", a.ApeNom);
	printf("Curso: %d\n", a.curso);
}




Alumnos inicializaLista(){
	Alumnos l;
	l.n = 0;
	return l;
}

void muestraLista(Alumnos l){
	int i;
	
	
	if(l.n){
		for(i=0; i<l.n; i++){
			muestraUno(l.list[i]);
		}
	}
	else{
		printf("\nlista vacia");
	}
}

	
void agregaUno(Alumnos *l, Alumno nuevo){
	if (l->n < MAX_LIS) {
		l->list[l->n] = nuevo;
		l->n++;
	} else {
		printf("\nNo se pudo agregar: la lista está llena.\n");
	}
}
	
	
// Permite cargar varios alumnos (usa agregaUno)
void cargaLista(Alumnos *l) {
	int seguir;
	Alumno aux;
	
	seguir = 1;
	while (seguir && l->n < MAX_LIS) {
		aux = creaUno();
		agregaUno(l, aux);
		
		printf("\n¿Desea agregar otro alumno? (1=Sí / 0=No): ");
		scanf("%d", &seguir);
		limpiarBuffer();
	}
}
	
// Ordena la lista por DNI usando el método burbuja
void burbuja(Alumnos *l) {
	int i, j;
	Alumno aux;
	
	for (i = 0; i < l->n - 1; i++) {
		for (j = 0; j < l->n - i - 1; j++) {
			if (l->list[j].DNI > l->list[j + 1].DNI) {
				aux = l->list[j];
				l->list[j] = l->list[j + 1];
				l->list[j + 1] = aux;
			}
		}
	}
}
