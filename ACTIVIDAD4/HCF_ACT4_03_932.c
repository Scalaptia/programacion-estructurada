// Fernando Haro Calvo  MATR. 372106
// 29-AGO-2023
// Lee 6 números, y despliega el valor del número mayor.
// HCF_ACT4_03_932

#include <stdio.h>

int main () {
    int n1, n2, n3, n4, n5, n6, mayor;

    printf("Ingresa el primer numero: ");
    scanf("%d", &n1);
    printf("Ingresa el segundo numero: ");
    scanf("%d", &n2);
    printf("Ingresa el tercer numero: ");
    scanf("%d", &n3);
    printf("Ingresa el cuarto numero: ");
    scanf("%d", &n4);
    printf("Ingresa el quinto numero: ");
    scanf("%d", &n5);
    printf("Ingresa el sexto numero: ");
    scanf("%d", &n6);

    mayor = n1;

    if (n2 > mayor) {
        mayor = n2;
    }

    if (n3 > mayor) {
        mayor = n3;
    }

    if (n4 > mayor) {
        mayor = n4;
    }

    if (n5 > mayor) {
        mayor = n5;
    }

    if (n6 > mayor) {
        mayor = n6;
    }

    printf("El mayor numero es: %d", mayor);
    return 0;
}