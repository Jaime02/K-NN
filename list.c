#include <stdlib.h>
#include "list.h"

void crear_lista(Lista *l) {
    l->size = 0;
    l->ini = NULL;
}

void encolar(Lista *l, Imagen image, int label) {
    celda *nuevo = (celda *) malloc(sizeof(celda));
    // Copy the image array
    for (int i = 0; i < 28; i++) {
        for (int j = 0; j < 28; j++) {
            nuevo->image[i][j] = image[i][j];
        }
    }

    nuevo->label = label;
    nuevo->sig = NULL;
    
    if (l->size == 0) {
        l->ini = nuevo;
        l->fin = nuevo;
    } else {
        l->fin->sig = nuevo;
        l->fin = nuevo;
    }

    l->size++;
}

void desencolar(Lista *l) {
    if (l->size == 0) {
        return;
    }

    celda *aux = l->ini;
    l->ini = l->ini->sig;
    l->size--;
    free(aux);
}

void borrar_lista(Lista *l) {
    while (l->size > 0) {
        desencolar(l);
    }
}
