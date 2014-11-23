#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cJSON.h"

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

void crearJson(cJson* unJson){
    unJson = (cJson*) malloc(sizeof(cJson));

}

void guardarArchivo(cJson* cJson){
    FILE *archivoJson;
    //variant* unAtributo = cJson->actual;

    printf("%s  ", getStringClave(cJson->actual));
    printf("%s\n", getStringValor(cJson->actual));

 	archivoJson = fopen ( "archivoJson.txt", "w" );


    fprintf(archivoJson, "%s %s\n", getStringClave(cJson->actual),getStringValor(cJson->actual));

 	fclose (archivoJson);
    //liberarVariant(unAtributo);
}

void asignarJson(cJson* unJson, variant* unAtributo){

    unsigned tamanio = strlen(getStringClave(unAtributo))+ unAtributo->largo;
    unJson->actual = (variant*) malloc(tamanio);
    memcpy(unJson->actual, unAtributo, tamanio);
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

variant* setVariant( variant* v, void* unaClave, void* valor, unsigned largoClave, unsigned largo) {
    v->largo = largo;

    if ( v->valor ){
        free( v->valor );
    }
    v->valor = malloc( largo );
    memcpy( v->valor, valor, largo);

    if(v->clave){
        free(v->clave);
    }
    v->clave = malloc(largoClave);
    printf("la clave: %s, %s\n",((char*)v->clave), ((char*)unaClave));

    memcpy( v->clave, unaClave, largoClave);

    printf("la clave: %s, %s\n",((char*)v->clave), ((char*)unaClave));

    return v;

}
