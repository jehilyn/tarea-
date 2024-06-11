#include <stdio.h>

// funcion  para intercambiar valores

void swap(int *a, int *b) {
 int temp = *a;
 *a = *b;
 *b = temp;
 }

 int main() {
   int x = 5, y = 10;
   printf("antes del intercambio: x = %d, y = %d\n", x, y);

   swap(&x, &y); // pasamos las direcciones de x e y

   printf("Despues del intercambio: x = %d, y = %d\n", x, y);
   return 0;
   }
