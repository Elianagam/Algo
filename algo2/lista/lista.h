#ifndef LISTA_H
#define LISTA_H

#include <stdlib.h>
#include <stdbool.h>

struct lista;
typedef struct lista lista_t;

struct lista_iter;
typedef struct lista_iter lista_iter_t;

//******************PRIMITIVAS DE LISTA******************


// Crea una lista.
// Post: devuelve una nueva lista vacía.
lista_t *lista_crear(void);

// Devuelve verdadero o falso, según si la lista tiene o no elementos encolados.
// Pre: la lista fue creada.
bool lista_esta_vacia(const lista_t *lista);

// Agrega un nuevo elemento a la lista. Devuelve falso en caso de error.
// Pre: la lista fue creada.
// Post: se agregó un nuevo elemento al comienzo de la lista.
bool lista_insertar_primero(lista_t *lista, void *dato);

// Agrega un nuevo elemento a la lista. Devuelve falso en caso de error.
// Pre: la lista fue creada.
// Post: se agregó un nuevo elemento al final de la lista.
bool lista_insertar_ultimo(lista_t *lista, void *dato);

// Saca el primer elemento de la lista y se devuelve su valor, si está vacía, devuelve NULL.
// Pre: la lista fue creada.
// Post: se devolvió el valor del primer elemento, la lista contiene un elemento menos.
void *lista_borrar_primero(lista_t *lista);

// Obtiene el valor del primer elemento de la lista, si está vacía devuelve NULL.
// Pre: la lista fue creada.
// Post: se devolvió el primer elemento de la lista, cuando no está vacía.
void *lista_ver_primero(const lista_t *lista);

// Obtiene el valor del ultimo elemento de la lista, si está vacía devuelve NULL.
// Pre: la lista fue creada.
// Post: se devolvió el ultimo elemento de la lista, cuando no está vacía.
void *lista_ver_ultimo(const lista_t* lista);

//Obtiene la cantidad de elementos de la lista.
//Pre: la lista fue creada.
//Post: devolvio el largo de la lista.
size_t lista_largo(const lista_t *lista);

// Destruye la lista. Si se recibe la función destruir_dato por parámetro,
// para cada uno de los elementos de la lista llama a destruir_dato.
// Pre: la lista fue creada. destruir_dato es una función capaz de destruir
// los datos de la lista, o NULL en caso de que no se la utilice.
// Post: se eliminaron todos los elementos de la lista.
void lista_destruir(lista_t *lista, void (*destruir_dato)(void *));

// Realiza pruebas sobre la implementación del alumno.
void pruebas_cola_alumno(void);

//******************PRIMITIVAS DE LISTA******************

// Crea una iterador de la lista.
// Post: devuelve iter con referencia anterior a null y actual al primer
// elemento de la lista.
lista_iter_t *lista_iter_crear(lista_t *lista);

// Avanza al siguiente elemento de la lista.
// Pre: el iter fue creado.
// Post: devuelve true mientras a punte actual a un nodo o 
// false en caso de que este el final y no pueda seguir avanzando.
bool lista_iter_avanzar(lista_iter_t *iter);

// Deveulve el dato del nodo en el que esta parado el puntero actual.
// Pre: el nodo fue creado.
// Post: se devolvio el elemento si no esta vacia o estar refenciado a null.
void *lista_iter_ver_actual(const lista_iter_t *iter);

// Devuelve verdadero o falso en caso de estar al final de la lista.
// Pre: el iterador fue creado.
// Post: devuelve true si esta al final de de la lista.
bool lista_iter_al_final(const lista_iter_t *iter);

// Destruye el iterador.
// Pre: el iterador fue creado.
// Post: el iterador fue destruido.
void lista_iter_destruir(lista_iter_t *iter);

// Agrega elemento en la posicion donde se encuentra actual.
// Pre: el iterador fue creado.
// Post: se agrego un nuevo elemento en la posicion actual.
bool lista_iter_insertar(lista_iter_t *iter, void *dato);

// Borra el elemento actual del iterador.
// Pre: el iterador fue creado.
// Post: se borro el elemnto actual de la lista.
void *lista_iter_borrar(lista_iter_t *iter);

//************ITERADOR INTERNO**************
// Pre: la lista fue creada.
// Post: itera hasta final de la lista, aplicando funcion visitar
void lista_iterar(lista_t *lista, bool (*visitar)(void *dato, void *extra), void *extra);

#endif // LISTA_H
