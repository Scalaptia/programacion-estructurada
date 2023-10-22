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
    char CURP[18];
} Tpersona;

/********* PROTOTIPOS DE FUNCIONES *********/
int msges(void);
void menu(void);

/* Funciones principales */
void generarCURP(void);
void cadenaCURP(Tpersona pers, char CURP[]);
void codigoEstado(char codigo[], char nomEstado[]);
char letraNom(char nombre[]);
char consoInterNom(char nombre[]);
char homonimia(int anio);
char vocalApe(char ape[]);
char consApe(char ape[]);
void palabrasIncon(char CURP[]);

/* Funciones auxiliares */
char buscaCons(char cad[]);
char buscaPrimCons(char cad[]);
char buscaVocal(char cad[]);
void separarNombres(char cadena[], char primerNombre[], char restoNombres[]);
bool valiPrepos(char cadena[]);
bool valiMariaJose(char cadena[]);

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
    srand(time(NULL));

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

void generarCURP(void)
{
    Tpersona pers;

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

    system("CLS");
    cadenaCURP(pers, pers.CURP);
    printf("El CURP es: %s\n", pers.CURP);
}

void cadenaCURP(Tpersona pers, char CURP[])
{
    char diaCad[3], mesCad[3], anioCad[3];
    sprintf(diaCad, "%02d", pers.dia);
    sprintf(mesCad, "%02d", pers.mes);
    sprintf(anioCad, "%02d", pers.anio % 100);

    CURP[0] = letraNom(pers.appat) ? letraNom(pers.appat) : 'X';
    CURP[1] = vocalApe(pers.appat);
    CURP[2] = letraNom(pers.apmat) ? letraNom(pers.apmat) : 'X';
    CURP[3] = letraNom(pers.nombre);
    CURP[4] = anioCad[0];
    CURP[5] = anioCad[1];
    CURP[6] = mesCad[0];
    CURP[7] = mesCad[1];
    CURP[8] = diaCad[0];
    CURP[9] = diaCad[1];
    CURP[10] = pers.sexo[0];
    CURP[11] = pers.edo.codigo[0];
    CURP[12] = pers.edo.codigo[1];
    CURP[13] = consApe(pers.appat);
    CURP[14] = consApe(pers.apmat);
    CURP[15] = consoInterNom(pers.nombre);
    CURP[16] = homonimia(pers.anio);
    CURP[17] = numAleatorio(0, 9) + '0';
    CURP[18] = '\0';

    palabrasIncon(CURP);
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
            strcpy(codigo, estados[i].codigo);
            return;
        }
    }

    strcpy(codigo, "X");
}

char letraNom(char nombre[])
{
    int largo = largoCadena(nombre);
    char primNom[largo], segNom[largo];
    separarNombres(nombre, primNom, segNom);

    if (valiMariaJose(primNom) || valiPrepos(primNom))
    {
        separarNombres(segNom, primNom, segNom);

        while (valiPrepos(primNom) && segNom[0] != '\0')
        {
            separarNombres(segNom, primNom, segNom);
        }
    }

    return primNom[0];
}

char consoInterNom(char nombre[])
{
    int largo = largoCadena(nombre);
    char primNom[largo], segNom[largo];
    separarNombres(nombre, primNom, segNom);

    if (valiMariaJose(primNom))
    {
        separarNombres(segNom, primNom, segNom);

        if (valiPrepos(primNom))
        {
            separarNombres(segNom, primNom, segNom);

            while (valiPrepos(primNom) && segNom[0] != '\0')
            {
                separarNombres(segNom, primNom, segNom);
            }
        }

        return buscaCons(primNom);
    }

    if (valiPrepos(primNom))
    {
        separarNombres(segNom, primNom, segNom);

        while (valiPrepos(primNom) && segNom[0] != '\0')
        {
            separarNombres(segNom, primNom, segNom);
        }
    }

    return buscaCons(primNom);
}

char vocalApe(char ape[])
{
    int largo = largoCadena(ape);
    char primApe[largo], segApe[largo];
    separarNombres(ape, primApe, segApe);

    if (valiPrepos(primApe))
    {
        separarNombres(segApe, primApe, segApe);

        while (valiPrepos(primApe) && segApe[0] != '\0')
        {
            separarNombres(segApe, primApe, segApe);
        }
    }

    return buscaVocal(primApe);
}

char consApe(char ape[])
{
    int largo = largoCadena(ape);
    char primApe[largo], segApe[largo];
    separarNombres(ape, primApe, segApe);

    if (valiPrepos(primApe))
    {
        separarNombres(segApe, primApe, segApe);

        while (valiPrepos(primApe) && segApe[0] != '\0')
        {
            separarNombres(segApe, primApe, segApe);
        }
    }

    return buscaCons(primApe);
}

char homonimia(int anio)
{
    if (anio < 2000)
    {
        return '0';
    }
    else
    {
        if (anio >= 2000 && anio <= 2009)
        {
            return 'A';
        }
        else
        {
            if (anio >= 2010 && anio <= 2019)
            {
                return 'B';
            }
            else
            {
                return 'C';
            }
        }
    }
}

void palabrasIncon(char CURP[])
{
    char lista[81][5] = {"BACA", "BAKA", "BUEI", "BUEY", "CACA", "CACO", "CAGA", "CAGO", "CAKA", "CAKO", "COGE", "COGI", "COJA", "COJE", "COJI", "COJO", "COLA", "CULO", "FALO", "FETO", "GETA", "GUEI", "GUEY", "JETA", "JOTO", "KACA", "KACO", "KAGA", "KAGO", "KAKA", "KAKO", "KOGE", "KOGI", "KOJA", "KOJE", "KOJI", "KOJO", "KOLA", "KULO", "LILO", "LOCA", "LOCO", "LOKA", "LOKO", "MAME", "MAMO", "MEAR", "MEAS", "MEON", "MIAR", "MION", "MOCO", "MOKO", "MULA", "MULO", "NACA", "NACO", "PEDA", "PEDO", "PENE", "PIPI", "PITO", "POPO", "PUTA", "PUTO", "QULO", "RATA", "ROBA", "ROBE", "ROBO", "RUIN", "SENO", "TETA", "VACA", "VAGA", "VAGO", "VAKA", "VUEI", "VUEY", "WUEI", "WUEY"};

    int i;
    char veri[5];
    strncpy(veri, CURP, 4);

    for (i = 0; i < 81; i++)
    {
        if (strcmp(veri, lista[i]) == 0)
        {
            CURP[1] = 'X';
        }
    }
}

// Busca la segunda consonante en una cadena
char buscaCons(char cad[])
{
    int i;
    int n = largoCadena(cad) + 1;
    i = 1;

    while (i < n)
    {
        if (cad[i] != 'A' && cad[i] != 'E' && cad[i] != 'I' && cad[i] != 'O' && cad[i] != 'U' && cad[i] != ' ')
        {
            return cad[i];
        }
        i++;
    }

    return 'X';
}

// Busca la primera consonante en una cadena
char buscaPrimCons(char cad[])
{
    int i;
    int n = largoCadena(cad) + 1;
    i = 0;

    while (i < n)
    {
        if (cad[i] != 'A' && cad[i] != 'E' && cad[i] != 'I' && cad[i] != 'O' && cad[i] != 'U' && cad[i] != ' ')
        {
            return cad[i];
        }
        i++;
    }

    return 'X';
}

// Busca la primera vocal en una cadena
char buscaVocal(char cad[])
{
    int i;
    int n = largoCadena(cad);
    i = 1;

    while (i < n)
    {
        if (cad[i] == 'A' || cad[i] == 'E' || cad[i] == 'I' || cad[i] == 'O' || cad[i] == 'U')
        {
            return cad[i];
        }
        i++;
    }

    return 'X';
}

// Separa primer y segundo nombre
void separarNombres(char cadena[], char primerNombre[], char restoNombres[])
{
    int i = 0;
    while (cadena[i] != ' ' && cadena[i] != '\0')
    {
        primerNombre[i] = cadena[i];
        i++;
    }
    primerNombre[i] = '\0';

    if (cadena[i] != '\0')
    {
        i++; // Saltar el espacio en blanco
        int j = 0;
        while (cadena[i] != '\0')
        {
            restoNombres[j] = cadena[i];
            i++;
            j++;
        }
        restoNombres[j] = '\0';
    }
    else
    {
        restoNombres[0] = '\0';
    }
}

bool valiPrepos(char cadena[])
{
    int i;
    char lista[19][4] = {"DA", "DAS", "DE", "DEL", "DER", "DI", "DIE", "DD", "Y", "EL", "LA", "LOS", "LAS", "LE", "LES", "MAC", "MC", "VAN", "VON"};

    for (i = 0; i < 19; i++)
    {
        if (strcmp(cadena, lista[i]) == 0)
        {
            return true;
        }
    }

    return false;
}

bool valiMariaJose(char cadena[])
{
    int i;
    char lista[8][6] = {"MARIA", "MAX", "MA", "MX", "M", "JOSE", "JX", "J"};

    for (i = 0; i < 8; i++)
    {
        if (strcmp(cadena, lista[i]) == 0)
        {
            return true;
        }
    }

    return false;
}