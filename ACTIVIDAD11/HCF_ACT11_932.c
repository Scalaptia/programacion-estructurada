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
void imprReg(Tprogra pers);

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

                        while (busqSeq(ingenieros, nPers, pers.key) != -1) // Valida matricula unica
                        {
                            system("CLS");
                            printf("Matricula repetida, ingrese una nueva: ");
                            pers.matricula = valiNum(300000, 399999);
                            pers.key = pers.matricula;
                        }

                        ingenieros[nPers] = pers;
                        nPers++;
                        band = false;
                        system("CLS");
                        printf("Registro Agregado: \n");
                        imprReg(pers);
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

                            while (busqSeq(ingenieros, nPers, pers.key) != -1) // Valida matricula unica
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
                    break;
                }
            } while (op != 3);
            break;

        case 2:
            printf("Ingrese la matricula del estudiante que desea eliminar: ");
            num = valiNum(300000, 399999);
            system("CLS");

            i = busqOpt(ingenieros, nPers, num, band);

            if (i != -1)
            {
                if (ingenieros[i].status != 0)
                {
                    imprReg(pers);
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

        case 3:
            printf("Ingrese la matricula del estudiante que desea buscar: ");
            num = valiNum(300000, 399999);
            system("CLS");

            i = busqOpt(ingenieros, nPers, num, band);

            if (i != -1)
            {
                printf("Matricula encontrada\n", num);
                imprReg(pers);
            }
            else
            {
                printf("La matricula %d no se encuentra en el vector\n", num);
            }
            break;

        case 4:
            if (band == false)
            {
                band = ordVect(ingenieros, nPers);
                printf("El vector ha sido ordenado\n");
            }
            else
            {
                printf("El vector ya estaba ordenado\n");
            }
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

// Genera una persona de forma manual
Tprogra genPersMan(void)
{
    Tprogra pers;

    system("CLS");
    printf("Ingresa la matricula (300000 - 399999): ");
    pers.matricula = valiNum(300000, 399999);

    do
    {
        system("CLS");
        printf("Ingresa el/los nombre/s: ");
        fflush(stdin);
        gets(pers.nombre.nombre);
    } while (valiCadena(pers.nombre.nombre) == 0 || pers.nombre.nombre[0] == '\0');

    do
    {
        system("CLS");
        printf("Ingresa el apellido paterno: ");
        fflush(stdin);
        gets(pers.nombre.appat);
    } while (valiCadena(pers.nombre.appat) == 0);

    do
    {
        system("CLS");
        printf("Ingresa el apellido materno: ");
        fflush(stdin);
        gets(pers.nombre.apmat);
    } while (valiCadena(pers.nombre.apmat) == 0);

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

    pers.edad = calculaEdad(pers.fecha);

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

    pers.key = pers.matricula;

    return pers;
}

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
        pers.fecha.anio = numAleatorio(1980, 2020);
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
    int i;

    printf("MATRICULA   NOMBRE                           APPAT                            APMAT                            FECHA NAC    EDAD   SEXO      LUGAR NAC              CURP\n\n");
    for (i = 0; i < n; i++)
    {
        if (vect[i].status != 0)
        {
            printf("%-9d   %-30s   %-30s   %-30s   %02d-%02d-%4d   %-4d   %-7s   %-20s   %-18s\n", vect[i].matricula, vect[i].nombre.nombre, vect[i].nombre.appat, vect[i].nombre.apmat, vect[i].fecha.dia, vect[i].fecha.mes, vect[i].fecha.anio, vect[i].edad, vect[i].sexo, vect[i].edo.nombre, vect[i].CURP);
        }
    }
}

// Imprime el registro de una persona.
void imprReg(Tprogra pers)
{
    printf("MATRICULA   NOMBRE                           APPAT                            APMAT                            FECHA NAC    EDAD   SEXO      LUGAR NAC              CURP\n\n");
    printf("%-9d   %-30s   %-30s   %-30s   %02d-%02d-%4d   %-4d   %-7s   %-20s   %-18s\n", pers.matricula, pers.nombre.nombre, pers.nombre.appat, pers.nombre.apmat, pers.fecha.dia, pers.fecha.mes, pers.fecha.anio, pers.edad, pers.sexo, pers.edo.nombre, pers.CURP);
}
