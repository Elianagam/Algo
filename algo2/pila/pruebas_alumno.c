#include "pila.h"
#include "testing.h"
#include <stddef.h>
#include <stdio.h>

#define CAN_PRUEBAS 1000


/* ******************************************************************
 *                   PRUEBAS UNITARIAS ALUMNO
 * *****************************************************************/
void apila_punteros(pila_t* pila){
	int *valor_a; 
	char *valor_b;
	for (int i = 0; i != CAN_PRUEBAS; i++){
		pila_apilar(pila, &valor_a);
	}
	printf("Apilar A x %d   ", CAN_PRUEBAS);
	print_test("",true);
	for (int i = 0; i != CAN_PRUEBAS; i++){
		pila_apilar(pila, &valor_b);
	}
	printf("Apilar B x %d   ", CAN_PRUEBAS);
	print_test("",true);
	print_test("Pila NO esta vacia",! pila_esta_vacia(pila));
	print_test("Ver tope: b       ",pila_ver_tope(pila) == &valor_b); 
	for (int i = 0; i != CAN_PRUEBAS; i++){
		pila_desapilar(pila);
	}
	printf("despilar B x %d   ", CAN_PRUEBAS);
	print_test("",true);
	print_test("Pila NO esta vacia",! pila_esta_vacia(pila));
	print_test("Ver tope: a       ",pila_ver_tope(pila) == &valor_a);
	for (int i = 0; i != CAN_PRUEBAS; i++){
		pila_desapilar(pila);
	}
	printf("despilar A x %d   ", CAN_PRUEBAS);
	print_test("",true);
	print_test("Ver tope          ",pila_ver_tope(pila) == NULL);
	print_test("Pila esta vacia   ",pila_esta_vacia(pila));
}

void apilar_int_char(pila_t* pila){
	int valor_a;
	char valor_b;
	for (int i = 0; i != CAN_PRUEBAS; i++){
		pila_apilar(pila, &valor_a);
	}
	printf("Apilar A x %d   ", CAN_PRUEBAS);
	print_test("",true);
	for (int i = 0; i != CAN_PRUEBAS; i++){
		pila_apilar(pila, &valor_b);
	}
	printf("Apilar B x %d   ", CAN_PRUEBAS);
	print_test("",true);
	print_test("Pila NO esta vacia",! pila_esta_vacia(pila));
	print_test("Ver tope: b       ",pila_ver_tope(pila) == &valor_b); 
	for (int i = 0; i != CAN_PRUEBAS; i++){
		pila_desapilar(pila);
	}
	printf("despilar B x %d   ", CAN_PRUEBAS);
	print_test("",true);
	print_test("Pila NO esta vacia",! pila_esta_vacia(pila));
	print_test("Ver tope: a       ",pila_ver_tope(pila) == &valor_a);
	for (int i = 0; i != CAN_PRUEBAS; i++){
		pila_desapilar(pila);
	}
	printf("despilar A x %d   ", CAN_PRUEBAS);
	print_test("",true);
	print_test("Ver tope          ",pila_ver_tope(pila) == NULL);
	print_test("Pila esta vacia   ",pila_esta_vacia(pila));
}

void apilar_cadenas_vectores(pila_t* pila){
	char cadena[10];
	int vector[10];
	print_test("\nApilar cadenas y vectores\nApilar cadena     ",pila_apilar(pila, &cadena));
	print_test("Apilar vector     ",pila_apilar(pila, &vector));

	print_test("Pila NO esta vacia",! pila_esta_vacia(pila));
	print_test("Ver tope: vector  ",pila_ver_tope(pila) == &vector);
	print_test("Desapilar vector  ",pila_desapilar(pila) == &vector);
	
	print_test("Pila NO esta vacia",! pila_esta_vacia(pila));
	print_test("Ver tope: cadena  ",pila_ver_tope(pila) == &cadena); 
	print_test("Desapilar cadena  ",pila_desapilar(pila) == &cadena);
	
	print_test("Ver tope          ",pila_ver_tope(pila) == NULL);
	print_test("Pila esta vacia   ",pila_esta_vacia(pila));
}

void apilar_pila(pila_t* pila){
	pila_t* pila2 = pila_crear();
	
	print_test("\nAPILAR PILAS EN PILAS\nApilar pila2      ",pila_apilar(pila, &pila2));	
	int *valor_a; 
	print_test("APILANDO EN PILA 2\nApilar en pila2: a",pila_apilar(pila2, &valor_a));
	
	print_test("Pila NO esta vacia",! pila_esta_vacia(pila2));
	print_test("Ver tope: pila2   ",pila_ver_tope(pila2) == &valor_a);
	print_test("Desapilar pila2   ",pila_desapilar(pila2) == &valor_a);
	
	print_test("\nPila NO esta vacia",! pila_esta_vacia(pila));
	print_test("Ver tope: pila2   ",pila_ver_tope(pila) == &pila2);
	print_test("Desapilar pila2   ",pila_desapilar(pila) == &pila2);
	
	print_test("Ver tope          ",pila_ver_tope(pila) == NULL);
	print_test("Pila esta vacia   ",pila_esta_vacia(pila));
	
	pila_destruir(pila2);
    print_test("\nPila2 destruida  ", true);
}

void pruebas_pila_alumno() {
    pila_t* ejemplo = NULL;

    print_test("Puntero inicializado a NULL", ejemplo == NULL);

//pruebas alumno
	pila_t* pila = pila_crear();
	print_test("Crear pila vacia  ",pila != NULL);
	print_test("Pila esta vacia   ",pila_esta_vacia(pila));
	print_test("Ver tope          ",pila_ver_tope(pila) == NULL);
	
	apila_punteros(pila);
	apilar_int_char(pila);
	apilar_cadenas_vectores(pila);
	apilar_pila(pila);

	print_test("\nPila esta vacia   ",pila_esta_vacia(pila));
	print_test("Ver tope          ",pila_ver_tope(pila) == NULL);
	print_test("Desapilar vacio   ",pila_desapilar(pila) == NULL);
	
	
	pila_destruir(pila);
    print_test("\nPila destruida  ", true);
	
}
