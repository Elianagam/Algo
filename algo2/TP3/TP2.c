#include "hash.h"
#include "strutil.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_INICIAL 100

struct tweet{
	char* usuario;
	char* tt;
	size_t cant;
};

size_t hashing1(const char* clave, size_t tam){
	size_t hash = 0;
	int c;
	while (c = *str++){
		hash = (hash << 13) + (hash << 25) - hash + c; 
	}
	return hash % tam;
}

size_t hashing2(const char* clave, size_t tam){
	size_t len = strlen ( clave );
	size_t hash = 0;
	for (int i = 0; i < len; i++)
		hash = hash + str[i];
	return hash % tam;
}

size_t hashing3(const char* clave, size_t tam){
	size_t hash = 5381;
	int c;
	while (c = *str++){
		hash = (hash << 5) + hash + c; 
	}
	return hash % tam;
}

void procesar_tweets(size_t n, size_t k){
	FILE* archivo = fopen("tweet","r");
	if (!archivo) return;
	char* linea = malloc((TAM_INICIAL + 1) * (sizeof(char)));
	if (! linea) return;

	size_t read;
	for (int i = 0; i < n; i++){
		read = fread(linea, sizeof(char), n_bytes, archivo);
		linea[read] = '/0';
		char** arreglo = split(linea, ',');
		// tendria que encolar en un heap el tt con la cantidad de apariciones que tiene
		// despues cuando se lean todas las cadenas devuelve los k tt con mayor cant de aparciones
	}
}

int main(int argc, char* arcgv[]){
	if (argc != 3){
		printf("Numero de argumentos invalidos");
		return -1;
	}
	size_t n = (size_t)atoi(arcgv[1]);
	size_t k = (size_t)atoi(arcgv[2]);
	procesar_tweets(n,k);
	return 0;
}
/*
procesar_tweets: este programa se utilizará para contar los trending topics en un conjunto de tweets, 
leyendo cada línea proveniente de la entrada estándar. Como se sabe que la cantidad de mensajes puede 
ser muy grande, para usarlo se requieren dos parámetros enteros, llamados n y k.

El programa deberá imprimir por salida estándar el histórico de los k TTs aproximados cada n lineas, 
ordenados por ocurrencias. Pueden suponer que n y k serán valores tales que se pueda almacenar en 
memoria esa cantidad de cadenas o estructuras auxiliares.

El tiempo de procesamiento de cada tag debe ser O(1), mientras que la impresión de los k TT debe 
realizarse en O(n log k).


Recomendamos crear un TDA CountingFilters, para lograr que el código quede modularizado.

procesar_usuarios: este programa tendrá como objetivo contar la cantidad de hashtags que usa cada usuario,
 leyendo cada línea del archivo pasado por parámetro. Como se sabe que la cantidad de usuarios es mucho
  menor a la cantidad de TTs, y que dicho archivo termina, consideramos que se puede almacenar en memoria 
  todo lo necesario para procesar la entrada.

El programa deberá procesar la entrada y luego deberá escribir por salida estándar los usuarios y la cantidad
 de hashtags que utilizaron en tiempo lineal: O(u + t) siendo u la cantidad de usuarios encontrados y t la cantidad 
 de hashtags diferentes, ordenados según ocurrencias. Los usuarios que tienen la misma cantidad de hashtags 
 pueden ser impresos en cualquier orden.
*/
