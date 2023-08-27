// Fernando Haro Calvo  MATR. 372106
// 26-AGO-2023
// Calcula salario semanal de un trabajador.
// HCF_ACT1_10_932

#include <stdio.h>

int main() {
    int horasTrabajadas, horasExtra;
    float salarioHora, salarioNormal, salarioExtra, salarioTotal;

    printf("Ingresa las horas trabajadas: ");
    scanf("%d", &horasTrabajadas);
    printf("Ingresa el salario por hora: ");
    scanf("%f", &salarioHora);

    if (horasTrabajadas <= 40) {
        salarioNormal = horasTrabajadas * salarioHora;
        salarioExtra = 0;
    } else {
        salarioNormal = 40 * salarioHora;
        horasExtra = horasTrabajadas - 40;

        if (horasExtra <= 9) {
            salarioExtra = horasExtra * salarioHora * 2;
        } else {
            salarioExtra = (9 * salarioHora * 2) + ((horasExtra - 9) * salarioHora * 3);
        }
    }

    salarioTotal = salarioNormal + salarioExtra;

    printf("\nSalario por hora: $%.2f\n", salarioHora);
    printf("Horas trabajadas: %.2d\n", horasTrabajadas);
    printf("Salario normal: $%.2f\n", salarioNormal);
    printf("Salario extra: $%.2f\n", salarioExtra);
    printf("Salario total: $%.2f\n", salarioTotal);

    return 0;
}