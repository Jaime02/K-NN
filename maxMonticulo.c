#include "maxMonticulo.h"

void nuevoMaxMonticulo(tipoMaxMonticulo *p, int n) {
    p->numEl = 0;
    p->array = (tipoElementoMaxMonticulo *) malloc(n * sizeof(tipoElementoMaxMonticulo));
    p->pos = -1;
}

void insertarMaxMonticulo(tipoMaxMonticulo *p, tipoElementoMaxMonticulo e) {
    int i;
    if (!estaLleno(*p)) {
        p->pos++;
        i = p->pos;
        while (i > 0 && (p->array)[(i - 1) / 2].distancia < e.distancia) {
            (p->array)[i] = (p->array)[(i - 1) / 2];
            i = (i - 1) / 2;
        }
        p->array[i] = e;
    }
}

void eliminarElemento(tipoMaxMonticulo *p, tipoElementoMaxMonticulo e) {
    // Deletes a element from the heap

    // Find the element
    int i = 0;
    while (i < p->numEl && (p->array)[i] != e) {
        i++;
    }

    // If the element is not in the heap, return
    if (i == p->numEl) {
        return;
    }

    // Swap the element with the last element
    (p->array)[i] = (p->array)[p->numEl - 1];
    p->numEl--;

    // Restore the heap property
    int j = i;
    while (j > 0 && (p->array)[j] > (p->array)[(j - 1) / 2]) {
        swap(&((p->array)[j]), &(p->array[(j - 1) / 2]));
        j = (j - 1) / 2;
    }
};

void swap(tipoElementoMaxMonticulo *a, tipoElementoMaxMonticulo *b) {
    tipoElementoMaxMonticulo temp = *a;
    *a = *b;
    *b = temp;
}

tipoElementoMaxMonticulo devolverRaiz(tipoMaxMonticulo p) {
    return p.array[0];
}

void mostrarAnchura(tipoMaxMonticulo m) {
    for (int i = 0; i <= m.pos; i++) printf("dist %d - tipo %d \n", m.array[i].distancia, m.array[i].tipo_numero);
}

bool esVacio(tipoMaxMonticulo m) {
    return m.numEl == 0;
}

bool estaLleno(tipoMaxMonticulo m) {
    return m.numEl == m.pos + 1;
};