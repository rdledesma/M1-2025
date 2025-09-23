#include <stdio.h>

//Es una colección finita de elementos del mismo tipo de dato,
// almacenados en posiciones contiguas de memoria.
//Por definicion los vectores deben ser entonces finitos, indizados y homogeneos


//la definición general de un vector es 
//tipo nombre[tamaño];

int main() {
	int A[6]; 
	char C[7];
	int i;
	
	
	//Cargar A manualmente
	A[0] = 3; 
	A[1] = -5; 
	A[2] = 2; 
	A[3] = 0; 
	A[4] = 7; 
	A[5] = -2;
	
	
	for(i=0; i<=5; i++){
		printf("%d ", A[i]); 
	}
	
	
	A[6] = 22; //Esto no da error, pero no está permitido, 
	           //Al usar A[6], estás accediendo a una posición 
				//que no existe dentro del arreglo, 
				//esto se llama acceso fuera de rango (out of bounds).
	
	printf("%d ", A[6]); 
	
	// Pausa hasta presionar ENTER
	printf("\nPresiona ENTER para continuar...");
	getchar();  // espera un Enter
	
	// Cargar C manualmente
	C[0] = 'a'; 
	C[1] = 'e'; 
	C[2] = 'i'; 
	C[3] = 'o'; 
	C[4] = 'u'; 
	C[5] = 'b'; 
	C[6] = 'c';
	
	
	//Veamos un ejemplo donde solo quiero recorrer por posiciones pares 
	for(i=0; i<=6; i=i+2){
		printf("%c ", C[i]); 
	}
	
	
	
	
	return 0;
}
