#ifndef CJSON_H_INCLUDED
#define CJSON_H_INCLUDED

/** Definición de la estructura Json en C
**/
#define vfalse 0
#define vtrue 1

#define vnull 2
#define ventero 3

#define vflotante 4
#define vcadena 5

#define vlista 6


typedef struct _Variant {
    void* valor; // Datos contenidos por el variant
    void* clave; // Tipo de dato contenido en el variant
    unsigned largo; // Cantidad de de bytes apuntados por data
    unsigned tamanio; //memoria utilizada por la estructura
    unsigned tipo;

} variant;

typedef struct _cJson{
    variant** arrayAt;
}cJson;

/***
* post: Almacenar los datos en el variant
* @param v Variant que quiero configurar
* @param data Puntero al comienzo del entero
* @param largo Cantidad de bytes que ocupa un entero
* @precondicion La estructura variant esta inicializada
*/
void setVariant( variant*, void* clave, void* valor, unsigned largoClave, unsigned largo, unsigned tipo);


/** Post:    asigna un nuevo valor a la estructura cJson **/
void asignarJson( cJson*, variant**, unsigned tamanio );

/***
* post: retorno un double que contiene el valor del atributo
* @param v Variant que quiero configurar
* @precondicion La estructura variant esta inicializada
*/
int getInteger( variant*);


/***
* post: retorno un float que contiene el valor del atributo
* @param v Variant que quiero configurar
* @precondicion La estructura variant esta inicializada
*/
float getFlotante( variant* );

/***
* post: retorno un double que contiene el valor del atributo
* @param v Variant que quiero configurar
* @precondicion La estructura variant esta inicializada
*/
double getDouble( variant*);

/***
* post: retorno un char* que contiene el valor del atributo
* @param v Variant que quiero configurar
* @precondicion La estructura variant esta inicializada
*/
char* getStringValor( variant*);

/***
* post: retorno un char* que contiene la clave
* @param v Variant que quiero configurar
* @precondicion La estructura variant esta inicializada
*/
char* getStringClave(variant* );

/** Pre:    recibe un puntero a una estructura cJson alocada en el Stack vacia
    Post:   invoca a la funcion Inicializar
**/

void crearJson( cJson*);

/** Pre:    recibe un puntero a una estructura cJson alocada en el Stack vacia
    Post:   inicializa cada uno de los atributos de la estructura NULL
**/
void inicializar( cJson*, variant*);

/** Pre:    recibe un puntero a una estructura variant alocada en el Stack vacia
    Post:   inicializa cada uno de los atributos de la estructura en NULL
**/
void inicializarAtributo( variant* unAtributo);


/** Pre:    recibe un puntero a una estructura cJson alocado en memoria inicializado y asignado
    Post:   guarda en un archivo destino los atributos de la estructura
**/
void guardarArchivo(cJson*, unsigned);

/** Pre:    recibe un puntero a una estructura cJson alocado en memoria inicializado y asignado
    Post:   imprime por pantalla los atributos de la estructura
**/
void mostrarPorConsola(cJson*, unsigned);

/***
* Dado un puntero a variant libero memoria (si es que está
* utilizando)
* @precondicion La estructura variant esta inicializada
*/
void liberarVariant(variant*);

/**
* post: libera la memoria utilizada por el array de variant
* @param variant**
**/
void liberarArrayVariant(variant**);

/**
    Post:   libera el espacio ocupado en memoria por la estructura cJson
**/
void liberar( cJson*);

#endif // CJSON_H_INCLUDED
