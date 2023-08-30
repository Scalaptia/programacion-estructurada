// Fernando Haro Calvo  MATR. 372106
// 29-AGO-2023
// Calcula el total por consumo de agua.
// HCF_ACT4_06_932

#include <stdio.h>

int main() {
    int m3, facturacion, costoIVA;

    printf("Ingresa los m3 de agua consumidos: ");
    scanf("%d", &m3);

    if (m3 <= 4) {
        facturacion = 50;
    } else {
        if (m3 <= 15) {
            facturacion = 50 + ((m3 - 4) * 8);
        } else {
            if (m3 <= 50) {
                facturacion = 138 + ((m3 - 15) * 10); 
            } else {
                facturacion = 488 + ((m3 - 50) * 11); 
            }
        }
    }

    costoIVA = facturacion * 0.16;

    printf("\nSubtotal: $%.2f\n", facturacion);
    printf("IVA (16%%): $%.2f\n", costoIVA);
    printf("Total: $%.2f\n", facturacion + costoIVA);
    return 0;
}