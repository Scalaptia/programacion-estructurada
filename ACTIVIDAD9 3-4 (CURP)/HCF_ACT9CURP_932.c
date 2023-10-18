// Fernando Haro Calvo  MATR. 372106
// 05-OCT-2023 (Creado)

/********* LIBRERIAS *********/
#include "alexandria.h"

/********* PROTOTIPOS DE FUNCIONES *********/
int msges(void);
void menu(void);
void generarCURP(void);

/*********  MAIN PRINCIPAL *********/
int main()
{
    menu();

    return 0;
}

/********* FUNCIONES *********/
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
    char apellidoPaterno[30], apellidoMaterno[30], nombre[30], sexo[2];
    int dia, mes, anio;

    do
    {
        system("CLS");
        printf("Ingresa el apellido paterno: ");
        fflush(stdin);
        gets(apellidoPaterno);
    } while (valiCad(apellidoPaterno) == 0 && largoCadena(apellidoPaterno) < 2);

    do
    {
        system("CLS");
        printf("Ingresa el apellido materno: ");
        fflush(stdin);
        gets(apellidoMaterno);
    } while (valiCad(apellidoMaterno) == 0 && largoCadena(apellidoMaterno) < 2);

    do
    {
        system("CLS");
        printf("Ingresa el/los nombre/s: ");
        fflush(stdin);
        gets(nombre);
    } while (valiCad(nombre) == 0 && largoCadena(nombre) < 2);

    do
    {
        system("CLS");
        printf("Ingresa el anio de nacimiento: ");
        anio = valiNum(1900, 2023);

        system("CLS");
        printf("Ingresa el mes de nacimiento: ");
        mes = valiNum(1, 12)

            system("CLS");
        printf("Ingresa el dia de nacimiento: ");
        dia = valiNum(1, 31);
    } while (!esFechaValida(dia, mes, anio));

    do
    {
        system("CLS");
        printf("Ingrese el sexo (H/M): ");
        fflush(stdin);
        gets(sexo);
        mayus(sexo);
    } while (strcmp(sexo, "H") != 0 && strcmp(sexo, "M") != 0);

    printf("El CURP es: %c %c %c %c %02d %02d %02d %c\n", apellidoPaterno[0], apellidoPaterno[1], apellidoMaterno[0], nombre[0], anio % 100, mes, dia);
}