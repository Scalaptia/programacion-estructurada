/*
1)
    - BUSCAR UNA CANCION
    - CREAR ARCHIVO.TXT
    - LEER EL ARCHIVO Y DESPLEGAR EN PANTALLA

2)
    - CREAR UN ASCII ART
    - CREAR UN ARCHIVO TEXTO CON EL ASCII ART
    - LEER EL ARCHIVO Y DESPLEGAR

3)
    - CREAR ARCHIVO TEXTO
    + LEER DATOS (Y CADENAS)
    + ESCRIBIRLAS EN UN ARCHIVO
*/

#include "alexandria.h"

//*** PROTOTIPOS DE FUNCIONES  ******
int msges(void);
void menu(void);
void imprArchivo(char archivo[]);
void escrArchivo(char archivo[]);

int main()
{
    srand(time(NULL));
    menu();

    return 0;
}

int msges()
{
    int op;
    system("CLS");
    printf("\n   M   E   N   U \n");
    printf("1.- IMPRIMIR CANCION \n");
    printf("2.- IMPRIMIR ASCII ART \n");
    printf("3.- ESCRIBIR CADENAS EN ARCHIVO \n");
    printf("0.- SALIR  \n");
    printf("ESCOGE UNA OPCION: ");
    op = valiNum(0, 3);
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
            imprArchivo("cancion.txt");
            break;

        case 2:
            imprArchivo("ascii-art.txt");
            break;

        case 3:
            escrArchivo("persona.txt");
            break;

        case 0:
            return;
        }

        printf("\n");
        system("PAUSE");
    } while (op != 0);
}

void imprArchivo(char archivo[])
{
    char car;
    FILE *fa;

    fa = fopen(archivo, "r");

    if (fa)
    {
        do
        {
            car = fgetc(fa);
            printf("%c", car);
        } while (!(feof(fa)));

        fclose(fa);
    }
    else
    {
        printf("No se encontró el archivo");
    }
}

void escrArchivo(char archivo[])
{
    char nombre[90];
    char edad[3];
    char lugar[90];

    FILE *fa;
    fa = fopen(archivo, "a");

    printf("Ingrese datos:\n");

    printf("Nombre: ");
    gets(nombre);
    fprintf(fa, "Nombre: ");
    fprintf(fa, "%s\n", nombre);

    printf("Edad: ");
    gets(edad);
    fprintf(fa, "Edad: ");
    fprintf(fa, "%s\n", edad);

    printf("Lugar: ");
    gets(lugar);
    fprintf(fa, "Lugar: ");
    fprintf(fa, "%s\n\n", lugar);

    fclose(fa);
}