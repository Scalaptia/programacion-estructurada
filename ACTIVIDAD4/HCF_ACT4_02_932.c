// Fernando Haro Calvo  MATR. 372106
// 29-AGO-2023
// Realizar operaciones de convesion de unidades de longitud.
// HCF_ACT4_02_932

#include <stdio.h>

int main () {
    int op, unidad, res;

    printf("\n--- MENU ---\n");
    printf("1- cm a pulgadas\n");
    printf("2- cm a pies\n");
    printf("3- km a millas\n");
    printf("4- pulgadas a cm\n");
    printf("5- pies a cm\n");
    printf("6- millas a km\n");
    scanf("%d", &op);

    printf("Ingresa la unidad a convertir");
    scanf("%d", &unidad);
    
    if (op == 1) {
        res = unidad / 2.54;
    } else {
        if (op == 2) {
            res = unidad / 30.48;
        } else {
            if (op == 3) {
                res = unidad / 1.609;
            } else {
                if (op == 4) {
                    res = unidad * 2.54;
                } else {
                    if (op == 5) {
                        res = unidad * 30.48;
                    } else {
                        if (op == 6) {
                            res = unidad * 1.609;
                        } else {
                            return 1;
                        }
                    }
                }
            }
        }
    }

    printf("El resultado es: %d", res);
    return 0;
}
