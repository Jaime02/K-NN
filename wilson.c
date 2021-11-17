#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "list.h"

int distancia_euclideana(Imagen img1, Imagen img2) {
    int distancia = 0;

    for (int i = 0; i < 28 * 28; i++) {
        distancia += pow((img1[i] - img2[i]), 2);
    }
    return (int)sqrt(distancia);
}

int main() {
    Lista dataset_lista;
    crear_lista(&dataset_lista);

    char* nombre_datos_binario = (char*)malloc(25);
    Imagen img;
    
    printf("Loading dataset... \n");
    for (int numero = 0; numero < 10; numero++) {
        sprintf(nombre_datos_binario, "binary_data/data%d.bin", numero);

        FILE* datos_binario = fopen(nombre_datos_binario, "rb");

        for (int j = 0; j < 1000; j++) {
            for (int k = 0; k < 28 * 28; k++) {
                fread(&(img[k]), sizeof(char), 1, datos_binario);
                encolar(&dataset_lista, img, numero);
            }
        }
        fclose(datos_binario);
    }
    printf("Loaded dataset \n");

    float distancia = 0;

    Celda* celda_actual = dataset_lista.ini;
    Celda* celda_comparar = celda_actual->sig;

    while (celda_actual != NULL) {
        
        celda_actual = celda_actual->sig;


    }



    free(nombre_datos_binario);
}