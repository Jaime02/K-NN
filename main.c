#include <stdio.h>
#include <stdlib.h>

void lee_imagen(FILE* archivo, int n) {
    char *nombre = (char*)malloc(20 * sizeof(char));

    sprintf(nombre, "img/0/0-%d.bin", n);

    FILE* ibin = fopen(nombre, "w+");

    char pixel;
    // 28x28 = 784
    for (int i = 0; i < 784; i++) {
        fread(&pixel, sizeof(char), 1, archivo);
        fwrite(&pixel, sizeof(char), 1, ibin);
    }
    fclose(ibin);
}

int main() {
    FILE* archivo  = fopen("data0.bin", "r");
    
    
    for (int i = 0; i < 1000; i++)
        lee_imagen(archivo, i);
    
    fclose(archivo);
}