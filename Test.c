#include <stdio.h>
#include <stdlib.h>
#include "CustomHeaders/SafeInput.h"
#include "CustomHeaders/IntArray.h"

void menu(){
    printf("1. Agregar dato al arreglo\n");
    printf("2. Cambiar dato del arreglo\n");
    printf("3. Imprimir arreglo\n");
    printf("0. Salir\n");
    printf("\tOpcion: ");
}

int main(int argc, char const *argv[]) {
    const size_t SIZE = 10;
    INT_ARRAY_T array;
    int opcion = 0;
    int flag = 0;
    int controlInput = 0;
    array = malloc(sizeof(INT_ARRAY));
    setUpArray_int(array, SIZE);
    do {
        flag = 0;
        menu();
        controlInput = read_Int(&opcion);
        if (controlInput) {
            switch (opcion) {
                case 1: {
                    int val;
                    printf("Ingrese el numero a insertar: ");
                    controlInput = read_Int(&val);
                    if (controlInput) {
                        pushValueArray_int(array, val);
                    } else {
                        printf("Fallo de entrada\n");
                    }
                    break;
                }
                case 2: {
                    int val;
                    int index;
                    int controlInput_aux;
                    printf("Ingrese el numero a insertar: ");
                    controlInput = read_Int(&val);
                    printf("Ingrese el indice del numero a reemplazar: ");
                    controlInput_aux = read_Int(&index);
                    if (controlInput && controlInput_aux) {
                        popValueArray_int(array, index, val);
                    } else {
                        printf("Fallo de entrada\n");
                    }
                    break;
                }
                case 3: {
                    printArray_int(array);
                    break;
                }
                case 0: {    
                    flag = 1;
                    break;
                }
            }
        } else {
            printf("Entrada invalida\n");
        }

    } while (!flag);

    return 0;
}
