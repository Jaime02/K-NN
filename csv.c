#include <stdio.h>
#include <stdlib.h>

void read_image(FILE* file, int numero, int num_imagen) {
    char *name = (char*)malloc(20 * sizeof(char));
    sprintf(name, "img/%d/bin/%d-%d.bin", numero, numero, num_imagen);

    FILE* img_bin = fopen(name, "wb+");

    char pixel;
    for (int i = 0; i < 28*28; i++) {
        fread(&pixel, sizeof(char), 1, file);
        fwrite(&pixel, sizeof(char), 1, img_bin);
    }
    free(name);
}

int main() {
    for (int num = 0; num < 10; num++) {
        printf("%d%%\n", num*10);
        char* name_src = malloc(sizeof(char)*25);
        
        sprintf(name_src, "binary_data/data%d.bin", num);

        char* name_dst = malloc(sizeof(char)*25);
        sprintf(name_dst, "binary_data/data%d.bin", num);

        FILE* file_src  = fopen(name_src, "rb");
        FILE* file_dst = fopen();
        for (int i = 0; i < 1000; i++)
            read_image(file_src, num, i);
        
        fclose(file_src);
        free(name);
    }
}