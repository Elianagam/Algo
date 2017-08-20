#include "lista.h"
#include "testing.h"
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

#define CANT_PRUEBAS 1000

// Pruebas para comprobas que la lista esta vacia
void probar_lista_vacia(lista_t* lista){
	print_test("Lista vacia   ",lista_esta_vacia(lista));
	print_test("Ver primero   ",lista_ver_primero(lista) == NULL);
	print_test("Ver ultimo    ",lista_ver_ultimo(lista) == NULL);
	print_test("Lista largo   ",lista_largo(lista) == 0);	
}

void insertar_primero_int() { 
	printf("\nPRUEBAS INSERTAR PUNTEROS PRIMERO INT\n");
	lista_t* lista = lista_crear();
	print_test("Crear lista vacia  ",lista != NULL);
	probar_lista_vacia(lista);
	int a = 1;
	int *valor_a = &a;
	
	print_test("Insertar primero a", lista_insertar_primero(lista, valor_a));
	print_test("Lista NO vacia",! lista_esta_vacia(lista));
	print_test("Ver primero: a",lista_ver_primero(lista) == valor_a);
	print_test("Ver ultimo: a ",lista_ver_ultimo(lista) == valor_a);
	
	print_test("Insertar primero a", lista_insertar_primero(lista, valor_a));
	print_test("Lista NO vacia",! lista_esta_vacia(lista));
	print_test("Ver primero: a",lista_ver_primero(lista) == valor_a);
	print_test("Ver ultimo: a ",lista_ver_ultimo(lista) == valor_a);
	
	print_test("Insertar primero a", lista_insertar_primero(lista, valor_a));
	print_test("Lista NO vacia",! lista_esta_vacia(lista));
	print_test("Ver primero: a",lista_ver_primero(lista) == valor_a);
	print_test("Ver ultimo: a ",lista_ver_ultimo(lista) == valor_a);
	
	print_test("Borrar primero A", lista_borrar_primero(lista) == valor_a);
	print_test("Lista NO vacia",! lista_esta_vacia(lista));
	print_test("Ver primero: a",lista_ver_primero(lista) == valor_a);
	print_test("Ver ultimo: a ",lista_ver_ultimo(lista) == valor_a);
	
	print_test("Borrar primero A", lista_borrar_primero(lista) == valor_a);
	print_test("Lista NO vacia",! lista_esta_vacia(lista));
	print_test("Ver primero: a",lista_ver_primero(lista) == valor_a);
	print_test("Ver ultimo: a ",lista_ver_ultimo(lista) == valor_a);
	
	print_test("Borrar primero A", lista_borrar_primero(lista) == valor_a);
	probar_lista_vacia(lista);
	lista_destruir(lista,NULL);
}


void insertar_ultimo_char() {
	printf("\nPRUEBAS INSERTAR PUNTEROS ULTIMO CHAR\n");
	lista_t* lista = lista_crear();
	print_test("Crear lista vacia  ",lista != NULL);
	probar_lista_vacia(lista);
	char a = 'c';
	char* valor_a = &a;
	
	print_test("Insertar primero a", lista_insertar_ultimo(lista, valor_a));
	print_test("Lista NO vacia",! lista_esta_vacia(lista));
	print_test("Ver primero: a",lista_ver_primero(lista) == valor_a);
	print_test("Ver ultimo: a ",lista_ver_ultimo(lista) == valor_a);
	
	print_test("Insertar primero a", lista_insertar_ultimo(lista, valor_a));
	print_test("Lista NO vacia",! lista_esta_vacia(lista));
	print_test("Ver primero: a",lista_ver_primero(lista) == valor_a);
	print_test("Ver ultimo: a ",lista_ver_ultimo(lista) == valor_a);
	
	print_test("Insertar primero a", lista_insertar_ultimo(lista, valor_a));
	print_test("Lista NO vacia",! lista_esta_vacia(lista));
	print_test("Ver primero: a",lista_ver_primero(lista) == valor_a);
	print_test("Ver ultimo: a ",lista_ver_ultimo(lista) == valor_a);
	
	print_test("Borrar primero A", lista_borrar_primero(lista) == valor_a);
	print_test("Lista NO vacia",! lista_esta_vacia(lista));
	print_test("Ver primero: a",lista_ver_primero(lista) == valor_a);
	print_test("Ver ultimo: a ",lista_ver_ultimo(lista) == valor_a);
	
	print_test("Borrar primero A", lista_borrar_primero(lista) == valor_a);
	print_test("Lista NO vacia",! lista_esta_vacia(lista));
	print_test("Ver primero: a",lista_ver_primero(lista) == valor_a);
	print_test("Ver ultimo: a ",lista_ver_ultimo(lista) == valor_a);
	
	print_test("Borrar primero A", lista_borrar_primero(lista) == valor_a);
	probar_lista_vacia(lista);
	lista_destruir(lista,NULL);
}

void pruebas_volumen(){
	lista_t* lista = lista_crear();
	print_test("Crear lista vacia  ",lista != NULL);
	probar_lista_vacia(lista);
	int valor_a = 1; 
	char valor_b = 'b';
	printf("\nPRUEBAS VOLUMEN INSERTAR ULTIMO\n");
	for (int i = 0; i != CANT_PRUEBAS; i++){
		lista_insertar_ultimo(lista, &valor_a);
	}
	printf("Insertar ultimo A x %d   ", CANT_PRUEBAS);
	print_test("",true);
	print_test("Lista NO vacia",! lista_esta_vacia(lista));
	print_test("Ver primero: a",lista_ver_primero(lista) == &valor_a);
	print_test("Ver ultimo: a ",lista_ver_ultimo(lista) == &valor_a);
	print_test("Lista largo   ",lista_largo(lista) == CANT_PRUEBAS);
	
	for (int i = 0; i != CANT_PRUEBAS; i++){
		lista_insertar_ultimo(lista, &valor_b);
	}
	printf("Insertar ultimoB x %d   ", CANT_PRUEBAS);
	print_test("",true);
	print_test("Lista NO vacia",! lista_esta_vacia(lista));
	print_test("Ver primero: a",lista_ver_primero(lista) == &valor_a);
	print_test("Ver ultimo: b ",lista_ver_ultimo(lista) == &valor_b);
	print_test("Lista largo   ",lista_largo(lista) == CANT_PRUEBAS * 2);
	
	for (int i = 0; i != CANT_PRUEBAS; i++){
		lista_borrar_primero(lista);
	}
	printf("Borrar primero A x %d   ", CANT_PRUEBAS);
	print_test("",true);
	print_test("Lista NO vacia",! lista_esta_vacia(lista));
	print_test("Ver primero: b",lista_ver_primero(lista) == &valor_b);
	print_test("Ver ultimo: b ",lista_ver_ultimo(lista) == &valor_b);
	print_test("Lista largo   ",lista_largo(lista) == CANT_PRUEBAS);
	for (int i = 0; i != CANT_PRUEBAS; i++){
		lista_borrar_primero(lista);
	}
	printf("Borrar primero B x %d   ", CANT_PRUEBAS);
	print_test("",true);
	probar_lista_vacia(lista);
	probar_lista_vacia(lista);
	lista_destruir(lista,NULL);
}

void destruir_lista(void* dato){
    lista_destruir((lista_t*) dato, NULL);
}

// Insertar lista dentro de listas y llamo a la funcion destruir dato 
void insertar_tdas(){
	printf("\nINSERTAR LISTAS A LISTAS\n");
	lista_t* lista1 = lista_crear();
	print_test("Crear lista1 vacia  ",lista1 != NULL);
	lista_t* lista2 = lista_crear();
	print_test("Crear lista2 vacia  ",lista2 != NULL);
	
	char *valor;
	for (int i = 0; i != CANT_PRUEBAS; i++){
		lista_insertar_primero(lista1, &valor);
	}
	printf("Insertar primero en lista1 x %d   ", CANT_PRUEBAS);
	print_test("",true);
	print_test("lista1 NO esta vacia ",! lista_esta_vacia(lista1));
	print_test("Lista1 largo  ",lista_largo(lista1) == CANT_PRUEBAS);
	
	print_test("insertar prim lista2 EN lista1",lista_insertar_primero(lista2, lista1));
	print_test("lista2 NO esta vacia ",! lista_esta_vacia(lista2));
	print_test("Lista2 largo   ",lista_largo(lista2) == 1);

	lista_destruir(lista2,destruir_lista);
	print_test("Destruir lista1", true);
}
// Pruebas del iterador externo, inserto elementos haciendo avanzar el iterador
// luego creo un nuevo iterador para borrar los elementos insertados
void pruebas_iter(){
	lista_t* lista = lista_crear();
	int* valor1;
	printf("\nPRUEBAS ITER\n");
	lista_iter_t* iter = lista_iter_crear(lista);
	print_test("Crear iter vacio  ",iter != NULL);
	
	lista_iter_insertar(iter,&valor1);
	print_test("valor insertado en vacio", lista_iter_ver_actual(iter) == &valor1);
	print_test("VER ACTUAL V1", lista_iter_ver_actual(iter) == &valor1);
	print_test("Lista NO vacia",! lista_esta_vacia(lista));
	print_test("Ver primero: v1",lista_ver_primero(lista) == &valor1);
	print_test("Ver ultimo: v1 ",lista_ver_ultimo(lista) == &valor1);
	lista_iter_avanzar(iter);
	lista_iter_insertar(iter,&valor1);
	print_test("valor insertado al final", lista_iter_ver_actual(iter) == &valor1);
	print_test("VER ACTUAL V2", lista_iter_ver_actual(iter) == &valor1);
	print_test("Lista NO vacia",! lista_esta_vacia(lista));
	print_test("Ver primero: v1",lista_ver_primero(lista) == &valor1);
	print_test("Ver ultimo: v2 ",lista_ver_ultimo(lista) == &valor1);
	lista_iter_avanzar(iter);
	print_test("Iter al final",lista_iter_al_final(iter));
    lista_iter_destruir(iter);
    
    lista_iter_t* iter_medio = lista_iter_crear(lista);
    print_test("Crear iter_medio vacio  ",iter_medio != NULL);
    print_test("VER ACTUAL V1", lista_iter_ver_actual(iter_medio) == lista_ver_primero(lista));
    lista_iter_avanzar(iter_medio);
    print_test("VER ACTUAL V1", lista_iter_ver_actual(iter_medio) == &valor1);
    
    lista_iter_insertar(iter_medio,&valor1);
	print_test("valor insertado en medio", lista_iter_ver_actual(iter_medio) == &valor1);
	print_test("VER ACTUAL V1", lista_iter_ver_actual(iter_medio) == &valor1);
	lista_iter_avanzar(iter_medio);
    print_test("VER ACTUAL V2", lista_iter_ver_actual(iter_medio) == lista_ver_ultimo(lista));
    lista_iter_avanzar(iter_medio);
	print_test("Iter al final",lista_iter_al_final(iter_medio));
    
    lista_iter_destruir(iter_medio);
   
    lista_iter_t* iter2 = lista_iter_crear(lista);
    print_test("Crear iter2 vacio  ",iter_medio != NULL);
    print_test("VER ACTUAL V1", lista_iter_ver_actual(iter2) == &valor1);
    print_test("Iter al final",!lista_iter_al_final(iter2));
    while(!lista_iter_al_final(iter2)){
		print_test("VER ACTUAL V1", lista_iter_ver_actual(iter2) == &valor1);
		print_test("Iter al final",!lista_iter_al_final(iter2));
		lista_iter_borrar(iter2);
		lista_iter_avanzar(iter2);
		
	}
	lista_iter_destruir(iter2);
	lista_destruir(lista,NULL);
}

// Pruebas pedir memoria para un puntero int que inserto en lista
// luego borro cada elemento y se comprueba que la lista este vacia para destruirla
void pruebas_pedir_memoria(){
	lista_t* lista = lista_crear();
	for (int i = 0; i != CANT_PRUEBAS; i++){
		int* num = malloc(sizeof(int));
		if (num == NULL) return;
		lista_insertar_primero(lista, num);
	}
	print_test("Lista_int largo   ",lista_largo(lista) == CANT_PRUEBAS);
	lista_destruir(lista,free);
}	

//***************************Pruebas ejemplo catredra iter******
bool imprimir_un_item(void *elemento, void *extra){
    // Sabemos que ‘extra’ es un entero, por tanto le podemos hacer un cast.
    int *contador = extra;
    printf("%d. %s\n", ++(*contador), (char*) elemento);
    return true; // seguir iterando
}

void imprimir_iter_interno(lista_t *lista){
    int num_items = 0;
    lista_iterar(lista, imprimir_un_item, &num_items);
    printf("Tengo que comprar %d ítems\n", num_items);
}

void pruebas_super(){
	printf("\nPRUEBAS ITER DE LA CATEDRA\n");
	lista_t *super = lista_crear();
	lista_insertar_ultimo(super, "leche");
	lista_insertar_ultimo(super, "huevos");
	lista_insertar_ultimo(super, "pan");
	lista_insertar_ultimo(super, "mermelada");
	imprimir_iter_interno(super);
    lista_destruir(super, NULL);
}

//************************fin Pruebas ejemplo catredra iter******

void pruebas_lista_alumno() {
	insertar_primero_int();
	insertar_ultimo_char();
	pruebas_volumen();
	insertar_tdas();
	pruebas_pedir_memoria();
	pruebas_iter();
	pruebas_super();
}
