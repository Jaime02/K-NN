#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "maxMonticulo.h"

#define N 20//La N del KNN

int distancia_euclideana(Imagen img1, Imagen img2) {
    // Entre 0 y 7140
    int distancia = 0;
    for (int i = 0; i < 28 * 28; i++) {
        distancia += (int)pow((abs(img1[i] - img2[i])), 2);
    }
    return (int)sqrt(distancia);
}

void crea_img_vacia(Imagen *img){
    char* nombre_datos_binario = (char*)malloc(25);
    int numero = 2;
    sprintf(nombre_datos_binario, "../binary_data/data%d.bin", numero);
    FILE* datos_binario = fopen(nombre_datos_binario, "rb");

    for (int k = 0; k < 28 * 28; k++) {
        fread(&((*img)[k]), sizeof(char), 1, datos_binario);
    }
    fclose(datos_binario);
}

int main() {
    Celda *aux;
    Lista dataset_lista;
    crear_lista(&dataset_lista);
    tipoMaxMonticulo dist_minimas;
    nuevoMaxMonticulo(&dist_minimas, N);

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

    aux = dataset_lista.ini;
    crea_img_vacia(&img);

    for(int i = 0; i < dataset_lista.tamanio; i++){
        int dist = distancia_euclideana(img, aux->image);//0 - 7140
        if(!estaLleno(dist_minimas))
            insertarMaxMonticulo(&dist_minimas,(tipoElementoMaxMonticulo) {.distancia = dist, .tipo_numero = aux->numero});
        else{
            if(dist < devolverRaiz(dist_minimas).distancia){
                eliminarElemento(&dist_minimas, devolverRaiz(dist_minimas));
                insertarMaxMonticulo(&dist_minimas, (tipoElementoMaxMonticulo) {.distancia = dist, .tipo_numero = aux->numero});
            }
        }
        aux = aux->sig;
    }
    printf("Las dist minimas son:\n");
    mostrarAnchura(dist_minimas);
    fflush(stdout);
    free(nombre_datos_binario);
}