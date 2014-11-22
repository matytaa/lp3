#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "cJSON.h"
#include "cJSON.c"


int main(int argc, char** argv)
{
    cJson* unJson = (cJson*) malloc(sizeof(cJson));

    atributo* unAtributo = (atributo*) malloc(sizeof(atributo));
    inicializar(unJson, unAtributo);
    char* clave= "nombre: ";
    char* valor= "matias";

    asignarAtributo(unAtributo, clave, valor);
    asignarJson(unJson, unAtributo);

    mostrarPorConsola(unJson);
    printf("%i\n", sizeof(unAtributo));
    printf("%i\n", sizeof(unJson));
    //guardarArchivo(unJson);
    free(unAtributo);
    free(unJson);
    return 0;
}
