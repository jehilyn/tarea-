#include <stdio.h>

#include <stdio.h>

int main(){
int num = 10; // declaramos un variable entra "num" con valor 10. //
int *ptr; // declaramos un puntero a un entero //
ptr = &num; // asignamos la direccion de memoria de "num" de puntero "ptr" //

printf("valor de num: %d\n", num);
printf("direccion de num: %p\n", &num);
printf("valor apuntado por el puntero ptr: %d\n", *ptr);
printf("direccion almacenada en el puntero ptr: %p\n", ptr);
return 0;

}
