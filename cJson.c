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

void mostrarPorConsola(cJson* unJson) {

	if (unJson->primero) {
		printf("%s", "{\n");
		variant* auxIt = unJson->primero;

		while (auxIt) {
            unsigned auxiliarFinJson = auxIt->tipo;
            if((auxIt->tipo > 10) && (auxIt->tipo < 20) ){
                printf("%s", "[\n");
                auxIt->tipo -= 10;
            }

            if(auxIt->tipo > 20){
                auxIt->tipo -= 20;
            }

			printf("\"%s\": ", getStringClave(auxIt));

			unsigned tipo = getTipoElemento(auxIt);
			unsigned elementos = getCantidadElemtos(auxIt);

			switch (tipo) {

			case ventero:
				printf("%i", getInteger(auxIt));
				break;
			case vflotante:
				printf("%f", getFloat(auxIt));
				break;
			case vcadena:
				printf("\"%s\"", getStringValor(auxIt));
				break;
			case vlistaInt:
				printf("%s", "[");
				mostrarListaDeEnteros(auxIt, elementos);
				break;
			case vlistaFloat:
				printf("%s", "[");
				mostrarListaDeFloat(auxIt, elementos);
				break;
			case vlistaChar:
				printf("%s", "[");
				mostrarListaDeChar(auxIt, elementos);
				break;
			}

			if(auxiliarFinJson>20 ){
                printf("\n%s", "]");
                auxiliarFinJson = 0;
            }

			auxIt = auxIt->siguiente;
			if(auxIt){
                printf(",");
			}
			printf("\n");
		}

		printf("%s", "}\n");
	}
}

void mostrarListaDeEnteros(variant* aux, unsigned elementos) {
	unsigned contador = 0;
	int* auxInt = aux->valor;

	for (contador = 0; contador < elementos; contador++) {
		if (contador != elementos - 1) {
			printf("%i, ", (auxInt[contador]));
		} else {
			printf("%i", (auxInt[contador]));
			printf("%s", "]");
		}
	}
	aux = NULL;
}

void mostrarListaDeFloat(variant* aux, unsigned elementos) {
	unsigned contador = 0;
	float* auxFloat = aux->valor;

	for (contador = 0; contador < elementos; contador++) {
		if (contador != elementos - 1) {
			printf("%f, ", (auxFloat[contador]));
		} else {
			printf("%f", (auxFloat[contador]));
			printf("%s", "]");
		}
	}
	auxFloat = NULL;
}

void mostrarListaDeChar(variant* aux, unsigned elementos) {

	unsigned contador = 0;
	char* auxChar = aux->valor;

	for (contador = 0; contador < elementos; contador++) {
		if (contador != elementos - 1) {
			printf("%.1s, ", (auxChar + contador));
		} else {
			printf("%.1s", (auxChar + contador));
			printf("%s", "]");
		}
	}
	auxChar = NULL;
}

void guardarArchivo(cJson* unJson, int argc, char** argv) {
	if (unJson->primero) {

		FILE *archivoJson;
		archivoJson = fopen(argv[1], "w");
		fprintf(archivoJson, "%s", "{\n");

		variant* auxIt = unJson->primero;

		int* auxInt = NULL;
		float* auxFloat = NULL;
		char* auxChar = NULL;


		while (auxIt) {

			unsigned auxiliarFinJson = auxIt->tipo;
            if((auxIt->tipo > 10) && (auxIt->tipo < 20) ){
                fprintf(archivoJson, "%s", "[\n");
                auxIt->tipo -= 10;
            }

            if(auxIt->tipo > 20){
                auxIt->tipo -= 20;
            }

			fprintf(archivoJson, "\"%s\": ", getStringClave(auxIt));
			unsigned tipo = getTipoElemento(auxIt);
			unsigned elementos = getCantidadElemtos(auxIt);
			unsigned contador = 0;

			switch (tipo) {
			case ventero:
				fprintf(archivoJson, "%i", getInteger(auxIt));
				break;

			case vflotante:
				fprintf(archivoJson, "%f", getFloat(auxIt));
				break;

			case vcadena:
				fprintf(archivoJson, "\"%s\"", getStringValor(auxIt));
				break;

			case vlistaInt:
				/** mal, muestra cualquier cosa **/
				auxInt = auxIt->valor;
				fprintf(archivoJson, "%s", "[");
				for (contador = 0; contador < elementos; contador++) {
					if (contador != elementos - 1) {
						fprintf(archivoJson, "%i, ", (auxInt[contador]));
					} else {
						fprintf(archivoJson, "%i", (auxInt[contador]));
						fprintf(archivoJson, "%s", "]");
					}
				}
				auxInt = NULL;
				break;

			case vlistaFloat:
				/** mal, muestra cualquier cosa **/
				auxFloat = auxIt->valor;
				fprintf(archivoJson, "%s", "[");
				for (contador = 0; contador < elementos; contador++) {
					if (contador != elementos - 1) {
						fprintf(archivoJson, "%f, ", (auxFloat[contador]));
					} else {
						fprintf(archivoJson, "%f", (auxFloat[contador]));
						fprintf(archivoJson, "%s", "]");
					}
				}
				auxFloat = NULL;
				break;

			case vlistaChar:
				/** mal, muestra cualquier cosa **/
				auxChar = auxIt->valor;
				fprintf(archivoJson, "%s", "[");
				for (contador = 0; contador < elementos; contador++) {
					if (contador != elementos - 1) {
						fprintf(archivoJson, "%.1s, ", (auxChar + contador));
					} else {
						fprintf(archivoJson, "%.1s", (auxChar + contador));
						fprintf(archivoJson, "%s", "]");
					}
				}
				auxChar = NULL;
				break;
			}

            if(auxiliarFinJson>20 ){
                fprintf(archivoJson,"\n%s", "]");
                auxiliarFinJson = 0;
            }

			auxIt = auxIt->siguiente;
			if(auxIt){
                fprintf(archivoJson, "%s",",");
			}
			fprintf(archivoJson,"\n");
		}
		fprintf(archivoJson, "%s", "}");

		fclose(archivoJson);
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
    if(!unAtributo){
        printf("No cumple pre-condición \n");
        return;
    }

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

void asignarJsonDeJson( cJson* jsonAAsignar, cJson* unJson){
    if(!unJson->primero){
        printf("No cumple pre-condición \n");
        return;
    }
    variant* auxIt = unJson->primero;
    (auxIt->tipo) += vjsoninicio;

    asignarJson(jsonAAsignar, auxIt);

    while(auxIt->siguiente){
        auxIt = auxIt->siguiente;
        if(!auxIt->siguiente)
            auxIt->tipo += vjsonfinal;
        asignarJson(jsonAAsignar, auxIt);
    }

    auxIt = NULL;
}

/** si uso este metodo debo decrementar a  mano el tamaño del json
        ya que no tengo forma de acceder al json**/
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

    /** si quiero eliminar un variant que no se encuentre e
    n los extremos tengo que enganchar al anterior con el siguiente**/
    if((variant->anterior)&&(variant->siguiente)){
        variant->anterior->siguiente = variant->siguiente;
        variant->siguiente->anterior = variant->anterior;
    }
    /** si quiero eliminar el ultimo variant cambia el puntero del
    ultimo variant, y dice que el nuevo ultimo es su anterior **/
    if((variant->anterior)&&(!variant->siguiente)){
        variant->anterior->siguiente = NULL;
    }

    if((!variant->anterior)&&(variant->siguiente)){
        variant->siguiente->anterior = NULL;
    }

    if(variant->anterior)
        free(variant->anterior);
    if(variant->anterior)
        free(variant->anterior);
    variant->anterior=NULL;
    variant->siguiente=NULL;
}


/** borro el contenido del 1er variant
    y cambia los punteros del json primero y/o ultimo
    al siguiente del 1er variant **/
void liberarPrimero(cJson* unJson){

    if(unJson->primero!=unJson->ultimo){
        unJson->primero = unJson->primero->siguiente;
        liberarVariant(unJson->primero->anterior);
        unJson->tamanioJson -= sizeof(variant);

        if(unJson->primero->anterior)
            free(unJson->primero->anterior);
        unJson->primero->anterior = NULL;

    }
    else{
        unJson->tamanioJson = 0;
        liberarVariant(unJson->primero);

        if(unJson->primero)
            free(unJson->primero);
        unJson->primero = NULL;

        if(unJson->ultimo)
            free(unJson->ultimo);
        unJson->ultimo = NULL;
    }

}

/** este va liberar lo hara hasta la muerte misma del json**/
void liberar(cJson* unJson){

    if(getStringValor(unJson->primero)){
        unJson->tamanioJson = 0;
        while((unJson->primero)){
            liberarPrimero(unJson);
        }

        if(unJson->primero)
            free(unJson->primero);
        if(unJson->ultimo)
            free(unJson->ultimo);
    }
    unJson->primero = NULL;
    unJson->ultimo = NULL;

}

/** el set que todos conocemos **/
void setVariant( variant* v, void* unaClave, void* valor, unsigned largoClave, unsigned largo, unsigned tipo, unsigned elementos) {
    v->largo = largo;
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
