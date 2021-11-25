#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "list.h"
#include "maxMonticulo.h"

#define N 50  // La N del KNN

int distancia_euclideana(Imagen img1, Imagen img2) {
    // Entre 0 y 7140
    int distancia = 0;
    for (int i = 0; i < 28 * 28; i++) {
        distancia += (int)pow((abs(img1[i] - img2[i])), 2);
    }
    return (int)sqrt(distancia);
}

void crea_img_vacia(Imagen* img) {
    char* nombre_datos_binario = (char*)malloc(25);
    int numero = 2;
    sprintf(nombre_datos_binario, "../binary_data/data%d.bin", numero);
    FILE* datos_binario = fopen(nombre_datos_binario, "rb");

    for (int k = 0; k < 28 * 28; k++) {
        fread(&((*img)[k]), sizeof(char), 1, datos_binario);
    }
    fclose(datos_binario);
}

int main(int argc, char* argv[]) {
    Celda* aux;
    Lista listaDataset;
    crear_lista(&listaDataset);
    tipoMaxMonticulo distMinimas;
    nuevoMaxMonticulo(&distMinimas, N);

    char* nombre_datos_binario = (char*)malloc(25);
    Imagen img;
    Imagen img_entrada;

    // El programa recibe como argumento una imagen a comparar
    if (argc == 1) {
        printf("No se ha introducido ningun parametro.\n");
        return 0;
    } else if (argc == 2) {
        // Se lee la imagen a comparar
        char* nombre_imagen = argv[1];
        FILE* imagen = fopen(nombre_imagen, "rb");

        if (imagen == NULL) {
            printf("No se ha podido abrir la imagen.\n");
            return 0;
        }

        for (int k = 0; k < 28 * 28; k++) {
            fread(&(img_entrada[k]), sizeof(unsigned char), 1, imagen);
        }

        fclose(imagen);
    } else {
        printf("Demasiados parametros.\n");
        return 0;
    }

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

    Celda* celda_comparar = listaDataset.ini;

    int tipos[10][2];
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 2; ++j) tipos[i][j] = 0;
    }

    int max_ap = 0, max_tipo = 0;

    for (int i = 0; i < listaDataset.tamanio; i++) {
        int dist = distancia_euclideana(img_entrada,
                                        celda_comparar->image);  // 0 - 7140
        if (!estaLleno(distMinimas))
            insertarMaxMonticulo(
                &distMinimas,
                (tipoElementoMaxMonticulo){
                    .distancia = dist, .tipoNumero = celda_comparar->numero});
        else {
            if (dist < devolverRaiz(distMinimas).distancia) {
                eliminarElemento(&distMinimas, devolverRaiz(distMinimas));
                insertarMaxMonticulo(
                    &distMinimas, (tipoElementoMaxMonticulo){
                                       .distancia = dist,
                                       .tipoNumero = celda_comparar->numero});
            }
        }

        celda_comparar = celda_comparar->sig;
    }

    for (int j = 0; j < N; j++) {
        tipoElementoMaxMonticulo aux = devolverRaiz(distMinimas);
        tipos[aux.tipoNumero][0]++;
        tipos[aux.tipoNumero][1] += aux.distancia;
        eliminarElemento(&distMinimas, devolverRaiz(distMinimas));
    }

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

    printf("Tipos: \n");
    for (int i = 0; i < 10; ++i) {
        printf("%d: %d\n", i, tipos[i][0]);
    }

    printf("Max tipo: %d\n", max_tipo);

    fflush(stdout);
    free(nombre_datos_binario);
}