// Fernando Haro Calvo  MATR. 372106
// 03-OCT-2023 (Creado)

//*** LIBRERIAS     ******
#include "../LIBRERIAS/alexandria.h"

//*** PROTOTIPOS DE FUNCIONES  ******
int msges(void);
void menu(void);

//****  MAIN PRINCIPAL  *********
int main()
{
    srand(time(NULL));
    menu();

    return 0;
}

//**** DESARROLLO DE LAS FUNCIONES  ******
int msges()
{
    int op;
    system("CLS");
    printf("\n   M   E   N   U \n");
    printf("1.- LLENAR VECTOR \n");
    printf("2.- LLENAR MATRIZ \n");
    printf("3.- IMPRIMIR VECTOR \n");
    printf("4.- IMPRIMIR MATRIZ \n");
    printf("5.- ORDENAR VECTOR \n");
    printf("6.- BUSCAR VALOR EN VECTOR \n");
    printf("0.- SALIR  \n");
    printf("ESCOGE UNA OPCION: ");
    scanf("%d", &op);
    return op;
}

//*********************
void menu()
{
    int op;
    int vect[15];
    int matriz[4][4];
    system("CLS");

    do
    {
        op = msges();
        system("CLS");
        switch (op)
        {
        case 1:
            llenarVectSinRep(vect, 15, 100, 200);
            break;

        case 2:
            break;

        case 3:
            break;

        case 4:
            break;

        case 5:
            break;

        case 6:
            break;

        case 0:
            return;
        }

        printf("\n\n");
        system("PAUSE");
    } while (op != 0);
}