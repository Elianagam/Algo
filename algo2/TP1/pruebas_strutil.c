#include "strutil.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void pruebas_comun(){
	char str[] = "Pruebas,de,SPLIT,Y,JOIN";
	printf ("\nFrase de prueba: %s\n", str);
	clock_t ini = clock();
	char** arreglo = split(str,',');
	clock_t fin = clock();
	printf("\ntiempo: %f seg\n", (double)(fin - ini)/CLOCKS_PER_SEC);
	
	ini = clock();
	char* str2 = join(arreglo,',');
	fin = clock();
	printf("\ntiempo: %f seg\n", (double)(fin - ini)/CLOCKS_PER_SEC);
	free(str2);
	free_strv(arreglo);
}

void pruebas_vacio(){
	char str[] = " , ";
	printf ("\nFrase de prueba1: '%s'\n", str);
	char** arreglo = split(str,',');
	
	char* str2 = join(arreglo,',');
	free(str2);
	free_strv(arreglo);
}

void pruebas_vacio_medio(){
	char str[] = "abc,,def";
	printf ("\nFrase de prueba1: %s\n", str);
	char** arreglo = split(str,',');
	char* str2 = join(arreglo,'-');
	
	free(str2);
	free_strv(arreglo);
	
	char str3[] = ",,abc,def";
	printf ("\nFrase de prueba2: %s\n", str3);
	char** arreglo2 = split(str3,',');
	char* str4 = join(arreglo2,'-');
	
	free(str4);
	free_strv(arreglo2);
	
	char str5[] = "abc,def,,";
	printf ("\nFrase de prueba2: %s\n", str5);
	char** arreglo3 = split(str5,',');
	char* str6 = join(arreglo3,'-');
	
	free(str6);
	free_strv(arreglo3);
}

void pruebas_cadana_separador(){
	char str[] = "/";
	printf ("\nFrase de prueba: %s\n", str);
	char** arreglo = split(str,'/');
	
	char* str2 = join(arreglo,'/');
	free(str2);
	free_strv(arreglo);
}


int main(){
	pruebas_comun();
	pruebas_vacio();
	pruebas_vacio_medio();
	pruebas_cadana_separador();
	return 0;
}
