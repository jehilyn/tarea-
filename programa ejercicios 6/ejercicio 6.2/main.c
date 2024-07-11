#include <stdio.h>

/* Suma matrices.
El programa, al recibir como datos dos arreglos bidimensional del mismo
tamaño, calcula la suma de ambos y la almacena un tercer arreglo
bidimensional. */

const int MAX = 50;

/* Prototipo de funciones. */
void lectura(int [][MAX], int, int);
void suma(int [][MAX], int [][MAX], int [][MAX], int, int);
void imprime(int [][MAX], int, int);

void main(void)
{
int MA[MAX][MAX], MB[MAX][MAX], MC[MAX][MAX];
/* Declaracion de los tres arreglos. */
int FIL, COL;
do
{
    printf("Ingrese el numero de filas de los arreglos: ");
    scanf("%d", &FIL);
}
while (FIL> MAX || FIL< 1);
/* Se verifica que el numero de filas sea correcto. */
do
{
    printf("Ingrese el numero de columnas de los arreglos: ");
    scanf("%d", &COL);
}
while (COL > MAX || COL < 1);
/* Se verifica que el numero de columnas sea correcto. */
printf("\nlectura del Arreglo MA\n");
lectura(MA, FIL, COL);
printf("\nlectura del Arreglo MB\n");
lectura(MB, FIL, COL);
suma (MA, MB, MC, FIL, COL);
printf("\nImprime del arreglo MC\n");
imprime (MC, FIL, COL);
}

void lectura(int A[][MAX], int F, int C)
/*La funcion lectura se utiliza para leer u arreglo biodimensional entero de F
filas y  C columnas. */
{
int I, J;
for (I=0; I<F; I++)
    for (J=0; J<C; J++)
    {
        printf("Ingrese el elemento %d %d: ", I+1, J+1);
        scanf("%d", &A[I][J]);
    }
}
void suma(int M1[][MAX], int M2[][MAX], int M3[][MAX], int F, int C)
/* La funcion suma se utiliza para sumar los arreglos y almacenar el resultado
en un tercer arreglo bidimensional. */
{
int I, J;
for (I=0; I<F; I++)
    for (J=0; J<C; J++)
         M3[I][J]=M1[I][J] + M2[I][J];
}

void imrpime(int A[][MAX], int F, int C)
/* La funcion imrpime se utiliza para escribir un arreglo bidimensional de tipo
entero de F filas y C columnas. */
{
int I, J;
for (I=0; I<F; I++)
    for (J=0; J<C; J++)
        printf("\nElemento %d %d: %d ", I, J, A[I][J]);
}
