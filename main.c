#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "cJSON.h"
#include "cJSON.c"

void crearUnJsonDeUnAtributo();
void crearJsonDeVariosAtributos();

int main(int argc, char** argv)
{
    //crearUnJsonDeUnAtributo();
    crearJsonDeVariosAtributos();
    return 0;
}


void crearUnJsonDeUnAtributo(){

    cJson* unJson = (cJson*) malloc(sizeof(cJson));

    variant** unAtributo = (variant**) malloc(sizeof(variant));
    inicializarJson(unJson);
    inicializarAtributo(*(unAtributo));
    char* clave= "escuderia:";
    char* valor= "ferrari";
    unsigned largo = strlen(valor)+1;
    unsigned largoClave = strlen(clave)+1;
    unsigned tamanio = largo + largoClave;

    setVariant(*(unAtributo), clave, valor, largoClave, largo);
    asignarJson(unJson, unAtributo, tamanio);
    guardarArchivo(unJson);

    liberar(unJson);
}

void crearJsonDeVariosAtributos(){
    char claveNombre[] = "nombre:";
    char valorNombre[] = "matias";
    unsigned largoClaveNombre = strlen(claveNombre) +1;
    unsigned largoValorNombre = strlen(valorNombre) +1;

    char claveEdad[] = "edad: ";
    unsigned edad= 23;
    void* valorEdad= &edad;
    unsigned largoClaveEdad = strlen(claveEdad) +1;
    unsigned largoValorEdad= sizeof(unsigned);

    char claveDomicilio[] = "domicilio:";
    char valorDomicilio[] = "calle falsa 123";
    unsigned largoClaveDomicilio = strlen(claveDomicilio) +1;
    unsigned largoValorDomicilio = strlen(valorDomicilio) +1;

    cJson* unJson = (cJson*) malloc(sizeof(cJson));
    inicializarJson(unJson);

    variant* atributoNombre = (variant*) malloc(sizeof(variant));
    inicializarAtributo(atributoNombre);

    variant* atributoEdad = (variant*) malloc(sizeof(variant));
    inicializarAtributo(atributoEdad);

    variant* atributoDomicilio = (variant*) malloc(sizeof(variant));
    inicializarAtributo(atributoDomicilio);

    setVariant(atributoNombre, claveNombre, valorNombre, largoClaveNombre, largoValorNombre);
    setVariant(atributoEdad, claveEdad, valorEdad, largoClaveEdad, largoValorEdad);
    setVariant(atributoDomicilio, claveDomicilio, valorDomicilio, largoClaveDomicilio, largoValorDomicilio);

    unsigned tamanioNombre = strlen(getStringClave(atributoNombre))+ atributoNombre->largo;
    unsigned tamanioEdad = strlen(getStringClave(atributoEdad))+ atributoEdad->largo;
    unsigned tamanioDomicilio =  strlen(getStringClave(atributoDomicilio))+ atributoDomicilio->largo;

    unsigned tamanioTotal = tamanioDomicilio + tamanioEdad + tamanioNombre;
    /** esto anda

    variant* atributos = (variant*)malloc(tamanioTotal);
    inicializarAtributo(atributos);

    atributos = atributoNombre,atributoEdad,atributoDomicilio;
    asignarJson(unJson, atributos, tamanioTotal);
    **/

    variant** arrayAt;
    arrayAt = (variant**) malloc(tamanioNombre);
    *(arrayAt) = atributoNombre;

    *(arrayAt+1) = (variant*) malloc(tamanioEdad);
    arrayAt[1] = atributoEdad;

    arrayAt[2] = (variant*) malloc(tamanioDomicilio);
    arrayAt[2] = atributoDomicilio;

    printf("1 %s \n", getStringClave(*(arrayAt)));
    printf("2 %s \n", getStringClave(*(arrayAt+1)));
    printf("3 %s \n", getStringClave(*(arrayAt+2)));


    asignarJson(unJson, arrayAt, tamanioTotal);
    guardarArchivo(unJson);


    //asignarJson(unJson, (variant*)arrayAt, tamanioTotal);

    //printf("puntero %p \n", unJson->actual);

//    arrayJson[0] = atributoDomicilio;


    //asignarJson(unJson, atributoDomicilio, tamanioDomicilio);
    //reasicnarJson(unJson, atributoNombre, tamanioNombre);

    //variant at2 = *(unJson+1)->actual;
    //printf("algo %s \n", getStringValor(at));
//    printf("%s \n", getStringValor(&at2));

    //guardarArchivo(unJson);

}
