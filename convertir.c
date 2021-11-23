#include <stdio.h>
#include <stdlib.h>

void read_image(FILE* file, int numero, int num_imagen) {
    char *name = (char*)malloc(20 * sizeof(char));
    sprintf(name, "./img/%d/bin/%d-%d.bin", numero, numero, num_imagen);

    FILE* img_bin = fopen(name, "wb+");

    char pixel;
    for (int i = 0; i < 28*28; i++) {
        fread(&pixel, sizeof(char), 1, file);
        fwrite(&pixel, sizeof(char), 1, img_bin);
    }
    fclose(img_bin);
    free(name);
}

int main() {
    for (int num = 9; num < 10; num++) {
        printf("%d%%\n", num*10);
        char* name = malloc(sizeof(char)*15);
        
        sprintf(name, "./binary_data/data%d.bin", num);

        FILE* file  = fopen(name, "rb");

        for (int i = 0; i < 1000; i++)
            read_image(file, num, i);
        
        fclose(file);
        free(name);
    }
}