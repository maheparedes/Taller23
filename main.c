#include <stdio.h>
#include <string.h>

int main() {

    char nombre[5][30];
    float nota[5][3]; // 3 asignaturas por estudiante
    int cont = 0;     // contador de estudiantes ingresados
    int opc = 0, opc2 = 0;

    do {
        printf("\n===== MENU PRINCIPAL =====\n");
        printf("1. Ingresar estudiante y sus calificaciones\n");
        printf("2. Mostrar calificaciones registradas\n");
        printf("3. Ver promedios por estudiante\n");
        printf("4. Ver promedios por asignatura\n");
        printf("5. Ver nota más alta y más baja\n");
        printf("6. Ver aprobados y reprobados por asignatura\n");
        printf(">> ");
        scanf("%d", &opc);

        switch (opc) {
        case 1:
            if (cont >= 5) {
                printf("Ya se ingresaron los 5 estudiantes permitidos.\n");
                break;
            }

            printf("\nIngrese el nombre del estudiante %d: ", cont + 1);
            getchar(); // limpia el salto de línea pendiente del scanf anterior
            fgets(nombre[cont], 30, stdin);
            int len = strlen(nombre[cont]) - 1;
            if (nombre[cont][len] == '\n') nombre[cont][len] = '\0';

            for (int j = 0; j < 3; j++) {
                do {
                    printf("Ingrese la nota %d (0-10): ", j + 1);
                    scanf("%f", &nota[cont][j]);
                    if (nota[cont][j] < 0 || nota[cont][j] > 10)
                        printf("Nota inválida. Debe estar entre 0 y 10.\n");
                } while (nota[cont][j] < 0 || nota[cont][j] > 10);
            }
            cont++;
            printf("Estudiante ingresado correctamente.\n");
            break;

        case 2:
            if (cont == 0) {
                printf("No hay estudiantes registrados.\n");
                break;
            }
            printf("\n----------- Calificaciones ----------\n");
            printf("#\tNombre\t\tNota1\tNota2\tNota3\n");
            for (int i = 0; i < cont; i++) {
                printf("%d\t%-15s\t%.1f\t%.1f\t%.1f\n",
                       i, nombre[i], nota[i][0], nota[i][1], nota[i][2]);
            }
            break;

        case 3:
            if (cont == 0) {
                printf("No hay datos disponibles.\n");
                break;
            }
            printf("\n--- Promedio por estudiante ---\n");
            for (int i = 0; i < cont; i++) {
                float suma = nota[i][0] + nota[i][1] + nota[i][2];
                printf("%s -> Promedio: %.2f\n", nombre[i], suma / 3);
            }
            break;

        case 4:
            if (cont == 0) {
                printf("No hay datos disponibles.\n");
                break;
            }
            printf("\n--- Promedio por asignatura ---\n");
            for (int j = 0; j < 3; j++) {
                float suma = 0;
                for (int i = 0; i < cont; i++)
                    suma += nota[i][j];
                printf("Asignatura %d -> Promedio: %.2f\n", j + 1, suma / cont);
            }
            break;

        case 5:
            if (cont == 0) {
                printf("No hay datos disponibles.\n");
                break;
            }
            printf("\n--- Nota más alta y más baja ---\n");
            for (int i = 0; i < cont; i++) {
                float max = nota[i][0], min = nota[i][0];
                for (int j = 1; j < 3; j++) {
                    if (nota[i][j] > max) max = nota[i][j];
                    if (nota[i][j] < min) min = nota[i][j];
                }
                printf("%s -> Máx: %.2f | Mín: %.2f\n", nombre[i], max, min);
            }
            break;

        case 6:
            if (cont == 0) {
                printf("No hay datos disponibles.\n");
                break;
            }
            printf("\n--- Aprobados y Reprobados por asignatura ---\n");
            for (int j = 0; j < 3; j++) {
                int aprob = 0, reprob = 0;
                for (int i = 0; i < cont; i++) {
                    if (nota[i][j] >= 6)
                        aprob++;
                    else
                        reprob++;
                }
                printf("Asignatura %d -> Aprobados: %d | Reprobados: %d\n",
                       j + 1, aprob, reprob);
            }
            break;

        default:
            printf("Opción no válida.\n");
            break;
        }

        printf("\n¿Desea realizar otra operación? 1.Sí / 2.No: ");
        scanf("%d", &opc2);

    } while (opc2 != 2);

    printf("\nFin del programa.\n");
    return 0;
}
