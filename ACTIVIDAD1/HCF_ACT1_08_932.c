// Fernando Haro Calvo  MATR. 372106
// 22-AGO-2023
// Lee 3 numeros y determina el valor medio.
// HCF_ACT1_08_932

#include <stdio.h>

int main() {
    int num1, num2, num3;
    
    printf("Ingrese el primer numero: ");
    scanf("%d", &num1);
    printf("Ingrese el segundo numero: ");
    scanf("%d", &num2);
    printf("Ingrese el tercer numero: ");
    scanf("%d", &num3);

    if (num1 < num2) {
        if (num1 > num3) {
            printf("El primer numero: %d es el medio", num1);
        } else {
            if (num2 < num3) {
                printf("El segundo numero: %d es el medio", num2);
            } else {
                printf("El tercer numero: %d es el medio", num3);
            }
        }
    } else {
        if (num3 < num2) {
            printf("El segundo numero: %d es el medio", num2);
        } else {
            if (num3 < num1) {
                printf("El tercer numero %d es el medio", num3);
            } else {
                printf("El primer numero %d es el medio", num1);
            }
        }
    }
}