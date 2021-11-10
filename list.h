#include <stdlib.h>

// Define a list of Images
typedef char Imagen[28*28];

typedef struct celda {
    Imagen image;
    int numero;
    struct celda *sig;
    struct celda *ant;
} Celda;

typedef struct lista {
    int tamanio;
    Celda *ini;
} Lista;

void crear_lista(Lista *l);

void encolar(Lista *l, Imagen image, int numero);

void desencolar(Lista *l);

void borrar_lista(Lista *l);

void borrar_elemento(Lista *l, Celda *c);