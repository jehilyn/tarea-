#include <stdio.h>

int main (){
    int edad;

    // pedir al usuario que ingrese su edad
    printf("Ingrese su edad: ");
    scanf("%d", &edad);

    // Inferencia logica usando estructuras condicionales
       if(edad >= 18) {
            // premisa: Si la edad es 18 o mayor, entonces la persona puede votar
            printf("La persona puede votar.\n");
       }else{
           // Premisas: Si la edad es menor de 18, entonces la persona no puede votar
             printf("La persona no puede votar.\n");
              }
              return 0;
              }

