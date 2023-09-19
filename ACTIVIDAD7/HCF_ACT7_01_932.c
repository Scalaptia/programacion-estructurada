// Fernando Haro Calvo  MATR. 372106
// 19-SEP-2023

//*** LIBRERIAS     ******
#include <stdio.h>
#include <stdlib.h>

//*** PROTOTIPOS DE FUNCIONES  ******
int msges();
int msgCiclos();
void menu();
void printNormal(char cadena[]);
// void printReversa(char cadena[]);
// void printVertical(char cadena[]);
// void printVerticalReversa(char cadena[]);
// void printBorrarDer(char cadena[]);
// void printReversaBorrarDer(char cadena[]);
// void printBorrarIzq(char cadena[]);
// void printReversaBorrarIzq(char cadena[]);
// void printAlternar(char cadena[]);
// void printVocals(char cadena[]);

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
    printf("\n   M  E   N   U \n");
    printf("1.- NORMAL \n");
    printf("2.- REVERSA \n");
    printf("3.- VERTICAL \n");
    printf("4.- VERTICAL REVERSE \n");
    printf("5.- BORRAR DERECHA \n");
    printf("6.- REVERSA BORRAR DERECHA \n");
    printf("7.- BORRAR IZQUIERDA \n");
    printf("8.- REVERSA BORRAR IZQUIERDA \n");
    printf("9.- ALTERNAR (UNO SI UNO NO) \n");
    printf("10.- VOCALES \n");
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
    do
    {
        system("CLS");
        puts("Ingrese una cadena: ");
        fflush(stdin);
        gets(cadena);

        op = msges();
        switch (op)
        {
        case 1:
            printNormal(cadena);
            break;

        case 2:
            // printReversa(cadena);
            break;

        case 3:
            // printVertical(cadena);
            break;

        case 4:
            // printVerticalReversa(cadena);
            break;

        case 5:
            // printBorrarDer(cadena);
            break;

        case 6:
            // printReversaBorrarDer(cadena);
            break;

        case 7:
            // printBorrarIzq(cadena);
            break;

        case 8:
            // printReversaBorrarIzq(cadena);
            break;

        case 9:
            // printAlternar(cadena);
            break;

        case 10:
            // printVocals(cadena);
            break;
        }
    } while (op != 0);
}
//*********************
// Imprime la cadena normalmente.
// HCF_ACT7_01_01_932
void printNormal(char cadena[])
{
    // Variables Locales
    int i;

    // Titulo
    system("CLS");

    // Programa

    printf("\n");
    system("PAUSE");
}
//*********************
// Imprime la cadena al revés.
// HCF_ACT7_01_02_932
void printReversa(char cadena[])
{
    // Variables Locales
    int i;

    // Titulo
    system("CLS");

    // Programa

    printf("\n");
    system("PAUSE");
}