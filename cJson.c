#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cJSON.h"

int getInteger(variant* v) {
    int resultado = *(int*)v->valor;
    return resultado;
}

float getFlotante(variant* v) {
    float resultado = *(float*)v->valor;
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

void mostrarPorConsola(cJson* unJson, unsigned desplazamiento){

    printf("%s ", getStringClave((unJson->arrayAt[desplazamiento])));
    unsigned tipo = (unJson->arrayAt[desplazamiento]->tipo);
    switch(tipo){
        case ventero:
        printf("%i \n",getInteger(*(unJson->arrayAt+desplazamiento)));
        break;
        case vflotante:
        printf("%f \n",getDouble(*(unJson->arrayAt+desplazamiento)));
        break;
        case vcadena:
        printf("%s \n",getStringValor(*(unJson->arrayAt+desplazamiento)));
        break;
        default:
        printf("%f \n",getDouble(*(unJson->arrayAt+desplazamiento)));

    }
}

void guardarArchivo(cJson* unJson, unsigned desplazamiento){
    FILE *archivoJson;

 	archivoJson = fopen ( "archivoJson.txt", "a" );


    fprintf(archivoJson, "%s ", getStringClave((unJson->arrayAt[desplazamiento])));


    unsigned tipo = (unJson->arrayAt[desplazamiento]->tipo);
    switch(tipo){
        case ventero:
        fprintf(archivoJson, "%i \n",getInteger(*(unJson->arrayAt+desplazamiento)));
        break;
        case vflotante:
        fprintf(archivoJson, "%f \n",getDouble(*(unJson->arrayAt+desplazamiento)));
        break;
        case vcadena:
        fprintf(archivoJson, "%s \n",getStringValor(*(unJson->arrayAt+desplazamiento)));
        break;
        default:
        fprintf(archivoJson, "%f \n",getDouble(*(unJson->arrayAt+desplazamiento)));

    }

 	fclose (archivoJson);
}


void inicializarJson(cJson* nuevoJson){
    nuevoJson->arrayAt= NULL;
}


/** Aca hay problemas **/
void inicializarAtributo( variant* unAtributo){
    unAtributo->clave= NULL;
    unAtributo->valor= NULL;
    unAtributo->largo= 0;
    unAtributo->tipo = 0;
}

/** quitar numeros magicos, automatizar **/
void asignarJson(cJson* unJson, variant** unAtributo, unsigned tamanio){
    unJson->arrayAt = (variant**) malloc(tamanio);
    memcpy(unJson->arrayAt, unAtributo, tamanio);
}

void liberarVariant(variant* variant) {
    variant->largo = 0;
    variant->tipo = 0;
    if (variant->clave)
        free(variant->clave);
    variant->clave= NULL;
    if ( variant->valor )
        free( variant->valor );
    variant->valor = NULL;
}

void liberar(cJson* unJson){
    if(unJson->arrayAt)
        liberarArrayVariant(unJson->arrayAt);
    unJson->arrayAt= NULL;

}

void liberarArrayVariant(variant** arrayAt){
    if(arrayAt)
        liberarVariant(*(arrayAt));
}

void setVariant( variant* v, void* unaClave, void* valor, unsigned largoClave, unsigned largo, unsigned tipo) {
    v->largo = largo;
    v->tamanio = largo + largoClave;
    v->tipo = tipo;
    if ( v->valor ){
        free( v->valor );
    }
    v->valor = malloc( largo );
    memcpy( v->valor, valor, largo);

    if(v->clave){
        free(v->clave);
    }

    v->clave = malloc(largoClave);
    memcpy( v->clave, unaClave, largoClave);
}
