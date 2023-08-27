// Fernando Haro Calvo  MATR. 372106
// 26-AGO-2023
// Calcula el precio total de una llamada telefónica.
// HCF_ACT1_11_932

#include <stdio.h>

int main() {
    int minutos, tipoLlamada;
    float costoSubtotal, costoIVA, costoTotal;

    printf("Ingrese la duración de la llamada (en minutos): ");
    scanf("%d", &minutos);
    printf("Ingrese el tipo de llamada:\n");
    printf("1- Llamada local\n");
    printf("2- Llamada nacional\n");
    printf("3- Llamada internacional\n");
    scanf("%d", &tipoLlamada);

    if (tipoLlamada == 1) {
        costoSubtotal = 3.00;
    } else {
        if (tipoLlamada == 2) {
            if (minutos <= 3) {
                costoSubtotal = 7.00;
            } else {
                costoSubtotal = 7.00 + (minutos - 3) * 2;
            }
        } else {
            if (tipoLlamada == 3) {
                if (minutos <= 2) {
                    costoSubtotal = 9.00;
                } else {
                    costoSubtotal = 9.00 + (minutos - 2) * 4;
                }
            }
        } 
    }

    costoIVA = costoSubtotal * 0.16;
    costoTotal = costoSubtotal + costoIVA;

    printf("\nSubtotal: $%.2f\n", costoSubtotal);
    printf("IVA (16%%): $%.2f\n", costoIVA);
    printf("Total: $%.2f\n", costoTotal);

    return 0;
}