#ifndef CJSON_H_INCLUDED
#define CJSON_H_INCLUDED


/** Definición de la estructura Json en C
**/

typedef struct _atributo{
    char* clave;
    char* valor;
}atributo;

typedef struct _cJson{
    atributo* actual;
    atributo* siguiente;
}cJson;

/** Pre:    recibe un puntero a una estructura cJson alocada en el Stack vacia
    Post:   invoca a la funcion Inicializar
**/

void crearJson(cJson* unJson);

/** Pre:    recibe un puntero a una estructura cJson alocada en el Stack vacia
    Post:   inicializa cada uno de los atributos de la estructura en 0 o NULL
            dependiendo del caso
**/
void inicializar(cJson* unJson,atributo* unAtributo);

/** Pre:    recibe un puntero a una estructura cJson alocado en el Stack inicializada
    Post:   muestra por consola los atributos de la estructura
**/
void mostrarPorConsola(cJson* unJson);

/** Pre:    recibe un puntero a una estructura cJson alocado en el Stack inicializada
    Post:   guarda en un archivo destino los atributos de la estructura
**/
void guardarArchivo(cJson* unJson);

/**
    Post:   libera el espacio ocupado en memoria por la estructura cJson
**/
void liberar(cJson* unJson);

/** Post:    asigna un nuevo valor a la estructura cJson **/
void asignarJson(cJson* unJson, atributo* unAtributo);

void asignarAtributo (atributo* unAtributo, char* clave, char* valor);

/** Post:    asigna un nuevo valor del tipo entero a un atributo de la estructura cJson **/

#endif // CJSON_H_INCLUDED
