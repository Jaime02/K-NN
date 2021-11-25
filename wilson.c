#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "list.h"
#include "maxMonticulo.h"

#define N 20  // La N del KNN

int distancia_euclideana(Imagen img1, Imagen img2) {
    double distancia = 0;

    for (int i = 0; i < 28 * 28; i++) {
        distancia += (int)pow((img1[i] - img2[i]), 2.0);
    }
    return (int)sqrt(distancia);
}
void resetTablaTipos(int t[10][2]) {
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 2; ++j) t[i][j] = 0;
    }
}

void ini_matriz(int m[10][10]) {
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) m[i][j] = 0;
    }
}

int main() {
    int tiposTeoricos[10000], tipos[10][2], matriz_dispersion[10][10];
    resetTablaTipos(tipos);
    Lista listaDataset;
    crear_lista(&listaDataset);
    tipoMaxMonticulo distMinimas;
    nuevoMaxMonticulo(&distMinimas, N);
    ini_matriz(matriz_dispersion);

    char* nombre_datos_binario = (char*)malloc(25);
    Imagen img;

    FILE* datos_binario;
    printf("Loading dataset... \n");
    for (int numero = 0; numero < 10; numero++) {
        sprintf(nombre_datos_binario, "../binary_data/data%d.bin", numero);
        datos_binario = fopen(nombre_datos_binario, "rb");

        for (int j = 0; j < 1000; j++) {
            for (int k = 0; k < 28 * 28; k++) {
                fread(&(img[k]), sizeof(char), 1, datos_binario);
            }
            encolar(&listaDataset, img, numero);
        }
        fclose(datos_binario);
    }
    printf("Loaded dataset \n");

    double distancia = 0;

    Celda* celda_actual = listaDataset.ini;
    Celda* celda_comparar = listaDataset.ini;

    for (int i = 0; i < listaDataset.tamanio; i++) {
        for (int j = 0; j < listaDataset.tamanio; j++) {
            if (i != j) {
                int dist = distancia_euclideana(celda_actual->image, celda_comparar->image);  // 0 - 7140
                if (!estaLleno(distMinimas))
                    insertarMaxMonticulo(&distMinimas, (tipoElementoMaxMonticulo){.distancia = dist, .tipoNumero = celda_comparar->numero});
                else {
                    if (dist < devolverRaiz(distMinimas).distancia) {
                        eliminarElemento(&distMinimas, devolverRaiz(distMinimas));
                        insertarMaxMonticulo(&distMinimas, (tipoElementoMaxMonticulo){.distancia = dist, .tipoNumero = celda_comparar->numero});
                    }
                }
            }
            celda_comparar = celda_comparar->sig;
        }
        celda_actual = celda_actual->sig;
        celda_comparar = listaDataset.ini;
        for (int j = 0; j < N; j++) {
            tipoElementoMaxMonticulo aux = devolverRaiz(distMinimas);
            tipos[aux.tipoNumero][0]++;
            tipos[aux.tipoNumero][1] += aux.distancia;
            eliminarElemento(&distMinimas, devolverRaiz(distMinimas));
        }
        int max_ap = 0, max_tipo = 0;
        for (int j = 0; j < 10; j++) {
            if (max_ap < tipos[j][0]) {
                max_tipo = j;
                max_ap = tipos[j][0];
            } else if (max_ap == tipos[j][0]) {
                if (tipos[max_tipo][1] > tipos[j][1]) {
                    max_ap = tipos[j][0];
                    max_tipo = j;
                }
            }
        }
        matriz_dispersion[celda_actual->numero][max_tipo]++;
        tiposTeoricos[i] = max_tipo;
        resetTablaTipos(tipos);
    }

    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            printf(" %d", matriz_dispersion[i][j]);
        }
        printf("\n");
    }

    free(nombre_datos_binario);
}