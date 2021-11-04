#include <stdlib.h>

// Define a list of Images
typedef char Imagen[28][28];

typedef struct celda {
    Imagen image;
    int label;
    struct celda *sig;
} celda;

typedef struct lista {
    int size;
    celda *ini;
    celda *fin;
} Lista;

void crear_lista(Lista *l);

void encolar(Lista *l, Imagen image, int label);

void desencolar(Lista *l);

void borrar_lista(Lista *l);