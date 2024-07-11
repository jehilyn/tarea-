#include <stdio.h>

/* Diagonal principal
El programa, al recibir como dato una matriz de tipo entero, escirbe la
diagonal principal. */

const int TAM = 10;

void lectura(int [][TAM], int);         /* Prototipos de funciones. */
void Imprime(int [][TAM], int);
/* Observa que siempre es necesario declarar el numero de columnas. Si no lo
haces, el compilador marcara en error de sintaxis. */

void manin(void)
{
int MAT[TAM][TAM];
lectura(MAT, TAM);
imprime(MAT, TAM);
}

void lectura(int A[][TAM], int F)
/* La funcion lectura se utliza para leer un arreglo bidimensional. Observa
que solo se debe pasar como parametro el numero de filas ya que la matriz
es cuadrada. */
{
int I, J;
for (I=0; I<F; I++)
    for (J=0; J<F; J++)
    {
        printf("Ingrese el elemento %d %d: ", I+1, J+1);
        scanf("%d", &A[I][J]);
        }
}
void imprime(int A[][TAM], int F)
/* La funcion imprime se utiliza para escribir un arreglo bidimensional
cuadrado de F filas y columnas. */
{
int I, J;
for (I=0; I<F; I++)
    for (J=0; J<TAM; J++)
    if (I == J)
              printf("\nDiagonal %d %d: %d ", I, J, A[I][J]);

}
