#include "list.h"
#include <stdio.h>
#include <stdlib.h>

void crear_lista(Lista *l) {
    l->tamanio = 0;
    l->ini = NULL;
}

void encolar(Lista *l, Imagen image, int numero) {
    Celda *nuevo = (Celda *)malloc(sizeof(Celda));

    // Copy the image array to the celda nuevo
    for (int i = 0; i < 28 * 28; i++) {
        (nuevo->image)[i] = image[i];
    }
    nuevo->numero = numero;

    if (l->tamanio == 0) {
        l->ini = nuevo;
        nuevo->sig = NULL;
        nuevo->ant = NULL;
    } else {
        l->ini->ant = nuevo;
        nuevo->sig = l->ini;
        nuevo->ant = NULL;
        l->ini = nuevo;
    }
    (l->tamanio)++;
}

void desencolar(Lista *l) {
    if (l->tamanio == 0) {
        return;
    } else if (l->tamanio == 1) {
        free(l->ini);
        l->ini = NULL;
        (l->tamanio)--;
    } else {
        Celda *aux = l->ini;
        l->ini = l->ini->sig;
        l->ini->ant = NULL;
        free(aux);
        (l->tamanio)--;
    }
}

void borrar_lista(Lista *l) {
    while (l->tamanio > 0) {
        desencolar(l);
    }
}

void borrar_elemento(Lista *l, Celda *c) {
    // Borra la celda c de la lista l
    if (l->tamanio == 0) {
        printf("Error borraste un elemento en lista de  tamaño 0");
        return;
    } else if (l->tamanio == 1) {
        if (l->ini == c) {
            free(l->ini);
            l->ini = NULL;
            (l->tamanio)--;
            c = NULL;
        } else {
            printf("Error borraste un elemento que no existe en la lista");
            return;
        }
    } else {
        if (c == l->ini) {
            l->ini = l->ini->sig;
            l->ini->ant = NULL;
            free(c);
            (l->tamanio)--;
        } else if (c->sig == NULL) {
            c->ant->sig = NULL;
            free(c);
            (l->tamanio)--;
        } else {
            c->ant->sig = c->sig;
            c->sig->ant = c->ant;
            free(c);
            (l->tamanio)--;
        }
    }
}