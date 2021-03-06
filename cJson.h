#ifndef CJSON_H_INCLUDED
#define CJSON_H_INCLUDED

/** Definición de la estructura Json en C
**/
#define vjsoninicio 10 //indica inicio del json

#define vjsonfinal 20 //indica final del Json
#define ventero 3

#define vflotante 4
#define vcadena 5

#define vlistaInt 6
#define vlistaFloat 7
#define vlistaChar 8


typedef struct _Variant {
    void* valor; // Datos contenidos por el variant
    char* clave; // Clave de los datos contenidos por el variant
    unsigned largo; // Cantidad de de bytes apuntados por dato valor
    unsigned cantidadElementos; //si es mayor a 1 es un array
    unsigned tipo;
    struct _Variant* anterior;
    struct _Variant* siguiente;

} variant;

typedef struct _cJson{
    unsigned tamanioJson;
    variant* primero;
    variant* ultimo;

}cJson;

/***
* pre: variant inicializado, todos los parametros deben no ser nulos
* post: Almacenar los datos en el variant
* @param v Variant que quiero configurar
* @param data Puntero al comienzo del entero
* @param largo Cantidad de bytes que ocupa un entero
* @precondicion La estructura variant esta inicializada
*/
void setVariant( variant*, void* clave, void* valor, unsigned largoClave, unsigned largo, unsigned tipo, unsigned elementos);


/** Post:    asigna un nuevo valor a la estructura cJson **/
void asignarJson( cJson*, variant*);

/** pre: cJson inicializado, el json a asignar no debe ser nulo
* Post:    asigna un nuevo valor a la estructura cJson **/
void asignarJsonDeJson( cJson*, cJson*);

/***
* post: retorno un double que contiene el valor del atributo
* @param v Variant que quiero configurar
* @precondicion La estructura variant esta inicializada
*/
int getInteger( variant*);

void* getLista (variant* v);

/**pre: variant no debe ser nulo
* post: retorno un float que contiene el valor del atributo
* @param v Variant que quiero configurar
* @precondicion La estructura variant esta inicializada
*/
float getFloat( variant* );

/**pre: variant no debe ser nulo
* post: retorno un char* que contiene el valor del atributo
* @param v Variant que quiero configurar
* @precondicion La estructura variant esta inicializada
*/
char* getStringValor( variant*);

/**pre: variant no debe ser nulo
* post: retorno un char* que contiene la clave
* @param v Variant que quiero configurar
* @precondicion La estructura variant esta inicializada
*/
char* getStringClave(variant* );

/**pre: variant no debe ser nulo
* post: retorno la cantidad de elementos que poseé la clave
* @param v Variant que quiero configurar
* @precondicion La estructura variant esta inicializada
*/
unsigned getCantidadElemtos (variant* );

/**pre: variant no debe ser nulo
* post: retorno el tipo de elementos que poseé el valor
* @param v Variant que quiero configurar
* @precondicion La estructura variant esta inicializada
*/
unsigned getTipoElemento ( variant* );


/** Pre:    recibe un puntero a una estructura cJson alocada en el Stack vacia
    Post:   inicializa cada uno de los atributos de la estructura NULL
**/
void inicializarJson( cJson* );

/** Pre:    recibe un puntero a una estructura variant alocada en el Stack vacia
    Post:   inicializa cada uno de los atributos de la estructura en NULL
**/
void inicializarAtributo( variant* unAtributo);


/** Pre:    recibe un puntero a una estructura cJson alocado en memoria inicializado y asignado
    Post:   guarda en un archivo destino los atributos de la estructura
**/
void guardarArchivo(cJson*, int argc, char** argv);

/** Pre:    recibe un puntero a una estructura cJson alocado en memoria inicializado y asignado
    Post:   imprime por pantalla los atributos de la estructura
**/
void mostrarPorConsola(cJson*);

/** Pre:    recibe un puntero a un variant alocado en memoria asignado y un unsigned
    que determina la cantidad de elementos que posee
    Post:   imprime por pantalla los atributos de la estructura
**/
void mostrarListaDeEnteros(variant*, unsigned);

/** Pre:    recibe un puntero a un variant alocado en memoria asignado y un unsigned
    que determina la cantidad de elementos que posee
    Post:   imprime por pantalla los atributos de la estructura
**/
void mostrarListaDeFloat(variant*, unsigned);

/** Pre:    recibe un puntero a un variant alocado en memoria asignado y un unsigned
    que determina la cantidad de elementos que posee
    Post:   imprime por pantalla los atributos de la estructura
**/
void mostrarListaDeChar(variant*, unsigned);

/***
* Dado un puntero a variant libero memoria (si es que está
* utilizando)
* @precondicion La estructura variant esta inicializada
*/
void liberarVariant(variant*);

/**
* post: libera la memoria utilizada por el primer variant y redefine el primer variant
* @param cJson*, variant*
**/
void liberarPrimero(cJson* unJson);

/**
    Post:   libera el espacio ocupado en memoria por la estructura cJson
**/
void liberar( cJson*);

#endif // CJSON_H_INCLUDED
