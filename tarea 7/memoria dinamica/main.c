#include <stdio.h>
#include <stdlib.h>

#define MAX_NOMBRE 50

// Estructura para almacenar los datos de un alumno
typedef struct {
     int matricula;
    char nombre[MAX_NOMBRE];
    float promedio;
} Alumno;

// Estructura para almacenar la lista de alumnos
typedef struct {
    Alumno* alumnos;
    int cantidad;
    int capacidad;
} Almacenamiento;

// Función para inicializar el almacenamiento
void inicializarAlmacenamiento(Almacenamiento* almacenamiento, int capacidadInicial) {
    almacenamiento->alumnos = (Alumno*)malloc(capacidadInicial * sizeof(Alumno));
    almacenamiento->cantidad = 0;
    almacenamiento->capacidad = capacidadInicial;
}

// Función para liberar el almacenamiento
void liberarAlmacenamiento(Almacenamiento* almacenamiento) {
    free(almacenamiento->alumnos);
}

// Función para mostrar el menú
void mostrarMenu() {
    printf("Menu:\n");
    printf("1. Agregar datos\n");
    printf("2. Leer datos\n");
    printf("3. Salir\n");
    printf("Selecciona una opcion: ");
}

// Función para agregar datos
void agregarDatos(Almacenamiento* almacenamiento) {
    if (almacenamiento->cantidad >= almacenamiento->capacidad) {
        printf("No se pueden agregar más alumnos. El almacenamiento está lleno.\n");
        return;
    }
    Alumno nuevoAlumno;
    printf("Introduce la matrícula: ");
    scanf("%d", &nuevoAlumno.matricula);
    getchar(); // Limpiar el buffer de entrada
    printf("Introduce el nombre: ");
    fgets(nuevoAlumno.nombre, MAX_NOMBRE, stdin);
    nuevoAlumno.nombre[strcspn(nuevoAlumno.nombre, "\n")] = '\0'; // Eliminar el salto de línea
    printf("Introduce el promedio: ");
    scanf("%f", &nuevoAlumno.promedio);

    almacenamiento->alumnos[almacenamiento->cantidad] = nuevoAlumno;
    almacenamiento->cantidad++;
    printf("Alumno agregado.\n");
}

// Función para leer datos
void leerDatos(Almacenamiento* almacenamiento) {
    if (almacenamiento->cantidad == 0) {
        printf("No hay datos almacenados.\n");
        return;
    }
    printf("Datos almacenados:\n");
    for (int i = 0; i < almacenamiento->cantidad; i++) {
        Alumno a = almacenamiento->alumnos[i];
        printf("%d. Matricula: %d, Nombre: %s, Promedio: %.2f\n", i + 1, a.matricula, a.nombre, a.promedio);
    }
}

int main() {
    Almacenamiento almacenamiento;
    int capacidadInicial = 100; // Capacidad inicial
    inicializarAlmacenamiento(&almacenamiento, capacidadInicial);

    int opcion;

    do {
        mostrarMenu();
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                agregarDatos(&almacenamiento);
                break;
            case 2:
                leerDatos(&almacenamiento);
                break;
            case 3:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opción no válida. Intenta de nuevo.\n");
                break;
        }
    } while (opcion != 3);

    liberarAlmacenamiento(&almacenamiento);

    return 0;
}
