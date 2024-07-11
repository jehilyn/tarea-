#include <stdio.h>


/* Simetrico.
El programa, al recibir como dato un arreglo bidimensional cuadrado, determina
si el mismo es simetrico. */

const int MAX = 100;

void lectura(int [][MAX], int);      /* Prototipos de funcions. */
int Simetrico(int [][MAX], int);

void main(void)
{
int MAT[MAX][MAX], N, RES;
do
{
    printf("Ingrese el tama�o del arreglo: ");
    scanf("%d", &N);
}
while (N > MAX || N < 1);     /* Se verifica que el tama�o del arreglo sea
                                valido. */
Lectura (MAT, N);
RES = Simetrico(MAT, N);
if (RES)
    printf("\nEl arreglo bidimensional es simetrico");
else
    printf("\nEl arreglo bidimensional no es simetrico");
}

void lectura(int A[][MAX], int T)
/*La funcion lectura se utiliza para leer un arreglo bidimensional cuadrado de
tipo entero de T filas  y T columnas. */
{
int I, J;
for (I=0; I<T; I++)
    for (J=0; J<T; J++)
{
    printf("Fila: %d\tColumna: %d", I+1, J+1);
    scanf("%d", &A[I][J]);
}
}

int Simetrico (int A[][MAX], int T)
/* La funcion simetrico se utiliza para determinar si el arreglo bidimensional
cuadrado es Simetrico. Si es simetrico regresa 1, en caso contrario, 0.
Observa que el segundo ciclo solamente se recorre la matriz triangular
inferior, sin la diagonal principal. */
{
int I = 0; J, F = 1;
while ((I < T) && F)
{
    J = 0;
    while ((J < I) && F)
        if (A[I][J] == A [J][I])
              J++;
    else
        F = 0;
    I++;
}
return (F);
}
