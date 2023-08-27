// Fernando Haro Calvo  MATR. 372106
// 22-AGO-2023
// Lee 3 calificaciones, calcula el promedio y juzga su rendimiento.
// HCF_ACT1_05_932

#include <stdio.h>

int main() {
    int cal1, cal2, cal3;
    float promedio;

    printf("Ingrese la 1ra calificacion: ");
    scanf("%d", &cal1);
    printf("Ingrese la 2da calificacion: ");
    scanf("%d", &cal2);
    printf("Ingrese la 3ra calificacion: ");
    scanf("%d", &cal3);

    promedio = (cal1 + cal2 + cal3) / 3.0;

    if (promedio < 30) {
        printf("Repetir\n");
    } else {
        if (promedio < 60) {
            printf("Extraordinario\n");
        } else {
            if (promedio < 70) {
                printf("Suficiente\n");
            } else {
                if (promedio < 80) {
                    printf("Regular\n");
                } else {
                    if (promedio < 90) {
                        printf("Bien\n");
                    } else {
                        if (promedio < 98) {
                            printf("Muy Bien\n");
                        } else {
                            if (promedio <= 100) {
                                printf("Excelente\n");
                            } else {
                                printf("Error en promedio\n");
                            }
                        }
                    }
                }
            }
        }
    }

    return 0;
}