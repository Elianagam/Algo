#include "abb.h"
#include "pila.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct abb_nodo{
	void* dato;
	char* clave;
	struct abb_nodo* padre;
	struct abb_nodo* izq;
	struct abb_nodo* der;
}typedef abb_nodo_t;

struct abb{
	abb_nodo_t* raiz;
	size_t cant;
	abb_comparar_clave_t cmp;
	abb_destruir_dato_t funcion_destruir;
};

struct abb_iter{
	pila_t* pila;
};

// FUNCIONES AUXILIARES ----------------------------------------------------------------------------------------
abb_nodo_t* buscar_dato(abb_nodo_t* nodo, const char* clave, abb_comparar_clave_t cmp){
	if (! nodo ) return NULL;
	
	int comp = cmp( nodo->clave, clave);
	if ( comp == 0) return nodo;
	if ( comp > 0) return buscar_dato( nodo->izq, clave, cmp);
	else return buscar_dato( nodo->der, clave, cmp);
}

abb_nodo_t* buscar_mayor(abb_nodo_t* nodo){
	// busco mayor siempre a la derecha
	while ( nodo->der != NULL ) {
		nodo = nodo->der;
	}
	return nodo;
}

abb_nodo_t* buscar_menor(abb_nodo_t* nodo){
	// busco menor siempre a la izquierda
	while ( nodo->izq != NULL ) {
		nodo = nodo->izq;
	}
	return nodo;
}

// PRIMITIVAS DEL ARBOL ----------------------------------------------------------------------------------------
abb_t* abb_crear(abb_comparar_clave_t cmp, abb_destruir_dato_t destruir_dato){
	abb_t* arbol = malloc( sizeof( abb_t ));
	if (! arbol ) return NULL;
	arbol->cant = 0;
	arbol->cmp = cmp;
	arbol->funcion_destruir = destruir_dato;
	arbol->raiz = NULL;
	return arbol;
}

void *abb_obtener(const abb_t *arbol, const char *clave){
	if (! arbol ) return NULL;
	abb_nodo_t* nodo = buscar_dato( arbol->raiz, clave, arbol->cmp);
	if (! nodo ) return NULL;
	return nodo->dato;
}

bool abb_pertenece(const abb_t *arbol, const char *clave){
	if (! arbol ) return NULL;
	abb_nodo_t* nodo = buscar_dato( arbol->raiz, clave, arbol->cmp);
	return nodo != NULL;
}

size_t abb_cantidad(abb_t *arbol){
	if (! arbol ) return 0;
	return arbol->cant;
}
// GUARDAR -----------------------------------------------------------------------------------------------------

char* crear_clave_aux(const char* clave){
	char* clave_aux = malloc( sizeof(char) * (strlen( clave ) + 1));
	strcpy(clave_aux, clave);
	return clave_aux;
}

abb_nodo_t* crear_nodo( const char *clave, void *dato){
	abb_nodo_t* nodo = malloc( sizeof( abb_nodo_t ));
	if (! nodo ) return NULL;
	
	char* clave_aux = crear_clave_aux( clave );
	if ( clave_aux == NULL ){
		free( nodo );
		return NULL;
	}
	nodo->dato = dato;
	nodo->clave = clave_aux;
	nodo->izq = NULL;
	nodo->der = NULL;
	return nodo;
}

bool abb_guardar_aux(abb_t* arbol, abb_nodo_t *nodo, abb_nodo_t* nuevo){
	bool guardado = false;
	if ( nodo == NULL ){
		nodo = nuevo;
		arbol->cant++;
		return true;
	}
	int comp = arbol->cmp(nodo->clave, nuevo->clave);
	if ( comp == 0){ 
		if ( arbol->funcion_destruir ){
			arbol->funcion_destruir(nodo->dato);
		}
		nodo->dato = nuevo->dato;
		free ( nuevo->clave );
		free ( nuevo );
		return true;
	}
	else if ( comp > 0){
		if ( !nodo->izq ){
			nodo->izq = nuevo;
			arbol->cant++;
			return true;
		}
		return abb_guardar_aux(arbol, nodo->izq, nuevo); 
	}
	else if ( comp < 0){
		if (! nodo->der ){
			nodo->der = nuevo;
			arbol->cant++;
			return true;
		}
		return abb_guardar_aux(arbol, nodo->der, nuevo);
	}
	return guardado;
}

bool abb_guardar(abb_t *arbol, const char *clave, void *dato){
	if (! arbol) return false;
	abb_nodo_t* nuevo = crear_nodo(clave,dato); 
	if (! nuevo ) return false;
	if ( !arbol->raiz ){
		arbol->raiz = nuevo;
		arbol->cant++;
		return true;
	}
	return abb_guardar_aux( arbol, arbol->raiz, nuevo);

}

// BORRAR-------------------------------------------------------------------------------------------------
void* destruir_nodo(abb_nodo_t* nodo){
	if (! nodo ) return NULL;
	void* dato = nodo->dato;
	free( nodo->clave );
	free( nodo );
	return dato;
}

void* borrar_sin_hijos(abb_t* arbol, abb_nodo_t* nodo, abb_nodo_t* padre){
	if ( padre == NULL ) arbol->raiz = NULL;
	else if ( arbol->cmp(nodo->clave, padre->clave) < 0 )
		padre->izq = NULL;
	else padre->der = NULL; 
	arbol->cant--;
	return destruir_nodo(nodo);
}

void* borrar_un_hijo(abb_t* arbol, abb_nodo_t* nodo, abb_nodo_t* padre){
	if ( nodo->izq && (!nodo->der)){
		if ( ! padre ){ 
			arbol->raiz = nodo->izq;
			nodo->izq->padre = NULL;
		}
		else if ( arbol->cmp(nodo->clave, padre->clave) < 0 ) 
			padre->izq = nodo->izq;
		else padre->der = nodo->izq;
		nodo->izq->padre = padre;
	}
	else if ( nodo->der && (!nodo->izq)){
		if (! padre ){
			arbol->raiz = nodo->der;
			nodo->der->padre = NULL;
		}
		else if ( arbol->cmp( nodo->clave, padre->clave) < 0)
			padre->izq = nodo->der;
		else padre->der = nodo->der;
		nodo->der->padre = padre;
	}
	arbol->cant--;
	return destruir_nodo(nodo);
}
/*
void swap(abb_nodo_t *nodo, abb_nodo_t *aux){
	char* clave_aux = aux->clave;
	void *dato_aux = aux->dato;
	aux->dato = nodo->dato;
	nodo->dato = dato_aux;

	aux->clave = nodo->clave;
	nodo->clave = clave_aux;
}
*/

void* borrar_dos_hijos(abb_t* arbol, abb_nodo_t* nodo, abb_nodo_t* padre){
	//void* dato = nodo->dato;
	abb_nodo_t* aux = buscar_mayor( nodo->izq );
	char* clave_aux = crear_clave_aux( aux->clave );
	void* dato = nodo->dato;
	void* dato_aux = abb_borrar(arbol, clave_aux);
	free (nodo->clave);
	nodo->clave = clave_aux;
	nodo->dato = dato_aux;
	return dato;
	//swap( nodo, aux );
	//return abb_borrar_aux(arbol, aux, aux->padre, clave_aux);
	/*
	if ( !aux->izq && !aux->der ){
		printf("\ntiene 2 hijos, swap, 0 hijo\n");
		borrar_sin_hijos(arbol, aux, aux->padre);
	}
	else if ( (aux->izq && !aux->der ) || (aux->der && !aux->izq ) ){
		printf("\ntiene 2 hijos, swap, 1 hijo\n");
		borrar_un_hijo(arbol, aux, aux->padre);
	}
	*/
}

void* abb_borrar_aux(abb_t* arbol, abb_nodo_t *nodo, abb_nodo_t* padre, const char *clave){
	if (! nodo ) return NULL;
	int comp = arbol->cmp( nodo->clave, clave );
	void* dato = nodo->dato;
	if ( comp == 0 ){
		if ( !nodo->izq && !nodo->der ){
			return borrar_sin_hijos(arbol, nodo, padre);
		}
		else if ( (nodo->izq && !nodo->der ) || (nodo->der && !nodo->izq ) ){
			return borrar_un_hijo(arbol, nodo, padre);
		}
		else if ( nodo->izq && nodo->der ){
			return borrar_dos_hijos(arbol, nodo, padre);	
		}
	}
	else if ( comp > 0 ) return abb_borrar_aux( arbol, nodo->izq, nodo, clave);
	else if ( comp < 0 ) return abb_borrar_aux( arbol, nodo->der, nodo, clave);
	
	return dato;
}

void *abb_borrar(abb_t *arbol, const char *clave){
	if (! arbol ) return NULL;
	if (! abb_pertenece(arbol, clave)) return NULL;
	return abb_borrar_aux(arbol, arbol->raiz, NULL, clave);
}

//  DESTRUIR -------------------------------------------------------------------------------------------------
void abb_destruir_aux(abb_t* arbol, abb_nodo_t* nodo){
	if (! nodo) return;

	abb_destruir_aux( arbol, nodo->izq );
	abb_destruir_aux( arbol, nodo->der );
	void* dato = destruir_nodo( nodo );
	if ( arbol->funcion_destruir )
		arbol->funcion_destruir( dato );
}

void abb_destruir(abb_t *arbol){
	abb_destruir_aux( arbol, arbol->raiz);
	free( arbol );
}
	
// ITERADOR INTERNO ------------------------------------------------------------------------------------------

bool abb_in_order_aux(abb_nodo_t* nodo, bool visitar(const char *, void *, void *), void *extra){
	if (! nodo ) return true;
	
	if (! abb_in_order_aux( nodo->izq, visitar, extra )) return false;
	if (! visitar( nodo->clave, nodo->dato, extra )) return false;
	if (! abb_in_order_aux( nodo->der, visitar, extra )) return false;
	return true;
}

void abb_in_order(abb_t *arbol, bool visitar(const char *, void *, void *), void *extra){
	if (! arbol ) return;
	
	abb_in_order_aux(arbol->raiz, visitar,extra);
}

// ITERRADOR EXTERNO ------------------------------------------------------------------------------------------

void apilar_recursivo(abb_iter_t* iter, abb_nodo_t* nodo){
	if (! nodo ) return;
	pila_apilar(iter->pila, nodo);
	apilar_recursivo(iter, nodo->izq);
}

abb_iter_t *abb_iter_in_crear(const abb_t *arbol){
	if (! arbol) return NULL;
	abb_iter_t* iter = malloc( sizeof ( abb_iter_t ));
	if (! iter ) return NULL;
	iter->pila = pila_crear();
	if (! iter->pila ){
		free ( iter );
		return NULL;
	}
	apilar_recursivo(iter, arbol->raiz);
	return iter;
}

const char *abb_iter_in_ver_actual(const abb_iter_t *iter){
	abb_nodo_t* tope = pila_ver_tope(iter->pila);
	if (! tope ) return NULL;
	return tope->clave;
}

bool abb_iter_in_al_final(const abb_iter_t *iter){
	return pila_esta_vacia(iter->pila);
}

bool abb_iter_in_avanzar(abb_iter_t *iter){
	if ( abb_iter_in_al_final(iter)) return false;
	
	abb_nodo_t* actual = pila_desapilar(iter->pila);
	apilar_recursivo(iter, actual->der);
	return true;
}

void abb_iter_in_destruir(abb_iter_t* iter){
	while ( !pila_esta_vacia(iter->pila) ) {
		pila_desapilar(iter->pila);
	}
	pila_destruir(iter->pila);
	free(iter);
}
