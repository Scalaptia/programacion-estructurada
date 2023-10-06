// Fernando Haro Calvo  MATR. 372106
// 05-OCT-2023 (Creado)

//*** LIBRERIAS     ******
#include "../LIBRERIAS/alexandria.h"

//*** PROTOTIPOS DE FUNCIONES  ******
int msges(void);
void menu(void);
void generarCURP(void);

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
    printf("\n   M   E   N   U \n");
    printf("1.- GENERAR CURP \n");
    printf("0.- SALIR  \n");
    printf("ESCOGE UNA OPCION: ");
    op = valiNum(0, 1);
    return op;
}

//*********************
void menu()
{
    int op;
    system("CLS");

    do
    {
        op = msges();
        system("CLS");
        switch (op)
        {
        case 1:
            generarCURP();
            break;

        case 0:
            return;
        }

        printf("\n");
        system("PAUSE");
    } while (op != 0);
}

void generarCURP(void)
{
}