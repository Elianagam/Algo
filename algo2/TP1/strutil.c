#include "strutil.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


char** split(const char* str, char sep){
	if (sep == '\0') return NULL;
	size_t cont = 0, i = 0;
	size_t largo = strlen(str);
	
	while( i < largo ){
		if (str[i] == sep) cont++;
		i++;
	}
	cont++;
	//printf("cantidad de cadenas %zu  \n", cont);
	char** arreglo = malloc(sizeof(char*) * (cont + 1));
	if (! arreglo ) return NULL;

	int j = 0, len = 0;
	int c = 0;
    while ( j < cont){
		if ( str[c] == sep || str[c] == '\0'){ 
			arreglo[j] = malloc( sizeof(char) * (len + 1));
			if (arreglo[j] == NULL) return NULL;
			j++;
			len = 0;
		}
		c++;
		len++;
	}
	int caracter = 0, x = 0, fin = 0;
	while ( x < cont){
		while (str[caracter] != sep && str[caracter] != '\0') {
			arreglo[x][fin] = str[caracter];
			caracter++;
			fin++;
		}
		arreglo[x][fin] = '\0';
		//printf("\n%s", arreglo[x]);
		caracter++;
		fin = 0;
		x++;
	}
	
	arreglo[cont] = NULL;
	return arreglo;
}

char* join(char** strv, char sep){
	size_t i = 0;
	size_t largo = 0;
	while( strv[i] != NULL ){
		largo += strlen(strv[i]);
		i++;
	}
	size_t fin = largo + i +1;
	//printf("\nlargo de la cadena %zu", fin);
	char* str = malloc(sizeof(char) * fin);
	if (! strv ) return NULL;
	
	size_t cant = 0, c = 0;
	for (int j = 0; j < i; j++){
		while ( strv[j][c] != '\0' ){
			str[cant] = strv[j][c];
			c++;
			cant++;
		}
		str[cant] = sep;
		cant++;
		c = 0;
	}
	if (fin == 1) str[fin -1] = '\0';
	else str[fin -2] = '\0'; 
	//printf("join: %s", str);
	return str;
	
}

void free_strv(char* strv[]){
	int i = 0;
	while (strv[i]){
		free(strv[i]);
		i++;
	}
	free(strv);
}
