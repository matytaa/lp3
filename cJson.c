#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cJSON.h"

int getInteger(variant* v) {
    int resultado = *(int*)v->valor;
    return resultado;
}

void* getLista (variant* v){
    return v->valor;
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

void mostrarPorConsola(cJson* unJson, unsigned desplazamiento, unsigned elementos){

    printf("%s ", getStringClave((unJson->arrayAt[desplazamiento])));
    unsigned tipo = (unJson->arrayAt[desplazamiento]->tipo);
    switch(tipo){
        case ventero:
            printf("%i\n",getInteger(*(unJson->arrayAt+desplazamiento)));
            break;
        case vflotante:
            printf("%f\n",getDouble(*(unJson->arrayAt+desplazamiento)));
            break;
        case vcadena:
            printf("%s\n",getStringValor(*(unJson->arrayAt+desplazamiento)));
            break;
        case vlistaInt:
            mostrarListaDeEnteros(unJson, elementos);
            break;
        case vlistaDouble:
            mostrarListaDeDouble(unJson, elementos);
            break;
        case vlistaChar:
            mostrarListaDeChar(unJson, elementos);
            break;
        default:
        printf("%f\n",getDouble(*(unJson->arrayAt+desplazamiento)));

    }
}

void mostrarListaDeEnteros(cJson* unJson, unsigned elementos){
    unsigned contador = 0;
    int* aux = getLista(*unJson->arrayAt);

    for (contador=0; contador<elementos; contador++){
        if(contador!=elementos-1){
            printf("%i, ", (aux[contador]));
        }else{
            printf("%i ", (aux[contador]));
        }
    }
    printf("\n");
    aux=NULL;
}

void mostrarListaDeDouble(cJson* unJson, unsigned elementos){
    unsigned contador = 0;
    double* auxDouble = getLista(*unJson->arrayAt);

    for (contador=0; contador<elementos; contador++){
        if(contador!=elementos-1){
            printf("%f, ", (auxDouble[contador]));
        }else{
            printf("%f ", (auxDouble[contador]));
        }
    }
    printf("\n");
    auxDouble=NULL;
}

void mostrarListaDeChar(cJson* unJson, unsigned elementos){

    char* auxChar = getLista(*unJson->arrayAt);
    printf("%s \n", (auxChar));
    auxChar=NULL;
}

void guardarArchivo(cJson* unJson, unsigned desplazamiento){
    FILE *archivoJson;
 	archivoJson = fopen ( "archivoJson.txt", "a" );
    fprintf(archivoJson, "%s ", getStringClave((unJson->arrayAt[desplazamiento])));

    unsigned tipo = (unJson->arrayAt[desplazamiento]->tipo);
    switch(tipo){
        case ventero:
        fprintf(archivoJson, "%i\n",getInteger(*(unJson->arrayAt+desplazamiento)));
        break;
        case vflotante:
        fprintf(archivoJson, "%f\n",getDouble(*(unJson->arrayAt+desplazamiento)));
        break;
        case vcadena:
        fprintf(archivoJson, "%s\n",getStringValor(*(unJson->arrayAt+desplazamiento)));
        break;
        default:
        fprintf(archivoJson, "%f\n",getDouble(*(unJson->arrayAt+desplazamiento)));

    }

 	fclose (archivoJson);
}

void inicializarJson(cJson* nuevoJson){
    nuevoJson->tamanioJson=0;
    nuevoJson->arrayAt= NULL;
}

void inicializarAtributo( variant* unAtributo){
    unAtributo->clave= NULL;
    unAtributo->valor= NULL;
    unAtributo->largo= 0;
    unAtributo->tipo = 0;
}

void asignarJson(cJson* unJson, variant** unAtributo, unsigned tamanio){
    unJson->tamanioJson += tamanio;
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

    if ( v->valor )
        free( v->valor );

    v->valor = malloc( largo );
    memcpy( v->valor, valor, largo);

    if(v->clave)
        free(v->clave);

    v->clave = malloc(largoClave);
    memcpy( v->clave, unaClave, largoClave);
}
