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

void mostrarPorConsola(cJson* unJson, unsigned desplazamiento){

    if(desplazamiento==0){
        printf("%s", "{\n");
    }

    printf("\"%s\": ", getStringClave((unJson->arrayAt[desplazamiento])));
    unsigned tipo = getTipoElemento(unJson->arrayAt[desplazamiento]);
    void* aux = getLista(unJson->arrayAt[desplazamiento]);
    unsigned elementos = getCantidadElemtos(unJson->arrayAt[desplazamiento]);

    switch(tipo){
        case ventero:
            printf("%i,\n",getInteger(*(unJson->arrayAt+desplazamiento)));
            break;
        case vflotante:
            printf("%f,\n",getFloat(*(unJson->arrayAt+desplazamiento)));
            break;
        case vcadena:
            printf("\"%s\",\n",getStringValor(*(unJson->arrayAt+desplazamiento)));
            break;
        case vlistaInt:
            printf("%s","[");
            mostrarListaDeEnteros(aux, elementos);
            break;
        case vlistaFloat:
            printf("%s","[");
            mostrarListaDeFloat(aux, elementos);
            break;
        case vlistaChar:
            printf("%s","[");
            mostrarListaDeChar(aux, elementos);
            break;
    }
    if(desplazamiento==2){
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

void guardarArchivo(cJson* unJson, unsigned desplazamiento,int argc, char** argv){
    FILE *archivoJson;
 	archivoJson = fopen ( "archivoJson.txt", "a" );//fopen(argv[argc+1], "a");
    if(desplazamiento==0){
        fprintf(archivoJson, "\n");
        fprintf(archivoJson, "%s", "{\n");
    }
    fprintf(archivoJson, "\"%s\": ",getStringClave((unJson->arrayAt[desplazamiento])));

    unsigned tipo = getTipoElemento(unJson->arrayAt[desplazamiento]);
    void* aux = getLista(unJson->arrayAt[desplazamiento]);
    unsigned elementos = getCantidadElemtos(unJson->arrayAt[desplazamiento]);
    unsigned contador = 0;

    int* auxInt = NULL;
    float* auxFloat = NULL;
    char* auxChar = NULL;

    switch(tipo){
        case ventero:
        fprintf(archivoJson, "%i\n",getInteger(*(unJson->arrayAt+desplazamiento)));
        break;

        case vflotante:
        fprintf(archivoJson, "%f,\n",getFloat(*(unJson->arrayAt+desplazamiento)));
        break;

        case vcadena:
        fprintf(archivoJson, "\"%s\",\n",getStringValor(*(unJson->arrayAt+desplazamiento)));
        break;

        case vlistaInt:
            auxInt = aux;
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
            auxFloat = aux;
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
            auxChar = aux;
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

    if(desplazamiento==2){
        fprintf(archivoJson, "%s","}");
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
    unAtributo->cantidadElementos = 0;
    unAtributo->tipo = 0;
}

void asignarJson(cJson* unJson, variant** unAtributo, unsigned tamanio){
    unJson->tamanioJson += tamanio;
    unJson->arrayAt = (variant**) malloc(tamanio);
    memcpy(unJson->arrayAt, unAtributo, tamanio);
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
