#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cJSON.h"

void crearJson(cJson* unJson){
    unJson = (cJson*) malloc(sizeof(cJson));

}

void guardarArchivo(cJson* cJson){
    FILE *archivoJson;
    variant* unAtributo = cJson->actual;

 	archivoJson = fopen ( "archivoJson.txt", "w" );


    fprintf(archivoJson, "%s%p\n",unAtributo->clave, unAtributo->valor);

 	fclose (archivoJson);

}

void asignarJson(cJson* unJson, variant* unAtributo){

    unJson->actual = (variant*) malloc(sizeof(variant));
    memcpy(unJson->actual, unAtributo, sizeof(unAtributo));
}

void inicializar(cJson* nuevoJson, variant* unAtributo){
    nuevoJson->actual= NULL;
    nuevoJson->siguiente= NULL;

    unAtributo->clave= NULL;
    unAtributo->valor= NULL;
    unAtributo->largo= 0;
}

void liberarVariant(variant* variant) {
    variant->largo = 0;
    if (variant->clave)
        free(variant->clave);
    variant->clave= NULL;
    if ( variant->valor )
        free( variant->valor );
    variant->valor = NULL;
}

void liberar(cJson* unJson){
    if(unJson->actual)
        liberarVariant(unJson->actual);
    unJson->actual= NULL;

    if(unJson->siguiente)
        liberarVariant(unJson->siguiente);
    unJson->siguiente= NULL;
}

void setVariant( variant* v, char* clave, void* valor, unsigned largo) {
    v->largo = largo;

    if(v->clave)
    free(v->clave);
    v->clave = (char*) malloc( strlen( clave )+1);
    memcpy( v->clave, clave, strlen( clave )+1);

    if ( v->valor )
    free( v->valor );
    v->valor = malloc( largo );
    memcpy( v->valor, valor, largo);
}

int getInteger(variant* v) {
    int resultado = *(int*)v->valor;
    return resultado;
}

double getDouble(variant* v) {
    double resultado = *(double*)v->valor;
    return resultado;
}

char* getStringValor(variant* v) {
    return (char*)v->valor;
}

char* getStringClave(variant* v) {
    return (char*)v->clave;
}
