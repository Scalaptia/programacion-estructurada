// Fernando Haro Calvo  MATR. 372106
// 25-SEP-2023 (Creado)

//*** LIBRERIAS     ******
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//*** PROTOTIPOS DE FUNCIONES  ******
int msges(void);
int msgCiclos(void);
void menu(void);
int validar(char msg[], int ri, int rf);
void llenarVectManual(int vector[], int m);
void llenarVectAuto(int vector[], int m);
void llenarVectConVectores(int vector1[], int m, int vector2[], int n, int vector3[], int p);
void imprimirVectores(int vector1[], int m, int vector2[], int n, int vector3[], int p);
void llenarMatriz4x4(int vector1[], int m, int vector2[], int n, int matriz[][4]);
void imprimirMatriz(int matriz[][4]);

//****  MAIN PRINCIPAL  *********
int main()
{
    menu();

    return 0;
}

//**** DESARROLLO DE LAS FUNCIONES  ******
int msges()
{
    int op;
    system("CLS");
    printf("\n   M  E   N   U \n");
    printf("1.- LLENAR VECTOR 1 (MANUALMENTE) \n");
    printf("2.- LLENAR VECTOR 2 ALEATORIAMENTE \n");
    printf("3.- LLENAR VECTOR 3 (CON VECTOR1 Y VECTOR2) \n");
    printf("3.- LLENAR VECTOR 3 (CON VECTOR1 Y VECTOR2) \n");
    printf("4.- IMPRIMIR VECTORES \n");
    printf("5.- LLENA MATRIZ 4 X 4 \n");
    printf("6.- IMPRIMIR MATRIZ \n");
    printf("0.- SALIR  \n");
    printf("ESCOGE UNA OPCION: ");
    scanf("%d", &op);
    return op;
}

//*********************
void menu()
{
    int op;
    int vector1[10], vector2[10], vector3[20];
    int matriz4x4[4][4];
    system("CLS");

    do
    {
        op = msges();
        system("CLS");
        switch (op)
        {
        case 1:
            llenarVectManual(vector1, 10);
            break;

        case 2:
            llenarVectAuto(vector2, 10);
            break;

        case 3:
            llenarVectConVectores(vector1, 10, vector2, 10, vector3, 20);
            break;

        case 4:
            imprimirVectores(vector1, 10, vector2, 10, vector3, 20);
            break;

        case 5:
            llenarMatriz4x4(vector1, 10, vector2, 10, matriz4x4);
            break;

        case 6:
            imprimirMatriz(matriz4x4);
            break;

        case 0:
            return 0;
        }

        printf("\n\n");
        system("PAUSE");
    } while (op != 0);
}

//*********************
// Valida la entrada del usuario en un rango de numeros.
int validar(char msg[], int ri, int rf)
{
    char cadena[50];
    int num;

    do
    {
        printf("%s", msg);
        fflush(stdin);
        gets(cadena);
        num = atoi(cadena);
    } while (num < ri || num > rf);

    return num;
}

//*********************
// Llena el vector con valores introducidos por el usuario del 30 al 70.
// HCF_ACT8_01_932
void llenarVectManual(int vector[], int m)
{
    int i, num;

    for (i = 0; i < m; i++)
    {
        printf("Valor %d -> ", i + 1);
        num = validar("Ingrese un numero entre 30-70: ", 30, 70);
        vector[i] = num;
    }
}

//*********************
// Llena el vector con valores generados aleatoriamente del 1 al 20 sin repetir.
// HCF_ACT8_02_932
void llenarVectAuto(int vector[], int m)
{
}

//*********************
// Llena un vector con los valores de otros dos vectores.
// HCF_ACT8_03_932
void llenarVectConVectores(int vector1[], int m, int vector2[], int n, int vector3[], int p)
{
}

//*********************
// Imprime los valores de todos los vectores.
// HCF_ACT8_04_932
void imprimirVectores(int vector1[], int m, int vector2[], int n, int vector3[], int p)
{
}

//*********************
// Llena una matriz 4x4 con los datos de dos vectores.
// HCF_ACT8_05_932
void llenarMatriz4x4(int vector1[], int m, int vector2[], int n, int matriz[][4])
{
}

//*********************
// Imprime los valores de la matriz 4x4.
// HCF_ACT8_06_932
void imprimirMatriz(int matriz[][4])
{
}