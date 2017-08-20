#include "filesplit.h"
#include <stdio.h>
#include <stdlib.h>

#define BYTES_NOMBRE 50

FILE* generar_archivo(char* name,int num){
	char* nombre_archivo = malloc(sizeof(char) * BYTES_NOMBRE);
	if (! nombre_archivo ) return NULL;
	sprintf(nombre_archivo,"%s_%04d",name,num);
	
	FILE* arc = fopen(nombre_archivo,"w");
	free(nombre_archivo);
	return arc;
}

void filesplit(char* name,size_t n_bytes){
	FILE* archivo = fopen(name,"r");
	if (!archivo) return;
	char* linea = malloc((n_bytes + 1) * (sizeof(char)));
	if (! linea) return;
	size_t read;
	int num = 1;
	while ((read = fread(linea, sizeof(char), n_bytes, archivo))){
		FILE* archivo_escritura = generar_archivo(name,num);
		if (! archivo_escritura){ 
			fclose(archivo);
			return;
		}
		if (read <= n_bytes) linea[read] = '\0';
		fputs(linea,archivo_escritura);
		fclose(archivo_escritura);
		num++;
	}
	free(linea);
	fclose(archivo);
}

