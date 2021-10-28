#include <stdio.h>
#include <stdlib.h>

void lee_imagen(FILE* archivo, int numero, int num_imagen) {
    char *nombre = (char*)malloc(20 * sizeof(char));
    sprintf(nombre, "img/%d/bin/0-%d.bin", numero, num_imagen);

    FILE* ibin = fopen(nombre, "wb+");

    char pixel;
    // 28x28 = 784
    for (int i = 0; i < 784; i++) {
        fread(&pixel, sizeof(char), 1, archivo);
        fwrite(&pixel, sizeof(char), 1, ibin);
    }
    fclose(ibin);
}

int main() {
    int numero;
    printf("Introduce el numero que quieres convertir: ");
    scanf(" %d", &numero);

    if (numero < 0 || numero > 9) {
        printf("Cagaste \n");
        return -1;
    }

    char* nombre = malloc(sizeof(char)*15);
    
    sprintf(nombre, "binary_data/data%d.bin", numero);

    FILE* archivo  = fopen(nombre, "rb");

    for (int i = 0; i < 1000; i++)
        lee_imagen(archivo, numero, i);
    
    fclose(archivo);
}