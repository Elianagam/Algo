#include "cola.h"
#include "testing.h"
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

#define CAN_PRUEBAS 1000

void encolar_punteros_int() {
	cola_t* cola = cola_crear();
	printf("\nENCOLAR PUNETEROS INT\n");
	print_test("Crear cola vacia  ",cola != NULL);
	print_test("Cola esta vacia   ",cola_esta_vacia(cola));
	print_test("Ver primero       ",cola_ver_primero(cola) == NULL);
	int a = 1;
	int *valor_a = &a; 
	//encolo 3 int*
	print_test("Encolar a en cola",cola_encolar(cola, valor_a));
	print_test("Cola NO esta vacia",! cola_esta_vacia(cola));
	print_test("Ver primero: a    ",cola_ver_primero(cola) == valor_a);
	
	print_test("Encolar a en cola",cola_encolar(cola, valor_a));
	print_test("Cola NO esta vacia",! cola_esta_vacia(cola));
	print_test("Ver primero: a    ",cola_ver_primero(cola) == valor_a);
	
	print_test("Encolar a en cola",cola_encolar(cola, valor_a));
	print_test("Cola NO esta vacia",! cola_esta_vacia(cola));
	print_test("Ver primero: a    ",cola_ver_primero(cola) == valor_a);
	//desencolo 3 int*
	print_test("desencolar a de cola", cola_desencolar(cola) == valor_a); 
	print_test("Cola NO esta vacia",! cola_esta_vacia(cola));
	print_test("Ver primero: a    ",cola_ver_primero(cola) == valor_a);
	
	print_test("desencolar a de cola", cola_desencolar(cola) == valor_a); 
	print_test("Cola esta vacia   ",!cola_esta_vacia(cola));
	print_test("Ver primero       ",cola_ver_primero(cola) == valor_a);
	cola_destruir(cola,NULL);
	print_test("Destruir cola", true);
}

void encolar_punteros_char(){
	cola_t* cola = cola_crear();
	printf("\nENCOLAR PUNETEROS CHAR\n");
	print_test("Crear cola vacia  ",cola != NULL);
	print_test("Cola esta vacia   ",cola_esta_vacia(cola));
	print_test("Ver primero       ",cola_ver_primero(cola) == NULL);
	char b = 'b';
	char *valor_b = &b;
	
	print_test("Encolar a en cola",cola_encolar(cola, valor_b));
	print_test("Cola NO esta vacia",! cola_esta_vacia(cola));
	print_test("Ver primero: b    ",cola_ver_primero(cola) == valor_b);
	
	print_test("Encolar a en cola",cola_encolar(cola, valor_b));
	print_test("Cola NO esta vacia",! cola_esta_vacia(cola));
	print_test("Ver primero: b    ",cola_ver_primero(cola) == valor_b);
	
	print_test("desencolar a de cola", cola_desencolar(cola) == valor_b); 
	print_test("Cola NO esta vacia",! cola_esta_vacia(cola));
	print_test("Ver primero: a    ",cola_ver_primero(cola) == valor_b);
	
	print_test("desencolar a de cola", cola_desencolar(cola) == valor_b); 
	print_test("Cola esta vacia   ",cola_esta_vacia(cola));
	print_test("Ver primero       ",cola_ver_primero(cola) == NULL);
	print_test("Desencolar vacio  ",cola_desencolar(cola) == NULL);
	cola_destruir(cola,NULL);
	print_test("Destruir cola", true);
}

void encolar_int() {
	cola_t* cola = cola_crear();
	printf("\nENCOLAR  INT\n");
	print_test("Crear cola vacia  ",cola != NULL);
	print_test("Cola esta vacia   ",cola_esta_vacia(cola));
	print_test("Ver primero       ",cola_ver_primero(cola) == NULL);
	int valor_a = 1; 
	//encolo 3 int
	print_test("Encolar a en cola",cola_encolar(cola, &valor_a));
	print_test("Cola NO esta vacia",! cola_esta_vacia(cola));
	print_test("Ver primero: a    ",cola_ver_primero(cola) == &valor_a);
	
	print_test("Encolar a en cola",cola_encolar(cola, &valor_a));
	print_test("Cola NO esta vacia",! cola_esta_vacia(cola));
	print_test("Ver primero: a    ",cola_ver_primero(cola) == &valor_a);
	
	print_test("Encolar a en cola",cola_encolar(cola, &valor_a));
	print_test("Cola NO esta vacia",! cola_esta_vacia(cola));
	print_test("Ver primero: a    ",cola_ver_primero(cola) == &valor_a);
	//desencolo 2 int
	print_test("desencolar a de cola", cola_desencolar(cola) == &valor_a); 
	print_test("Cola NO esta vacia",! cola_esta_vacia(cola));
	print_test("Ver primero: a    ",cola_ver_primero(cola) == &valor_a);
	
	print_test("desencolar a de cola", cola_desencolar(cola) == &valor_a); 
	print_test("Cola NO esta vacia",! cola_esta_vacia(cola));
	print_test("Ver primero: a    ",cola_ver_primero(cola) == &valor_a);
	//destruyo cola aunque no este vacia
	cola_destruir(cola,NULL);
	print_test("Destruir cola", true);
}

void encolar_char(){
	cola_t* cola = cola_crear();
	printf("\nENCOLAR CHAR \n");
	print_test("Crear cola vacia  ",cola != NULL);
	print_test("Cola esta vacia   ",cola_esta_vacia(cola));
	print_test("Ver primero       ",cola_ver_primero(cola) == NULL);
	char valor_b = 'b';
	print_test("Encolar a en cola",cola_encolar(cola, &valor_b));
	print_test("Cola NO esta vacia",! cola_esta_vacia(cola));
	print_test("Ver primero: b    ",cola_ver_primero(cola) == &valor_b);
	
	print_test("Encolar a en cola",cola_encolar(cola, &valor_b));
	print_test("Cola NO esta vacia",! cola_esta_vacia(cola));
	print_test("Ver primero: b    ",cola_ver_primero(cola) == &valor_b);
	
	print_test("desencolar a de cola", cola_desencolar(cola) == &valor_b); 
	print_test("Cola NO esta vacia",! cola_esta_vacia(cola));
	print_test("Ver primero: a    ",cola_ver_primero(cola) == &valor_b);
	
	print_test("desencolar a de cola", cola_desencolar(cola) == &valor_b); 
	print_test("Cola esta vacia   ",cola_esta_vacia(cola));
	print_test("Ver primero       ",cola_ver_primero(cola) == NULL);
	print_test("Desencolar vacio  ",cola_desencolar(cola) == NULL);
	cola_destruir(cola,NULL);
	print_test("Destruir cola", true);
}

void pruebas_volumen(){
	cola_t* cola = cola_crear();
	printf("\nPRUEBAS VOLUMEN\n");
	print_test("Crear cola vacia  ",cola != NULL);
	print_test("Cola esta vacia   ",cola_esta_vacia(cola));
	print_test("Ver primero       ",cola_ver_primero(cola) == NULL);
	int valor_a = 1;
	for (int i = 0; i != CAN_PRUEBAS; i++){
		cola_encolar(cola, &valor_a);
	}
	printf("\nencolar elemento A x %d\n", CAN_PRUEBAS);
	print_test("Cola NO esta vacia",! cola_esta_vacia(cola));
	print_test("Ver primero: a    ",cola_ver_primero(cola) == &valor_a);
	for (int i = 0; i != CAN_PRUEBAS; i++){
		cola_desencolar(cola);
	}
	printf("\ndesencolar elemento A x %d\n", CAN_PRUEBAS);
	print_test("Cola esta vacia   ",cola_esta_vacia(cola));
	print_test("Ver primero       ",cola_ver_primero(cola) == NULL);
	print_test("Desencolar vacio  ",cola_desencolar(cola) == NULL);
	cola_destruir(cola,NULL);
	print_test("Destruir cola", true);
}

void destruir_dato(void* dato){
    cola_destruir((cola_t*) dato, NULL);
}

void encolar_tdas(){
	cola_t* cola1 = cola_crear();
	printf("\nENCOLAR COLAS A COLAS\n");
	print_test("Crear cola1 vacia  ",cola1 != NULL);
	print_test("Cola esta vacia   ",cola_esta_vacia(cola1));
	print_test("Ver primero       ",cola_ver_primero(cola1) == NULL);
	cola_t* cola2 = cola_crear();
	print_test("Crear cola2 vacia  ",cola2 != NULL);
	print_test("Cola esta vacia   ",cola_esta_vacia(cola2));
	print_test("Ver primero       ",cola_ver_primero(cola2) == NULL);
	cola_t* cola3 = cola_crear();
	print_test("Crear cola3 vacia  ",cola3 != NULL);
	print_test("Cola esta vacia   ",cola_esta_vacia(cola3));
	print_test("Ver primero       ",cola_ver_primero(cola3) == NULL);
	
	print_test("Encolar cola1 en cola 2 ",cola_encolar(cola2,cola1));
	print_test("Encolar cola3 en cola 2 ",cola_encolar(cola2,cola3));
	
	print_test("Cola2 NO esta vacia ",! cola_esta_vacia(cola2));
	print_test("Ver primero cola2    ",cola_ver_primero(cola2) == cola1);
	cola_destruir(cola2,destruir_dato);
	print_test("Destruir cola", true);
}

void pruebas_pedir_memoria(){
	cola_t* cola = cola_crear();
	printf("\nENCOLAR PIDIENDO MEMERIA PAARA PUNTEROS INT\n");
	print_test("Crear cola vacia  ",cola != NULL);
	print_test("Cola esta vacia   ",cola_esta_vacia(cola));
	print_test("Ver primero       ",cola_ver_primero(cola) == NULL);
	for (int i = 0; i != CAN_PRUEBAS; i++){
		int* num = malloc(sizeof(int));
		if (num == NULL) return;
		cola_encolar(cola,num);
	}
	int* num = malloc(sizeof(int));
	if (num == NULL) return;
	print_test("encolar NUM a cola", cola_encolar(cola,num));
	print_test("Cola NO esta vacia",! cola_esta_vacia(cola));
	cola_destruir(cola,free);
	print_test("Destruir cola", true);
}
	

void pruebas_cola_alumno() {
	encolar_punteros_int();
	encolar_punteros_char();
	encolar_int();
	encolar_char();
	encolar_tdas();
	pruebas_pedir_memoria();
	pruebas_volumen();
}
