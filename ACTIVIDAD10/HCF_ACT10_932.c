// Fernando Haro Calvo  MATR. 372106
// 05-OCT-2023 (Creado)

//***  LIBRERIAS  ******
#include "alexandria.h"

//***  STRUCTS  *****
struct _alum
{
    int status;    // 0 Inactivo - 1 Activo
    int matricula; // 300000 - 399999
    char apPat[30];
    char apMat[30];
    char nombre[30];
    int edad;
    int sexo; // 1 Hombre - 2 Mujer
};

typedef struct _alum Talum;

///***  NOMBRES ******
char nombresH[20][30] = {"Juan", "Pedro", "Luis", "Carlos", "Miguel", "José", "Antonio", "Francisco", "Manuel", "Javier", "Alejandro", "David", "Fernando", "Roberto", "Rafael", "José Luis", "Daniel", "Alberto", "Mario", "Andrés"};
char nombresM[20][30] = {"María", "Ana", "Laura", "Luisa", "Sofía", "Isabel", "Carmen", "Rosa", "Elena", "Lucía", "Patricia", "Lourdes", "Marta", "Raquel", "Julia", "Clara", "Mónica", "Diana", "Valentina", "Carolina"};
char apellidos[40][30] = {"González", "Rodríguez", "Pérez", "Fernández", "López", "Martínez", "Gómez", "Sánchez", "Díaz", "Torres", "Vargas", "Ruiz", "Ramírez", "Hernández", "Flores", "Jiménez", "Moreno", "Alvarez", "Castro", "Ortega", "Silva", "Núñez", "Mendoza", "Rojas", "Vega", "Cruz", "Morales", "Guerrero", "Romero", "Valdez", "Gutiérrez", "Reyes", "Soto", "Chavez", "Navarro", "Zapata", "Acosta", "Fuentes", "Lara"};

//*** PROTOTIPOS DE FUNCIONES  ******
int msges(void);
void menu(void);
void genAlum(Talum vect[], int n, int *alumnos, int num);

//****  MAIN PRINCIPAL  *********
int main()
{
    srand(time(NULL));
    menu();

    return 0;
}

//****  DESARROLLO DE LAS FUNCIONES  ******
int msges()
{
    int op;
    system("CLS");
    printf("\n   M   E   N   U \n");
    printf("1.- AGREGAR (AUTOM 10 REGISTROS) \n");
    printf("2.- AGREGAR MANUAL \n");
    printf("3.- ELIMINAR REGISTRO (LOGICO) \n");
    printf("4.- BUSCAR \n");
    printf("5.- ORDENAR \n");
    printf("6.- IMPRIMIR \n");
    printf("0.- SALIR  \n");
    printf("ESCOGE UNA OPCION: ");
    op = valiNum(0, 6);
    return op;
}

//*********************
void menu()
{
    int op;
    Talum ingenieros[500];
    int alumnos = 0;

    system("CLS");

    do
    {
        op = msges();
        system("CLS");

        switch (op)
        {
        case 1:
            genAlum(ingenieros, 500, &alumnos, 10);
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

        printf("\n");
        system("PAUSE");
    } while (op != 0);
}

// Genera n cantidad de registros de alumnos aleatoriamente dentro del vector de alumnos especificado.
void genAlum(Talum vect[], int n, int *alumnos, int num)
{
    int i;

    for (i = 0; i < num; i++)
    {
        if ((*alumnos + 1) > n)
        {
            printf("Ha llegado al maximo de alumnos");
            system("PAUSE");
            return;
        }

        alumnos++;
        Talum alum;

        alum.status = 1;
        alum.matricula = numAleatorio(300000, 399999); // Falta validar repeticiones
        alum.apPat[30] = *apellidos[numAleatorio(0, 40)];
        alum.apMat[30] = *apellidos[numAleatorio(0, 40)];
        alum.edad = numAleatorio(18, 30);
        alum.sexo = numAleatorio(1, 2);

        if (alum.sexo == 1)
        {
            alum.nombre[30] = *nombresH[numAleatorio(0, 20)];
        }
        else
        {
            alum.nombre[30] = *nombresM[numAleatorio(0, 20)];
        }

        vect[*alumnos] = alum;
    }
}