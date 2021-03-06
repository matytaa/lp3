#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "cJSON.h"
#include "cJSON.c"

void crearJson(int argc, char** argv);

int main(int argc, char** argv)
{
    crearJson(argc, argv);
    return 0;
}

void crearJson(int argc, char** argv){

    cJson* unJson = (cJson*) malloc(sizeof(cJson));
    inicializarJson(unJson);

    cJson* otroJson = (cJson*) malloc(sizeof(cJson));
    inicializarJson(otroJson);


    /** variant 1 **/
    char claveNombre[] = "nombre";
    char valorNombre[] = "matias";
    unsigned largoClaveNombre = strlen(claveNombre) +1;
    unsigned largoValorNombre = strlen(valorNombre) +1;
    unsigned tipoNombre = 5;
    unsigned elementosNombre = 1;

    variant* atributoNombre = (variant*) malloc(sizeof(variant));
    inicializarAtributo(atributoNombre);


    /** variant 2 **/
    char claveEdad[] = "edad";
    unsigned edad= 23;
    void* valorEdad= &edad;
    unsigned largoClaveEdad = strlen(claveEdad) +1;
    unsigned largoValorEdad= sizeof(unsigned);
    unsigned tipoEdad = 3;
    unsigned elementosEdad = 1;

    variant* atributoEdad = (variant*) malloc(sizeof(variant));
    inicializarAtributo(atributoEdad);
    setVariant(atributoEdad, claveEdad, valorEdad, largoClaveEdad, largoValorEdad, tipoEdad, elementosEdad);

    /** variant 3 **/
    char claveDomicilio[] = "domicilio";
    char valorDomicilio[] = "calle falsa 123";
    unsigned largoClaveDomicilio = strlen(claveDomicilio) +1;
    unsigned largoValorDomicilio = strlen(valorDomicilio) +1;
    unsigned tipoDomicilio = 5;
    unsigned elementosDomicilio = 1;

    variant* atributoDomicilio = (variant*) malloc(sizeof(variant));
    inicializarAtributo(atributoDomicilio);

    setVariant(atributoNombre, claveNombre, valorNombre, largoClaveNombre, largoValorNombre, tipoNombre, elementosNombre);
    setVariant(atributoDomicilio, claveDomicilio, valorDomicilio, largoClaveDomicilio,
               largoValorDomicilio, tipoDomicilio, elementosDomicilio);

    /** asigno los primeros tres variant en unJson**/
    asignarJson(unJson, atributoDomicilio);
    asignarJson(unJson, atributoEdad);
    asignarJson(unJson, atributoNombre);


    /** variant 4 **/
    unsigned cantidadElementos=4;
    char* clave= "notas";
    unsigned largo = cantidadElementos*(sizeof(int));
    int unArray[4]= {4,5,6,7};
    void* valor = unArray;
    unsigned largoClave = strlen(clave)+1;
    unsigned tipo = 6;
    variant* atributoNotas = (variant*) malloc(sizeof(variant));
    inicializarAtributo(atributoNotas);

    /** variant 5 **/
    unsigned cantidadElementosD = 5;
    char* claveD= "notas doubles";
    unsigned largoD = cantidadElementos*(sizeof(double));
    float unArrayD[]= {4.5, 5.5, 4.5, 3.5, 7.7};
    void* valorD = unArrayD;
    unsigned largoClaveD = strlen(claveD)+1;
    unsigned tipoD = 7;
    variant* atributoNotasDouble = (variant*) malloc(sizeof(variant));
    inicializarAtributo(atributoNotasDouble);

    /** variant 6 **/
    unsigned cantidadDeChar = 4;
    char arrayChar[]= {'a','b','c','d'};
    char* claveDeptos = "Departamentos";
    void* valorDeptos = arrayChar;
    unsigned largoClaveDeptos = strlen(claveDeptos) + 1;
    unsigned largoValorDeptos = strlen(valorDeptos);
    unsigned tipoDepto= 8;
    variant* atributoDeptos= (variant*) malloc(sizeof(variant));
    inicializarAtributo(atributoDeptos);

    setVariant(atributoNotas, clave, valor, largoClave, largo, tipo, cantidadElementos);
    setVariant(atributoNotasDouble, claveD, valorD, largoClaveD, largoD, tipoD, cantidadElementosD);
    setVariant(atributoDeptos, claveDeptos, valorDeptos, largoClaveDeptos, largoValorDeptos, tipoDepto, cantidadDeChar);

    /** asigno los variant en unJson**/
    asignarJson(unJson, atributoNotas);
    asignarJson(unJson, atributoNotasDouble);
    asignarJson(unJson, atributoDeptos);


    /** variant 7 **/
    char* claveMarca= "marca";
    char* valorMarca = "fiat";
    unsigned largoValorMarca = strlen(valorMarca)+1;
    unsigned largoClaveMarca = strlen(claveMarca)+1;
    unsigned tipoMarca = 5;
    unsigned elementosMarca=1;

    variant* atributoMarca = (variant*) malloc(sizeof(variant));
    inicializarAtributo(atributoMarca);
    setVariant(atributoMarca, claveMarca, valorMarca, largoClaveMarca, largoValorMarca, tipoMarca, elementosMarca);


    /** variant 8 **/
    char claveModelo[] = "modelo";
    unsigned modelo= 2013;
    void* valorModelo= &modelo;
    unsigned largoClaveModelo= strlen(claveModelo) +1;
    unsigned largoValorModelo= sizeof(unsigned);
    unsigned tipoModelo = 3;
    unsigned elementosModelo = 1;

    variant* atributoModelo = (variant*) malloc(sizeof(variant));
    inicializarAtributo(atributoModelo);
    setVariant(atributoModelo, claveModelo, valorModelo, largoClaveModelo, largoValorModelo, tipoModelo, elementosModelo);


    /** variant 9 **/
    char claveKm[] = "kilometros";
    unsigned kilometros= 30000;
    void* valorKm= &kilometros;
    unsigned largoClaveKm= strlen(claveKm) +1;
    unsigned largoValorKm= sizeof(unsigned);
    unsigned tipoKm = 3;
    unsigned elementosKm = 1;

    variant* atributoKm= (variant*) malloc(sizeof(variant));
    inicializarAtributo(atributoKm);
    setVariant(atributoKm, claveKm, valorKm, largoClaveKm, largoValorKm, tipoKm, elementosKm);


    /** asigno los variant en unJson**/
    asignarJson(unJson, atributoMarca);
    asignarJson(unJson, atributoModelo);
    asignarJson(unJson, atributoKm);

    /** realizo unas bajas en unJson**/
    liberarPrimero(unJson);
    unJson->tamanioJson -= sizeof(variant);
    liberarPrimero(unJson);
    unJson->tamanioJson -= sizeof(variant);


    /** variant 10 **/
    char* claveEscuderia= "escuderia";
    char* valorEscuderia= "ferrari";
    unsigned largoEscuderia = strlen(valorEscuderia)+1;
    unsigned largoClaveEscuderia = strlen(claveEscuderia)+1;
    unsigned tipoEscuderia = 5;
    unsigned elementosEscuderia = 1;

    variant* unAtributoEscuderia = (variant*) malloc(sizeof(variant));
    inicializarAtributo(unAtributoEscuderia);
    setVariant(unAtributoEscuderia, claveEscuderia, valorEscuderia, largoClaveEscuderia
               , largoEscuderia, tipoEscuderia, elementosEscuderia);

    asignarJson(unJson, unAtributoEscuderia);

    /** variant 11 **/
    char claveLocalidad[] = "Localidad";
    char valorLocalidad[] = "San Miguel";
    unsigned largoClaveLocalidad = strlen(claveLocalidad) +1;
    unsigned largoValorLocalidad = strlen(valorLocalidad) +1;
    unsigned tipoLocalidad = 5;
    unsigned elementosLocalidad = 1;

    variant* atributoLocalidad = (variant*) malloc(sizeof(variant));
    inicializarAtributo(atributoLocalidad);
    setVariant(atributoLocalidad, claveLocalidad, valorLocalidad, largoClaveLocalidad, largoValorLocalidad
               , tipoLocalidad, elementosLocalidad);


    /** variant 12 **/
    char claveHabitantes[] = "Habitantes";
    unsigned habitantes= 23;
    void* valorHabitantes= &habitantes;
    unsigned largoClaveHabitantes = strlen(claveHabitantes) +1;
    unsigned largoValorHabitantes= sizeof(unsigned);
    unsigned tipoHabitantes = 3;
    unsigned elementosHabitantes = 1;

    variant* atributoHabitantes = (variant*) malloc(sizeof(variant));
    inicializarAtributo(atributoHabitantes);
    setVariant(atributoHabitantes, claveHabitantes, valorHabitantes, largoClaveHabitantes
               , largoValorHabitantes, tipoHabitantes, elementosHabitantes);


    /** variant 13 **/
    char claveProvincia[] = "Provincia";
    char valorProvincia[] = "Buenos Aires";
    unsigned largoClaveProvincia = strlen(claveProvincia) +1;
    unsigned largoValorProvincia = strlen(valorProvincia) +1;
    unsigned tipoProvincia = 5;
    unsigned elementosProvincia = 1;

    variant* atributoProvincia = (variant*) malloc(sizeof(variant));
    inicializarAtributo(atributoProvincia);
    setVariant(atributoProvincia, claveProvincia, valorProvincia, largoClaveProvincia,
               largoValorProvincia, tipoProvincia, elementosProvincia);


    /** asigno los variant en unJson**/
    asignarJson(otroJson, atributoProvincia);
    asignarJson(otroJson, atributoHabitantes);
    asignarJson(otroJson, atributoLocalidad);

    /** asigno otroJson en unJson**/
    asignarJsonDeJson(unJson, otroJson);

    /** el pasaje por parametros **/
    if((argc == 2)&&(argv[1])){
        printf("Json almacenado en el archivo destino indicado\n");
        printf("%s\n", argv[1]);
        guardarArchivo(unJson,argc, argv);
    }else{
        printf("Salida estandar\n");
        mostrarPorConsola(unJson);
    }

    liberar(unJson);
    /** verifico que se haya liberado unJson **/
    mostrarPorConsola(unJson);
    /** libero el otro Json, aunque ya no posee variant asignados **/
    liberar(otroJson);
    /** verifico que se haya liberado otroJson **/
    mostrarPorConsola(otroJson);
}

