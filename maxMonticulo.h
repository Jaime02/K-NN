#include <stdbool.h>

#ifndef MAXMONTICULO_H_
#define MAXMONTICULO_H_

typedef struct {
    double distancia;
    int tipo_numero;
} tipoElementoMaxMonticulo;

const tipoElementoMaxMonticulo ERROR_VALUE = {.distancia = -1, .tipo_numero = -1};

typedef struct {
    tipoElementoMaxMonticulo *array;
    int pos;
    int numEl;
} tipoMaxMonticulo;

void nuevoMaxMonticulo(tipoMaxMonticulo *, int);

void insertarMaxMonticulo(tipoMaxMonticulo *, tipoElementoMaxMonticulo);

void eliminarElemento(tipoMaxMonticulo *, tipoElementoMaxMonticulo);

tipoElementoMaxMonticulo devolverRaiz(tipoMaxMonticulo);

void mostrarAnchura(tipoMaxMonticulo);

bool esVacio(tipoMaxMonticulo);

bool estaLleno(tipoMaxMonticulo);

#endif /* MAXMONTICULO_H_ */