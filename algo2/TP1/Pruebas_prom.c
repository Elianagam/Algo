#include "prom_movil.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void pruebas_prom_cuadratico(){
	int arreglo1[] = {1,3,12,6,17,9};
	printf("\nPRUEBAS CUADRATICAS\n");
	clock_t ini = clock();
	double* prom1 = obtener_promedio_movil(arreglo1,6,1);
	clock_t fin = clock();
	printf("tiempo: %f seg\n\n", (double)(fin - ini)/CLOCKS_PER_SEC);
	ini = clock();
	free(prom1);
	
	ini = clock();
	double* prom2 = obtener_promedio_movil(arreglo1,6,2);
	fin = clock();
	printf("tiempo2: %f seg\n", (double)(fin - ini)/CLOCKS_PER_SEC);
	free(prom2);
}

void pruebas_prom_lineal(){
	int arreglo1[] = {1,3,12,6,17,9};
	printf("\nPRUEBAS LINEALES\n");
	clock_t ini = clock();
	double* prom1 = promedio_movil_lineal(arreglo1,6,1);
	clock_t fin = clock();
	printf("tiempo1: %f seg\n", (double)(fin - ini)/CLOCKS_PER_SEC);
	free(prom1);
	ini = clock();
	double* prom2 = promedio_movil_lineal(arreglo1,6,2);
	fin = clock();
	printf("tiempo2: %f seg\n", (double)(fin - ini)/CLOCKS_PER_SEC);
	free(prom2);
}

void pruebas_largo(){
	int arreglo1[] = {1,1,2,1,1,2,1,1,2,1,1,2,1,1,2,1,1,2,1,1};
	printf("\nPRUEBAS Largo\n");
	clock_t ini = clock();
	double* prom2 = obtener_promedio_movil(arreglo1,20,5);
	clock_t fin = clock();
	printf("tiempo CUADRATICO: %f seg\n", (double)(fin - ini)/CLOCKS_PER_SEC);
	free(prom2);

	ini = clock();
	double* prom1 = promedio_movil_lineal(arreglo1,20,5);
	fin = clock();
	printf("tiempo LINEAL: %f seg\n", (double)(fin - ini)/CLOCKS_PER_SEC);
	free(prom1);
}

void pruebas_corto(){
	int arreglo1[] = {1,3};
	printf("\nPRUEBAS CORTO\n");
	clock_t ini = clock();
	double* prom1 = promedio_movil_lineal(arreglo1,2,1);
	clock_t fin = clock();
	printf("tiempo LINEAL: %f seg\n", (double)(fin - ini)/CLOCKS_PER_SEC);
	free(prom1);
	ini = clock();
	double* prom2 = obtener_promedio_movil(arreglo1,2,1);
	fin = clock();
	printf("tiempo CUADRATICO: %f seg\n", (double)(fin - ini)/CLOCKS_PER_SEC);
	free(prom2);
}

void pruebas_vol(){
	printf("\nPRUEBAS VOL\n");
	clock_t ini = clock();
	size_t n = 1000, k = 950;
	int arreglo[n];
	for (int i = 0; i < n; i++){
		arreglo[i] = 2;
	}
	double* prom1 = promedio_movil_lineal(arreglo,n,k);
	clock_t fin = clock();
	printf("tiempo LINEAL: %f seg\n", (double)(fin - ini)/CLOCKS_PER_SEC);
	free(prom1);
	
	ini = clock();
	double* prom2 = obtener_promedio_movil(arreglo,n,k);
	fin = clock();
	printf("tiempo CUADRATICO: %f seg\n", (double)(fin - ini)/CLOCKS_PER_SEC);
	free(prom2);
}

int main(){
	pruebas_prom_cuadratico();
	pruebas_prom_lineal();
	pruebas_largo();
	pruebas_corto();
	pruebas_vol();
	return 0;
}
	
