// Fernando Haro Calvo  MATR. 372106
// 29-AGO-2023
// Realizar operaciones aritméticas simples.
// HCF_ACT4_01_932

#include <stdio.h>

int main () {
    int op, num1, num2, res;

    printf("\n--- MENU ---\n");
    printf("1- Suma\n");
    printf("2- Resta\n");
    printf("3- Multiplicacion\n");
    printf("4- Division\n");
    scanf("%d", &op);

    printf("Ingresa el primer numero");
    scanf("%d", &num1);
    printf("Ingresa el segundo numero");
    scanf("%d", &num2);

    if (op == 1) {
        res = num1 + num2;
    } else {
        if (op == 2) {
            res = num1 - num2;
        } else {
            if (op == 3) {
                res = num1 * num2;
            } else {
                if (op == 4) {
                    res = num1 / num2;
                } else {
                    return 1;
                }
            }
        }
    }

    printf("El resultado es: %d", res);
    return 0;
}