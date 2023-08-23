// Fernando Haro Calvo  MATR. 372106
// 22-AGO-2023
// Lee 3 calificaciones, calcula el promedio y juzga su rendimiento.
// HCF_ACT1_6_932

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
        printf("Repetir");
    } else if (promedio >= 30 && promedio < 60) {
        printf("Extraordinario");
    } else if (promedio >= 60 && promedio < 70) {
        printf("Suficiente");   
    } else if (promedio >= 70 && promedio < 80) {
        printf("Regular");
    } else if (promedio >= 80 && promedio < 90) {
        printf("Bien");
    } else if (promedio >= 90 && promedio < 98) {
        printf("Muy bien");
    } else if (promedio >= 98 && promedio < 100) {
        printf("Excelente");
    } else if (promedio > 100) {
        printf("Error en promedio");
    }

    return 0;
}