#include <stdio.h>

/* Asigna.
/* El programa, al recibir un arreglo bidimensional cuadrado, asigna elementos en
funcion del modulo (residuo) a un arreglo unidimensional. */

void lectura(int [][10], int);
void calcula(int [][10], float [], int);
float mod0(int [][10], int, int);
float mod1(int [][10], int);    /* prototipos de funciones. */
float mod2(int [][10], int, int);
void imprime(float [10], int);

void main(void)
{
int MAT [10][10], TAM;
float VEC[10];
do
{
printf("Ingrese el tama�o de la matriz: ");
scanf("%d", &TAM);
}
while (TAM >10 || TAM < 1);
lectura(MAT, TAM);
calcula(MAT, VEC, TAM);
imprime(VEC, TAM);
}

void lectura(int A[][10], int N)
/* La funcion lectura se utiliza para leer un arreglo bidimensional cuadrado
de este tipo entero. */
{
int I, J;
for (I=0; I<N; I++)
for (J=0; J<N; J++)
{
    printf("Ingrese el elemento %d %d: ", I+1, J+1);
    scanf("%d", &A[I][J]);
}
}

void calcula(int A[][10], float B[], int N)
/* Esta funcion se utiliza tanto para calcular el modulo entres lo indices del
arreglo unidimensional y 3, como para llamar a las funciones
correspondientes para resolver el problema. */
{
int I;
for (I=0; I<N; I++)
switch (I%3)
{
    case 1: B[I] = mod1 (A,I);
         break;
    case 2: B[I] = mod2 (A, I, N);
         break;
    default: B[I] = mod0 (A,I,N);
         break;
}
}
float mod0 (int A[][10], int K, int M)
/* Esta funcion calcula el cociente entre productoria y una sumatoria. */
{
int I;
float PRO = 1.0, SUM = 0.0;
for (I=0; I<M; I++)
{
    PRO *= A[I][K];
    SUM += A[I][K];
}
return (PRO / SUM);
}
float mod1(int A[][10], int N)
/* Esta funcion obtiene el resultado de una sumatoria. */
{
int I;
float SUM = 0.0;
for (I=0; I<N; I++)
    SUM += A[N][I];
return (SUM);
float mod2(int A[][10], int N, int M)
/* Esta funcion obtiene el resultado de la productoria. */
{
int I;
float PRO = 1.0;
for (I=N; I<M; I++)
    PRO *= A[I][N];
return (PRO);
}

void imprime(float B[], int N);
/* Esta funcion se utiliza para escribir un arreglo unidimensional de tipo
real de N elementos. */
{
int I;
for (I=0; I<N; I++)
    printf("\nElemento %d: %.2f", I, B[I]);
}
