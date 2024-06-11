#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Ingrese el numero de elementos: ");
    scanf("%d", &n);

    // asignacion dinamica de memoria para un arreglo de n elementos
    int *arr = (int*) malloc(n * sizeof(int));

    if (arr == NULL) {
            printf("Error al asignar memoria\n");
            return 1;
        }

        // Imprimir los elementos del arreglo
        for (int i = 0; i < n; i++) {
                printf("arr[%d] = %d\n", i, arr[i]);
        }

        // Liberar la memoria asignada
          free(arr);

          return 0;
        }
