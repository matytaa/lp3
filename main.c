#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "cJSON.h"
#include "cJSON.c"

void crearUnJsonDeUnAtributo(int argc, char** argv);
void crearJsonDeVariosAtributos(int argc, char** argv);
void crearJsonArrayDeAtributos(int argc, char** argv);

int main(int argc, char** argv)
{
    crearUnJsonDeUnAtributo(argc, argv);
    crearJsonDeVariosAtributos(argc, argv);
    crearJsonArrayDeAtributos(argc, argv);
    return 0;
}


void crearUnJsonDeUnAtributo(int argc, char** argv){

    cJson* unJson = (cJson*) malloc(sizeof(cJson));
    inicializarJson(unJson);

    variant* unAtributo = (variant*) malloc(sizeof(variant));
    inicializarAtributo(unAtributo);

    char* clave= "escuderia";
    char* valor= "ferrari";
    unsigned largo = strlen(valor)+1;
    unsigned largoClave = strlen(clave)+1;
    unsigned tipo = 5;
    unsigned elementos = 1;

    setVariant(unAtributo, clave, valor, largoClave, largo, tipo, elementos);

    asignarJson(unJson, unAtributo);
    //if(strcmp(argv[argc-1],"-f") == 0){
        guardarArchivo(unJson, argc, argv);
    //}else{
        mostrarPorConsola(unJson);
    //}

    liberar(unJson);
}

void crearJsonDeVariosAtributos(int argc, char** argv){

    /** variant 1 **/
    char claveNombre[] = "nombre";
    char valorNombre[] = "matias";
    unsigned largoClaveNombre = strlen(claveNombre) +1;
    unsigned largoValorNombre = strlen(valorNombre) +1;
    unsigned tipoNombre = 5;
    unsigned elementosNombre = 1;

    /** variant 2 **/
    char claveEdad[] = "edad";
    unsigned edad= 23;
    void* valorEdad= &edad;
    unsigned largoClaveEdad = strlen(claveEdad) +1;
    unsigned largoValorEdad= sizeof(unsigned);
    unsigned tipoEdad = 3;
    unsigned elementosEdad = 1;

    /** variant 3 **/
    char claveDomicilio[] = "domicilio";
    char valorDomicilio[] = "calle falsa 123";
    unsigned largoClaveDomicilio = strlen(claveDomicilio) +1;
    unsigned largoValorDomicilio = strlen(valorDomicilio) +1;
    unsigned tipoDomicilio = 5;
    unsigned elementosDomicilio = 1;

    cJson* unJson = (cJson*) malloc(sizeof(cJson));
    inicializarJson(unJson);

    variant* atributoNombre = (variant*) malloc(sizeof(variant));
    inicializarAtributo(atributoNombre);

    variant* atributoEdad = (variant*) malloc(sizeof(variant));
    inicializarAtributo(atributoEdad);

    variant* atributoDomicilio = (variant*) malloc(sizeof(variant));
    inicializarAtributo(atributoDomicilio);

    setVariant(atributoNombre, claveNombre, valorNombre, largoClaveNombre, largoValorNombre, tipoNombre, elementosNombre);
    setVariant(atributoEdad, claveEdad, valorEdad, largoClaveEdad, largoValorEdad, tipoEdad, elementosEdad);
    setVariant(atributoDomicilio, claveDomicilio, valorDomicilio, largoClaveDomicilio,
               largoValorDomicilio, tipoDomicilio, elementosDomicilio);

    asignarJson(unJson, atributoDomicilio);
    asignarJson(unJson, atributoEdad);
    asignarJson(unJson, atributoNombre);

    //if(strcmp(argv[argc-1],"-f") == 0){
        guardarArchivo(unJson, argc, argv);
    //}else{
    //desplazamiento=0;
        mostrarPorConsola(unJson);

    //}

    liberar(unJson);
}

void crearJsonArrayDeAtributos(int argc, char** argv){

    unsigned cantidadElementos=4;
    char* clave= "notas";
    unsigned largo = cantidadElementos*(sizeof(int));
    int unArray[4]= {4,5,6,7};
    void* valor = unArray;
    unsigned largoClave = strlen(clave)+1;
    unsigned tipo = 6;

    unsigned cantidadElementosD = 5;
    char* claveD= "notas doubles";
    unsigned largoD = cantidadElementos*(sizeof(double));
    float unArrayD[]= {4.5, 5.5, 4.5, 3.5, 7.7};
    void* valorD = unArrayD;
    unsigned largoClaveD = strlen(claveD)+1;
    unsigned tipoD = 7;

    unsigned cantidadDeChar = 4;
    char arrayChar[]= {'a','b','c','d'};
    char* claveDeptos = "Departamentos";
    void* valorDeptos = arrayChar;
    unsigned largoClaveDeptos = strlen(claveDeptos) + 1;
    unsigned largoValorDeptos = strlen(valorDeptos);
    unsigned tipoDepto= 8;

    cJson* unJson = (cJson*) malloc(sizeof(cJson));
    inicializarJson(unJson);

    variant* atributoNotas = (variant*) malloc(sizeof(variant));
    variant* atributoNotasDouble = (variant*) malloc(sizeof(variant));
    variant* atributoDeptos= (variant*) malloc(sizeof(variant));
    inicializarAtributo(atributoNotas);
    inicializarAtributo(atributoNotasDouble);
    inicializarAtributo(atributoDeptos);

    setVariant(atributoNotas, clave, valor, largoClave, largo, tipo, cantidadElementos);
    setVariant(atributoNotasDouble, claveD, valorD, largoClaveD, largoD, tipoD, cantidadElementosD);
    setVariant(atributoDeptos, claveDeptos, valorDeptos, largoClaveDeptos, largoValorDeptos, tipoDepto, cantidadDeChar);


    asignarJson(unJson, atributoNotas);
    asignarJson(unJson, atributoNotasDouble);
    asignarJson(unJson, atributoDeptos);

    //if(strcmp(argv[argc-1],"-f") == 0){
        guardarArchivo(unJson,argc, argv);
    //}else{
        mostrarPorConsola(unJson);
    //}

    liberar(unJson);
}

