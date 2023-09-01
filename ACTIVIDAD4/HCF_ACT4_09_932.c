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

    switch (jugador) {
        case 1:
            switch (computadora) {
                case 1:
                    printf("Empate (J: Piedra, C: Piedra)");
                    break;
                
                case 2:
                    printf("Gana computadora (J: Piedra, C: Papel)");
                    break;
                
                case 3:
                    printf("Gana jugador (J: Piedra, C: Tijeras)");
                    break;
            }
            break;
        
        case 2:
            switch (computadora) {
                case 1:
                    printf("Gana jugador (J: Papel, C: Piedra)");
                    break;
                
                case 2:
                    printf("Empate (J: Papel, C: Papel)");
                    break;
                
                case 3:
                    printf("Gana computadora (J: Papel, C: Tijeras)");
                    break;
            }
            break;
        
        case 3:
            switch (computadora) {
                case 1:
                    printf("Gana computadora (J: Tijeras, C: Piedra)");
                    break;
                
                case 2:
                    printf("Gana jugador (J: Tijeras, C: Papel)");
                    break;
                
                case 3:
                    printf("Empate (J: Tijeras, C: Tijeras)");
                    break;
            }
            break;
    }

    return 0;
}