#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "cJSON.h"
#include "cJSON.c"


int main(int argc, char** argv)
{
    cJson* unJson = (cJson*) malloc(sizeof(cJson));

    variant* unAtributo = (variant*) malloc(sizeof(variant));
    inicializar(unJson, unAtributo);
    char* clave= "nombre:";
    void* valor= "matias";
    unsigned largo = strlen(valor)+1;

    setVariant(unAtributo, clave, valor, largo);
    asignarJson(unJson, unAtributo);

    printf("%i\n", sizeof(unAtributo));
    printf("%i\n", sizeof(unJson));

    printf("%s %s\n", getStringClave(unAtributo), getStringValor(unAtributo));

    guardarArchivo(unJson);

    liberar(unJson);
    return 0;
}
