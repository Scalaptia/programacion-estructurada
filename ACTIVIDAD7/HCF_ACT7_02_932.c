// Fernando Haro Calvo  MATR. 372106
// 23-SEP-2023 (Creado)

//*** LIBRERIAS     ******
#include <stdio.h>
#include <stdlib.h>

//*** PROTOTIPOS DE FUNCIONES  ******
int msges();
int msgCiclos();
void menu();
void printMayus(char cadena[]);
// void printMinus(char cadena[]);
// void printCapital(char cadena[]);
// void printCantChar(char cadena[]);
// void printReversa(char cadena[]);
// void printSinEspacios(char cadena[]);
// void printCharAlfa(char cadena[]);
// void printAll(char cadena[]);
// void printPalindromo(char cadena[]);

//****  MAIN PRINCIPAL  *********
int main()
{
    menu();

    return 0;
}

//  *** DESARROLLO DE LAS FUNCIONES  ******
//*********************
int msges()
{
    int op;
    system("CLS");
    printf("\n   M  E   N   U \n");
    printf("1.- MAYUSCULAS \n");
    printf("2.- MINUSCULAS \n");
    printf("3.- CAPITAL \n");
    printf("4.- CANTIDAD CARACTERES \n");
    printf("5.- REVERSA \n");
    printf("6.- SIN ESPACIOS \n");
    printf("7.- CARACTERES ALFABÉTICOS \n");
    printf("8.- IMPRIMIR VARIAS \n");
    printf("9.- PALINDROMO \n");
    printf("0.- SALIR  \n");
    printf("ESCOGE UNA OPCION: ");
    scanf("%d", &op);
    return op;
}
//*********************
void menu()
{
    int op;
    char cadena[30];
    system("CLS");
    printf("Ingrese una cadena: ");
    fflush(stdin);
    gets(cadena);
    do
    {
        op = msges();
        switch (op)
        {
        case 1:
            printMayus(cadena);
            break;

        case 2:
            // printMinus(cadena);
            break;

        case 3:
            // printCapital(cadena);
            break;

        case 4:
            // printCantChar(cadena);
            break;

        case 5:
            // printReversa(cadena);
            break;

        case 6:
            // printSinEspacios(cadena);
            break;

        case 7:
            // printCharAlfa(cadena);
            break;

        case 8:
            // printAll(cadena);
            break;

        case 9:
            // printPalindromo(cadena);
            break;
        }
    } while (op != 0);
}
//*********************
// Imprime la cadena en mayúscula.
// HCF_ACT7_02_01_932
void printMayus(char cadena[])
{
    // Variables Locales
    int i;

    // Programa
    system("CLS");
    for (i = 0; cadena[i] != '\0'; i++)
    {
        char caracter = cadena[i];

        if (caracter >= 'a' && caracter <= 'z')
        {
            caracter -= 32; // Convertir a mayúscula (ASCII)
        }

        printf("%c", caracter);
    }

    printf("\n");
    system("PAUSE");
}
