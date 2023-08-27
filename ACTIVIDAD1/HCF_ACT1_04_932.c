// Fernando Haro Calvo  MATR. 372106
// 22-AGO-2023
// Lee un número e imprime tu sexo.
// HCF_ACT1_04_932

#include <stdio.h>

int main() {
    int sexo;

    printf("¿Cual es tu sexo?\n");
    printf("1- HOMBRE\n2- MUJER\n");
    scanf("%d", &sexo);

    if (sexo == 1) {
        printf("HOLA, ERES HOMBRE");
    }

    if (sexo == 2) {
        printf("HOLA, ERES MUJER");
    }

    return 0;
}