// Fernando Haro Calvo  MATR. 372106
// 27-OCT-2023 (Creado)

/********* LIBRERIAS *********/
#include "alexandria.h"
#include "curp.h"

#define N 2000

//*** PROTOTIPOS DE FUNCIONES  ******
int msges(void);
void menu(void);

Tprogra genPersAlea(void);
Tprogra genPersMan(void);
void imprPersonas(Tprogra vect[], int n);

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
    printf("5.- IMPRIMIR \n");
    printf("6.- ARCHIVO TEXTO \n");
    printf("0.- SALIR  \n");
    printf("ESCOGE UNA OPCION: ");
    op = valiNum(0, 6);
    return op;
}

int msgesAgg()
{
    int op;
    system("CLS");
    printf("\n   A   G   R   E   G   A   R \n");
    printf("1.- MANUAL (1) \n");
    printf("2.- AUTOMATICO (100) \n");
    printf("3.- REGRESAR \n");
    printf("ESCOGE UNA OPCION: ");
    op = valiNum(1, 3);
    return op;
}

/********* MENUS *********/
void menu()
{
    int op, i, num;
    int nPers = 0;
    int nAuto = 100;
    bool band;

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
            do
            {
                op = msgesAgg();
                system("CLS");

                switch (op)
                {
                case 1:
                    if ((nPers + 1) <= N)
                    {
                        pers = genPersMan();

                        while (busqSeq(ingenieros, nPers, pers.matricula) != -1) // Valida matricula unica
                        {
                            system("CLS");
                            printf("Matricula repetida, ingrese una nueva: ");
                            pers.matricula = valiNum(300000, 399999);
                        }

                        ingenieros[nPers] = pers;
                        nPers++;
                        band = false;
                    }
                    else
                    {
                        printf("Ha llegado al maximo de personas\n");
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

                            while (busqSeq(ingenieros, nPers, pers.matricula) != -1) // Valida matricula unica
                            {
                                pers.matricula = numAleatorio(300000, 399999);
                            }

                            ingenieros[nPers] = pers;
                            nPers++;
                        }
                        band = false;
                        printf("Se han añadido %d personas\n", nAuto);
                    }
                    else
                    {
                        printf("Ha llegado al maximo de personas\n");
                    }
                    printf("\n");
                    system("PAUSE");
                    break;

                case 3:
                    break;
                }
            } while (op != 3);

            break;

        case 5:
            imprPersonas(ingenieros, nPers);
            break;

        case 0:
            return;
        }

        printf("\n");
        system("PAUSE");
    } while (op != 0);
}

/********* FUNCIONES *********/

// Genera n cantidad de registros de personas aleatoriamente dentro del vector de personas especificado.
Tprogra genPersAlea(void)
{
    Tprogra pers;
    int sexo;

    pers.status = 1;
    pers.matricula = numAleatorio(300000, 399999);
    genAp(pers.appat);
    genAp(pers.apmat);
    sexo = numAleatorio(1, 2);
    do
    {
        pers.fecha.dia = numAleatorio(1, 31);
        pers.fecha.mes = numAleatorio(1, 12);
        pers.fecha.anio = numAleatorio(1980, 2020);
    } while (esFechaValida(pers.fecha.dia, pers.fecha.mes, pers.fecha.anio) == false);

    pers.edad = 2023 - pers.fecha.anio;
    if (11 < pers.fecha.mes || (11 == pers.fecha.mes && 31 < pers.fecha.mes)) // 11 mes 31 dia
    {
        pers.edad--;
    }

    if (sexo == 1)
    {
        genNomH(pers.nombre);
        strcpy(pers.sexo, "HOMBRE");
    }
    else
    {
        genNomM(pers.nombre);
        strcpy(pers.sexo, "MUJER");
    }

    genEdoAlea(pers.edo.nombre, pers.edo.codigo);

    cadenaCURP(pers, pers.CURP);

    return pers;
}

// Genera una persona de forma manual
Tprogra genPersMan(void)
{
    Tprogra pers;

    do
    {
        system("CLS");
        printf("Ingresa el apellido paterno: ");
        fflush(stdin);
        gets(pers.appat);
    } while (valiCadena(pers.appat) == 0);

    do
    {
        system("CLS");
        printf("Ingresa el apellido materno: ");
        fflush(stdin);
        gets(pers.apmat);
    } while (valiCadena(pers.apmat) == 0);

    do
    {
        system("CLS");
        printf("Ingresa el/los nombre/s: ");
        fflush(stdin);
        gets(pers.nombre);
    } while (valiCadena(pers.nombre) == 0 || pers.nombre[0] == '\0');

    system("CLS");
    printf("Ingresa el anio de nacimiento: ");
    pers.fecha.anio = valiNum(1893, 2023);

    do
    {
        system("CLS");
        printf("Ingresa el mes de nacimiento: ");
        pers.fecha.mes = valiNum(1, 12);
    } while (valiMes(pers.fecha.mes, pers.fecha.anio) == false);

    do
    {
        system("CLS");
        printf("Ingresa el dia de nacimiento: ");
        pers.fecha.dia = valiNum(1, 31);
    } while (esFechaValida(pers.fecha.dia, pers.fecha.mes, pers.fecha.anio) == false);

    do
    {
        system("CLS");
        printf("Ingrese el sexo (H/M): ");
        fflush(stdin);
        gets(pers.sexo);
        valiChars(pers.sexo);
    } while (strcmp(pers.sexo, "H") != 0 && strcmp(pers.sexo, "M") != 0);
    (strcmp(pers.sexo, "M")) ? strcpy(pers.sexo, "HOMBRE") : strcpy(pers.sexo, "MUJER");

    do
    {
        system("CLS");
        printf("Ingresa el estado de nacimiento (o 'extranjero'): ");
        fflush(stdin);
        gets(pers.edo.nombre);
        valiChars(pers.edo.nombre);
        codigoEstado(pers.edo.codigo, pers.edo.nombre);
    } while (!strcmp(pers.edo.codigo, "X"));

    cadenaCURP(pers, pers.CURP);

    return pers;
}

// Imprime todas las personas en un vector dado.
void imprPersonas(Tprogra vect[], int n)
{
    int i;

    printf("MATRICULA   NOMBRE                           APPAT                            APMAT                            FECHA NAC    EDAD   SEXO      LUGAR NAC              CURP\n\n");
    for (i = 0; i < n; i++)
    {
        if (vect[i].status != 0)
        {
            printf("%-9d   %-30s   %-30s   %-30s   %02d-%02d-%4d   %-4d   %-7s   %-20s   %-18s\n", vect[i].matricula, vect[i].nombre, vect[i].appat, vect[i].apmat, vect[i].fecha.dia, vect[i].fecha.mes, vect[i].fecha.anio, vect[i].edad, vect[i].sexo, vect[i].edo.nombre, vect[i].CURP);
        }
    }
}
