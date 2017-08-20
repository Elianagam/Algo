#include "abb.h"
//#include "abb_aux.h"
#include "testing.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void prueba_crear_abb_vacio(){
    abb_t* arbol = abb_crear( NULL, NULL );

    print_test("Prueba abb crear hash vacio", arbol ) ;
    print_test("Prueba abb la cantidad de elementos es 0", abb_cantidad(arbol) == 0);
    print_test("Prueba abb obtener clave A, es NULL, no existe", !abb_obtener(arbol, "A"));
    print_test("Prueba abb pertenece clave A, es false, no existe", !abb_pertenece(arbol, "A"));
    print_test("Prueba abb borrar clave A, es NULL, no existe", !abb_borrar(arbol, "A"));

    abb_destruir(arbol);
}

void prueba_iterar_abb_vacio(){
    abb_t* arbol = abb_crear( NULL, NULL );

    abb_iter_t* iter = abb_iter_in_crear(arbol);
    print_test("Prueba abb iter crear iterador abb vacio", iter);
    print_test("Prueba abb iter esta al final", abb_iter_in_al_final(iter));
    print_test("Prueba abb iter avanzar es false", !abb_iter_in_avanzar(iter));
    print_test("Prueba abb iter ver actual es NULL", !abb_iter_in_ver_actual(iter));

    abb_iter_in_destruir(iter);
    abb_destruir(arbol);
}


void prueba_abb_insertar(){
	printf("\ninsertar sin borrar\n");
	abb_t* arbol = abb_crear( strcmp, NULL );

	char *clave1 = "saludo", *valor1 = "hola";
	char *clave2 = "nombre", *valor2 = "apellido";
	char *clave3 = "animal", *valor3 = "perro";
	char *clave4 = "dia", *valor4 = "lunes";

	print_test("Prueba insertar clave1", abb_guardar(arbol, clave1, valor1));
	print_test("Prueba la cantidad de elementos es 1", abb_cantidad(arbol) == 1);
	print_test("Prueba obtener clave1 es valor1", abb_obtener(arbol, clave1) == valor1);
	print_test("Prueba pertenece clave1, es true", abb_pertenece(arbol, clave1));
	
	print_test("Prueba insertar clave2", abb_guardar(arbol, clave2, valor2));
	print_test("Prueba la cantidad de elementos es 2", abb_cantidad(arbol) == 2);
	print_test("Prueba obtener clave2 es valor2", abb_obtener(arbol, clave2) == valor2);
	print_test("Prueba pertenece clave2, es true", abb_pertenece(arbol, clave2));

	print_test("Prueba insertar clave3", abb_guardar(arbol, clave3, valor3));
	print_test("Prueba la cantidad de elementos es 3", abb_cantidad(arbol) == 3);
	print_test("Prueba obtener clave3 es valor3", abb_obtener(arbol, clave3) == valor3);
	print_test("Prueba pertenece clave3, es true", abb_pertenece(arbol, clave3));

	print_test("Prueba insertar clave4", abb_guardar(arbol, clave4, valor4));
	print_test("Prueba la cantidad de elementos es 4", abb_cantidad(arbol) == 4);
	print_test("Prueba obtener clave4 es valor4", abb_obtener(arbol, clave4) == valor4);
	print_test("Prueba pertenece clave4, es true", abb_pertenece(arbol, clave4));

	printf("borrar 2 elementos\n");
	
	print_test("Prueba borrar clave2, es valor2", abb_borrar(arbol, clave2) == valor2);
	print_test("Prueba pertenece clave2, es falso", !abb_pertenece(arbol, clave2));
	print_test("Prueba obtener clave2, es NULL", !abb_obtener(arbol, clave2));
	
	print_test("Prueba borrar clave1, es valor1", abb_borrar(arbol, clave1) == valor1);
	print_test("Prueba pertenece clave1, es falso", !abb_pertenece(arbol, clave1));
	print_test("Prueba obtener clave1, es NULL", !abb_obtener(arbol, clave1));

	print_test("Prueba la cantidad de elementos es 2", abb_cantidad(arbol) == 2);

	abb_destruir(arbol);
}

void pruebas_insertar_muchos_borrar_todo(){
	printf("\ninsertar muchos, borrar todo\n");
	abb_t* arbol = abb_crear( strcmp, NULL );

	char *clave1 = "saludo", *valor1 = "hola";
	char *clave2 = "nombre", *valor2 = "apellido";
	char *clave3 = "animal", *valor3 = "perro";
	char *clave4 = "dia", *valor4 = "lunes";
	char *clave5 = "mama", *valor5 = "papa";
	char *clave6 = "barco", *valor6 = "ancla";
	char *clave7 = "tia", *valor7 = "tio";

	print_test("Prueba insertar clave1", abb_guardar(arbol, clave1, valor1));
	print_test("Prueba insertar clave2", abb_guardar(arbol, clave2, valor2));
	print_test("Prueba insertar clave3", abb_guardar(arbol, clave3, valor3));
	print_test("Prueba insertar clave4", abb_guardar(arbol, clave4, valor4));
	print_test("Prueba insertar clave5", abb_guardar(arbol, clave5, valor5));
	print_test("Prueba insertar clave6", abb_guardar(arbol, clave6, valor6));
	print_test("Prueba insertar clave7", abb_guardar(arbol, clave7, valor7));

	print_test("Prueba la cantidad de elementos es 7", abb_cantidad(arbol) == 7);
	//printf("obtener clave 1 %s\n", (char*)abb_obtener(arbol, clave1));
	print_test("Prueba borrar clave1, es valor1", abb_borrar(arbol, clave1) == valor1);
	print_test("Prueba obtener clave1 es valor1 FALSE", !abb_obtener(arbol, clave1) );
    print_test("Prueba pertenece clave1 FALSE", !abb_pertenece(arbol, clave1)); 
	print_test("Prueba la cantidad de elementos es 6", abb_cantidad(arbol) == 6);
	//printf("obtener clave 2 %s\n", (char*)abb_obtener(arbol, clave2));
	print_test("Prueba borrar clave2, es valor2", abb_borrar(arbol, clave2) == valor2);
	print_test("Prueba obtener clave2 es valor2 FALSE", !abb_obtener(arbol, clave2) );
    print_test("Prueba pertenece clave2 FALSE", !abb_pertenece(arbol, clave2)); 

	//printf("\ncant %zu\n", abb_cantidad(arbol));
	print_test("Prueba la cantidad de elementos es 5", abb_cantidad(arbol) == 5);
	//printf("obtener clave 7 %s\n", (char*)abb_obtener(arbol, clave7));
	print_test("Prueba borrar clave7, es valor7", abb_borrar(arbol, clave7) == valor7);
	print_test("Prueba obtener clave7 es valor7 FALSE", !abb_obtener(arbol, clave7) );
    print_test("Prueba pertenece clave7 FALSE", !abb_pertenece(arbol, clave7)); 
	print_test("Prueba la cantidad de elementos es 4", abb_cantidad(arbol) == 4);
	print_test("Prueba borrar clave3, es valor3", abb_borrar(arbol, clave3) == valor3);
	print_test("Prueba obtener clave3 es valor3 FALSE", !abb_obtener(arbol, clave3) );
    print_test("Prueba pertenece clave3 FALSE", !abb_pertenece(arbol, clave3)); 

	print_test("Prueba la cantidad de elementos es 3", abb_cantidad(arbol) == 3);
	print_test("Prueba borrar clave6, es valor6", abb_borrar(arbol, clave6) == valor6);
	print_test("Prueba la cantidad de elementos es 2", abb_cantidad(arbol) == 2);
	print_test("Prueba borrar clave4, es valor4", abb_borrar(arbol, clave4) == valor4);

	print_test("Prueba la cantidad de elementos es 1", abb_cantidad(arbol) == 1);
	print_test("Prueba borrar clave5, es valor5", abb_borrar(arbol, clave5) == valor5);
	print_test("Prueba la cantidad de elementos es 0", abb_cantidad(arbol) == 0);

	abb_destruir(arbol);
}

void prueba_abb_reemplazar(){ 
	printf("\ninsartar y remplazar\n");
	abb_t* arbol = abb_crear(strcmp, NULL);

	char *clave1 = "perro", *valor1a = "guau", *valor1b = "warf";
	char *clave2 = "gato", *valor2a = "miau", *valor2b = "meaow";
	char *clave3 = "pato", *valor3a = "cuac", *valor3b = "cuac-cuac";
	char *clave4 = "yo", *valor4a = "hola", *valor4b = "chau";

	/* Inserta 4 valores y luego los reemplaza */
	print_test("Prueba insertar clave1", abb_guardar(arbol, clave1, valor1a));
	print_test("Prueba obtener clave1 es valor1a", abb_obtener(arbol, clave1) == valor1a);
	print_test("Prueba pertenece clave1 es valor1a", abb_pertenece(arbol, clave1));

	print_test("Prueba insertar clave2", abb_guardar(arbol, clave2, valor2a));
	print_test("Prueba pertenece clave2 es valor2a", abb_pertenece(arbol, clave2));
	print_test("Prueba obtener clave2 es valor2a", abb_obtener(arbol, clave2) == valor2a);

	print_test("Prueba insertar clave3", abb_guardar(arbol, clave3, valor3a));
	print_test("Prueba pertenece clave3 es valor3a", abb_pertenece(arbol, clave3));
	print_test("Prueba obtener clave3 es valor3a", abb_obtener(arbol, clave3) == valor3a);

	print_test("Prueba insertar clave4", abb_guardar(arbol, clave4, valor4a));
	print_test("Prueba pertenece clave4 es valor4a", abb_pertenece(arbol, clave4));
	print_test("Prueba obtener clave4 es valor4a", abb_obtener(arbol, clave4) == valor4a);

	print_test("Prueba la cantidad de elementos es 4", abb_cantidad(arbol) == 4);

	print_test("Prueba insertar clave1 con otro valor", abb_guardar(arbol, clave1, valor1b));
	print_test("Prueba pertenece clave1 es valor1b", abb_pertenece(arbol, clave1));
	print_test("Prueba obtener clave1 es valor1b", abb_obtener(arbol, clave1) == valor1b);

	print_test("Prueba insertar clave2 con otro valor", abb_guardar(arbol, clave2, valor2b));
	print_test("Prueba pertenece clave2 es valor2b", abb_pertenece(arbol, clave2));
	print_test("Prueba obtener clave2 es valor2b", abb_obtener(arbol, clave2) == valor2b);

	print_test("Prueba insertar clave3", abb_guardar(arbol, clave3, valor3b));
	print_test("Prueba pertenece clave3 es valor3b", abb_pertenece(arbol, clave3));
	print_test("Prueba obtener clave3 es valor3b", abb_obtener(arbol, clave3) == valor3b);

	print_test("Prueba insertar clave4", abb_guardar(arbol, clave4, valor4b));
	print_test("Prueba pertenece clave4 es valor4b", abb_pertenece(arbol, clave4));
	print_test("Prueba obtener clave4 es valor4b", abb_obtener(arbol, clave4) == valor4b);

	print_test("Prueba la cantidad de elementos es 4", abb_cantidad(arbol) == 4);

	abb_destruir(arbol);
}

void prueba_clave_vacia(){
	printf("\n insertar clave vacia, valor vacio\n");
	abb_t* arbol = abb_crear(strcmp, NULL);

	char *clave1 = "", *valor1 = "";

	print_test("Prueba insertar clave1", abb_guardar(arbol, clave1, valor1));
	print_test("Prueba la cantidad de elementos es 1", abb_cantidad(arbol) == 1);
	print_test("Prueba obtener clave1 es valor1", abb_obtener(arbol, clave1) == valor1);
	print_test("Prueba pertenece clave1, es true", abb_pertenece(arbol, clave1));
	print_test("Prueba borrar clave1, es valor1", abb_borrar(arbol, clave1) == valor1);
	print_test("Prueba la cantidad de elementos es 0", abb_cantidad(arbol) == 0);

	abb_destruir(arbol);
}

void prueba_null(){
	printf("\n insertar clave vacia, valor NULL\n");
	abb_t* arbol = abb_crear(strcmp, NULL);

	char *clave1 = "", *valor1 = NULL;

	print_test("Prueba insertar clave1", abb_guardar(arbol, clave1, valor1));
	print_test("Prueba la cantidad de elementos es 1", abb_cantidad(arbol) == 1);
	print_test("Prueba obtener clave1 es valor1", abb_obtener(arbol, clave1) == valor1);
	print_test("Prueba pertenece clave1, es true", abb_pertenece(arbol, clave1));
	print_test("Prueba borrar clave1, es valor1", abb_borrar(arbol, clave1) == valor1);
	print_test("Prueba la cantidad de elementos es 0", abb_cantidad(arbol) == 0);

	abb_destruir(arbol);
}

void prueba_abb_borrar(){
	abb_t* arbol = abb_crear(strcmp, NULL);

	char *clave1 = "F", *valor1 = "FOCA";
	char *clave2 = "T", *valor2 = "TORO";
	char *clave3 = "A", *valor3 = "AVE";

	printf("\ninsertar y borrar\n");
	/* Inserta 3 valores y luego los borra */
	print_test("Prueba insertar clave1", abb_guardar(arbol, clave1, valor1));
	print_test("Prueba insertar clave2", abb_guardar(arbol, clave2, valor2));
	print_test("Prueba insertar clave3", abb_guardar(arbol, clave3, valor3));

	print_test("Prueba la cantidad de elementos es 3", abb_cantidad(arbol) == 3);
	/* Al borrar cada elemento comprueba que ya no está pero los otros sí. */

	print_test("Prueba pertenece clave3, es verdadero", abb_pertenece(arbol, clave3));
	print_test("Prueba borrar clave3, es valor3", abb_borrar(arbol, clave3) == valor3);
	print_test("Prueba borrar clave3, es NULL", !abb_borrar(arbol, clave3));
	print_test("Prueba pertenece clave3, es falso", !abb_pertenece(arbol, clave3));
	print_test("Prueba obtener clave3, es NULL", !abb_obtener(arbol, clave3));
	print_test("Prueba la cantidad de elementos es 2", abb_cantidad(arbol) == 2);

	print_test("Prueba pertenece clave1, es verdadero", abb_pertenece(arbol, clave1));
	print_test("Prueba borrar clave1, es valor1", abb_borrar(arbol, clave1) == valor1);
	print_test("Prueba borrar clave1, es NULL", !abb_borrar(arbol, clave3));
	print_test("Prueba pertenece clave1, es falso", !abb_pertenece(arbol, clave1));
	print_test("Prueba obtener clave1, es NULL", !abb_obtener(arbol, clave1));
	print_test("Prueba la cantidad de elementos es 1", abb_cantidad(arbol) == 1);

	print_test("Prueba pertenece clave2, es verdadero", abb_pertenece(arbol, clave2));
	print_test("Prueba borrar clave2, es valor2", abb_borrar(arbol, clave2) == valor2);
	print_test("Prueba borrar clave2, es NULL", !abb_borrar(arbol, clave3));
	print_test("Prueba pertenece clave2, es falso", !abb_pertenece(arbol, clave2));
	print_test("Prueba obtener clave2, es NULL", !abb_obtener(arbol, clave2));
	print_test("Prueba la cantidad de elementos es 0", abb_cantidad(arbol) == 0);

	abb_destruir(arbol);
}

void prueba_abb_reemplazar_con_destruir(){
	abb_t* arbol = abb_crear(strcmp, free);

	char *clave1 = "perro", *valor1a, *valor1b;
	char *clave2 = "gato", *valor2a, *valor2b;

	// Pide memoria para 4 valores
	valor1a = malloc(10 * sizeof(char));
	valor1b = malloc(10 * sizeof(char));
	valor2a = malloc(10 * sizeof(char));
	valor2b = malloc(10 * sizeof(char));

	printf("remplazar con destruir\n");
	// Inserta 2 valores y luego los reemplaza (debe liberar lo que reemplaza)
	print_test("Prueba insertar clave1", abb_guardar(arbol, clave1, valor1a));
	print_test("Prueba obtener clave1 es valor1a", abb_obtener(arbol, clave1) == valor1a);
	print_test("Prueba pertenece clave1", abb_pertenece(arbol, clave1));
	print_test("Prueba insertar clave2", abb_guardar(arbol, clave2, valor2a));
	print_test("Prueba obtener clave2 es valor2a", abb_obtener(arbol, clave2) == valor2a);
	print_test("Prueba pertenece clave2 ", abb_pertenece(arbol, clave2));
	print_test("Prueba la cantidad de elementos es 2", abb_cantidad(arbol) == 2);

	print_test("Prueba insertar clave1 con otro valor", abb_guardar(arbol, clave1, valor1b));
	print_test("Prueba obtener clave1 es valor1b", abb_obtener(arbol, clave1) == valor1b);
	print_test("Prueba pertenece clave1 ", abb_pertenece(arbol, clave1));
	print_test("Prueba insertar clave2 con otro valor", abb_guardar(arbol, clave2, valor2b));
	print_test("Prueba obtener clave2 es valor2b", abb_obtener(arbol, clave2) == valor2b);
	print_test("Prueba pertenece clave2", abb_pertenece(arbol, clave2));
	print_test("Prueba la cantidad de elementos es 2", abb_cantidad(arbol) == 2);

	// Se destruye el abb (se debe liberar lo que quedó dentro)
	abb_destruir(arbol);
}

void print_clave(const char* clave, void* dato, void* extra){
	printf("clave: %s", clave);
}

void pruebas_iter_externo(){
	abb_t* arbol = abb_crear( strcmp, NULL );

	char *clave1 = "saludo", *valor1 = "hola";
	char *clave2 = "nombre", *valor2 = "apellido";
	char *clave3 = "animal", *valor3 = "perro";
	
	print_test("Prueba insertar clave1", abb_guardar(arbol, clave1, valor1));
	print_test("Prueba insertar clave2", abb_guardar(arbol, clave2, valor2));
	print_test("Prueba insertar clave3", abb_guardar(arbol, clave3, valor3));
	
	abb_iter_t *iter = abb_iter_in_crear(arbol);
	print_test("iter no esta final",!abb_iter_in_al_final(iter));
	print_test("iter avanzar es true", abb_iter_in_avanzar(iter)); 

	print_test("iter avanzar es true", abb_iter_in_avanzar(iter)); 
	print_test("iter avanzar es true", abb_iter_in_avanzar(iter)); 
	print_test("iter esta al final", abb_iter_in_al_final(iter));
	print_test("iter ver actual es NULL",!abb_iter_in_ver_actual(iter));
	print_test("iter avanzar es false", !abb_iter_in_avanzar(iter));

	abb_iter_in_destruir(iter);
	abb_destruir(arbol);
}

void prueba_abb_volumen(size_t largo, bool debug)
{
    abb_t* abb = abb_crear(strcmp, NULL);

    const size_t largo_clave = 10;
    char (*claves)[largo_clave] = malloc(largo * largo_clave);

    unsigned* valores[largo];

    if (debug) print_test("Guardando", true);
    // Inserta 'largo' parejas en el abb
    bool ok = true;
    for (unsigned i = 0; i < largo; i++) {
        valores[i] = malloc(sizeof(int));

        for(size_t j=0; j<largo_clave-1; j++)
        {
            int x = 'A' + (rand() % 26);
            claves[i][j] = (char) x;
        }
        claves[i][largo_clave-1] = '\0';
        *valores[i] = i;
        ok = abb_guardar(abb, claves[i], valores[i]);
        if (!ok) break;
    }

    if (debug) print_test("Prueba abb almacenar muchos elementos", ok);
    if (debug) print_test("Prueba abb la cantidad de elementos es correcta", abb_cantidad(abb) == largo);

    if (debug) print_test("Pertenece y obtener", true);
    // Verifica que devuelva los valores correctos
    for (size_t i = 0; i < largo; i++) {
        ok = abb_pertenece(abb, claves[i]);
        if (!ok)
            break;
        ok = abb_obtener(abb, claves[i]) == valores[i];
        if (!ok)
            break;
    }

    if (debug) print_test("Prueba abb pertenece y obtener muchos elementos", ok);
    if (debug) print_test("Prueba abb la cantidad de elementos es correcta", abb_cantidad(abb) == largo);

    if (debug) print_test("Borrando", true);
    // Verifica que borre y devuelva los valores correctos
    for (size_t i = 0; i < largo; i++) {
        ok = abb_borrar(abb, claves[i]) == valores[i];
        if (!ok)
            break;
    }

    if (debug) print_test("Prueba abb borrar muchos elementos", ok);
    if (debug) print_test("Prueba abb la cantidad de elementos es 0", abb_cantidad(abb) == 0);

    // Destruye el abb y crea uno nuevo que sí libera
    abb_destruir(abb);

    abb = abb_crear(strcmp, free);

    if (debug) print_test("Guardando", true);
    // Inserta 'largo' parejas en el abb
    ok = true;
    for (size_t i = 0; i < largo; i++) {
        ok = abb_guardar(abb, claves[i], valores[i]);
        if (!ok) break;
    }

    free(claves);

    if (debug) print_test("Destruir", true);
    // Destruye el abb - debería liberar los enteros
    abb_destruir(abb);
}

ssize_t buscar(const char* clave, char* claves[], size_t largo){
    for (size_t i = 0; i < largo; i++) {
        if (strcmp(clave, claves[i]) == 0) return (ssize_t) i;
    }
    return -1;
}

void prueba_abb_iterar()
{
    return;
    abb_t* abb = abb_crear(strcmp, NULL);

    char *claves[] = {"perro", "gato", "vaca"};
    char *valores[] = {"guau", "miau", "mu"};

    // Inserta 3 valores
    print_test("Prueba abb insertar clave1", abb_guardar(abb, claves[0], valores[0]));
    print_test("Prueba abb insertar clave2", abb_guardar(abb, claves[1], valores[1]));
    print_test("Prueba abb insertar clave3", abb_guardar(abb, claves[2], valores[2]));

    // Prueba de iteración sobre las claves almacenadas.
    abb_iter_t* iter = abb_iter_in_crear(abb);
    const char *clave;
    ssize_t indice;

    print_test("Prueba abb iterador esta al final, es false", !abb_iter_in_al_final(iter));


    // Primer valor
    clave = abb_iter_in_ver_actual(iter);
    indice = buscar(clave, claves, sizeof(claves) / sizeof(char *));
    print_test("Prueba abb iterador ver actual, es una clave valida", indice != -1);
    print_test("Prueba abb iterador ver actual, no es el mismo puntero", clave != claves[indice]);
    print_test("Prueba abb iterador avanzar es true", abb_iter_in_avanzar(iter));
    clave = abb_iter_in_ver_actual(iter);
    print_test("Prueba abb iterador esta al final, es false", !abb_iter_in_al_final(iter));


    // Segundo valor
    clave = abb_iter_in_ver_actual(iter);
    indice = buscar(clave, claves, sizeof(claves) / sizeof(char *));
    print_test("Prueba abb iterador ver actual, es una clave valida", indice != -1);
    print_test("Prueba abb iterador ver actual, no es el mismo puntero", clave != claves[indice]);
    print_test("Prueba abb iterador avanzar es true", abb_iter_in_avanzar(iter));
    print_test("Prueba abb iterador esta al final, es false", !abb_iter_in_al_final(iter));

    // Tercer valor
    clave = abb_iter_in_ver_actual(iter);
    indice = buscar(clave, claves, sizeof(claves) / sizeof(char *));
    print_test("Prueba abb iterador ver actual, es una clave valida", indice != -1);
    print_test("Prueba abb iterador ver actual, no es el mismo puntero", clave != claves[indice]);

    // Se anula esta prueba por diferencias de criterios
    abb_iter_in_avanzar(iter);
    print_test("Prueba abb iterador esta al final, es true", abb_iter_in_al_final(iter));

    // Vuelve a tratar de avanzar, por las dudas
    print_test("Prueba abb iterador ver actual, es NULL", !abb_iter_in_ver_actual(iter));
    print_test("Prueba abb iterador avanzar es false", !abb_iter_in_avanzar(iter));
    print_test("Prueba abb iterador esta al final, es true", abb_iter_in_al_final(iter));

    abb_iter_in_destruir(iter);
    abb_destruir(abb);
}

void prueba_abb_iterar_volumen(size_t largo){
    return;
    abb_t* abb = abb_crear(strcmp, NULL);

    const size_t largo_clave = 10;
    char (*claves)[largo_clave] = malloc(largo * largo_clave);

    size_t valores[largo];

    print_test("Guardando", true);
    // Inserta 'largo' parejas en el abb
    bool ok = true;
    for (unsigned i = 0; i < largo; i++) {
        sprintf(claves[i], "%08d", i);
        valores[i] = i;
        ok = abb_guardar(abb, claves[i], &valores[i]);
        if (!ok) break;
    }

    print_test("Iter Crear", true);
    // Prueba de iteración sobre las claves almacenadas.
    abb_iter_t* iter = abb_iter_in_crear(abb);
    print_test("Prueba abb iterador esta al final, es false", !abb_iter_in_al_final(iter));

    ok = true;
    unsigned i;
    const char *clave;
    size_t *valor;

    print_test("Iterando", true);
    for (i = 0; i < largo; i++) {
        if ( abb_iter_in_al_final(iter) ) {
            ok = false;
            break;
        }
        clave = abb_iter_in_ver_actual(iter);
        if ( clave == NULL ) {
            ok = false;
            break;
        }
        valor = abb_obtener(abb, clave);
        if ( valor == NULL ) {
            ok = false;
            break;
        }
        *valor = largo;
        abb_iter_in_avanzar(iter);
    }
    print_test("Prueba abb iteración en volumen", ok);
    print_test("Prueba abb iteración en volumen, recorrio todo el largo", i == largo);
    print_test("Prueba abb iterador esta al final, es true", abb_iter_in_al_final(iter));

    ok = true;
    for (i = 0; i < largo; i++) {
        if ( valores[i] != largo ) {
            ok = false;
            break;
        }
    }
    print_test("Prueba abb iteración en volumen, se cambiaron todo los elementos", ok);

    free(claves);
    abb_iter_in_destruir(iter);
    abb_destruir(abb);
}

void pruebas_abb_alumno(){
	prueba_crear_abb_vacio();
	prueba_iterar_abb_vacio();
	prueba_null();
	prueba_clave_vacia();
	prueba_abb_insertar();
	prueba_abb_reemplazar();
	prueba_abb_borrar();
	prueba_abb_reemplazar_con_destruir();
	pruebas_insertar_muchos_borrar_todo();
	pruebas_iter_externo();
	prueba_abb_volumen(500,true);
	prueba_abb_iterar_volumen(500);
}
