// Fernando Haro Calvo  MATR. 372106
// 22-AGO-2023
// Lee 3 numeros y los muestra en orden ascendente.
// HCF_ACT1_09_932

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
            printf("%d, %d, %d", num3, num1, num2);
        } else {
            if (num2 < num3) {
                printf("%d, %d, %d", num1, num2, num3);
            } else {
                printf("%d, %d, %d", num1, num3, num2);
            }
        }
    } else {
        if (num3 < num2) {
            printf("%d, %d, %d", num3, num2, num1);
        } else {
            if (num3 < num1) {
                printf("%d, %d, %d", num2, num3, num1);
            } else {
                printf("%d, %d, %d", num2, num1, num3);
            }
        }
    }
}