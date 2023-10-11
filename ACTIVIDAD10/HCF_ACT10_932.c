// Fernando Haro Calvo  MATR. 372106
// 05-OCT-2023 (Creado)

//***  LIBRERIAS  ******
#include "alexandria.h"

//***  STRUCTS  *****
typedef struct _alum
{
    int status;    // 0 Inactivo - 1 Activo
    int matricula; // 300000 - 399999
    char apPat[30];
    char apMat[30];
    char nombre[30];
    int edad;
    int sexo; // 1 Hombre - 2 Mujer
} Talum;

///***  NOMBRES ******
char nombresH[20][30] = {"JUAN", "PEDRO", "LUIS", "CARLOS", "MIGUEL", "JOSE", "ANTONIO", "FRANCISCO", "MANUEL", "JAVIER", "ALEJANDRO", "DAVID", "FERNANDO", "ROBERTO", "RAFAEL", "JOSE LUIS", "DANIEL", "ALBERTO", "MARIO", "ANDRES"};
char nombresM[20][30] = {"MARIA", "ANA", "LAURA", "LUISA", "SOFIA", "ISABEL", "CARMEN", "ROSA", "ELENA", "LUCIA", "PATRICIA", "LOURDES", "MARTA", "RAQUEL", "JULIA", "CLARA", "MONICA", "DIANA", "VALENTINA", "CAROLINA"};
char apellidos[40][30] = {"GONZALEZ", "RODRIGUEZ", "PEREZ", "FERNANDEZ", "LOPEZ", "MARTINEZ", "GOMEZ", "SANCHEZ", "DIAZ", "TORRES", "VARGAS", "RUIZ", "RAMIREZ", "HERNANDEZ", "FLORES", "JIMENEZ", "MORENO", "ALVAREZ", "CASTRO", "ORTEGA", "SILVA", "NUNEZ", "MENDOZA", "ROJAS", "VEGA", "CRUZ", "MORALES", "GUERRERO", "ROMERO", "VALDEZ", "GUTIERREZ", "REYES", "SOTO", "CHAVEZ", "NAVARRO", "ZAPATA", "ACOSTA", "FUENTES", "LARA", "YEPIZ"};

#define N 50

//*** PROTOTIPOS DE FUNCIONES  ******
int msges(void);
void menu(void);
int busqMatri(Talum vect[], int n, int matri);
Talum genAlumAlea(void);
Talum genAlumMan(void);

void imprAlumnos(Talum vect[], int n);

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
    int op, i;
    int alumnos = 0;

    Talum ingenieros[N];
    Talum alum;

    system("CLS");

    do
    {
        op = msges();
        system("CLS");

        switch (op)
        {
        case 1:
            if ((alumnos + 10) <= N)
            {
                for (i = 0; i < 10; i++)
                {
                    alum = genAlumAlea();

                    while (busqMatri(ingenieros, alumnos, alum.matricula) != -1) // Valida matricula unica
                    {
                        alum.matricula = numAleatorio(300000, 399999);
                    }

                    ingenieros[alumnos] = alum;
                    alumnos++;
                }
            }
            else
            {
                printf("Ha llegado al maximo de alumnos\n");
            }

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
            imprAlumnos(ingenieros, alumnos);
            break;

        case 0:
            return;
        }

        printf("\n");
        system("PAUSE");
    } while (op != 0);
}

// Busca una matricula en un arreglo de alumnos NO ORDENADO.
int busqMatri(Talum vect[], int n, int matri)
{
    int i;

    for (i = 0; i < n; i++)
    {
        if (vect[i].matricula == matri)
        {
            return i; // Retorna índice
        }
    }

    return -1; // No se encontró
}

// Genera n cantidad de registros de alumnos aleatoriamente dentro del vector de alumnos especificado.
Talum genAlumAlea()
{
    Talum alum;

    alum.status = 1;
    alum.matricula = numAleatorio(300000, 399999);
    strcpy(alum.apPat, apellidos[numAleatorio(0, 39)]);
    strcpy(alum.apMat, apellidos[numAleatorio(0, 39)]);
    alum.edad = numAleatorio(18, 30);
    alum.sexo = numAleatorio(1, 2);

    if (alum.sexo == 1)
    {
        strcpy(alum.nombre, nombresH[numAleatorio(0, 19)]);
    }
    else
    {
        strcpy(alum.nombre, nombresM[numAleatorio(0, 19)]);
    }

    return alum;
}

Talum genAlumMan()
{
    Talum alum;

    alum.status = 1;

    printf("Ingresa una matricula (300000 - 399999): ");
    alum.matricula = valiNum(300000, 399999);

    strcpy(alum.apPat, apellidos[numAleatorio(0, 40)]);

    strcpy(alum.apMat, apellidos[numAleatorio(0, 40)]);
    alum.edad = numAleatorio(18, 30);
    alum.sexo = numAleatorio(1, 2);

    if (alum.sexo == 1)
    {
        strcpy(alum.nombre, nombresH[numAleatorio(0, 20)]);
    }
    else
    {
        strcpy(alum.nombre, nombresM[numAleatorio(0, 20)]);
    }

    return alum;
}

// Imprime todos los alumnos en un vector dado.
void imprAlumnos(Talum vect[], int n)
{
    int i;

    printf("MATRICULA   NOMBRE                           APPAT                            APMAT                            EDAD   SEXO  \n\n");
    for (i = 0; i < n; i++)
    {
        if (vect[i].status != 0)
        {
            printf("%-9d   %-30s   %-30s   %-30s   %-4d   ", vect[i].matricula, vect[i].nombre, vect[i].apPat, vect[i].apMat, vect[i].edad);

            if (vect[i].sexo == 1)
            {
                printf("HOMBRE\n");
            }
            else
            {
                printf("MUJER\n");
            }
        }
    }
}