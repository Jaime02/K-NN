#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "list.h"
#include "maxMonticulo.h"

#define N 20 //La N del KNN

int distancia_euclideana(Imagen img1, Imagen img2) {
    double distancia = 0;

    for (int i = 0; i < 28 * 28; i++) {
        distancia += (int)pow((img1[i] - img2[i]), 2.0);
    }
    return (int)sqrt(distancia);
}
void reset_tabla_tipos(int t[10][2]){
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 2; ++j)
            t[i][j] = 0;
    }
}

void ini_matriz(int m[10][10]){
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j)
            m[i][j] = 0;
    }
}

int main() {
    int tipos_teoricos[10000], tipos[10][2], matriz_dispersion[10][10];
    reset_tabla_tipos(tipos);
    Lista dataset_lista;
    crear_lista(&dataset_lista);
    tipoMaxMonticulo dist_minimas;
    nuevoMaxMonticulo(&dist_minimas, N);
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
            encolar(&dataset_lista, img, numero);
        }
        fclose(datos_binario);
    }
    printf("Loaded dataset \n");
    fflush(stdout);

    double distancia = 0;

    Celda* celda_actual = dataset_lista.ini;
    Celda* celda_comparar = dataset_lista.ini;

    for (int i = 1; i < dataset_lista.tamanio; i++){
        printf("%d ", i);
        for (int j = 1; j < dataset_lista.tamanio; j++) {
            if(i != j) {
                int dist = distancia_euclideana(celda_actual->image, celda_comparar->image);//0 - 7140
                if (!estaLleno(dist_minimas))
                    insertarMaxMonticulo(&dist_minimas,
                                         (tipoElementoMaxMonticulo) {.distancia = dist, .tipo_numero = celda_comparar->numero});
                else {
                    if (dist < devolverRaiz(dist_minimas).distancia) {
                        eliminarElemento(&dist_minimas, devolverRaiz(dist_minimas));
                        insertarMaxMonticulo(&dist_minimas,
                                             (tipoElementoMaxMonticulo) {.distancia = dist, .tipo_numero = celda_comparar->numero});
                    }
                }
            }else{celda_comparar = celda_comparar->sig;continue;}
            celda_comparar = celda_comparar->sig;

        }
        celda_actual = celda_actual->sig;
        celda_comparar = dataset_lista.ini;
        for (int j = 0; j < N; j++) {
            tipoElementoMaxMonticulo aux = devolverRaiz(dist_minimas);
            tipos[aux.tipo_numero][0] ++;
            tipos[aux.tipo_numero][1] += aux.distancia;
            eliminarElemento(&dist_minimas, devolverRaiz(dist_minimas));
        }
        int max_ap = 0, max_tipo = 0;
        for (int j = 0; j < 10; j++) {
            if(max_ap < tipos[j][0]){
                max_tipo = j;
                max_ap = tipos[j][0];
            }else if(max_ap == tipos[j][0]){
                if(tipos[max_tipo][1] > tipos[j][1]){
                    max_ap = tipos[j][0];
                    max_tipo = j;
                }
            }
        }
        matriz_dispersion[celda_actual->numero][max_tipo]++;
        tipos_teoricos[i] = max_tipo;
        reset_tabla_tipos(tipos);
    }

    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            printf(" %d",matriz_dispersion[i][j]);
        }
        printf("\n");
    }

    free(nombre_datos_binario);
}