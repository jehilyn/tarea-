#include <stdio.h>

/* Archivo y cadenas de caracteres.
El programa escribe cadenas de caracteres en un archivo. */

void main(void)
{
char cad[50];
int res;
FILE *ar;
if ((ar = fopen("arc.txt", "w")) != NULL)
    /* Se abre el archivo para escritura. En la misma instruccion se verifica si se
    pudo abrir. */
{
    printf("\n=¿Desea ingresar una cadena de caracteres? Si-1 No-2:");
    scanf("%d", &res);
    while (res)
    {
        fflush(stdin);
        printf("Ingrese la cadena: ");
        gets(cad);
        fputs(cad, ar);     /* Observa la forma como se escribe la cadena en el
                              archivo. */
        printf("\n¿Desea ingresar otra cadena de caracteres? Si-1 No-2:");
        if (res)
            fputs("\n", ar);
        /* mSe indica un salto de linea, excepto en la ultima cadena. Si no
        se hiciera esta indicacion, la funcion fputs pegaria las cadenas y
        luego tendriamos dificultades en el momento de leerlas. Por otra
        parte, si realizamos este salto de linea al final de la ultima
        cadena, en el escritura se repetiria la ultima cadena. */
    }
    fclose(ar);
}
else
    printf("no se puede abrir el archivo");
}
