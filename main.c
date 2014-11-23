#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "cJSON.h"
#include "cJSON.c"


void crearUnJsonDeUnAtributo();

int main(int argc, char** argv)
{
    crearUnJsonDeUnAtributo();
    return 0;
}


void crearUnJsonDeUnAtributo(){

    cJson* unJson = (cJson*) malloc(sizeof(cJson));

    variant* unAtributo = (variant*) malloc(sizeof(variant));
    inicializar(unJson, unAtributo);
    char* clave= "nombre:";
    char* valor= "matias";
    unsigned largo = strlen(valor)+1;
    unsigned largoClave = strlen(clave)+1;

    setVariant(unAtributo, clave, valor, largoClave, largo);
    asignarJson(unJson, unAtributo);
    guardarArchivo(unJson);

    liberar(unJson);
}
