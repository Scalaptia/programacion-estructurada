// Fernando Haro Calvo  MATR. 372106
// 29-AGO-2023
// Calcula el promedio final donde la calificación menor de los exámenes se anula.
// HCF_ACT4_07_932

#include <stdio.h>

int main() {
    int cal1, cal2, cal3, cal4, cal5;
    float prom;

    printf("Ingresa la calificacion del primer examen: ");
    scanf("%d", &cal1);
    printf("Ingresa la calificacion del segundo examen: ");
    scanf("%d", &cal2);
    printf("Ingresa la calificacion del tercer examen: ");
    scanf("%d", &cal3);
    printf("Ingresa la calificacion del cuarto examen: ");
    scanf("%d", &cal4);
    printf("Ingresa la calificacion del quinto examen: ");
    scanf("%d", &cal5);

    int menor = cal1;

    if (cal2 < menor) {
        menor = cal2;
    }
    if (cal3 < menor) {
        menor = cal3;
    }
    if (cal4 < menor) {
        menor = cal4;
    }
    if (cal5 < menor) {
        menor = cal5;
    }

    prom = (cal1 + cal2 + cal3 + cal4 + cal5 - menor) / 4;
    printf("El promedio final es de: %.2f", prom);

    return 0;
}