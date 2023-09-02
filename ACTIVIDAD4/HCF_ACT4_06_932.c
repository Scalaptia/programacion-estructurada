// Fernando Haro Calvo  MATR. 372106
// 29-AGO-2023
// Calcula el total por consumo de agua.
// HCF_ACT4_06_932

#include <stdio.h>

int main() {
    float m3, facturacion, costoIVA;

    printf("Ingresa los m3 de agua consumidos: ");
    scanf("%f", &m3);

    if (m3 <= 4) {
        facturacion = 50.0;
    } else {
        if (m3 <= 15) {
            facturacion = 50.0 + (m3 - 4) * 8.0;
        } else {
            if (m3 <= 50) {
                facturacion = 50 + 11 * 8.0 + (m3 - 15) * 10.0; 
            } else {
                facturacion = 50 + 11 * 8.0 + 35 * 10.0 + (m3 - 50) * 11.0;
            }
        }
    }

    costoIVA = facturacion * 0.16;

    printf("\nSubtotal: $%.2f\n", facturacion);
    printf("IVA (16%%): $%.2f\n", costoIVA);
    printf("Total: $%.2f\n", facturacion + costoIVA);
    return 0;
}