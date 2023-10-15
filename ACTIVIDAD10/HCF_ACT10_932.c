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
int busqSeqMatri(Talum vect[], int n, int matri);
int busqBinMatri(Talum vect[], int n, int matri);
int busqMatri(Talum vect[], int n, int matri, bool band);
bool ordMatri(Talum vect[], int n);

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
    int op, i, num;
    int alumnos = 0;
    bool band;

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

                    while (busqSeqMatri(ingenieros, alumnos, alum.matricula) != -1) // Valida matricula unica
                    {
                        alum.matricula = numAleatorio(300000, 399999);
                    }

                    ingenieros[alumnos] = alum;
                    alumnos++;
                }
                band = false;
            }
            else
            {
                printf("Ha llegado al maximo de alumnos\n");
            }

            break;

        case 2:
            if ((alumnos + 1) <= N)
            {
                alum = genAlumMan();

                while (busqSeqMatri(ingenieros, alumnos, alum.matricula) != -1) // Valida matricula unica
                {
                    system("CLS");
                    printf("Matricula repetida, ingrese una nueva: ");
                    alum.matricula = valiNum(300000, 399999);
                }

                ingenieros[alumnos] = alum;
                alumnos++;
                band = false;
            }
            else
            {
                printf("Ha llegado al maximo de alumnos\n");
            }

            break;

        case 3:
            printf("Ingrese la matricula del estudiante que desea eliminar: ");
            num = valiNum(300000, 399999);

            system("CLS");
            i = busqMatri(ingenieros, alumnos, num, band);

            if (i != -1)
            {
                if (ingenieros[i].status != 0)
                {
                    ingenieros[i].status = 0;
                    printf("Matricula eliminada con exito\n");
                }
                else
                {
                    printf("El alumno ya se encuentra inactivo\n");
                }
            }
            else
            {
                printf("Matricula no encontrada\n");
            }

            break;

        case 4:
            printf("Ingrese la matricula del estudiante que desea buscar: ");
            num = valiNum(300000, 399999);
            system("CLS");

            // Verifica si está ordenado el vector
            i = busqMatri(ingenieros, alumnos, num, band);

            if (i != -1)
            {
                printf("La matricula %d SI se encuentra en el vector\n", num);
            }
            else
            {
                printf("La matricula %d NO se encuentra en el vector\n", num);
            }

            break;

        case 5:
            if (band == false)
            {
                band = ordMatri(ingenieros, alumnos);
                printf("El vector ha sido ordenado\n");
            }
            else
            {
                printf("El vector ya estaba ordenado\n");
            }
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
int busqSeqMatri(Talum vect[], int n, int matri)
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

// Busca una matricula en un arreglo de alumnos ORDENADO.
int busqBinMatri(Talum vect[], int n, int matri)
{
    int med;
    int ri = 0;
    int rf = n;

    while (ri <= rf)
    {
        med = ri + (rf - ri) / 2;

        if (vect[med].matricula == matri)
        {
            return med; // Valor encontrado en indice med
        }
        else
        {
            // Verifica si es menor o mayor
            if (matri < vect[med].matricula)
            {
                rf = med--;
            }
            else
            {
                ri = med++;
            }
        }
    }

    return -1; // No se encontró
}

// Busca una matricula en un arreglo usando el algoritmo optimo
int busqMatri(Talum vect[], int n, int matri, bool band)
{
    int i;
    if (band)
    {
        printf("Buscando con busqueda binaria...\n\n");
        i = busqBinMatri(vect, n, matri);
    }
    else
    {
        printf("Buscando con busqueda secuencial...\n\n");
        i = busqSeqMatri(vect, n, matri);
    }

    return i;
}

// Ordena el vector de alumnos usando una mezcla de bubble e insertion sort.
bool ordMatri(Talum vect[], int n)
{
    int i, j;
    Talum temp;

    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (vect[j].matricula <= vect[i].matricula)
            {
                temp = vect[i];
                vect[i] = vect[j];
                vect[j] = temp;
            }
        }
    }

    return true;
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

    printf("Ingresa el status (0- No Activo, 1- Activo): ");
    alum.status = valiNum(0, 1);

    system("CLS");
    printf("Ingresa una matricula (300000 - 399999): ");
    alum.matricula = valiNum(300000, 399999);

    do
    {
        system("CLS");
        printf("Ingresa el apellido paterno: ");
        fflush(stdin);
        gets(alum.apPat);
    } while (valiCad(alum.apPat) == 0);

    do
    {
        system("CLS");
        printf("Ingresa el apellido materno: ");
        fflush(stdin);
        gets(alum.apMat);
    } while (valiCad(alum.apMat) == 0);

    do
    {
        system("CLS");
        printf("Ingresa el/los nombre/s: ");
        fflush(stdin);
        gets(alum.nombre);
    } while (valiCad(alum.nombre) == 0);

    system("CLS");
    printf("Ingresa la edad: ");
    alum.edad = valiNum(17, 100);

    system("CLS");
    printf("Ingresa el sexo (1- Hombre, 2- Mujer): ");
    alum.sexo = valiNum(1, 2);

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