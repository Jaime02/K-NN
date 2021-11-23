#include <stdio.h>

#include "maxMonticulo.h"

int main() {
    int numEl, opcion;
    tipoElementoMaxMonticulo elem;
    tipoMaxMonticulo mon;
    // printf("Introduce el numero maximo de elementos: ");
    // scanf("%d", &numEl);
    numEl = 6;
    nuevoMaxMonticulo(&mon, numEl);
    do {
        printf("\n--------MENU-------- \n");
        printf("1 - Insertar un elemento en el monticulo\n");
        printf("2 - Eliminar un elemento del monticulo\n");
        printf("3 - Mostrar el elemento de la raiz\n");
        printf("4 - Mostrar el monticulo en anchura\n");
        printf("5 - Salir.\n");
        printf("Escoja una opcion: ");
        scanf("%d", &opcion);
        switch (opcion) {
            case 1:
                printf("Introduce distancia y tipo: ");
                scanf("%d %d", &elem.distancia, &elem.tipo_numero);
                if(!estaLleno(mon))
                    insertarMaxMonticulo(&mon, elem);
                else{
                    if(elem.distancia < devolverRaiz(mon).distancia){
                        eliminarElemento(&mon, devolverRaiz(mon));
                        insertarMaxMonticulo(&mon, elem);
                    }
                }
                break;
            case 2:
                printf("Introduce el entero: ");
                scanf("%d %d", &elem.distancia, &elem.tipo_numero);
                eliminarElemento(&mon, elem);
                break;
            case 3:
                printf("El elemento de la raiz esdistancia  %d y tipo %d\n", devolverRaiz(mon).distancia, devolverRaiz(mon).tipo_numero);
                break;
            case 4:
                printf("Los elementos del monticulo son:\n");
                mostrarAnchura(mon);
                printf("\n");
                break;
        }
    } while (opcion < 5);
}