// Fernando Haro Calvo  MATR. 372106
// 05-OCT-2023 (Creado)

/********* LIBRERIAS *********/
#include "alexandria.h"

/********* STRUCTS *********/

typedef struct _est
{
    char nombre[20];
    char codigo[3];
} Testado;

typedef struct _persona
{
    char appat[30];
    char apmat[30];
    char nombre[30];
    int anio;
    int mes;
    int dia;
    char sexo[7];
    Testado edo;
} Tpersona;

/********* PROTOTIPOS DE FUNCIONES *********/
int msges(void);
void menu(void);
void generarCURP(void);
void cadenaCURP(char CURP[], Tpersona pers);
void codigoEstado(char codigo[], char nomEstado[]);

/*********  MAIN PRINCIPAL *********/
int main()
{
    menu();

    return 0;
}

/********* FUNCIONES *********/
int msges()
{
    int op;
    system("CLS");
    printf("\n   M   E   N   U \n");
    printf("1.- GENERAR CURP \n");
    printf("0.- SALIR  \n");
    printf("ESCOGE UNA OPCION: ");
    op = valiNum(0, 1);
    return op;
}

void menu()
{
    int op;
    system("CLS");

    do
    {
        op = msges();
        system("CLS");
        switch (op)
        {
        case 1:
            generarCURP();
            break;

        case 0:
            return;
        }

        printf("\n");
        system("PAUSE");
    } while (op != 0);
}

void codigoEstado(char codigo[], char nomEstado[])
{
    Testado estados[] = {
        {"AGUASCALIENTES", "AS"},
        {"BAJA CALIFORNIA", "BC"},
        {"BAJA CALIFORNIA SUR", "BS"},
        {"CAMPECHE", "CC"},
        {"COAHUILA", "CL"},
        {"COLIMA", "CM"},
        {"CHIAPAS", "CS"},
        {"CHIHUAHUA", "CH"},
        {"DISTRITO FEDERAL", "DF"},
        {"DURANGO", "DG"},
        {"GUANAJUATO", "GT"},
        {"GUERRERO", "GR"},
        {"HIDALGO", "HG"},
        {"JALISCO", "JC"},
        {"MEXICO", "MC"},
        {"MICHOACAN", "MN"},
        {"MORELOS", "MS"},
        {"NAYARIT", "NT"},
        {"NUEVO LEON", "NL"},
        {"OAXACA", "OC"},
        {"PUEBLA", "PL"},
        {"QUERETARO", "QT"},
        {"QUINTANA ROO", "QR"},
        {"SAN LUIS POTOSI", "SP"},
        {"SINALOA", "SL"},
        {"SONORA", "SR"},
        {"TABASCO", "TC"},
        {"TAMAULIPAS", "TS"},
        {"TLAXCALA", "TL"},
        {"VERACRUZ", "VZ"},
        {"YUCATAN", "YN"},
        {"ZACATECAS", "ZS"},
        {"EXTRANJERO", "NE"},
    };

    for (int i = 0; i < 33; i++)
    {
        if (strcmp(estados[i].nombre, nomEstado) == 0)
        {
            strcpy(codigo, estados[i].codigo); // Encontrado
            return;
        }
    }

    strcpy(codigo, "X"); // No encontrado
}

void cadenaCURP(char CURP[], Tpersona pers)
{
    // Convertir fecha a cadena
    char diaCad[3], mesCad[3], anioCad[3];
    sprintf(diaCad, "%02d", pers.dia);
    sprintf(mesCad, "%02d", pers.mes);
    sprintf(anioCad, "%02d", pers.anio % 100);

    CURP[0] = pers.appat[0];
    CURP[1] = pers.appat[1];
    CURP[2] = pers.apmat[0];
    CURP[3] = pers.nombre[0];
    CURP[4] = anioCad[0];
    CURP[5] = anioCad[1];
    CURP[6] = mesCad[0];
    CURP[7] = mesCad[1];
    CURP[8] = diaCad[0];
    CURP[9] = diaCad[1];
    CURP[10] = pers.sexo[0];
    CURP[11] = pers.edo.codigo[0];
    CURP[12] = pers.edo.codigo[1];
    CURP[13] = ' ';
    CURP[14] = ' ';
    CURP[15] = ' ';
    CURP[16] = ' ';
    CURP[17] = ' ';
    CURP[18] = ' ';
}

void generarCURP(void)
{
    Tpersona pers;

    do
    {
        system("CLS");
        printf("Ingresa el apellido paterno: ");
        fflush(stdin);
        gets(pers.appat);
    } while (valiCad(pers.appat) == 0);

    do
    {
        system("CLS");
        printf("Ingresa el apellido materno: ");
        fflush(stdin);
        gets(pers.apmat);
    } while (valiCad(pers.apmat) == 0);

    do
    {
        system("CLS");
        printf("Ingresa el/los nombre/s: ");
        fflush(stdin);
        gets(pers.nombre);
    } while (valiCad(pers.nombre) == 0);

    system("CLS");
    printf("Ingresa el anio de nacimiento: ");
    pers.anio = valiNum(1893, 2023);

    do
    {
        system("CLS");
        printf("Ingresa el mes de nacimiento: ");
        pers.mes = valiNum(1, 12);
    } while (valiMes(pers.mes, pers.anio) == false);

    do
    {
        system("CLS");
        printf("Ingresa el dia de nacimiento: ");
        pers.dia = valiNum(1, 31);
    } while (esFechaValida(pers.dia, pers.mes, pers.anio) == false);

    do
    {
        system("CLS");
        printf("Ingrese el sexo (H/M): ");
        fflush(stdin);
        gets(pers.sexo);
        mayus(pers.sexo);
    } while (strcmp(pers.sexo, "H") != 0 && strcmp(pers.sexo, "M") != 0);
    (strcmp(pers.sexo, "M")) ? strcpy(pers.sexo, "HOMBRE") : strcpy(pers.sexo, "MUJER");

    do
    {
        system("CLS");
        printf("Ingresa el estado de nacimiento (o 'extranjero'): ");
        fflush(stdin);
        gets(pers.edo.nombre);
        mayus(pers.edo.nombre);
        codigoEstado(pers.edo.codigo, pers.edo.nombre);
    } while (!strcmp(pers.edo.codigo, "X"));

    system("CLS");
    char curp[18];
    cadenaCURP(curp, pers);
    printf("El CURP es: %s\n", curp);
}