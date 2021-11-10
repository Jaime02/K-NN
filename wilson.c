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
    Imagen aux;
    
    printf("Loading dataset... \n");
    for (int numero = 0; numero < 10; numero++) {
        sprintf(nombre_datos_binario, "binary_data/data%d.bin", i);

        FILE* datos_binario = fopen(nombre_datos_binario, "rb");

        for (int j = 0; j < 1000; j++) {
            for (int k = 0; k < 28 * 28; k++) {
                fread(&(aux[j][k]), sizeof(char), 1, datos_binario);
                encolar(dataset_lista, aux, numero);
            }
        }
        fclose(datos_binario);
    }
    printf("Loaded dataset \n");

    float distancia = 0;
    

    Celda* celda_actual = dataset_lista->ini;
    for (int i = 0; i < dataset_lista->tamanio; i++) {

        for (int j = 0; j < dataset_lista->tamanio; j++) {
            if (i == j) {
                continue;
            }
            // array 2d clase distancia 
            distancia = distancia_euclideana(celda_actual->imagen, celda_actual->imagen);
            printf("%d \n", distancia);
        }


        celda_actual = celda_actual->sig;
    }



    free(nombre_datos_binario);
}