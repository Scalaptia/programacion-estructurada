// Fernando Haro Calvo  MATR. 372106
// 23-NOV-2023 (Creado)

/********* LIBRERIAS *********/
#include "alexandria.h"

/********* DEFINICIONES *********/
#define N_AUTO 1

//*** PROTOTIPOS DE FUNCIONES  ******
int msges(void);
void menu(void);

// Auxiliares
void leerNomArch(char nomArchivo[]);
TWrkr genPersAlea(void);
void imprArchBin(Tindice indice[], int n, int ordenado);

// Registros
void imprReg(TWrkr pers);
void agregarReg(Tindice indice[], int *n, int *ordenado);
void eliminarReg(Tindice indice[], int *n, int ordenado);
void buscarReg(Tindice indice[], int n, int ordenado);
void ordenarReg(Tindice indice[], int n, int *ordenado);

// Archivos
void escrArchTXT(char nomArchivo[], Tindice vect[], int n, int ordenado);

// Archivos binarios
void empaquetar(Tindice indice[], int *n);
bool cargarIndice(Tindice vect[], int *n);
int contarRegArch(char nomArchivo[]);

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
    printf("1.- AGREGAR REGISTRO \n");
    printf("2.- ELIMINAR REGISTRO \n");
    printf("3.- BUSCAR REGISTRO \n");
    printf("4.- ORDENAR INDICE \n");
    printf("5.- IMPRIMIR ARCHIVO \n");
    printf("6.- IMPRIMIR INDICE \n");
    printf("7.- GENERAR ARCHIVO TEXTO \n");
    printf("8.- EMPAQUETAR \n");
    printf("9.- SALIR  \n");
    printf("ESCOGE UNA OPCION: ");
    op = valiNum(1, 9);
    return op;
}

/********* MENU *********/
void menu()
{
    int op;
    int nPers = 0;
    int ordenado = 0;
    char nomArchivo[15];

    int N = contarRegArch("datos");
    N *= 1.25;

    Tindice indice[N];
    cargarIndice(indice, &nPers);

    system("CLS");

    do
    {
        op = msges();
        system("CLS");

        switch (op)
        {
        // Agregar registros
        case 1:
            agregarReg(indice, &nPers, &ordenado);
            break;

        // Eliminar registro
        case 2:
            eliminarReg(indice, &nPers, ordenado);
            break;

        // Buscar registros
        case 3:
            buscarReg(indice, nPers, ordenado);
            break;

        // Ordenar registros
        case 4:
            ordenarReg(indice, nPers, &ordenado);
            break;

        // Imprimir registros originales desde el archivo
        case 5:
            imprArchBin(indice, nPers, 0);
            break;

        // Imprimir registros ordenados desde el indice
        case 6:
            imprArchBin(indice, nPers, 1);
            break;

        // Escribir archivo de texto
        case 7:
            leerNomArch(nomArchivo);

            system("CLS");
            printf("1 - Archivo\n2 - Indice\n\nElija una opcion: ");
            if (valiNum(1, 2) == 1)
            {
                escrArchTXT(nomArchivo, indice, nPers, 0);
            }
            else
            {
                escrArchTXT(nomArchivo, indice, nPers, 1);
            }

            break;

        // Empaquetar registros
        case 8:
            empaquetar(indice, &nPers);
            break;
        }

        printf("\n");
        system("PAUSE");
    } while (op != 9);

    return;
}

/********* FUNCIONES *********/

// Genera n cantidad de registros de personas aleatoriamente dentro del vector de personas especificado.
TWrkr genPersAlea(void)
{
    TWrkr pers;
    int sexo;

    pers.status = 1;
    pers.enrollment = matriAlea();
    pers.cellPhone = numTelAlea();

    genEdo(pers.state);
    genAp(pers.LastName1);
    genAp(pers.LastName2);
    genPuesto(pers.JobPstion);

    sexo = numAleatorio(1, 2);
    pers.age = numAleatorio(18, 31);

    if (sexo == 1)
    {
        genNomH(pers.name);
        strcpy(pers.sex, "HOMBRE");
    }
    else
    {
        genNomM(pers.name);
        strcpy(pers.sex, "MUJER");
    }

    return pers;
}

void imprArchBin(Tindice indice[], int n, int ordenado)
{
    int i, activos, op;

    FILE *fa;
    TWrkr reg;
    fa = fopen("datos.dat", "rb");

    printf("Registros 1 - 40\n");
    printf("------------------------------------------------------------------------------------------------------------------------------\n");
    printf("  No  | MATRICULA | TELEFONO   | ESTADO | PUESTO         | NOMBRE        | APELLIDO P.  |  APELLIDO MAT.     | EDAD  | SEXO \n");
    printf("------------------------------------------------------------------------------------------------------------------------------\n");
    for (i = 0, activos = 1; i < n; i++)
    {
        if (ordenado == 1)
        {
            fseek(fa, indice[i].indice * sizeof(TWrkr), SEEK_SET);
        }
        else
        {
            fseek(fa, i * sizeof(TWrkr), SEEK_SET);
        }

        fread(&reg, sizeof(TWrkr), 1, fa);

        if (reg.status == 1)
        {
            printf("%4d.-  %6d      %-7d      %-2s       %-11s      %-10s      %-10s      %-10s          %2d      %-7s\n", activos - 1, reg.enrollment, reg.cellPhone, reg.state, reg.JobPstion, reg.name, reg.LastName1, reg.LastName2, reg.age, reg.sex);
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
                printf("Registros %d - %d\n", activos + 1, (activos + 40) > n ? n : (activos + 40));
                printf("------------------------------------------------------------------------------------------------------------------------------\n");
                printf("  No  | MATRICULA | TELEFONO   | ESTADO | PUESTO         | NOMBRE        | APELLIDO P.  |  APELLIDO MAT.     | EDAD  | SEXO \n");
                printf("------------------------------------------------------------------------------------------------------------------------------\n");
            }
            else
            {
                fclose(fa);
                return;
            }
        }
    }

    fclose(fa);
}

// Imprime el registro de una persona.
void imprReg(TWrkr pers)
{
    printf("STATUS: ");
    printf("%s\n", pers.status == 1 ? "ACTIVO" : "NO ACTIVO");
    printf("MATRICULA: ");
    printf("%d\n", pers.enrollment);
    printf("TELEFONO: ");
    printf("%d\n", pers.cellPhone);
    printf("ESTADO: ");
    printf("%s\n", pers.state);
    printf("PUESTO: ");
    printf("%s\n", pers.JobPstion);
    printf("NOMBRE: ");
    printf("%s\n", pers.name);
    printf("AP. PATERNO: ");
    printf("%s\n", pers.LastName1);
    printf("AP. MATERNO: ");
    printf("%s\n", pers.LastName2);
    printf("EDAD: ");
    printf("%d\n", pers.age);
    printf("SEXO: ");
    printf("%s\n", pers.sex);
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

// Escribe un archivo de texto con los registros especificados. Escribir
void escrArchTXT(char nomArchivo[], Tindice indice[], int n, int ordenado)
{
    int i, cont = 0;
    TWrkr reg;

    FILE *fa;
    FILE *fb;

    char temp[30];
    strcpy(temp, nomArchivo);
    strcat(temp, ".txt");

    fa = fopen(temp, "w");
    fb = fopen("datos.dat", "rb");

    fprintf(fa, "------------------------------------------------------------------------------------------------------------------------------\n");
    fprintf(fa, "  No  | MATRICULA | TELEFONO   | ESTADO | PUESTO         | NOMBRE        | APELLIDO P.  |  APELLIDO MAT.     | EDAD  | SEXO \n");
    fprintf(fa, "------------------------------------------------------------------------------------------------------------------------------\n");

    for (i = 0, cont = 1; i < n; i++)
    {
        if (ordenado == 1)
        {
            fseek(fb, indice[i].indice * sizeof(TWrkr), SEEK_SET);
        }
        else
        {
            fseek(fb, i * sizeof(TWrkr), SEEK_SET);
        }

        fread(&reg, sizeof(TWrkr), 1, fb);

        if (reg.status == 1)
        {
            fprintf(fa, "%4d.-  %6d      %-7d      %-2s       %-11s      %-10s      %-10s      %-10s          %2d      %-7s\n", cont - 1, reg.enrollment, reg.cellPhone, reg.state, reg.JobPstion, reg.name, reg.LastName1, reg.LastName2, reg.age, reg.sex);
            cont++;
        }
    }

    fprintf(fa, "\n------------------------------------------------------------------------------------------------------------------------------\n");
    fprintf(fa, "--  TODOS LOS DERECHOS RESERVADOS @Scalaptia     ONLYCODES      ESPY               www.profeyepiz.com      @2023-2          --\n");
    fprintf(fa, "------------------------------------------------------------------------------------------------------------------------------");

    fclose(fa);
    fclose(fb);
}

// Actualiza el archivo binario eliminando los registros no activos.
void empaquetar(Tindice indice[], int *n)
{
    TWrkr reg;
    FILE *fa;
    FILE *fb;

    rename("datos.dat", "datos.bak");

    fa = fopen("datos.dat", "wb");
    fb = fopen("datos.bak", "rb");

    while (fread(&reg, sizeof(TWrkr), 1, fb) == 1)
    {
        if (reg.status == 1)
        {
            fwrite(&reg, sizeof(TWrkr), 1, fa);
        }
    }

    fclose(fa);
    fclose(fb);

    *n = 0;
    cargarIndice(indice, n);

    printf("Archivo empaquetado con exito\n");
}

// Carga los registros de un archivo binario especificado en un vector de indices
bool cargarIndice(Tindice indice[], int *n)
{
    FILE *fa;
    TWrkr reg;

    fa = fopen("datos.dat", "rb");

    if (fa)
    {
        while (fread(&reg, sizeof(TWrkr), 1, fa) == 1)
        {
            indice[*n].key = reg.enrollment;
            indice[*n].indice = *n;
            (*n)++;
        }

        fclose(fa);
        return true;
    }

    return false;
}

// Cuenta los registros de un archivo de texto especificado desde el ejecutable contadorReg.
int contarRegArch(char nomArchivo[])
{
    int cont;
    char fileName[50];
    char cmd[50];

    system("gcc contadorReg.c -o contadorReg");
    sprintf(cmd, "contadorReg.exe %s", nomArchivo);
    cont = system(cmd);

    return cont;
}

// Agrega un registro al vector de indices y al final del archivo binario.
void agregarReg(Tindice indice[], int *n, int *ordenado)
{
    TWrkr reg;
    FILE *fa;

    reg = genPersAlea();

    while (busqOpt(indice, *n, reg.enrollment, *ordenado) != -1)
    {
        reg.enrollment = matriAlea();
    }

    fa = fopen("datos.dat", "ab");
    fwrite(&reg, sizeof(TWrkr), 1, fa);
    fclose(fa);

    indice[*n].key = reg.enrollment;
    indice[*n].indice = *n;
    (*n)++;

    printf("Registro agregado con exito\n");

    if (*ordenado == 1)
    {
        *ordenado = 2;
    }
}

void eliminarReg(Tindice indice[], int *n, int ordenado)
{
    Tkey i;
    int num, op;
    FILE *fa;
    TWrkr reg;

    printf("Ingrese la matricula del estudiante que desea eliminar: ");
    num = valiNum(300000, 399999);
    system("CLS");

    i = busqOpt(indice, *n, num, ordenado);

    if (i != -1)
    {
        fa = fopen("datos.dat", "rb+");

        fseek(fa, indice[i].indice * sizeof(TWrkr), SEEK_SET);
        fread(&reg, sizeof(TWrkr), 1, fa);

        if (reg.status == 0)
        {
            printf("Matricula se encuentra eliminada\n");
        }
        else
        {
            imprReg(reg);
            printf("\n\nDesea eliminar el registro? (1 - Si, 2 - No) ");
            op = valiNum(1, 2);
            system("CLS");

            if (op == 1)
            {
                reg.status = 0;
                fseek(fa, indice[i].indice * sizeof(TWrkr), SEEK_SET);
                fwrite(&reg, sizeof(TWrkr), 1, fa);

                printf("Matricula eliminada con exito\n");
            }
            else
            {
                printf("Matricula no eliminada\n");
            }
        }

        fclose(fa);
    }
    else
    {
        printf("Matricula no encontrada\n");
    }
}

void buscarReg(Tindice indice[], int n, int ordenado)
{
    Tkey i;
    int num;

    FILE *fa;
    TWrkr reg;

    printf("Ingrese la matricula del estudiante que desea buscar: ");
    num = valiNum(300000, 399999);
    system("CLS");

    i = busqOpt(indice, n, num, ordenado);

    if (i != -1)
    {
        printf("Matricula encontrada\n\n", num);
        fa = fopen("datos.dat", "rb");

        fseek(fa, indice[i].indice * sizeof(TWrkr), SEEK_SET);
        fread(&reg, sizeof(TWrkr), 1, fa);
        imprReg(reg);

        fclose(fa);
    }
    else
    {
        printf("La matricula %d no se encuentra en el vector\n", num);
    }
}

void ordenarReg(Tindice indice[], int n, int *ordenado)
{
    if (*ordenado == 0 || *ordenado == 2)
    {
        *ordenado = ordOpt(indice, n, *ordenado);
        printf("El vector ha sido ordenado\n");
    }
    else
    {
        printf("El vector ya estaba ordenado\n");
    }
}