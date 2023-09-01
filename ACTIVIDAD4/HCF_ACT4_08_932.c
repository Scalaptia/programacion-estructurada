// Fernando Haro Calvo  MATR. 372106
// 31-AGO-2023
// Piedra papel y Tijeras con condiciones anidadas.
// HCF_ACT4_08_932

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int jugador, computadora;

    srand(time(NULL)); // Generar semilla aleatoria
    computadora = rand() % 3 + 1; 

    printf("Ingresa tu jugada (1: Piedra, 2: Papel, 3: Tijera): ");
    scanf("%d", &jugador);

    if (!(jugador >= 1 && jugador <= 3)) {
        printf("Jugada ingresada no valida");
        return 1;
    }

    if (jugador == 1) {
        if (computadora == 1) {
            printf("Empate (J: Piedra, C: Piedra)");
        } else {
            if (computadora == 2) {
                printf("Gana computadora (J: Piedra, C: Papel)");
            } else {
                printf("Gana jugador (J: Piedra, C: Tijeras)");
            }
        }
    } else {
        if (jugador == 2) {
            if (computadora == 1) {
                printf("Gana jugador (J: Papel, C: Piedra)");
            } else {
                if (computadora == 2) {
                    printf("Empate (J: Papel, C: Papel)");
                } else {
                    printf("Gana computadora (J: Papel, C: Tijeras)");
                }
            }
        } else {
            if (computadora == 1) {
                printf("Gana computadora (J: Tijeras, C: Piedra)");
            } else {
                if (computadora == 2) {
                    printf("Gana jugador (J: Tijeras, C: Papel)");
                } else {
                    printf("Empate (J: Tijeras, C: Tijeras)");
                }
            }
        }
    }

    return 0;
}