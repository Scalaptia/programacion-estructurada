// Fernando Haro Calvo  MATR. 372106
// 06-NOV-2023 (Creado)

/********* LIBRERIAS *********/
#include "alexandria.h"
#include "curp.h"

#define N 1500

//*** PROTOTIPOS DE FUNCIONES  ******
int msges(void);
void menu(void);

Tprogra genPersAlea(void);
Tprogra genPersMan(void);
void imprPersonas(Tprogra vect[], int n);
void imprReg(Tprogra pers);
void escrArch(char nomArchivo[], Tprogra vect[], int n);
void cargarArch(char nomArchivo[], Tprogra vect[]);

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
    op = valiNum(0, 6);
    return op;
}

/********* MENUS *********/
void menu()
{
    int op, i, num;
    int nPers = 0;
    int nAuto = 10;
    bool band;
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
            // Cargar Archivo de Texto
            printf("Ingresa el nombre del archivo: ");
            fflush(stdin);
            gets(nomArchivo);
            valiCadena(nomArchivo);
            cargarArch(nomArchivo, ingenieros);

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
            printf("Ingresa el nombre del archivo: ");
            fflush(stdin);
            gets(nomArchivo);
            valiCadena(nomArchivo);

            escrArch(nomArchivo, ingenieros, nPers);
            printf("\n");
            system("PAUSE");
            break;

        case 0:
            return;
        }
    } while (op != 0);
}

/********* FUNCIONES *********/

// Genera n cantidad de registros de personas aleatoriamente dentro del vector de personas especificado.
Tprogra genPersAlea(void)
{
    Tprogra pers;
    int sexo;

    pers.status = 1;
    pers.matricula = matriAlea();
    genAp(pers.nombre.appat);
    genAp(pers.nombre.apmat);
    sexo = numAleatorio(1, 2);
    do
    {
        pers.fecha.dia = numAleatorio(1, 31);
        pers.fecha.mes = numAleatorio(1, 12);
        pers.fecha.anio = numAleatorio(1990, 2003);
    } while (esFechaValida(pers.fecha.dia, pers.fecha.mes, pers.fecha.anio) == false);

    pers.edad = calculaEdad(pers.fecha);

    if (sexo == 1)
    {
        genNomH(pers.nombre.nombre);
        strcpy(pers.sexo, "HOMBRE");
    }
    else
    {
        genNomM(pers.nombre.nombre);
        strcpy(pers.sexo, "MUJER");
    }

    genEdoAlea(pers.edo.nombre, pers.edo.codigo);

    cadenaCURP(pers, pers.CURP);

    pers.key = pers.matricula;
    return pers;
}

// Imprime todas las personas en un vector dado.
void imprPersonas(Tprogra vect[], int n)
{
    int i, activos, op;

    printf("Registros 1 - 40\n\n");
    printf("NO     MATRICULA   APPAT                            APMAT                            NOMBRE                           EDAD   SEXO      CURP              \n\n");
    for (i = 0, activos = 0; i < n; i++)
    {
        if (vect[i].status != 0)
        {
            printf("%-4d   %-9d   %-30s   %-30s   %-30s   %-4d   %-7s   %-18s\n", i + 1, vect[i].matricula, vect[i].nombre.appat, vect[i].nombre.apmat, vect[i].nombre.nombre, vect[i].edad, vect[i].sexo, vect[i].CURP);
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
    printf("%s\n", pers.nombre.nombre);
    printf("AP. PATERNO: ");
    printf("%s\n", pers.nombre.appat);
    printf("AP. MATERNO: ");
    printf("%s\n", pers.nombre.apmat);
    printf("FECHA NAC: ");
    printf("%02d-%02d-%4d\n", pers.fecha.dia, pers.fecha.mes, pers.fecha.anio);
    printf("EDAD: ");
    printf("%d\n", pers.edad);
    printf("SEXO: ");
    printf("%s\n", pers.sexo);
    printf("LUGAR NAC: ");
    printf("%s\n", pers.edo.nombre);
    printf("CURP: ");
    printf("%s\n", pers.CURP);
}

// Escribe el archivo con los registros.
void escrArch(char nomArchivo[], Tprogra vect[], int n)
{
    int i;
    FILE *fa;

    strcat(nomArchivo, ".txt");
    fa = fopen(nomArchivo, "w");
    fprintf(fa, "MATRICULA   NOMBRE                           APPAT                            APMAT                            FECHA NAC    EDAD   SEXO      LUGAR NAC              CURP\n\n");
    for (i = 0; i < n; i++)
    {
        if (vect[i].status != 0)
        {
            fprintf(fa, "%-9d   %-30s   %-30s   %-30s   %02d-%02d-%4d   %-4d   %-7s   %-20s   %-18s\n", vect[i].matricula, vect[i].nombre.nombre, vect[i].nombre.appat, vect[i].nombre.apmat, vect[i].fecha.dia, vect[i].fecha.mes, vect[i].fecha.anio, vect[i].edad, vect[i].sexo, vect[i].edo.nombre, vect[i].CURP);
        }
    }

    printf("Archivo escrito con exito");
    fclose(fa);
}

// Carga los registros de un arhivo de texto especificado.
void cargarArch(char nomArchivo[], Tprogra vect[])
{
    int i, x;
    FILE *fa;

    strcat(nomArchivo, ".txt");
    fa = fopen(nomArchivo, "r");

    if (fa)
    {
        fscanf(fa, "MATRICULA   NOMBRE                           APPAT                            APMAT                            FECHA NAC    EDAD   SEXO      LUGAR NAC              CURP\n\n", x, x, x, x, x, x, x, x, x, x, x, x, x, x, x, x);
        do
        {
            if (vect[i].status != 0)
            {
                fscanf(fa, "%-9d   %-30s   %-30s   %-30s   %02d-%02d-%4d   %-4d   %-7s   %-20s   %-18s\n", vect[i].matricula, vect[i].nombre.nombre, vect[i].nombre.appat, vect[i].nombre.apmat, vect[i].fecha.dia, vect[i].fecha.mes, vect[i].fecha.anio, vect[i].edad, vect[i].sexo, vect[i].edo.nombre, vect[i].CURP);
            }
        } while (!feof(fa));

        printf("Archivo cargado con exito");
        fclose(fa);
    }
    printf("Archivo no encontrado");
}
