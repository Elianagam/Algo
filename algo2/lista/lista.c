#include "lista.h"
#include <stdlib.h>

struct nodo {
	void* dato;
	struct nodo* prox;
}typedef nodo_t;

struct lista {
    nodo_t* primero;
    nodo_t* ultimo;
    size_t cantidad;
};

struct lista_iter {
	lista_t* lista;
	nodo_t* actual;
	nodo_t* anterior;
};

nodo_t* crear_nodo(void *dato){
	nodo_t* nodo = malloc(sizeof(nodo_t));
	if (nodo == NULL) return NULL;
	nodo->dato = dato;
	nodo->prox = NULL;
	return nodo;
}

lista_t *lista_crear(void){
	lista_t* lista = malloc(sizeof(lista_t));
	if (lista ==  NULL) return NULL;
	lista->primero = NULL;
	lista->ultimo = NULL;
	lista->cantidad = 0;
	return lista;
}

bool lista_esta_vacia(const lista_t *lista){
	return lista->primero == NULL;
}

bool lista_insertar_primero(lista_t *lista, void *dato){
	nodo_t* nodo = crear_nodo(dato);
	if (!nodo) return false;
	if (lista_esta_vacia(lista)) lista->ultimo = nodo;
	else nodo->prox = lista->primero;
	
	lista->primero = nodo;
	lista->cantidad++;
	return true;
}

bool lista_insertar_ultimo(lista_t *lista, void *dato){
	nodo_t* nodo = crear_nodo(dato);
	if (!nodo) return false;
	if (lista_esta_vacia(lista)) lista->primero = nodo;
	else lista->ultimo->prox = nodo;
	
	lista->ultimo = nodo;
	lista->cantidad++;
	return true;
}

void *lista_borrar_primero(lista_t *lista){
	if (lista_esta_vacia(lista)) return NULL;
	nodo_t* nodo_prim = lista->primero;
	void* dato = nodo_prim->dato;
	
	if (lista->primero == lista->ultimo){
		lista->primero = NULL;
		lista->ultimo = NULL;
	}
	else lista->primero = nodo_prim->prox;
	
	free(nodo_prim);
	lista->cantidad--;
	return dato;
}

void *lista_ver_primero(const lista_t *lista){
	if (lista_esta_vacia(lista)) return NULL;
	return lista->primero->dato;
}

void *lista_ver_ultimo(const lista_t* lista){
	if (lista_esta_vacia(lista)) return NULL;
	return lista->ultimo->dato;
}

size_t lista_largo(const lista_t *lista){
	return lista->cantidad;
}

void lista_destruir(lista_t *lista, void (*destruir_dato)(void *)){
	while(! lista_esta_vacia(lista)){
		void* dato = lista_borrar_primero(lista);
		if (destruir_dato != NULL) destruir_dato(dato);
	}
	free(lista);
}

//*****************ITER PRIMITIVAS*********************
lista_iter_t *lista_iter_crear(lista_t *lista){
	lista_iter_t* iter = malloc(sizeof(lista_iter_t));
	if (iter == NULL) return NULL;
	iter->lista = lista;
	iter->actual = lista->primero;
	iter->anterior = NULL;
	return iter;
}

bool lista_iter_al_final(const lista_iter_t *iter){
	return iter->actual == NULL;	
}

bool lista_iter_avanzar(lista_iter_t *iter){
	if (lista_iter_al_final(iter)) return false;
	nodo_t* actual = iter->actual;
	iter->actual = actual->prox;
	iter->anterior = actual;
	return true;
}
	
void *lista_iter_ver_actual(const lista_iter_t *iter){
	if (lista_iter_al_final(iter)) return NULL;
	return iter->actual->dato;
}

void lista_iter_destruir(lista_iter_t *iter){
	free(iter);
}

bool lista_iter_insertar(lista_iter_t *iter, void *dato){
	//insertar primero o vacio
	if (lista_esta_vacia(iter->lista) || iter->actual == iter->lista->primero){
		lista_insertar_primero(iter->lista, dato);
		iter->actual = iter->lista->primero;
		return true;
	}
	// insertar final
	if (lista_iter_al_final(iter)){
		lista_insertar_ultimo(iter->lista,dato);
		iter->actual = iter->lista->ultimo;
		return true;
	}
	//insertar medio
	nodo_t* nodo = crear_nodo(dato);
	nodo->prox = iter->actual;
	iter->actual = nodo;
	iter->anterior->prox = nodo;
	iter->lista->cantidad++;
	return true;
}

void *lista_iter_borrar(lista_iter_t *iter){
	if (lista_esta_vacia(iter->lista) || lista_iter_al_final(iter)) return NULL;
	
	if (iter->actual == iter->lista->primero){ 
		void* dato = lista_borrar_primero(iter->lista);
		iter->actual = iter->lista->primero;
		return dato;	
	}
	nodo_t* nodo_borrar = iter->actual;
	void* dato = nodo_borrar->dato;
	iter->anterior->prox = nodo_borrar->prox;
	iter->actual = iter->actual->prox;
	if (iter->lista->cantidad == 2) iter->lista->ultimo = iter->lista->primero;
	free(nodo_borrar);
	iter->lista->cantidad--;
	return dato;
}

void lista_iterar(lista_t *lista, bool (*visitar)(void *dato, void *extra), void *extra){
	lista_iter_t* iter = lista_iter_crear(lista);
	while (!lista_iter_al_final(iter)){
		void* dato = lista_iter_ver_actual(iter);
		if (!visitar(dato,extra)) break;
		lista_iter_avanzar(iter);
	}
	lista_iter_destruir(iter);
}
