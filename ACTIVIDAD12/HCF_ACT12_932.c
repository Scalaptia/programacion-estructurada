// Fernando Haro Calvo  MATR. 372106
// 06-NOV-2023 (Creado)

/********* LIBRERIAS *********/
#include "alexandria.h"

#define N 1500
#define N_AUTO 10

//*** PROTOTIPOS DE FUNCIONES  ******
int msges(void);
void menu(void);

// Auxiliares
Tprogra genPersAlea(void);
void imprPersonas(Tprogra vect[], int n, int status);
void imprReg(Tprogra pers);
void escrArchTXT(char nomArchivo[], Tprogra vect[], int n, bool arch);
void leerNomArch(char nomArchivo[]);
void actBorrados(char nomArchivo[], Tprogra vect[], int n);
int cargarRegistros(Tprogra vect[], int *n);
bool cargarArchTXT(char nomArchivo[], Tprogra vect[], int *n);
int contarRegArch(char nomArchivo[], int status);

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
    printf("7.- GENERAR ARCHIVOS \n");
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
    int op, i, num, status;
    int nPers = 0;
    bool ordenado = false, cargado = false;

    char nomArchivo[15];
    strcpy(nomArchivo, "\n");

    Tprogra ingenieros[N];

    system("CLS");

    do
    {
        op = msges();
        system("CLS");

        switch (op)
        {
        // Cargar archivo
        case 1:
            if (!cargado)
            {
                leerNomArch(nomArchivo);
                cargado = cargarArchTXT(nomArchivo, ingenieros, &nPers);

                if (cargado)
                {
                    printf("Archivo cargado con exito\n");
                }
                else
                {
                    printf("Archivo no encontrado\n");
                }
            }
            else
            {
                printf("El archivo ya ha sido cargado\n");
            }
            break;

        // Agregar registros
        case 2:
            num = cargarRegistros(ingenieros, &nPers);

            if (num == -1)
            {
                printf("Ha llegado al maximo de personas\n");
            }
            else
            {
                printf("Se han agregado %d personas\n", N_AUTO);
                ordenado = false;
            }

            if (strcmp(nomArchivo, "\n") != 0)
            {
                escrArchTXT(nomArchivo, ingenieros, nPers, false);
                escrArchTXT(nomArchivo, ingenieros, nPers, true);
            }
            break;

        // Eliminar registros
        case 3:
            printf("Ingrese la matricula del estudiante que desea eliminar: ");
            num = valiNum(300000, 399999);
            system("CLS");

            i = busqOpt(ingenieros, nPers, num, ordenado);

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
            break;

        // Buscar registros
        case 4:
            printf("Ingrese la matricula del estudiante que desea buscar: ");
            num = valiNum(300000, 399999);
            system("CLS");

            i = busqOpt(ingenieros, nPers, num, ordenado);

            if (i != -1)
            {
                printf("Matricula encontrada\n\n", num);
                imprReg(ingenieros[i]);
            }
            else
            {
                printf("La matricula %d no se encuentra en el vector\n", num);
            }
            break;

        // Ordenar registros
        case 5:
            if (ordenado == false)
            {
                ordenado = ordOpt(ingenieros, nPers);
                printf("El vector ha sido ordenado\n");
            }
            else
            {
                printf("El vector ya estaba ordenado\n");
            }
            break;

        // Mostrar registros activos
        case 6:
            imprPersonas(ingenieros, nPers, 1);
            break;

        // Generar archivos
        case 7:
            leerNomArch(nomArchivo);

            escrArchTXT(nomArchivo, ingenieros, nPers, false);
            escrArchTXT(nomArchivo, ingenieros, nPers, true);
            break;

        // Contar registros
        case 8:
            printf("Ingrese el status de los registros que desea contar (1 - Borrados, 2 - Activos): ");
            status = valiNum(1, 2);

            leerNomArch(nomArchivo);
            num = contarRegArch(nomArchivo, status);

            system("CLS");
            if (num == -1)
            {
                printf("Archivo no encontrado\n");
            }
            else
            {
                printf("Hay %d registro(s) en el archivo\n", num);
            }
            break;

        // Mostrar registros borrados
        case 9:
            imprPersonas(ingenieros, nPers, 0);
            break;

        case 0:
            if (strcmp(nomArchivo, "\n") != 0)
            {
                escrArchTXT(nomArchivo, ingenieros, nPers, false);
                escrArchTXT(nomArchivo, ingenieros, nPers, true);
                actBorrados(nomArchivo, ingenieros, nPers);
            }
            else
            {
                printf("Desea guardar los datos? (1- Si, 2- No): \n");
                num = valiNum(1, 2);
                if (num == 1)
                {
                    leerNomArch(nomArchivo);

                    escrArchTXT(nomArchivo, ingenieros, nPers, false);
                    escrArchTXT(nomArchivo, ingenieros, nPers, true);
                    actBorrados(nomArchivo, ingenieros, nPers);
                }
            }
            break;
        }

        printf("\n");
        system("PAUSE");
    } while (op != 0);

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
void imprPersonas(Tprogra vect[], int n, int status)
{
    int i, activos, op;

    printf("Registros 1 - 40\n\n");
    printf("------------------------------------------------------------------------------------------\n");
    printf("  No  | MATRICULA | NOMBRE        | APELLIDO P.  |  APELLIDO MAT.     | EDAD  | SEXO \n");
    printf("------------------------------------------------------------------------------------------\n");
    for (i = 0, activos = 1; i < n; i++)
    {
        if (vect[i].status == status)
        {
            printf("%4d.-  %6d      %-10s      %-10s      %-10s          %2d      %-7s\n", activos - 1, vect[i].matricula, vect[i].nombre, vect[i].appat, vect[i].apmat, vect[i].edad, vect[i].sexo);
            activos++;
        }

        if (activos % 41 == 0 && activos < n)
        {
            printf("\n\n");
            printf("Desea continuar? (0 - Si, 1 - No): ");
            op = valiNum(0, 1);

            if (op == 0)
            {
                system("CLS");
                printf("Registros %d - %d\n\n", activos + 1, (activos + 40) > n ? n : (activos + 40));
                printf("------------------------------------------------------------------------------------------\n");
                printf("  No  | MATRICULA | NOMBRE        | APELLIDO P.  |  APELLIDO MAT.     | EDAD  | SEXO \n");
                printf("------------------------------------------------------------------------------------------\n");
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

// Lee el nombre de un archivo de texto especificado.
void leerNomArch(char nomArchivo[])
{
    do
    {
        system("CLS");
        printf("Ingresa el nombre del archivo (sin extension): ");
        fflush(stdin);
        gets(nomArchivo);
    } while (strcmp(nomArchivo, "\n") == 0);
}

// Escribe los registros de un vector de personas en un archivo de texto especificado.
void escrArchTXT(char nomArchivo[], Tprogra vect[], int n, bool arch)
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

    if (!arch)
    {
        strcat(temp, "_activos");
    }

    strcat(temp, ".txt");
    fa = fopen(temp, "w");

    if (arch)
    {
        fprintf(fa, "------------------------------------------------------------------------------------------\n");
        fprintf(fa, "  No  | MATRICULA | NOMBRE        | APELLIDO P.  |  APELLIDO MAT.     | EDAD  | SEXO \n");
        fprintf(fa, "------------------------------------------------------------------------------------------\n");
    }

    for (i = 0; i < n; i++)
    {
        if (vect[i].status == 1)
        {
            fprintf(fa, "%4d.-  %6d      %-10s      %-10s      %-10s          %2d      %-7s", cont, vect[i].matricula, vect[i].nombre, vect[i].appat, vect[i].apmat, vect[i].edad, vect[i].sexo);

            if (i < (n - 1))
            {
                fprintf(fa, "\n");
            }
            cont++;
        }
    }

    if (arch)
    {
        fprintf(fa, "\n------------------------------------------------------------------------------------------\n");
        fprintf(fa, "--  TODOS LOS DERECHOS RESERVADOS @Scalaptia        www.profeyepiz.com     @2023-2      --\n");
        fprintf(fa, "------------------------------------------------------------------------------------------");
    }

    fclose(fa);
}

// Actualiza los registros de un archivo de texto especificado.
void actBorrados(char nomArchivo[], Tprogra vect[], int n)
{
    FILE *fa;
    Tprogra reg;
    int i, cont;

    char temp[30];
    strcpy(temp, nomArchivo);
    strcat(temp, "_borrados.txt");

    fa = fopen(temp, "a");

    if (fa)
    {
        cont = contarRegArch(nomArchivo, 1);

        if (cont > 0)
        {
            fprintf(fa, "\n");
        }

        for (i = 0; i < n; i++)
        {
            if (vect[i].status == 0)
            {
                fprintf(fa, "%4d.-  %6d      %-10s      %-10s      %-10s          %2d      %-7s", cont, vect[i].matricula, vect[i].nombre, vect[i].appat, vect[i].apmat, vect[i].edad, vect[i].sexo);

                if (i < (n - 1))
                {
                    fprintf(fa, "\n");
                }
                cont++;
            }
        }

        fclose(fa);
    }
}

// Carga los registros de un arhivo de texto especificado.
bool cargarArchTXT(char nomArchivo[], Tprogra vect[], int *n)
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

    return false;
}

// Cuenta los registros de un archivo de texto especificado desde el ejecutable contadorReg.
int contarRegArch(char nomArchivo[], int status)
{
    int cont;
    char fileName[50];
    char cmd[50];

    system("gcc contadorReg.c -o contadorReg");
    sprintf(cmd, "contadorReg.exe %s %d", nomArchivo, status);
    cont = system(cmd);

    return cont;
}

// Carga n cantidad de registros de personas aleatoriamente dentro del vector de personas especificado.
int cargarRegistros(Tprogra vect[], int *nPers)
{
    int i;
    Tprogra pers;

    if ((*nPers + N_AUTO) <= N)
    {
        for (i = 0; i < N_AUTO; i++)
        {
            pers = genPersAlea();

            while (busqSeq(vect, *nPers, pers.key) != -1)
            {
                pers.matricula = matriAlea();
                pers.key = pers.matricula;
            }

            vect[(*nPers)++] = pers;
        }
    }
    else
    {
        return -1;
    }
}