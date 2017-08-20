//#define _POSIX_C_SOURCE 200809L
#include "fixcol.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

void fixcol(char* name, size_t n_bytes){
	FILE* archivo = fopen(name,"r");
	if (!archivo) return;
	char* linea = malloc((n_bytes + 2) * (sizeof(char)));
	if (! linea) return;
	//char* linea = NULL;
	size_t read;
	while ((read = fread(linea, sizeof(char), n_bytes, archivo))){
		linea[read] = '\n';
		linea[read +1] = '\0';
		printf("%s", linea);
	}
	free(linea);
	fclose(archivo);
}
