#include <stdio.h>
#include <stdlib.h>



#define MAX_ALUMNOS 100
#define MAX_NOMBRE 50

// Estructura para almacenar los datos de un alumno

typedef struct {
    int matricula;
    char nombre[MAX_NOMBRE];
    float promedio;
}Alumno;

// Estructura para alamacenar la lista de alumnos
typedef struct {
    Alumno Alumno[MAX_ALUMNOS];
    int cantidad;
}Almacenamiento;

// Funcion para mostar el menu
void mostrarMenu() {
    printf("menu:\n");
    printf("1. Agregar datos\n");
    printf("2. Leer datos\n");
    printf("3. Salir\n");
    printf("Selecciona una opcion: ");
}

// Funcion para agregar datos
void agregadosDatos(Almacenamiento* almacenamiento) {
    if (almacenamiento->cantidad >= MAX_ALUMNOS) {
            printf("No se pueden agregar mas alumnos. El almacenamiento esta lleno.\n");
    return;
    }
    Alumno nuevoAlumno;
    printf("Introduce la matricula: ");
    scanf("%d", &nuevoAlumno.matricula);
    getchar(); // Limpiar el buffer de entrada
    printf("Introduce el nombre: ");
    fgets(nuevoAlumno.nombre, MAX_NOMBRE, stdin);
    nuevoAlumno.nombre[strcspn(nuevoAlumno.nombre, "\n")] = '\0';    // Eliminar el salto de linea
    printf("Introduce el promedio ");
    scanf("%f", &nuevoAlumno.promedio);

    almacenamiento->alumno[almacenamiento->cantidad] = nuevoAlumno;
    almacenamiento->cantidad++;
    printf("Alumno agregado.\n");
}

// Funcion para leer datos
void LeerDatos(Almacenamiento* almacenamiento) {
    if (almacenamiento->cantidad == 0) {
            printf("No hay datos almacenados.\n");
    return;
    }
    printf("Datos almacenados:\n")
    for (int i = 0; i < almacenamiento->cantidad; i++) {
            Alumno a = almacenamiento->alumnos[i];
            printf("%d. Matricula: %d, Nombre: %s, Promedio: %.2f\n", i + 1, a.matricula, a.nombre, a.promedio);
    }
}

    int main() {
        Almacenamiento almacenamiento = { .cantidad = 0 };
    int opcion;

    do{
       mostrarMenu();
       scanf("%d", &opcion);

       switch (opcion) {
       case 1:
            agregarDatos(&almacenamiento);
            break;
       case 2:
            LeerDatos(&almacenamiento);
            break;
       case 3:
            printf("Saliendo...\n");
            break;
       default:
            printf("opcion no valida. Intentacion de nuevo.\n");
            break;
       }
    }while (opcion != 3);

    return 0;
    }
