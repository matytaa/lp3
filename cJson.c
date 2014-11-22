#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cJSON.h"

void crearJson(cJson* unJson){
    unJson = (cJson*) malloc(sizeof(cJson));

}

void inicializar(cJson* nuevoJson, atributo* unAtributo){
    nuevoJson->actual= NULL;
    nuevoJson->siguiente= NULL;
    unAtributo->clave=NULL;
    unAtributo->valor=NULL;
}

void mostrarPorConsola(cJson* unJson){

    mostrarAtributo(unJson->actual);

}

void guardarArchivo(cJson* cJson){
    FILE *archivoJson;
    atributo* unAtributo = cJson->actual;

 	archivoJson = fopen ( "archivoJson.txt", "w" );


    fprintf(archivoJson, "%s%s\n",unAtributo->clave, unAtributo->valor);

 	fclose (archivoJson);

}

void asignarJson(cJson* unJson, atributo* unAtributo){

    unJson->actual = (atributo*) malloc(sizeof(atributo));
    memcpy(unJson->actual, unAtributo, sizeof(unAtributo));
}

void asignarAtributo (atributo* unAtributo, char* clave, char* valor){

    unAtributo->clave = (char*) malloc(strlen(clave)+1);
    memcpy(unAtributo->clave, clave, strlen(clave)+1);

    unAtributo->valor = (char*) malloc(strlen(valor)+1);
    memcpy(unAtributo->valor, valor, strlen(valor)+1);
}

void mostrarAtributo(atributo* unAtributo){
    printf("%s",unAtributo->clave);
    printf("%s\n", unAtributo->valor);
}
