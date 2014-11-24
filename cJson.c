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

/** quitar numeros magicos, automatizar **/
void guardarArchivo(cJson* unJson){
    FILE *archivoJson;

 	archivoJson = fopen ( "archivoJson.txt", "a" );


    fprintf(archivoJson, "%s %s\n", getStringClave(*(unJson->arrayAt)),getStringValor(*(unJson->arrayAt)));
    fprintf(archivoJson, "%s %i\n", getStringClave(*(unJson->arrayAt+1)),getInteger(*(unJson->arrayAt+1)));
    fprintf(archivoJson, "%s %s\n", getStringClave(*(unJson->arrayAt+2)),getStringValor(*(unJson->arrayAt+2)));

 	fclose (archivoJson);
}


void inicializarJson(cJson* nuevoJson){
    nuevoJson->actual= NULL;
    nuevoJson->arrayAt= NULL;
}


/** Aca hay problemas **/
void inicializarAtributo( variant* unAtributo){
    unAtributo->clave= NULL;
    unAtributo->valor= NULL;
    unAtributo->largo= 0;
}

/** quitar numeros magicos, automatizar **/
void asignarJson(cJson* unJson, variant** unAtributo, unsigned tamanio){
    unJson->arrayAt = (variant**) malloc(tamanio);
    memcpy(unJson->arrayAt, unAtributo, tamanio);
    printf("haber 1 %s \n", getStringClave(*(unJson->arrayAt)));
    printf("haber 2 %s \n", getStringClave(*(unJson->arrayAt+2)));
}

/** hay que usarlo si queremos agregar un nuevo atributo, no se si anda **/
void reasicnarJson(cJson* unJson, variant* unAtributo, unsigned tamanio){
    unsigned aumentar = unJson->actual->largo + tamanio;
    cJson* otroJson= (cJson*) realloc(unJson, aumentar);
    liberar(unJson);
    unJson = otroJson;
    int i;
    for (i = 0; i<aumentar; i++){
        if(!((unJson+i))){
            asignarJson(&unJson[i], &unAtributo, tamanio);
            return;
        }
    }

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
    if(unJson->arrayAt)
        liberarArrayVariant(unJson->arrayAt);
    unJson->arrayAt= NULL;

}

/** quitar numeros magicos, automatizar para que llame a liberarVariant **/
void liberarArrayVariant(variant** arrayAt){
    if(arrayAt)
        liberarVariant(*(arrayAt));
}

void setVariant( variant* v, void* unaClave, void* valor, unsigned largoClave, unsigned largo) {
    v->largo = largo;
    v->tamanio = largo + largoClave;
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

    printf("%s %s\n", getStringClave(v), getStringValor(v));
}
