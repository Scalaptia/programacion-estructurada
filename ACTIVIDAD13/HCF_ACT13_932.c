// Fernando Haro Calvo  MATR. 372106
// 14-NOV-2023 (Creado)

/********* LIBRERIAS *********/
#include "alexandria.h"

#define N 5000
#define N_AUTO 100

//*** PROTOTIPOS DE FUNCIONES  ******
int msges(void);
void menu(void);

// Auxiliares
Tprogra genPersAlea(void);
void imprPersonas(Tprogra vect[], int n, int status);

// Registros
void imprReg(Tprogra pers);
void actBorrados(char nomArchivo[], Tprogra vect[], int n);
int cargarRegistros(Tprogra vect[], int *n);
void editarReg(Tprogra vect[], Tkey key, bool *band);

// Archivos
void leerNomArch(char nomArchivo[]);

void escrArchTXT(char nomArchivo[], Tprogra vect[], int n, bool arch);
bool cargarArchTXT(char nomArchivo[], Tprogra vect[], int *n);
void mostrarArchTXT(char nomArchivo[]);
int contarRegArch(char nomArchivo[], int status);

void escrArchBin(Tprogra vect[], int n);
bool cargarArchBin(Tprogra vect[], int *n, bool temp);
void mostrarBorradosBin(void);

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
    printf("1.- AGREGAR \n");
    printf("2.- EDITAR REGISTRO \n");
    printf("3.- ELIMINAR REGISTRO \n");
    printf("4.- BUSCAR \n");
    printf("5.- ORDENAR \n");
    printf("6.- MOSTRAR TABLA (ACTIVOS) \n");
    printf("7.- GENERAR ARCHIVO TEXTO \n");
    printf("8.- VER ARCHIVO TEXTO \n");
    printf("9.- CREAR ARCHIVO BINARIO \n");
    printf("10.- CARGAR ARCHIVO BINARIO \n");
    printf("11.- MOSTRAR ELIMINADOS \n");
    printf("0.- SALIR  \n");
    printf("ESCOGE UNA OPCION: ");
    op = valiNum(0, 11);
    return op;
}

/********* MENUS *********/
void menu()
{
    int op, num, status;
    int nPers = 0;
    bool ordenado = false, cargado = false;

    char nomArchivo[15];
    strcpy(nomArchivo, "\n");

    Tprogra ingenieros[N];
    Tkey i;

    system("CLS");

    do
    {
        op = msges();
        system("CLS");

        switch (op)
        {
        // Agregar registros
        case 1:
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

        // Editar registro
        case 2:
            printf("Ingrese la matricula del estudiante que desea editar: ");
            num = valiNum(300000, 399999);
            system("CLS");

            i = busqOpt(ingenieros, nPers, num, ordenado);

            if (i != -1)
            {
                if (ingenieros[i].status == 1)
                {
                    editarReg(ingenieros, i, &ordenado);
                }
                else
                {
                    printf("El alumno ya se encuentra inactivo\n");
                }
            }
            else
            {
                printf("La matricula %d no se encuentra en el vector\n", num);
            }
            break;

        // Eliminar registro
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

        // Escribir archivos de texto
        case 7:
            leerNomArch(nomArchivo);

            escrArchTXT(nomArchivo, ingenieros, nPers, false);
            escrArchTXT(nomArchivo, ingenieros, nPers, true);
            break;

        // Ver archivo de texto
        case 8:
            leerNomArch(nomArchivo);

            system("CLS");
            mostrarArchTXT(nomArchivo);

            break;

        // Escribir archivo binario
        case 9:
            escrArchBin(ingenieros, nPers);
            break;

        // Cargar archivo binario
        case 10:
            if (cargado)
            {
                printf("El archivo ya ha sido cargado\n");
                break;
            }

            printf("Que archivo desea cargar? (1 - datos.dll, 2 - datos.tmp): ");
            op = valiNum(1, 2);

            if (op == 1)
            {
                cargado = cargarArchBin(ingenieros, &nPers, false);
            }
            else
            {
                cargado = cargarArchBin(ingenieros, &nPers, true);
            }

            if (cargado)
            {
                printf("Archivo cargado con exito\n");
            }
            else
            {
                printf("No se pudo cargar el archivo\n");
            }

            break;

        // Mostrar registros inactivos
        case 11:
            mostrarBorradosBin();
            break;

        case 0:
            return;
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
    genPuesto(pers.puesto);
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
    printf("----------------------------------------------------------------------------------------------------------\n");
    printf("  No  | MATRICULA | PUESTO         | NOMBRE        | APELLIDO P.  |  APELLIDO MAT.     | EDAD  | SEXO \n");
    printf("----------------------------------------------------------------------------------------------------------\n");
    for (i = 0, activos = 1; i < n; i++)
    {
        if (vect[i].status == status)
        {
            printf("%4d.-  %6d      %-11s      %-10s      %-10s      %-10s          %2d      %-7s\n", activos - 1, vect[i].matricula, vect[i].puesto, vect[i].nombre, vect[i].appat, vect[i].apmat, vect[i].edad, vect[i].sexo);
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
                printf("----------------------------------------------------------------------------------------------------------\n");
                printf("  No  | MATRICULA | PUESTO         | NOMBRE        | APELLIDO P.  |  APELLIDO MAT.     | EDAD  | SEXO \n");
                printf("----------------------------------------------------------------------------------------------------------\n");
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
    printf("PUESTO: ");
    printf("%s\n", pers.puesto);
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
        fprintf(fa, "----------------------------------------------------------------------------------------------------------\n");
        fprintf(fa, "  No  | MATRICULA | PUESTO         | NOMBRE        | APELLIDO P.  |  APELLIDO MAT.     | EDAD  | SEXO \n");
        fprintf(fa, "----------------------------------------------------------------------------------------------------------\n");
    }

    for (i = 0; i < n; i++)
    {
        if (vect[i].status == 1)
        {
            fprintf(fa, "%4d.-  %6d      %-11s      %-10s      %-10s      %-10s          %2d      %-7s", cont, vect[i].matricula, vect[i].puesto, vect[i].nombre, vect[i].appat, vect[i].apmat, vect[i].edad, vect[i].sexo);

            if (i < (n - 1))
            {
                fprintf(fa, "\n");
            }
            cont++;
        }
    }

    if (arch)
    {
        fprintf(fa, "\n----------------------------------------------------------------------------------------------------------\n");
        fprintf(fa, "--  TODOS LOS DERECHOS RESERVADOS @Scalaptia        www.profeyepiz.com      @2023-2                     --\n");
        fprintf(fa, "----------------------------------------------------------------------------------------------------------");
    }

    fclose(fa);
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
                fscanf(fa, "%s %d %s %s %s %s %d %s", &temp, &reg.matricula, &reg.puesto, &reg.nombre, &reg.appat, &reg.apmat, &reg.edad, &reg.sexo);
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

// Edita un registro de una persona especificada.
void editarReg(Tprogra vect[], Tkey key, bool *band)
{
    int i, op, num;
    char temp[30];

    Tprogra reg = vect[key];

    if (i != -1)
    {
        do
        {
            system("CLS");
            printf("EDITANDO REGISTRO\n\n");
            imprReg(reg);
            printf("\n\n");

            printf("1.- MATRICULA\n");
            printf("2.- PUESTO\n");
            printf("3.- NOMBRE\n");
            printf("4.- AP. PATERNO\n");
            printf("5.- AP. MATERNO\n");
            printf("6.- EDAD\n");
            printf("7.- SEXO\n");
            printf("0.- SALIR\n");
            printf("ESCOGE UNA OPCION: ");
            op = valiNum(0, 7);
            system("CLS");

            switch (op)
            {
            case 1:
                do
                {
                    printf("Ingrese la nueva matricula: ");
                    num = valiNum(300000, 399999);
                    reg.matricula = num;
                    reg.key = num;

                    *band = false;
                } while (busqSeq(vect, key, num) != -1);

                break;

            case 2:
                char puestos[8][12] = {"GERENTE", "SUBGERENTE", "JEFE", "SUPERVISOR", "ANALISTA", "PROGRAMADOR", "AUXILIAR", "SECRETARIA"};

                printf("1.- GERENTE\n");
                printf("2.- SUBGERENTE\n");
                printf("3.- JEFE\n");
                printf("4.- SUPERVISOR\n");
                printf("5.- ANALISTA\n");
                printf("6.- PROGRAMADOR\n");
                printf("7.- AUXILIAR\n");
                printf("8.- SECRETARIA\n");
                printf("\nESCOGE UNA OPCION: ");

                op = valiNum(1, 8);
                strcpy(reg.puesto, puestos[op - 1]);
                break;

            case 3:
                printf("Ingrese el nuevo nombre: ");
                fflush(stdin);
                gets(temp);
                mayus(temp);
                strcpy(reg.nombre, temp);
                break;

            case 4:
                printf("Ingrese el nuevo apellido paterno: ");
                fflush(stdin);
                gets(temp);
                mayus(temp);
                strcpy(reg.appat, temp);
                break;

            case 5:
                printf("Ingrese el nuevo apellido materno: ");
                fflush(stdin);
                gets(temp);
                mayus(temp);
                strcpy(reg.apmat, temp);
                break;

            case 6:
                printf("Ingrese la nueva edad: ");
                num = valiNum(18, 31);
                reg.edad = num;
                break;

            case 7:
                char sexos[2][10] = {"MASCULINO", "FEMENINO"};
                printf("1.- MASULINO\n");
                printf("2.- FEEMENINO\n");
                printf("\nESCOGE UNA OPCION: ");

                op = valiNum(1, 2);
                strcpy(reg.sexo, sexos[op - 1]);
                break;
            }

            system("CLS");
        } while (op != 0);

        vect[key] = reg;
    }
}

// Muestra los registros de un archivo de texto especificado.
void mostrarArchTXT(char nomArchivo[])
{
    FILE *fa;
    Tprogra pers[N], reg;
    reg.status = 1;
    int n = 0;

    char temp[30];
    strcpy(temp, nomArchivo);
    strcat(temp, "_activos.txt");

    fa = fopen(temp, "r");

    if (fa)
    {
        while (!feof(fa))
        {
            fscanf(fa, "%s %d %s %s %s %s %d %s", &temp, &reg.matricula, &reg.puesto, &reg.nombre, &reg.appat, &reg.apmat, &reg.edad, &reg.sexo);
            pers[n++] = reg;
        }

        fclose(fa);
        imprPersonas(pers, n, 1);
    }
    else
    {
        printf("No se encontro el archivo\n");
    }
}

// Crea un archivo binario con los registros de un vector de personas especificado.
void escrArchBin(Tprogra vect[], int n)
{

    FILE *fa;
    Tprogra reg;

    char nomArchivo[11] = "datos.dll";

    rename("datos.dll", "datos.tmp");

    fa = fopen(nomArchivo, "wb");

    if (fa)
    {
        fwrite(vect, sizeof(Tprogra), n, fa);
        fclose(fa);
    }
    else
    {
        printf("No se pudo crear el archivo\n");
    }
}

// Carga los registros de un archivo binario especificado.
bool cargarArchBin(Tprogra vect[], int *n, bool temp)
{
    FILE *fa;
    Tprogra reg;

    char nomArchivo[11];

    (temp) ? strcpy(nomArchivo, "datos.tmp") : strcpy(nomArchivo, "datos.dll");

    fa = fopen(nomArchivo, "rb");

    if (fa)
    {
        while (fread(&reg, sizeof(Tprogra), 1, fa) == 1 && (*n) < N)
        {
            vect[(*n)++] = reg;
        }

        fclose(fa);
        return true;
    }

    return false;
}

// Muestra los registros inactivos de un archivo binario especificado.
void mostrarBorradosBin()
{
    FILE *fa;
    Tprogra borrados[N], reg;
    reg.status = 0;
    int cont = 0;

    fa = fopen("datos.dll", "rb");

    if (fa)
    {
        while (fread(&reg, sizeof(Tprogra), 1, fa) == 1)
        {
            if (reg.status == 0)
            {
                borrados[cont++] = reg;
            }
        }

        imprPersonas(borrados, cont, 0);
        fclose(fa);
    }
    else
    {
        printf("No se encontro el archivo\n");
    }
}