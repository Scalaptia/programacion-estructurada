// Fernando Haro Calvo  MATR. 372106
// 22-AGO-2023
// Lee numero y decide si es par o impar.
// HCF_ACT1_2_932

#include <stdio.h>

int main() {
    int num;

    printf("Ingrese un numero entero: ");
    scanf("%d", &num);

    if (num % 2 == 0) {
        printf("%d es PAR", num);
    } else {
        printf("%d es IMPAR", num);
    }
}