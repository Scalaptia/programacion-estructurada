// Fernando Haro Calvo  MATR. 372106
// 23-SEP-2023 (Creado)

//*** LIBRERIAS     ******
#include <stdio.h>
#include <stdlib.h>

//*** PROTOTIPOS DE FUNCIONES  ******
int msges();
int msgCiclos();
void menu();
int largoCadena(char cadena[]);
void printNormal(char cadena[]);

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
            printNormal(cadena);
            break;

        case 2:
            printReversa(cadena);
            break;

        case 3:
            printVertical(cadena);
            break;

        case 4:
            printVerticalReversa(cadena);
            break;

        case 5:
            printBorrarDer(cadena);
            break;

        case 6:
            printReversaBorrarDer(cadena);
            break;

        case 7:
            printBorrarIzq(cadena);
            break;

        case 8:
            printReversaBorrarIzq(cadena);
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
int largoCadena(char cadena[])
{
    int i;
    for (i = 0; cadena[i] != '\0'; i++)
        ;

    return i - 1;
}

//*********************
// Imprime la cadena normalmente.
// HCF_ACT7_01_01_932
void printNormal(char cadena[])
{
    // Variables Locales
    int i;

    // Programa
    system("CLS");
    for (i = 0; cadena[i] != '\0'; i++)
    {
        printf("%c", cadena[i]);
    }

    printf("\n");
    system("PAUSE");
}
//*********************
// Imprime la cadena al revés.
// HCF_ACT7_01_02_932
void printReversa(char cadena[])
{
    // Variables Locales
    int i, largo;

    // Programa
    system("CLS");
    largo = largoCadena(cadena);

    for (i = largo; i >= 0; i--)
    {
        printf("%c", cadena[i]);
    }

    printf("\n");
    system("PAUSE");
}
//*********************
// Imprime la cadena normal verticalmente.
// HCF_ACT7_01_03_932
void printVertical(char cadena[])
{
    // Variables Locales
    int i;

    // Programa
    system("CLS");
    for (i = 0; cadena[i] != '\0'; i++)
    {
        printf("%c\n", cadena[i]);
    }

    printf("\n");
    system("PAUSE");
}
//*********************
// Imprime la cadena al revés y verticalmente.
// HCF_ACT7_01_04_932
void printVerticalReversa(char cadena[])
{
    // Variables Locales
    int i, largo;

    // Programa
    system("CLS");
    largo = largoCadena(cadena);

    for (i = largo; i >= 0; i--)
    {
        printf("%c\n", cadena[i]);
    }

    printf("\n");
    system("PAUSE");
}
//*********************
// Imprime la cadena, en cada ciclo borrando un caracér a la derecha.
// HCF_ACT7_01_05_932
void printBorrarDer(char cadena[])
{
    // Variables Locales
    int i, j, largo;

    // Programa
    system("CLS");
    largo = largoCadena(cadena);

    for (i = largo + 1; i >= 0; i--)
    {
        for (j = 0; j < i; j++)
        {
            printf("%c", cadena[j]);
        }
        printf("\n");
    }

    system("PAUSE");
}
//*********************
// Imprime la cadena al revés, en cada ciclo borrando un caracér a la derecha.
// HCF_ACT7_01_06_932
void printReversaBorrarDer(char cadena[])
{
    // Variables Locales
    int i, j, largo;

    // Programa
    system("CLS");
    largo = largoCadena(cadena);

    for (i = 0; i <= largo; i++)
    {
        for (j = largo; j >= i; j--)
        {
            printf("%c", cadena[j]);
        }
        printf("\n");
    }

    printf("\n");
    system("PAUSE");
}
//*********************
// Imprime la cadena, en cada ciclo borrando un caracér a la izquierda.
// HCF_ACT7_01_07_932
void printBorrarIzq(char cadena[])
{
    // Variables Locales
    int i, j, contador, largo;

    // Programa
    system("CLS");
    largo = largoCadena(cadena);

    for (i = largo; i >= 0; i--)
    {
        for (j = largo - i; j <= largo; j++)
        {
            printf("%c", cadena[j]);
        }
        printf("\n");
    }

    printf("\n");
    system("PAUSE");
}
//*********************
// Imprime la cadena, en cada ciclo borrando un caracér a la izquierda.
// HCF_ACT7_01_08_932
void printReversaBorrarIzq(char cadena[])
{
    // Variables Locales
    int i, j, largo;

    // Programa
    system("CLS");
    largo = largoCadena(cadena);

    for (i = largo; i >= 0; i--)
    {
        for (j = i; j >= 0; j--)
        {
            printf("%c", cadena[j]);
        }
        printf("\n");
    }

    printf("\n");
    system("PAUSE");
}