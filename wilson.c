#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "list.h"

int main() {
    Imagen dataset[10][1000];

    // Create a list of images with the good images
    Lista lista;

    crear_lista(&lista);

    char* nombre_datos_binario = (char*)malloc(25);
    printf("Loading dataset... \n");
    for (int i = 0; i < 10; i++) {
        sprintf(nombre_datos_binario, "binary_data/data%d.bin", i);

        FILE* datos_binario = fopen(nombre_datos_binario, "rb");

        for (int j = 0; j < 1000; j++) {
            for (int k = 0; k < 28; k++) {
                for (int l = 0; l < 28; l++) {
                    fread(&dataset[i][j][k][l], sizeof(char), 1, datos_binario);
                }
            }
        }
        fclose(datos_binario);
    }
    printf("Loaded dataset \n");

    float distancia = 0;
    for (int actual = 0; actual < 10; actual++) {
        for (int j = 0; j < 1000; j++) {
            for (int k = 0; k < 1000; k++) {
                for (int otro = 0; otro < 10; otro++) {
                    if (j != k && otro != actual) {
                        distancia = 0;

                        // It calculates the euclidean distance between the two
                        // images which are stored as a array of arrays of chars
                        for (int row = 0; row < 28; row++) {
                            for (int col = 0; col < 28; col++) {
                                float res = ((float)dataset[actual][j][row][col]) - ((float)dataset[otro][k][row][col]);
                                printf(" %f", res);
                                distancia += pow(res, 2);
                            }
                            sleep(1);
                        }

                        distancia = sqrt(distancia);
                        printf("%f\n", distancia);
                        // If the distance is lower than the threshold, the
                        // image is added to the list of the valid images
                        sleep(1);
                    }
                }
            }
            // printf("Acabo con el numero %d \n", j);
        }
    }
    free(nombre_datos_binario);
}