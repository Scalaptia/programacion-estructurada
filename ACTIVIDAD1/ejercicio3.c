// Fernando Haro Calvo  MATR. 372106
// 22-AGO-2023
// Lee calificaciones y decide si aprobaste o no.
// HCF_ACT1_3_932

#include <stdio.h>

int main() {
    int cal1, cal2, cal3, cal4;
    float promedio;

    printf("Ingrese la 1ra calificacion: ");
    scanf("%d", &cal1);
    printf("Ingrese la 2da calificacion: ");
    scanf("%d", &cal2);
    printf("Ingrese la 3ra calificacion: ");
    scanf("%d", &cal3);
    printf("Ingrese la 4ta calificacion: ");
    scanf("%d", &cal4);

    promedio = (cal1 + cal2 + cal3 + cal4) / 4.0;

    if (promedio >= 60 && promedio <= 100) {
        printf("APROBADO\n");
    } else {
        printf("REPROBADO\n");
    }
    printf("Calificacion: %.2f", promedio);

    return 0;   
}