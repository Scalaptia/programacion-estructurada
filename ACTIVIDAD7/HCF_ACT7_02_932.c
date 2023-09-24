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
void printSinEspacios(char cadena[]);
void printCharAlfa(char cadena[]);
void printAll(char cadena[]);
void printPalindromo(char cadena[]);

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
    printf("7.- CARACTERES ALFABETICOS \n");
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
        system("CLS");
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
            printSinEspacios(cadena);
            break;

        case 7:
            printCharAlfa(cadena);
            break;

        case 8:
            printAll(cadena);
            break;

        case 9:
            printPalindromo(cadena);
            break;

        case 0:
            return 0;
        }

        printf("\n\n");
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
    char caracter;

    // Programa
    for (i = 0; cadena[i] != '\0'; i++)
    {
        caracter = cadena[i];

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
    char caracter;

    // Programa
    for (int i = 0; cadena[i] != '\0'; i++)
    {
        caracter = cadena[i];

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
    char caracter;

    // Programa
    // Primera letra
    caracter = cadena[0];
    if (caracter >= 'a' && caracter <= 'z')
    {
        caracter -= 32; // Convertir a minúscula (ASCII)
    }
    printf("%c", caracter);

    // Resto de la cadena
    for (int i = 1; cadena[i] != '\0'; i++)
    {
        caracter = cadena[i];

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
    int largo;

    // Programa
    for (largo = 0; cadena[largo] != '\0'; largo++)
        ;

    printf("La cadena tiene %d caracteres", largo);
}
//*********************
// Imprime la cadena al revés.
// HCF_ACT7_02_05_932
void printReversa(char cadena[])
{
    // Variables Locales
    int i, j, largo;
    char inversa[30];

    // Programa
    for (largo = 0; cadena[largo] != '\0'; largo++)
        ;

    for (i = largo - 1, j = 0; i >= 0; i--, j++)
    {
        inversa[j] = cadena[i];
        printf("%c", inversa[j]);
    }
}
//*********************
// Imprime la cadena sin espacios.
// HCF_ACT7_02_06_932
void printSinEspacios(char cadena[])
{
    // Variables Locales
    int i, j;
    char cadenaSE[30];

    // Programa
    for (i = 0, j = 0; cadena[i] != '\0'; i++)
    {
        if (cadena[i] != ' ')
        {
            cadenaSE[j] = cadena[i];
            printf("%c", cadenaSE[j]);
            j++;
        }
    }
}
//*********************
// Imprime la cadena con solo caracteres alfabeticos y el espacio,
// sin que empiece ni termine con espacio y sin tener dos espacios seguidos.
// HCF_ACT7_02_07_932
void printCharAlfa(char cadena[])
{
    // Variables Locales
    int i, j;
    char cadenaAlfa[30];

    // Programa
    for (i = 0, j = 0; cadena[i] != '\0'; i++)
    {
        // Verifica si es un caracter alfabetico o espacio
        if ((cadena[i] == ' ') || (cadena[i] >= 'a' && cadena[i] <= 'z') || (cadena[i] >= 'A' && cadena[i] <= 'Z'))
        {
            // Verifica si no existe un doble espacio y que el primer y ultimo caracter no sean espacio.
            if (cadena[i] != ' ' || (i > 0 && cadena[i + 1] != '\0' && cadena[i - 1] != ' '))
            {
                cadenaAlfa[j] = cadena[i];
                printf("%c", cadenaAlfa[j]);
                j++;
            }
        }
    }
}
//*********************
// Imprime la cadena en mayusculas, minusculas, capital, sin espacios y alreves.
// HCF_ACT7_02_08_932
void printAll(char cadena[])
{
    // Programa
    printf("Mayusculas: \n");
    printMayus(cadena);
    printf("\n\n");

    printf("Minusculas: \n");
    printMinus(cadena);
    printf("\n\n");

    printf("Capital: \n");
    printCapital(cadena);
    printf("\n\n");

    printf("Sin Espacios: \n");
    printSinEspacios(cadena);
    printf("\n\n");

    printf("Al reves: \n");
    printReversa(cadena);
}
//*********************
// Imprime si la cadena es un palindromo o no.
// HCF_ACT7_02_09_932
void printPalindromo(char cadena[])
{
    // Variables locales
    int i, inicio = 0, fin, largo = 0;
    char caracter;
    char cadenaM[30];

    // Programa
    // Crea una nueva cadena en mayusculas y sin espacios para comparar
    for (i = 0; cadena[i] != '\0'; i++)
    {
        caracter = cadena[i];

        // Verifica si es minuscula y convierte a mayuscula
        if (caracter >= 'a' && caracter <= 'z')
        {
            caracter -= 32; // Convertir a mayúscula (ASCII)
        }

        // Verifica si no es un espacio
        if (caracter != ' ')
        {
            cadenaM[largo] = caracter;
            largo++;
        }
    }
    fin = largo - 1;

    // Verifica si la cadena es un palíndromo
    while (inicio < fin)
    {
        // Ignora los espacios en blanco y caracteres no alfabéticos
        while (cadenaM[inicio] < 'A' || cadenaM[inicio] > 'Z')
        {
            inicio++;
        }

        while (cadenaM[fin] < 'A' || cadenaM[fin] > 'Z')
        {
            fin--;
        }

        // Compara los caracteres en los índices inicio y fin
        if (cadenaM[inicio] != cadenaM[fin])
        {
            printf("No es un palindromo");
            return;
        }

        inicio++;
        fin--;
    }

    printf("Si es un palindromo");
}