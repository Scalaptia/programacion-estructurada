// Fernando Haro Calvo  MATR. 372106
// 23-NOV-2023 (Creado)

/*
INSTRUCCIONES: Programa que contenga el menú anterior, el programa utiliza un vector de índices de la siguiente estructura:  [ llave, índice] donde el campo llave es  noempleado.
registros.dat es el archivo con los registros a cargar en el vector de índices  archivo binario sera proporcionado.

CARGAR ARCHIVO : El programa deberá cargar al arrancar el programa, el archivo Binario generará el vector de índices (llave, indice) sólo con registros válidos (el tamaño del vector debera ser 25% mas grande que el la cantidad de registros que contenga el archivo binario ) utiliza un archivo externo para averiguar tamaño y retorne cantidad de registros.

1.- Agregar :
El programa deberá ser capaz de agregar un registro al arreglo de índices y al final del archivo Binario.  (agregar forma automatica no repetido el campo llave)

2.- Eliminar :
El programa deberá buscar una noempleado en el vector de índices por medio del método de búsqueda más óptimo.
La función deberá retornar, el índice donde se encuentra la matrícula en el archivo Binario,  utilizar banderas para escoger el método más adecuado.
Una vez obtenido el índice moverse dentro del archivo binario (usar fseek ) usando el índice del vector de índices.
Leer el registro en la posición correcta, preguntar si se quiere eliminar registro.
Cambiar el status del registro si la respuesta es afirmativa, volver a posición anterior y sobreescribir el registro.


3.- Buscar :
El programa deberá buscar un noempleado en el vector de índices por medio del método de búsqueda más óptimo.
La función deberá retornar, el índice donde se encuentra la matrícula en el archivo Binario,  utilizar banderas para escoger el método más adecuado.
Una vez obtenido el índice moverse dentro del archivo binario (usar fseek ) usando el índice del vector de índices.
Leer el registro en la posición correcta, y desplegar el registro.

4.- Ordenar :
El programa deberá ordenar el vector de índices por medio del método de ordenación más óptimo. Utilizar banderas para escoger el método más adecuado por el que se ordenará por el campo llave (noempleado) o no ordenarse si ya está ordenado.   (utilizar 3 metodos de ordenacion diferentes segun sea el caso que se necesite Justificar los metodos en el reporte)

5 Y 6.- Mostrar Todo:
El programa deberá mostrar todos los registros del Archivo Binario, preguntar:  ordenado o normal.  Usar el vector de índices para imprimirlo ordenado, y directamente desde el archivo si es normal.

7.- GENERAR ARCHIVO TEXTO:

El programa deberá generar un archivo de texto, el usuario debe proporcionar el nombre del archivo.
El programa deberá mostrar todos los registros del Archivo Binario, preguntar:  ordenado o normal.  Usar el vector de índices para imprimirlo ordenado, y directamente desde el archivo si es normal.
el programa podrá generar múltiples archivos para comprobar las salidas.

8.- EMPAQUETAR :
El programa deberá actualizar el Archivo Binario, a partir de solo registros válidos, y eliminarlos del archivo binario.  Crear copia y archivo de respaldo .bak del archivo de antes de eliminarlos.
*/

/********* LIBRERIAS *********/
#include "alexandria.h"

/********* DEFINICIONES *********/
#define N_AUTO 1

//*** PROTOTIPOS DE FUNCIONES  ******
int msges(void);
void menu(void);

// Auxiliares
TWrkr genPersAlea(void);
void imprArchBin();
void imprArchBinOrdenado(Tindice indice[], int n);

// Registros
void imprReg(Tindice pers);
int cargarRegistros(Tindice vect[], int *n);

// Archivos
void leerNomArch(char nomArchivo[]);
void escrArchTXT(char nomArchivo[], Tindice vect[], int n);

// Archivos binarios
void empaquetar(Tindice vect[], int n);
bool cargarArchBin(TWrkr vect[]);
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
    printf("1.- AGREGAR \n");
    printf("2.- ELIMINAR REGISTRO \n");
    printf("3.- BUSCAR \n");
    printf("4.- ORDENAR \n");
    printf("5.- IMPRIMIR (ARCHIVO ORIGINAL) \n");
    printf("6.- IMPRIMIR (ARCHIVO ORDENADO) \n");
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
    int op, num;
    int nPers = 0;
    bool ordenado = false, cargado = false;

    char nomArchivo[15];
    strcpy(nomArchivo, "\n");

    int N = contarRegArch("datos");
    N *= 1.25;

    printf("N: %d\n", N);
    system("PAUSE");

    Tindice indice[N]; // [ llave, índice] donde el campo llave es noempleado.
    cargado = cargarIndice(indice, &nPers);

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
            num = cargarRegistros(indice, &nPers);

            if (num == -1)
            {
                printf("Ha llegado al maximo de personas\n");
            }
            else
            {
                printf("Se han agregado %d personas\n", N_AUTO);
                ordenado = false;
            }

            break;

        // Eliminar registro
        case 2:
            printf("Ingrese la matricula del estudiante que desea eliminar: ");
            num = valiNum(300000, 399999);
            system("CLS");

            i = busqOpt(indice, nPers, num, ordenado);

            if (i != -1)
            {
                imprReg(indice[i]);
                printf("\n\nDesea eliminar el registro? (1 - Si, 2 - No) ");
                op = valiNum(1, 2);
                system("CLS");

                if (op == 1)
                {
                    // Eliminar registro indice[i]
                    printf("Matricula eliminada con exito\n");
                }
                else
                {
                    printf("Matricula no eliminada\n");
                }
            }
            else
            {
                printf("Matricula no encontrada\n");
            }
            break;

        // Buscar registros
        case 3:
            printf("Ingrese la matricula del estudiante que desea buscar: ");
            num = valiNum(300000, 399999);
            system("CLS");

            i = busqOpt(indice, nPers, num, ordenado);

            if (i != -1)
            {
                printf("Matricula encontrada\n\n", num);
                imprReg(indice[i]);
            }
            else
            {
                printf("La matricula %d no se encuentra en el vector\n", num);
            }
            break;

        // Ordenar registros
        case 4:
            if (ordenado == false)
            {
                ordenado = ordOpt(indice, nPers);
                printf("El vector ha sido ordenado\n");
            }
            else
            {
                printf("El vector ya estaba ordenado\n");
            }
            break;

        // Imprimir registros originales
        case 5:
            imprArchBin();
            break;

        // Imprimir registros ordenados por matricula
        case 6:
            imprArchBinOrdenado(indice, nPers);
            break;

        // Escribir archivos de texto
        case 7:
            leerNomArch(nomArchivo);

            escrArchTXT(nomArchivo, indice, nPers);
            break;

        // Empaquetar registros
        case 8:
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

void imprArchBin()
{
    int i, activos, op;

    int n = contarRegArch("datos");

    TWrkr vect[n];
    cargarArchBin(vect);

    printf("Registros 1 - 40\n");
    printf("------------------------------------------------------------------------------------------------------------------------------\n");
    printf("  No  | MATRICULA | TELEFONO   | ESTADO | PUESTO         | NOMBRE        | APELLIDO P.  |  APELLIDO MAT.     | EDAD  | SEXO \n");
    printf("------------------------------------------------------------------------------------------------------------------------------\n");
    for (i = 0, activos = 1; i < n; i++)
    {
        if (vect[i].status == 1)
        {
            printf("%4d.-  %6d      %-7d      %-2s       %-11s      %-10s      %-10s      %-10s          %2d      %-7s\n", activos - 1, vect[i].enrollment, vect[i].cellPhone, vect[i].state, vect[i].JobPstion, vect[i].name, vect[i].LastName1, vect[i].LastName2, vect[i].age, vect[i].sex);
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
                return;
            }
        }
    }
}

void imprArchBinOrdenado(Tindice indice[], int n)
{
    int i, activos, op;

    Tindice indiceOrdenado[n];
    for (i = 0; i < n; i++)
    {
        indiceOrdenado[i] = indice[i];
    }
    ordOpt(indiceOrdenado, n);

    FILE *fa;
    TWrkr reg;
    fa = fopen("datos.dat", "rb");

    printf("Registros 1 - 40\n");
    printf("------------------------------------------------------------------------------------------------------------------------------\n");
    printf("  No  | MATRICULA | TELEFONO   | ESTADO | PUESTO         | NOMBRE        | APELLIDO P.  |  APELLIDO MAT.     | EDAD  | SEXO \n");
    printf("------------------------------------------------------------------------------------------------------------------------------\n");
    for (i = 0, activos = 1; i < n; i++)
    {
        fseek(fa, indiceOrdenado[i].indice * sizeof(TWrkr), SEEK_SET);
        fread(&reg, sizeof(TWrkr), 1, fa);

        printf("%4d.-  %6d      %-7d      %-2s       %-11s      %-10s      %-10s      %-10s          %2d      %-7s\n", activos - 1, reg.enrollment, reg.cellPhone, reg.state, reg.JobPstion, reg.name, reg.LastName1, reg.LastName2, reg.age, reg.sex);
        activos++;

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
                return;
            }
        }
    }

    fclose(fa);
}

// Imprime el registro de una persona.
void imprReg(Tindice indice)
{
    TWrkr pers;

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

// Escribe los registros de un vector de personas en un archivo de texto especificado.
void escrArchTXT(char nomArchivo[], Tindice indice[], int n)
{
    if (n <= 0)
    {
        printf("No hay registros para escribir\n");
        return;
    }

    int i, cont = 0;

    FILE *fa;
    TWrkr vect[n];

    char temp[30];
    strcpy(temp, nomArchivo);
    strcat(temp, ".txt");

    fa = fopen(temp, "w");

    fprintf(fa, "----------------------------------------------------------------------------------------------------------\n");
    fprintf(fa, "  No  | MATRICULA | PUESTO         | NOMBRE        | APELLIDO P.  |  APELLIDO MAT.     | EDAD  | SEXO \n");
    fprintf(fa, "----------------------------------------------------------------------------------------------------------\n");

    for (i = 0; i < n; i++)
    {
        if (vect[i].status == 1)
        {
            fprintf(fa, "%4d.-  %6d      %-0010d      %-13s      %-11s      %-10s      %-10s      %-10s          %2d      %-7s\n", cont, vect[i].enrollment, vect[i].cellPhone, vect[i].state, vect[i].JobPstion, vect[i].name, vect[i].LastName1, vect[i].LastName2, vect[i].age, vect[i].sex);

            if (i < (n - 1))
            {
                fprintf(fa, "\n");
            }
            cont++;
        }
    }

    fprintf(fa, "\n----------------------------------------------------------------------------------------------------------\n");
    fprintf(fa, "--  TODOS LOS DERECHOS RESERVADOS @Scalaptia        www.profeyepiz.com      @2023-2                     --\n");
    fprintf(fa, "----------------------------------------------------------------------------------------------------------");

    fclose(fa);
}

// Carga n cantidad de registros de personas aleatoriamente dentro del vector de personas especificado.
int cargarRegistros(Tindice vect[], int *nPers)
{
    int i;
    TWrkr pers;

    for (i = 0; i < N_AUTO; i++)
    {
        pers = genPersAlea();

        while (busqSeq(vect, *nPers, pers.enrollment) != -1)
        {
            pers.enrollment = matriAlea();
        }

        // Agregar persona al vector (archivo binario)

        // Agragar persona al vector de indices
    }
}

// Crea un archivo binario con los registros de un vector de personas especificado.
void empaquetar(Tindice vect[], int n)
{

    FILE *fa;
    Tindice reg;

    rename("datos.dat", "datos.bak");

    fa = fopen("datos.dat", "wb");

    if (fa)
    {
        fwrite(vect, sizeof(Tindice), n, fa);
        fclose(fa);
    }
    else
    {
        printf("No se pudo crear el archivo\n");
    }
}

// Carga los registros de un archivo binario especificado.
bool cargarArchBin(TWrkr vect[])
{
    FILE *fa;
    TWrkr reg;
    int n = 0;

    fa = fopen("datos.dat", "rb");

    if (fa)
    {
        while (fread(&reg, sizeof(TWrkr), 1, fa) == 1)
        {
            if (reg.status == 1)
            {
                vect[n] = reg;
                n++;
            }
        }

        fclose(fa);
        return true;
    }

    return false;
}

// Carga los registros de un archivo binario especificado en un vector de indices
bool cargarIndice(Tindice indice[], int *n)
{
    FILE *fa;

    int N = contarRegArch("datos");
    N *= 1.25;

    TWrkr vect[N];
    TWrkr reg;

    fa = fopen("datos.dat", "rb");

    if (fa)
    {
        while (fread(&reg, sizeof(TWrkr), 1, fa) == 1)
        {
            if (reg.status == 1)
            {
                vect[(*n)++] = reg;

                // Crear indice
                indice[(*n) - 1].key = reg.enrollment;
                indice[(*n) - 1].indice = (*n) - 1;
            }
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