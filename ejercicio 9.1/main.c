#include <stdio.h>

/* Archivos y caracteres.
El programa escribe caracteres en un archivo. */

void main(void)
{
char p1;
FILE *ar;
ar = fopen ("jugodetamarindo.txt", "w");        /* Se abre el archivo arc.txt para escritura. */
if (ar != NULL)
{
    while ((p1=getchar()) != '\n')
    /* Se escribe caracteres en el archivo mientras no se detecte el caracter
    que indica el fin de la linea: */
        fputc(p1, ar);
        fclose(ar);
}
else
    printf("no se puede abrir el archivo");
}
