#include <stdio.h>

/* Ordenacion por insercion directa. */

const int MAX = 100;

void lectura(int *, int);
void Ordena(int *, int);            /* Prototipos de funciones. */
void Imprime(int *, int);

void main(void)
{
int TAM, VEC[MAX];
do
{
    printf("Ingrese el tama�o del arreglo: ");
    scanf("%d", &TAM);
}
while (TAM>MAX || TAM<1);         /* Se verifica que el tama�o del arreglo sea
                                   correcto. */
lectura(VEC, TAM);
Ordena(VEC, TAM);
Imprime(VEC, TAM);
}

void lectura(int A[], int T)
/* La funcion lectura se utiliza para leer un arreglo unidimensional de T
elementos de tipo entero. */
{
int I;
for (I=0; I<T; I++)
{
    printf("Ingrese el elemento %d: ", I + 1);
    scanf("%d", &A[I]);
}
}

void Imprime(int A[], int T)
/* Esta funcion se utiliza para escribir un arreglo unidimensional
ordenado de T elementos de tipo entero. */
{
int I;
for (I=0; I<T; I++)
    printf("\nA[%d]: %d", I, A[I]);
}
void Ordena(int A[], int T)
/* La funcion ordena utiliza el metodo de insercion directa para ordenar
los elementos del arreglo unidimensional A. */
{
int AUX, L, I;
for (I=1; I<T; I++)
{
    AUX = A[I];
    L = I - 1;
    while ((L >= 0) && (AUX < A[L]))
    {
      A[L+1] = A[L];
      L --;
    }
    A[L+1] = AUX;
}
}
