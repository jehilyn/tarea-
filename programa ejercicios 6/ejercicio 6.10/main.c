#include <stdio.h>

/* Cuadrado magico.
El programa genera un cuadrado magico siguiente los criterios enunciados
anteriormente. */

const int MAX = 50;
void cuadrado(int [][MAX], int);
void imprime(int [][MAX], int);      /* Prototipos de funciones. */

void main(void)
{
int CMA[MAX][MAX], TAM;
do
{
    printf("Ingrese el tama�o impar de la matriz: ");
    scanf("%d", &TAM);
}
while ((TAM > MAX || TAM < 1) && (TAM % 2));
/* Se verifica el tama�o del arreglo y del orden (impar) del mismo*/
cuadrado (CMA, TAM);
imprime(CMA, TAM);
}
void cuadrado(int A[][MAX], int N)
/* Esta funcion se utiliza para formar el cuadrado magico. */
{
int I = 1; FIL = 0; COL = N / 2, NUM = N * N;
while (I <= NUM)
{
    A[FIL][COL] = I;
    if (I%N != 0)
    {
        FIL = (FIL - 1 + N) % N;
        COL = (COL + 1) % N;
    }
    else
        FIL++;
    I++;
}
}
void imprime(int A[][MAX], int N)
/* Esta funcion se utiliza para escribir el cuadrado magico. */
{
int I, J;
for (I=0; I<N; I++)
    for (J=0; J<N; J++)
    printf("\nElemento %d %d: %d ", I+1; J+1; A[I][J]);
}
