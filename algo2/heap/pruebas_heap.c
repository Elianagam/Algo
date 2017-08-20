/*
 * pruebas_alumno.c
 *
 *  Created on: 29 de may. de 2017
 *      Author: algoritmos2
 */
#include "heap.h"
#include "testing.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int intcmp (const void* a, const void* b) {
	int* inta = (int*)a;
	int* intb = (int*)b;
	return *inta - *intb;
}

int comparar_cadenas(const void* a, const void*b){
	return strcmp((char*)a,(char*)b);
}

void pruebas_heap_vacio(void) {
	heap_t* heap = heap_crear(intcmp);
	print_test("Heap creado con exito", heap != NULL);
	if (heap == NULL) return;
	print_test("Cantidad es cero", heap_cantidad(heap) == 0);
	print_test("Heap esta vacio", heap_esta_vacio(heap));
	print_test("Ver maximo es NULL", heap_ver_max(heap) == NULL);
	print_test("Desencolar devuelve NULL", heap_desencolar(heap) == NULL);
	heap_destruir(heap, NULL);
}

void prueba_heap_encolar_cadenas(){
	heap_t* heap = heap_crear(comparar_cadenas);
	char *clave1 = "ZORRO", *clave2 = "CHAU", *clave3 = "EL";
	char *clave4 = "ELLA", *clave5 = "PERRO", *clave6 = "GATO";
	char *clave7 = "FLOR";

	print_test("Prueba heap encolar cadenas clave1", heap_encolar(heap, clave1));
	print_test("Prueba heap encolar cadenas clave3", heap_encolar(heap, clave3));
	print_test("Prueba heap encolar cadenas clave4", heap_encolar(heap, clave4));
	print_test("Prueba heap encolar cadenas clave2", heap_encolar(heap, clave2));
	print_test("Prueba heap encolar cadenas clave5", heap_encolar(heap, clave5));
	print_test("Prueba heap encolar cadenas clave6", heap_encolar(heap, clave6));
	print_test("Prueba heap encolar cadenas clave7", heap_encolar(heap, clave7));
	print_test("Prueba heap la cantidad de elementos es 7", heap_cantidad(heap) == 7);
	print_test("Prueba heap ver max es clave1", heap_ver_max(heap) == clave1);

	heap_destruir(heap,NULL);
}

void pruebas_desencolar_cadenas(){
	heap_t* heap = heap_crear(comparar_cadenas);
	char *clave1 = "ZORRO", *clave2 = "TORTUGA", *clave3 = "PERRO";
	char *clave4 = "MONO", *clave5 = "LEON", *clave6 = "GATO";

	print_test("Prueba heap encolar cadenas clave1", heap_encolar(heap, clave1));
	print_test("Prueba heap encolar cadenas clave3", heap_encolar(heap, clave3));
	print_test("Prueba heap encolar cadenas clave4", heap_encolar(heap, clave4));
	print_test("Prueba heap encolar cadenas clave2", heap_encolar(heap, clave2));
	print_test("Prueba heap encolar cadenas clave5", heap_encolar(heap, clave5));
	print_test("Prueba heap encolar cadenas clave6", heap_encolar(heap, clave6));
	print_test("Prueba heap la cantidad de elementos es 6", heap_cantidad(heap) == 6);
	
	print_test("Prueba heap ver max es clave1", heap_ver_max(heap) == clave1);
	print_test("Prueba heap desencolar cadenas es clave1", heap_desencolar(heap) == clave1);
	print_test("Prueba heap la cantidad de elementos es 4", heap_cantidad(heap) == 5);
	print_test("Prueba heap ver max es clave2", heap_ver_max(heap) == clave2);
	print_test("Prueba heap desencolar cadenas es clave2", heap_desencolar(heap) == clave2);
	print_test("Prueba heap la cantidad de elementos es 4", heap_cantidad(heap) == 4);

	print_test("Prueba heap ver max es clave3", heap_ver_max(heap) == clave3);
	print_test("Prueba heap desencolar cadenas es clave3", heap_desencolar(heap) == clave3);
	print_test("Prueba heap la cantidad de elementos es 3", heap_cantidad(heap) == 3);
	print_test("Prueba heap ver max es clave5", heap_ver_max(heap) == clave5);
	print_test("Prueba heap desencolar cadenas es clave5", heap_desencolar(heap) == clave5);
	print_test("Prueba heap la cantidad de elementos es 2", heap_cantidad(heap) == 2);

	print_test("Prueba heap ver max es clave4", heap_ver_max(heap) == clave4);
	print_test("Prueba heap desencolar cadenas es clave4", heap_desencolar(heap) == clave4);
	print_test("Prueba heap la cantidad de elementos es 1", heap_cantidad(heap) == 1);
	print_test("Prueba heap ver max es clave6", heap_ver_max(heap) == clave6);
	print_test("Prueba heap desencolar cadenas es clave6", heap_desencolar(heap) == clave6);
	print_test("Prueba heap la cantidad de elementos es 0", heap_cantidad(heap) == 0);

	print_test("Prueba heap esta vacio es true", heap_esta_vacio(heap));

	heap_destruir(heap,NULL);
}

void pruebas_free(){
	heap_t* heap = heap_crear(intcmp);
	int* elem;
	for (int i = 0; i < 20; i++){
		elem = malloc(sizeof(int));
		*elem = i;
		heap_encolar(heap, elem);
	}
	print_test("Prueba heap la cantidad de elementos es 20", heap_cantidad(heap) == 20);
	heap_destruir(heap, free);
}

void pruebas_heap_alumno(void) {
	pruebas_heap_vacio();
	prueba_heap_encolar_cadenas();
	pruebas_desencolar_cadenas();
	pruebas_free();
}