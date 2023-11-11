// Fernando Haro Calvo  MATR. 372106
// 06-NOV-2023 (Creado)

/********* LIBRERIAS *********/
#include "alexandria.h"

#define N 1500

//*** PROTOTIPOS DE FUNCIONES  ******
int msges(void);
void menu(void);

Tprogra genPersAlea(void);
void imprPersonas(Tprogra vect[], int n);
void imprReg(Tprogra pers);
void escrArch(char nomArchivo[], Tprogra vect[], int n, int status, bool arch);
bool cargarArch(char nomArchivo[], Tprogra vect[], int *n);

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
    printf("1.- CARGAR ARCHIVO \n");
    printf("2.- AGREGAR \n");
    printf("3.- ELIMINAR REGISTRO \n");
    printf("4.- BUSCAR \n");
    printf("5.- ORDENAR \n");
    printf("6.- MOSTRAR TABLA (ACTIVOS) \n");
    printf("7.- GENERAR ARCHIVO \n");
    printf("8.- CANTIDAD DE REGISTROS (ARCHIVO) \n");
    printf("9.- MOSTRAR TABLA (BORRADOS) \n");
    printf("0.- SALIR  \n");
    printf("ESCOGE UNA OPCION: ");
    op = valiNum(0, 9);
    return op;
}

/********* MENUS *********/
void menu()
{
    int op, i, num;
    int nPers = 0;
    int nAuto = 10;
    bool band, cargado;
    char nomArchivo[15];

    Tprogra ingenieros[N];
    Tprogra pers;

    system("CLS");

    do
    {
        op = msges();
        system("CLS");

        switch (op)
        {
        case 1:
            if (!cargado)
            {
                printf("Ingresa el nombre del archivo (sin extension): ");
                fflush(stdin);
                gets(nomArchivo);

                cargado = cargarArch(nomArchivo, ingenieros, &nPers);
            }
            else
            {
                printf("El archivo ya ha sido cargado\n");
            }

            printf("\n");
            system("PAUSE");
            break;

        case 2:
            if ((nPers + nAuto) <= N)
            {
                for (i = 0; i < nAuto; i++)
                {
                    pers = genPersAlea();

                    while (busqSeq(ingenieros, nPers, pers.key) != -1)
                    {
                        pers.matricula = matriAlea();
                        pers.key = pers.matricula;
                    }

                    ingenieros[nPers] = pers;
                    nPers++;
                }
                band = false;
                printf("Se han agregado %d personas\n", nAuto);
            }
            else
            {
                printf("Ha llegado al maximo de personas\n");
            }
            printf("\n");
            system("PAUSE");
            break;

        case 3:
            printf("Ingrese la matricula del estudiante que desea eliminar: ");
            num = valiNum(300000, 399999);
            system("CLS");

            i = busqOpt(ingenieros, nPers, num, band);

            if (i != -1)
            {
                if (ingenieros[i].status != 0)
                {
                    imprReg(ingenieros[i]);
                    printf("\n\nDesea eliminar el registro? (1 - Si, 2 - No) ");
                    op = valiNum(1, 2);
                    system("CLS");

                    if (op == 1)
                    {
                        ingenieros[i].status = 0;
                        printf("Matricula eliminada con exito\n");
                    }
                    else
                    {
                        printf("Matricula no eliminada\n");
                    }
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
            printf("\n");
            system("PAUSE");
            break;

        case 4:
            printf("Ingrese la matricula del estudiante que desea buscar: ");
            num = valiNum(300000, 399999);
            system("CLS");

            i = busqOpt(ingenieros, nPers, num, band);

            if (i != -1)
            {
                printf("Matricula encontrada\n\n", num);
                imprReg(ingenieros[i]);
            }
            else
            {
                printf("La matricula %d no se encuentra en el vector\n", num);
            }
            printf("\n");
            system("PAUSE");
            break;

        case 5:
            if (band == false)
            {
                band = ordOpt(ingenieros, nPers);
                printf("El vector ha sido ordenado\n");
            }
            else
            {
                printf("El vector ya estaba ordenado\n");
            }
            printf("\n");
            system("PAUSE");
            break;

        case 6:
            imprPersonas(ingenieros, nPers);
            printf("\n");
            system("PAUSE");
            break;

        case 7:
            printf("Ingresa el nombre del archivo (sin extension): ");
            fflush(stdin);
            gets(nomArchivo);

            escrArch(nomArchivo, ingenieros, nPers, 1, false);
            escrArch(nomArchivo, ingenieros, nPers, 0, false);
            escrArch(nomArchivo, ingenieros, nPers, 1, true);
            printf("\n");
            system("PAUSE");
            break;
        }
    } while (op != 0);

    escrArch(nomArchivo, ingenieros, nPers, 1, false);
    escrArch(nomArchivo, ingenieros, nPers, 0, false);
    escrArch(nomArchivo, ingenieros, nPers, 1, true);
    return;
}

/********* FUNCIONES *********/

// Genera n cantidad de registros de personas aleatoriamente dentro del vector de personas especificado.
Tprogra genPersAlea(void)
{
    Tprogra pers;
    int sexo;

    pers.status = 1;
    pers.matricula = matriAlea();
    genAp(pers.appat);
    genAp(pers.apmat);
    sexo = numAleatorio(1, 2);
    pers.edad = numAleatorio(18, 31);

    if (sexo == 1)
    {
        genNomH(pers.nombre);
        strcpy(pers.sexo, "MASCULINO");
    }
    else
    {
        genNomM(pers.nombre);
        strcpy(pers.sexo, "FEMENINO");
    }

    pers.key = pers.matricula;
    return pers;
}

// Imprime todas las personas en un vector dado.
void imprPersonas(Tprogra vect[], int n)
{
    int i, activos, op;

    printf("Registros 1 - 40\n\n");
    printf("--------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("  No  | MATRICULA | NOMBRE                       | APELLIDO P.                 |  APELLIDO MAT.                    | EDAD  | SEXO \n");
    printf("--------------------------------------------------------------------------------------------------------------------------------------\n");
    for (i = 0, activos = 0; i < n; i++)
    {
        if (vect[i].status != 0)
        {
            printf("%4d.-  %6d      %-25s      %-25s      %-25s          %2d      %-7s\n", activos, vect[i].matricula, vect[i].nombre, vect[i].appat, vect[i].apmat, vect[i].edad, vect[i].sexo);
            activos++;
        }

        if ((activos) % 40 == 0 && activos < n)
        {
            printf("\n\n");
            printf("Desea continuar? (0 - Si, 1 - No): ");
            op = valiNum(0, 1);

            if (op == 0)
            {
                system("CLS");
                printf("Registros %d - %d\n\n", activos + 1, (activos + 40) > n ? n : (activos + 40));
                printf("NO     MATRICULA   APPAT                            APMAT                            NOMBRE                           EDAD   SEXO      CURP              \n\n");
            }
            else
            {
                return;
            }
        }
    }
}

// Imprime el registro de una persona.
void imprReg(Tprogra pers)
{
    printf("STATUS: ");
    printf("%s\n", pers.status == 1 ? "ACTIVO" : "NO ACTIVO");
    printf("MATRICULA: ");
    printf("%d\n", pers.matricula);
    printf("NOMBRE: ");
    printf("%s\n", pers.nombre);
    printf("AP. PATERNO: ");
    printf("%s\n", pers.appat);
    printf("AP. MATERNO: ");
    printf("%s\n", pers.apmat);
    printf("EDAD: ");
    printf("%d\n", pers.edad);
    printf("SEXO: ");
    printf("%s\n", pers.sexo);
}

// Escribe el archivo con los registros.
void escrArch(char nomArchivo[], Tprogra vect[], int n, int status, bool arch)
{
    if (n <= 0)
    {
        printf("No hay registros para escribir\n");
        return;
    }

    int i, cont = 0;
    FILE *fa;

    char temp[30];
    strcpy(temp, nomArchivo);

    if (arch)
    {
        strcpy(temp, nomArchivo);
    }
    else
    {
        if (status == 0)
        {
            strcat(temp, "_borrados");
        }
        else
        {
            strcat(temp, "_activos");
        }
    }

    strcat(temp, ".txt");
    fa = fopen(temp, "w");

    if (arch)
    {
        fprintf(fa, "--------------------------------------------------------------------------------------------------------------------------------------\n");
        fprintf(fa, "  No  | MATRICULA | NOMBRE                       | APELLIDO P.                 |  APELLIDO MAT.                    | EDAD  | SEXO \n");
        fprintf(fa, "--------------------------------------------------------------------------------------------------------------------------------------\n");
    }

    for (i = 0; i < n; i++)
    {
        if (vect[i].status == status)
        {
            fprintf(fa, "%4d.-  %6d      %-25s      %-25s      %-25s          %2d      %-7s\n", cont, vect[i].matricula, vect[i].nombre, vect[i].appat, vect[i].apmat, vect[i].edad, vect[i].sexo);
            cont++;
        }
    }

    if (arch)
    {
        fprintf(fa, "--------------------------------------------------------------------------------------------------------------------------------------\n");
        fprintf(fa, "--  TODOS LOS DERECHOS RESERVADOS @Scalaptia                     www.profeyepiz.com                                      @2023      --\n");
        fprintf(fa, "--------------------------------------------------------------------------------------------------------------------------------------\n");
    }

    fclose(fa);
}

// Carga los registros de un arhivo de texto especificado.
bool cargarArch(char nomArchivo[], Tprogra vect[], int *n)
{
    FILE *fa;
    Tprogra reg;

    char temp[30];

    strcpy(temp, nomArchivo);
    strcat(temp, "_activos.txt");

    fa = fopen(temp, "r");

    if (fa)
    {
        while (!feof(fa))
        {
            if (((*n) + 1) <= N)
            {
                reg.status = 1;
                fscanf(fa, "%s %d %s %s %s %d %s", &temp, &reg.matricula, &reg.nombre, &reg.appat, &reg.apmat, &reg.edad, &reg.sexo);
                reg.key = reg.matricula;
                vect[(*n)++] = reg;
            }
            else
            {
                printf("Vector llenado\n");
            }
        }

        fclose(fa);
        return true;
    }
    else
    {
        printf("Archivo no encontrado");
        return false;
    }
}
