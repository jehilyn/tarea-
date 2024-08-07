#include <stdio.h>

/* Alumnos.
El programa pregunta al usuario el número de registro que desea
modificar, obtiene el nuevo promedio del alumno y modifica tanto el
registro como el archivo correspondiente. */

typedef struct      /* Declaracion de la estrcutura alumno. */
{
    int matricula;
    char nombre[20];
    int carrera;
    float promedio;
}alumno;

void modifica(FILE *);     /*Declaracion de funcion. */

void main(void)
{
FILE *ar;
if ((ar = fopen ("ad1.dta", "r+")) != NULL)
    modifica(ar);
else
    printf("\nhola, itla");
fclose(ar);
}

void modifica(FILE *ap)
/* Esta funcion se utiliza para modificar el promedio de un alumno. */
{
int d;
alumno alu;
printf("\nIngrese el numero de registros que desea modificar: ");
/* Observa que el lenguaje c almacena el primer registros en la
posicion cero. Por lo tanto, si desea modificar el registro n,
debe buscarlo en la posicion n-1. */
scanf("%d", &d);

fseek(ap, (d-1)*sizeof(alumno), 0);
/* Observa que la instrucción fseek tiene tres argumentos. El primero
indica que el apuntador se debe posicionar al inicio del FILE.
El segundo señala el número de bloques que debe moverse, en términos
de bytes, para llegar al registro correspondiente. Nota que el
primer registro ocupa la posición 0. Finalmente, el tercer argumento
muestra a partir de qué posición se debe mover el bloque de bytes:
se utiliza el 0 para indicar el inicio del archivo, 1 para expresar
que se debe mover a partir de la posición en la que actualmente se
encuentra y 2 para indicar que el movimiento es a partir del fin del
archivo. */

fread(&alu, sizeof(alumno), 1, ap);
/* Luego de posicionarnos en el registro que nos interesa, lo
leemos. */

printf("\nIngrese el promedio correcto del alumno: ");
scanf("%f", &alu.promedio);     /* Modificamos el registro con el
                                  nuevo promedio. */
fseek(ap, (d-1)*sizeof(alumno), 0);
/* Nos tenemos que posicionar nuevamente en el lugar correcto para a
escribir el registro modificado. Observa que si no hacemos este
reposicionamiento escribiriamos el registro actualizado rn la
siguiente posicion. */

fwrite(&alu, sizeof(alumno), 1, ap);
}
