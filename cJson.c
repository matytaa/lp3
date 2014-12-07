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

float getFloat(variant* v) {
    float resultado = *(float*)v->valor;
    return resultado;
}

char* getStringValor(variant* v) {
    return (char*)v->valor;
}

char* getStringClave(variant* v) {
    return (char*)v->clave;
}

unsigned getCantidadElemtos (variant* v){
    return v->cantidadElementos;
}

unsigned getTipoElemento ( variant* v){
    return v->tipo;
}

void crearJson(cJson* unJson){
    unJson = (cJson*) malloc(sizeof(cJson));

}

void mostrarPorConsola(cJson* unJson){

    if(unJson->primero){
        printf("%s", "{\n");

        variant* auxIt = unJson->primero;

        while (auxIt){


            printf("\"%s\": ", getStringClave(auxIt));

            unsigned tipo = getTipoElemento(auxIt);
            unsigned elementos = getCantidadElemtos(auxIt);

            switch(tipo){
                case ventero:
                    printf("%i,\n",getInteger(auxIt));
                    break;
                case vflotante:
                    printf("%f,\n",getFloat(auxIt));
                    break;
                case vcadena:
                    printf("\"%s\",\n",getStringValor(auxIt));
                    break;
                case vlistaInt:
                    /** mal, muestra cualquier cosa **/
                    printf("%s","[");
                    mostrarListaDeEnteros(auxIt, elementos);
                    break;
                case vlistaFloat:
                    /** mal, muestra cualquier cosa **/
                    printf("%s","[");
                    mostrarListaDeFloat(auxIt, elementos);
                    break;
                case vlistaChar:
                    /** mal, muestra cualquier cosa **/
                    printf("%s","[");
                    mostrarListaDeChar(auxIt, elementos);
                    break;
            }
            auxIt= auxIt->siguiente;
        }

        printf("%s", "}\n");
    }
}

void mostrarListaDeEnteros(void* aux, unsigned elementos){
    unsigned contador = 0;
    int* auxInt = aux;

    for (contador=0; contador<elementos; contador++){
        if(contador!=elementos-1){
            printf("%i, ", (auxInt[contador]));
        }else{
            printf("%i", (auxInt[contador]));
            printf("%s","],\n");
        }
    }
    aux=NULL;
}

void mostrarListaDeFloat(void* aux, unsigned elementos){
    unsigned contador = 0;
    float* auxFloat= aux;

    for (contador=0; contador<elementos; contador++){
        if(contador!=elementos-1){
            printf("%f, ", (auxFloat[contador]));
        }else{
            printf("%f", (auxFloat[contador]));
            printf("%s","],\n");
        }
    }
    auxFloat=NULL;
}

void mostrarListaDeChar(void* aux, unsigned elementos){

    unsigned contador = 0;
    char* auxChar = aux;

    for (contador=0; contador<elementos; contador++){
        if(contador!=elementos-1){
            printf("%.1s, ", (auxChar + contador));
        }else{
            printf("%.1s", (auxChar + contador));
            printf("%s","],\n");
        }
    }
    auxChar=NULL;
}

void guardarArchivo(cJson* unJson,int argc, char** argv){
    if(unJson->primero){

        FILE *archivoJson;
        archivoJson = fopen ( "archivoJson.txt", "a" );//fopen(argv[argc+1], "a");
        fprintf(archivoJson, "\n");
        fprintf(archivoJson, "%s", "{\n");

        variant* auxIt = unJson->primero;
        fprintf(archivoJson, "\"%s\": ",getStringClave(auxIt));
        unsigned tipo = getTipoElemento(auxIt);
        unsigned elementos = getCantidadElemtos(auxIt);
        unsigned contador = 0;

        int* auxInt = NULL;
        float* auxFloat = NULL;
        char* auxChar = NULL;

        while (auxIt){

            switch(tipo){
                case ventero:
                fprintf(archivoJson, "%i\n",getInteger(auxIt));
                break;

                case vflotante:
                fprintf(archivoJson, "%f,\n",getFloat(auxIt));
                break;

                case vcadena:
                fprintf(archivoJson, "\"%s\",\n",getStringValor(auxIt));
                break;

                case vlistaInt:
                    /** mal, muestra cualquier cosa **/
                    auxInt = (int*)auxIt;
                    fprintf(archivoJson, "%s","[");
                    for (contador=0; contador<elementos; contador++){
                        if(contador!=elementos-1){
                            fprintf(archivoJson, "%i, ", (auxInt[contador]));
                        }else{
                            fprintf(archivoJson, "%i", (auxInt[contador]));
                            fprintf(archivoJson, "%s","],\n");
                        }
                    }
                    auxInt=NULL;
                    break;

                case vlistaFloat:
                    /** mal, muestra cualquier cosa **/
                    auxFloat = (float*)auxIt;
                    fprintf(archivoJson, "%s","[");
                    for (contador=0; contador<elementos; contador++){
                        if(contador!=elementos-1){
                            fprintf(archivoJson, "%f, ", (auxFloat[contador]));
                        }else{
                            fprintf(archivoJson, "%f", (auxFloat[contador]));
                            fprintf(archivoJson, "%s","],\n");
                        }
                    }
                    auxFloat=NULL;
                    break;

                case vlistaChar:
                    /** mal, muestra cualquier cosa **/
                    auxChar = (char*)auxIt;
                    fprintf(archivoJson, "%s","[");
                    for (contador=0; contador<elementos; contador++){
                        if(contador!=elementos-1){
                            fprintf(archivoJson, "%.1s, ", (auxChar + contador));
                        }else{
                            fprintf(archivoJson, "%.1s", (auxChar + contador));
                            fprintf(archivoJson, "%s","],\n");
                        }
                    }
                    auxChar=NULL;
                    break;
            }
            auxIt = auxIt->siguiente;
        }

        fprintf(archivoJson, "%s","}");

        fclose (archivoJson);
 	}
}

void inicializarJson(cJson* nuevoJson){
    nuevoJson->tamanioJson=0;
    nuevoJson->primero= NULL;
    nuevoJson->ultimo = NULL;
}

void inicializarAtributo( variant* unAtributo){
    unAtributo->clave= NULL;
    unAtributo->valor= NULL;
    unAtributo->largo= 0;
    unAtributo->cantidadElementos = 0;
    unAtributo->tipo = 0;
    unAtributo->anterior = NULL;
    unAtributo->siguiente = NULL;

}

void asignarJson(cJson* unJson, variant* unAtributo){

    unJson->tamanioJson += sizeof(variant);
    if(!unJson->primero){
        unJson->primero= unAtributo;
        unJson->ultimo= unAtributo;
        return;
    }

    unAtributo->anterior = unJson->ultimo;
    unJson->ultimo->siguiente = unAtributo;
    unJson->ultimo = unAtributo;


}

void liberarVariant(variant* variant) {
    variant->largo = 0;
    variant->cantidadElementos = 0;
    variant->tipo = 0;
    if (variant->clave)
        free(variant->clave);

    variant->clave= NULL;
    if ( variant->valor )
        free( variant->valor );

    variant->valor = NULL;
    variant->anterior = NULL;
    variant->siguiente = NULL;
}

void liberar(cJson* unJson){
    unJson->tamanioJson = 0;
    if(unJson->primero)
        liberarVariant(unJson->primero);
    unJson->primero= NULL;

    if(unJson->ultimo)
        liberarVariant(unJson->ultimo);
    unJson->ultimo= NULL;

}

void setVariant( variant* v, void* unaClave, void* valor, unsigned largoClave, unsigned largo, unsigned tipo, unsigned elementos) {
    v->largo = largo;
    v->tamanio = largo + largoClave;
    v->cantidadElementos = elementos;
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
