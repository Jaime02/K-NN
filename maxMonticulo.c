#include <stdio.h>
#include <stdlib.h>

#include "maxMonticulo.h"

const tipoElementoMaxMonticulo ERROR_VALUE = {.distancia = -1, .tipo_numero = -1};

void intercambiar(tipoElementoMaxMonticulo *a, int i, int j) {
    tipoElementoMaxMonticulo aux;
    aux = a[i];
    a[i] = a[j];
    a[j] = aux;
}

int padre(int i) { return ((i - 1) / 2); }

int hijoIzq(int i) { return (i * 2 + 1); }

int hijoDer(int i) { return (i * 2 + 2); }


void hundir(tipoElementoMaxMonticulo *a, int i) {
    while (a[padre(i)].distancia < a[i].distancia) {
        intercambiar(a, i, padre(i));
        i = padre(i);
    }
}

void flotar(tipoElementoMaxMonticulo *a, int i, int lim) {
    while ((a[hijoDer(i)].distancia > a[i].distancia || a[hijoIzq(i)].distancia > a[i].distancia) &&
           (hijoDer(i) <= lim && hijoIzq(i) <= lim)) {
        if (a[hijoDer(i)].distancia > a[i].distancia && a[hijoIzq(i)].distancia > a[i].distancia) {
            if(a[hijoDer(i)].distancia > a[hijoIzq(i)].distancia){
                intercambiar(a, i, hijoDer(i));
                i = hijoDer(i);
            }else if(a[hijoDer(i)].distancia <= a[hijoIzq(i)].distancia){
                intercambiar(a, i, hijoIzq(i));
                i = hijoIzq(i);
            }
        } else if (a[hijoDer(i)].distancia > a[i].distancia && !(a[hijoIzq(i)].distancia > a[i].distancia)) {
            intercambiar(a, i, hijoDer(i));
            i = hijoDer(i);
        } else if (!(a[hijoDer(i)].distancia > a[i].distancia) && a[hijoIzq(i)].distancia > a[i].distancia) {
            intercambiar(a, i, hijoIzq(i));
            i = hijoIzq(i);
        }
    }
    if (hijoIzq(i) <= lim && a[hijoIzq(i)].distancia > a[i].distancia) {
        intercambiar(a, i, hijoIzq(i));
    }
}

void nuevoMaxMonticulo(tipoMaxMonticulo *m, int tam) {
    m->pos = -1;
    m->array = (tipoElementoMaxMonticulo *)malloc(
        tam * sizeof(tipoElementoMaxMonticulo));
    m->numEl = tam;
}

void insertarMaxMonticulo(tipoMaxMonticulo *m, tipoElementoMaxMonticulo elem) {
    if (!estaLleno(*m)) {
        if (esVacio(*m)) {
            m->pos++;
            m->array[m->pos] = elem;
        } else {
            m->pos++;
            int i = m->pos;
            m->array[i] = elem;
            hundir(m->array, i);
        }
    } else
        printf("Error: Monticulo lleno\n");
}

void eliminarElemento(tipoMaxMonticulo *m, tipoElementoMaxMonticulo elem) {
    int i = 0;
    while (m->array[i].distancia != elem.distancia && i <= m->pos) {
        i++;
    }
    if (i <= m->pos) {
        m->array[i] = m->array[m->pos];
        m->pos--;
        flotar(m->array, i, m->pos);
    } else
        printf("El elemento no esta en el monticulo\n");
}

tipoElementoMaxMonticulo devolverRaiz(tipoMaxMonticulo m) {
    if (!esVacio(m))
        return (m.array[0]);
    else {
        printf("MaxMonticulo vacio\n");
        return ERROR_VALUE;
    }
}

void mostrarAnchura(tipoMaxMonticulo m) {
    for (int i = 0; i <= m.pos; i++) printf("dist %d - tipo %d \n", m.array[i].distancia, m.array[i].tipo_numero);
}

bool esVacio(tipoMaxMonticulo m) { return (m.pos == -1); }

bool estaLleno(tipoMaxMonticulo m) { return (m.pos == m.numEl - 1); }
