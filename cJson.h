#ifndef CJSON_H_INCLUDED
#define CJSON_H_INCLUDED


/** Definición de la estructura Json en C
**/



typedef struct _Variant {
    void* valor; // Datos contenidos por el variant
    void* clave; // Tipo de dato contenido en el variant
    unsigned largo; // Cantidad de de bytes apuntados por data
    unsigned tamanio; //memoria utilizada por la estructura
} variant;

typedef struct _cJson{
    variant* actual;
    variant** arrayAt;
}cJson;
/***
* Dado un puntero a variant libero memoria (si es que está
* utilizando)
*
* @precondicion La estructura variant esta inicializada
*/
void liberarVariant(variant*);

void liberarArrayVariant(variant**);

/***
* Set datos almacenados por el variant
*
* @param v Variant que quiero configurar
* @param data Puntero al comienzo del entero
* @param largo Cantidad de bytes que ocupa un entero
*
* @precondicion La estructura variant esta inicializada
*/
void setVariant( variant*, void* clave, void* valor, unsigned largoClave, unsigned largo);

void concatenarAtributo(variant*, void* claveNombre, void* valorNombre, unsigned largoClaveNombre, unsigned largoValorNombre);

/***
* Descargo un entero como si el variant tuviera almacenado
* un entero
*
* @param v Variant que quiero configurar
*
* @precondicion La estructura variant esta inicializada
*/
int getInteger( variant*);

/***
* Descargo un entero como si el variant tuviera almacenado
* un entero
*
* @param v Variant que quiero configurar
*
* @precondicion La estructura variant esta inicializada
*/
double getDouble( variant*);

/***
* Descargo un puntero a string como si el variant tuviera almacenado
* un entero
*
* @param v Variant que quiero configurar
*
* @precondicion La estructura variant esta inicializada
*/
char* getStringValor( variant*);

/***
* Descargo un puntero a string como si el variant tuviera almacenado
* un entero
*
* @param v Variant que quiero configurar
*
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


/** Pre:    recibe un puntero a una estructura cJson alocado en el Stack inicializada
    Post:   guarda en un archivo destino los atributos de la estructura
**/
void guardarArchivo(cJson*);

/**
    Post:   libera el espacio ocupado en memoria por la estructura cJson
**/
void liberar( cJson*);

/** Post:    asigna un nuevo valor a la estructura cJson **/
void asignarJson( cJson*, variant**, unsigned tamanio );

void reasicnarJson(cJson*, variant*, unsigned tamanio);

#endif // CJSON_H_INCLUDED
