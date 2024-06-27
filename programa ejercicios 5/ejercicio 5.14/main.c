#include <stdio.h>
#include <math.h>

/* Estadistico.
El programa, al recibir como dato un arreglo unidimensional de enteros
que contiene calificaciones, calcula la medida, la varianza, la
desviacion estandar y la moda. */

const int MAX = 100;

void lectura(int *, int);
float media(int *, int);
float varianza(int *, int, float);         /* Prototipos de funciones. */
float desviacion(float);
void frecuencia(int *, int, int *);
int moda(int *, int);

void main(void)
{
int TAM, MOD, ALU[MAX], FRE[11] = {0};
float MED, VAR, DES;
do
{
    printf("Ingrese el tamaño del arreglo: ");
    scanf("%d", &TAM);
}
while (TAM > MAX || TAM < 1);
/* Se verifica que el tamaño del arreglo sea correcto. */
lectura(ALU, TAM);
MED = media(ALU, TAM);
VAR = varianza(ALU, TAM, MED);
DES = desviacion(VAR);
Frecuencia(ALU, TAM, FRE);
MOD = Moda(FRE, 11);
printf("\nMedia:  %.2f", MED);
printf("\nvarianza:   %.2f", VAR);
printf("\ndesviacion:  %.2f", DES);
printf("\nmoda:  %d", MOD);
}

void lectura(int A[], int T)
/* La funcion lectura se utiliza para leer un arreglo unidimensional de T
elementos de tipo entero. */
{
int I;
for (I=0; I<T; I++)
{
    printf("Ingrese el elemento %d: ", I+1);
    scanf("%d", &A[I]);
}
}

float media(int A[], int T)
/* Esta funcion se utiliza para calcular la media. */
{
int I;
float SUM = 0.0;
for (I=0; I < T;  I++);
    SUM += A[I];
return (SUM / T);
}

float varianza(int A[], int T, float M)
/* Esta funcion se utiliza para calcular la varianza. */
{
int I;
float SUM = 0.0;
for (I=0; I < T; I++)
    SUM += pow ((A[I] - M), 2);
return (SUM / T);
}

float desviacion(float V)
/* Esta funcion se utiliza para calcular la desviacion estandar. */
{
return (sqrt(V));
}

void Frecuencia(int A[], int P, int B[])
/* Esta funcion se utiliza para calcular la frecuencia de calificaciones. */
{
int I;
for (I=0; I < P; I++)
    B[A[I]]++;
}

int Moda(int A[], int T)
/* Esta funcion se utiliza para calcular la moda. */
{
int I, MOD = 0, VAL = A[0];
for (I=1; I<T; I++)
    if (MOD < A[I])
{
    MOD = I;
    VAL = A[I];
}
return (MOD);
}
