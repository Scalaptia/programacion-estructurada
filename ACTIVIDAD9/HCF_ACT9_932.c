// Fernando Haro Calvo  MATR. 372106
// 03-OCT-2023 (Creado)

//*** LIBRERIAS     ******
#include "alexandria.h"

//*** PROTOTIPOS DE FUNCIONES  ******
int msges(void);
void menu(void);
void buscarVect(int vect[]);

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
    op = valiNum(0, 6);
    return op;
}

//*********************
void menu()
{
    int op;
    int vect[15];
    int mat[4][4];
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
            llenarMatSinRep(mat, 4, 4, 1, 16);
            break;

        case 3:
            imprVect(vect, 15);
            break;

        case 4:
            imprMat(mat, 4, 4);
            break;

        case 5:
            ordVect(vect, 15);
            break;

        case 6:
            buscarVect(vect);
            break;

        case 0:
            return;
        }

        printf("\n");
        system("PAUSE");
    } while (op != 0);
}

void buscarVect(int vect[])
{
    int num, indice;
    printf("Ingrese un numero entre 100-200 para buscar en el vector: ");
    num = valiNum(100, 200);
    indice = busqSeqVect(vect, 15, num);

    if (indice != -1)
    {
        printf("El numero %d se encuentra en el vector en el indice %d", num, indice);
    }
    else
    {
        printf("El numero %d no se encuentra en el vector", num);
    }
}