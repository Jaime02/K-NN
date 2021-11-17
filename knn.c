#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "list.h"
#include "maxMonticulo.h"

#define N 5 //La N del KNN

double distancia_euclideana(Imagen img1, Imagen img2) {
    // Entre 0 y 7140
    double distancia = 0;
    for (int i = 0; i < 28 * 28; i++) {
        distancia += pow((double)(abs(img1[i] - img2[i])), 2.0);
    }
    return sqrt(distancia);
}

int main() {
    Lista dataset_lista;
    crear_lista(&dataset_lista);
    tipoMaxMonticulo dist_minimas;
    nuevoMaxMonticulo(&dist_minimas, N);

    char* nombre_datos_binario = (char*)malloc(25);
    
    Imagen img;
    
    FILE* datos_binario;
    printf("Loading dataset... \n");
    for (int numero = 0; numero < 10; numero++) {
        sprintf(nombre_datos_binario, "binary_data/data%d.bin", numero);
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
    free(nombre_datos_binario);
}