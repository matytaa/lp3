#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "cJSON.h"
#include "cJSON.c"

void crearUnJsonDeUnAtributo();
void crearJsonDeVariosAtributos();
void crearJsonArrayDeAtributos();

int main(int argc, char** argv)
{
    //crearUnJsonDeUnAtributo();
    //crearJsonDeVariosAtributos();
    crearJsonArrayDeAtributos();
    return 0;
}


void crearUnJsonDeUnAtributo(){

    cJson* unJson = (cJson*) malloc(sizeof(cJson));
    inicializarJson(unJson);

    variant* unAtributo = (variant*) malloc(sizeof(variant));
    inicializarAtributo(unAtributo);

    char* clave= "escuderia:";
    char* valor= "ferrari";
    unsigned largo = strlen(valor)+1;
    unsigned largoClave = strlen(clave)+1;
    unsigned tamanio = largo + largoClave;
    unsigned tipo = 5;

    setVariant(unAtributo, clave, valor, largoClave, largo, tipo);

    asignarJson(unJson, &unAtributo, tamanio);
    unsigned desplazamiento = 0;
    guardarArchivo(unJson, desplazamiento);
    mostrarPorConsola(unJson, desplazamiento, 1);

    liberar(unJson);
}

void crearJsonDeVariosAtributos(){

    /** variant 1 **/
    char claveNombre[] = "nombre:";
    char valorNombre[] = "matias";
    unsigned largoClaveNombre = strlen(claveNombre) +1;
    unsigned largoValorNombre = strlen(valorNombre) +1;
    unsigned tipoNombre = 5;

    /** variant 2 **/
    char claveEdad[] = "edad:";
    unsigned edad= 23;
    void* valorEdad= &edad;
    unsigned largoClaveEdad = strlen(claveEdad) +1;
    unsigned largoValorEdad= sizeof(unsigned);
    unsigned tipoEdad = 3;

    /** variant 3 **/
    char claveDomicilio[] = "domicilio:";
    char valorDomicilio[] = "calle falsa 123";
    unsigned largoClaveDomicilio = strlen(claveDomicilio) +1;
    unsigned largoValorDomicilio = strlen(valorDomicilio) +1;
    unsigned tipoDomicilio = 5;

    cJson* unJson = (cJson*) malloc(sizeof(cJson));
    inicializarJson(unJson);

    variant* atributoNombre = (variant*) malloc(sizeof(variant));
    inicializarAtributo(atributoNombre);

    variant* atributoEdad = (variant*) malloc(sizeof(variant));
    inicializarAtributo(atributoEdad);

    variant* atributoDomicilio = (variant*) malloc(sizeof(variant));
    inicializarAtributo(atributoDomicilio);

    setVariant(atributoNombre, claveNombre, valorNombre, largoClaveNombre, largoValorNombre, tipoNombre);
    setVariant(atributoEdad, claveEdad, valorEdad, largoClaveEdad, largoValorEdad, tipoEdad);
    setVariant(atributoDomicilio, claveDomicilio, valorDomicilio, largoClaveDomicilio, largoValorDomicilio, tipoDomicilio);

    unsigned tamanioNombre = strlen(getStringClave(atributoNombre))+ atributoNombre->largo;
    unsigned tamanioEdad = strlen(getStringClave(atributoEdad))+ atributoEdad->largo;
    unsigned tamanioDomicilio =  strlen(getStringClave(atributoDomicilio))+ atributoDomicilio->largo;

    unsigned tamanioTotal = tamanioDomicilio + tamanioEdad + tamanioNombre;

    variant** arrayAt;
    arrayAt = (variant**) malloc(tamanioNombre);
    *(arrayAt) = atributoNombre;

    unsigned posicion = 1;
    *(arrayAt+posicion) = (variant*) malloc(tamanioEdad);
    arrayAt[posicion] = atributoEdad;

    posicion++;
    arrayAt[posicion] = (variant*) malloc(tamanioDomicilio);
    arrayAt[posicion] = atributoDomicilio;

    asignarJson(unJson, arrayAt, tamanioTotal);

    unsigned desplazamiento =0;
    for(desplazamiento=0; desplazamiento<3; desplazamiento++){
        guardarArchivo(unJson, desplazamiento);
    }

    desplazamiento =0;
    for(desplazamiento=0; desplazamiento<3; desplazamiento++){
        mostrarPorConsola(unJson, desplazamiento, 1);
    }
    liberar(unJson);
}

void crearJsonArrayDeAtributos(){

    cJson* unJson = (cJson*) malloc(sizeof(cJson));
    inicializarJson(unJson);

    variant* arrayAtributo = (variant*) malloc(sizeof(variant));
    inicializarAtributo(arrayAtributo);

    unsigned cantidadElementos=4;
    char* clave= "notas:";
    unsigned largo = cantidadElementos*(sizeof(int));
    int unArray[4]= {4,5,6,7};
    //char un[4]= {'a','b','c','d'};
    void* valor = unArray;
    unsigned largoClave = strlen(clave)+1;
    unsigned tamanio = largo + largoClave;
    unsigned tipo = 6;

    setVariant(arrayAtributo, clave, valor, largoClave, largo, tipo);

    asignarJson(unJson, &arrayAtributo, tamanio);
    unsigned desplazamiento = 0;
    //guardarArchivo(unJson, desplazamiento);
    mostrarPorConsola(unJson, desplazamiento, cantidadElementos);

    liberar(unJson);
}

