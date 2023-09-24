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
void printMinus(char cadena[]);
void printCapital(char cadena[]);
void printCantChar(char cadena[]);
void printReversa(char cadena[]);
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
            printMinus(cadena);
            break;

        case 3:
            printCapital(cadena);
            break;

        case 4:
            printCantChar(cadena);
            break;

        case 5:
            printReversa(cadena);
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

        printf("\n");
        system("PAUSE");
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
}
//*********************
// Imprime la cadena en minuscula.
// HCF_ACT7_02_02_932
void printMinus(char cadena[])
{
    // Variables Locales
    int i;

    // Programa
    system("CLS");
    for (int i = 0; cadena[i] != '\0'; i++)
    {
        char caracter = cadena[i];

        if (caracter >= 'A' && caracter <= 'Z')
        {
            caracter += 32; // Convertir a minúscula (ASCII)
        }

        printf("%c", caracter);
    }
}
//*********************
// Imprime la cadena capitalizada.
// HCF_ACT7_02_03_932
void printCapital(char cadena[])
{
    // Variables Locales
    int i;

    // Programa
    system("CLS");

    // Primera letra
    if (cadena[0] >= 'a' && cadena[0] <= 'z')
    {
        cadena[0] -= 32; // Convertir a minúscula (ASCII)
        printf("%c", cadena[0]);
    }

    // Resto de la cadena
    for (int i = 1; cadena[i] != '\0'; i++)
    {
        char caracter = cadena[i];

        if (caracter >= 'A' && caracter <= 'Z')
        {
            caracter += 32; // Convertir a minúscula (ASCII)
        }

        printf("%c", caracter);
    }
}
//*********************
// Imprime la cantidad de caracteres de la cadena.
// HCF_ACT7_02_04_932
void printCantChar(char cadena[])
{
    // Variables Locales
    int i;

    // Programa
    system("CLS");
    while (cadena[i] != '\0')
    {
        i++;
    }

    printf("La cadena tiene %d caracteres", i);
}
//*********************
// Imprime la cadena al revés.
// HCF_ACT7_02_05_932
void printReversa(char cadena[])
{
    // Variables Locales
    int i;

    // Programa
    system("CLS");

    for (i = largo; i >= 0; i--)
    {
        printf("%c", cadena[i]);
    }
}