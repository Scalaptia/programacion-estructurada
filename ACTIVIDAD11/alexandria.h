/********* LIBRERIAS *********/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

/********* STRUCTS *********/
typedef long Tkey;

typedef struct _nom
{
    char nombre[30];
    char appat[30];
    char apmat[30];
} Tnombre;

typedef struct _fecha
{
    int dia;
    int mes;
    int anio;
} Tfecha;

typedef struct _est
{
    char nombre[20];
    char codigo[3];
} Testado;

typedef struct _progra
{
    int status;
    Tkey key;
    int matricula;
    Tnombre nombre;
    Tfecha fecha;
    int edad;
    char sexo[7];
    Testado edo;
    char CURP[19];
} Tprogra;

/********* PROTOTIPOS *********/
int valiNum(int ri, int rf);
int valiEspacios(char cadena[]);
int valiAlfa(char cadena[]);
int valiCad(char cadena[]);

int numAleatorio(int ri, int rf);
int matriAlea(void);

int busqSeq(Tprogra vect[], int n, Tkey num);
int busqSeqOrd(Tprogra vect[], int n, Tkey num);
int busqBin(Tprogra vect[], int n, Tkey num);
int busqOpt(Tprogra vect[], int n, Tkey num, bool band);
int busqSeqMat(int mat[][4], int m, int n, int num);

void imprVect(int vect[], int n);
void imprMat(int mat[][4], int m, int n);

bool ordBubble(Tprogra vect[], int n);
bool ordQuick(Tprogra vect[], int n);
void qs(Tprogra vect[], int limite_izq, int limite_der);
bool ordOpt(Tprogra vect[], int n);

void mayus(char cadena[]);
int largoCadena(char cadena[]);

bool valiMes(int mes, int anio);
bool esAnioBisiesto(int anio);
bool esFechaValida(int dia, int mes, int anio);

void genNomH(char cadena[]);
void genNomM(char cadena[]);
void genAp(char cadena[]);

/********* VALIDACIÓN *********/

// Valida la entrada del usuario en un rango de numeros enteros.
int valiNum(int ri, int rf)
{
    char cadena[50];
    int num;

    do
    {
        fflush(stdin);
        gets(cadena);
        num = atoi(cadena);
    } while (num < ri || num > rf);

    return num;
}

// Valida que una cadena no inicie o termine con espacios, o contenga dobles espacios.
int valiEspacios(char cadena[])
{
    int i = 0;

    // Inicia con espacio
    if (cadena[0] == ' ') // no puede iniciar con espacios
    {
        return 0;
    }

    // Termina con espacio
    if (cadena[largoCadena(cadena)] == ' ')
    {
        return 0;
    }

    // 2 espacios seguidos
    while (cadena[i] != '\0')
    {
        if (cadena[i] == ' ')
        {
            if (cadena[i + 1] == ' ')
            {
                return 0;
            }
        }
        i++;
    }

    return 1;
}

// Valida que la cadena solo tenga caracteres alfabeticos
int valiAlfa(char cadena[])
{
    int i = 0;

    while (cadena[i] != '\0')
    {
        if (cadena[i] != ' ' && cadena[i] != ',')
        {
            if (cadena[i] < 'A' || cadena[i] > 'Z')
            {
                return 0;
            }
        }

        i++;
    }

    return 1;
}

// Valida que no haya caracteres especiales en una cadena.
int valiCad(char cadena[])
{
    mayus(cadena);

    if (valiAlfa(cadena) == 0)
    {
        return 0;
    }

    if (valiEspacios(cadena) == 0)
    {
        return 0;
    }

    return 1;
}

/********* LLENADO ALEATORIO *********/

// Genera un numero aleatorio en un rango de numeros enteros.
int numAleatorio(int ri, int rf)
{
    int rango = (rf - ri + 1);

    return rand() % rango + ri;
}

int matriAlea(void)
{
    int matri, mid, low;
    mid = rand() % 100 * 1000;
    low = rand() % 1000;

    matri = 300000 + mid + low;

    return matri;
}

/********* BUSQUEDA *********/

// Busca un valor en un arreglo NO ORDENADO de forma secuencial.
int busqSeq(Tprogra vect[], int n, Tkey num)
{
    int i;

    for (i = 0; i < n; i++)
    {
        if (vect[i].key == num)
        {
            return i; // Retorna índice
        }
    }

    return -1; // No se encontró
}

// Busca un valor en un arreglo ORDENADO de forma secuencial.
int busqSeqOrd(Tprogra vect[], int n, Tkey num)
{
    int i = 0;

    while (i < n)
    {
        if (num >= vect[i].key)
        {
            if (vect[i].key == num)
            {
                return i; // Retorna índice
            }
        }
        else
        {
            return -1; // No se encontró
        }
    }

    return -1; // No se encontró
}

// Busca un valor en un arreglo ORDENADO usando busqueda binaria.
int busqBin(Tprogra vect[], int n, Tkey num)
{
    int med;
    int ri = 0;
    int rf = n;

    while (ri <= rf)
    {
        med = ri + (rf - ri) / 2;

        if (vect[med].key == num)
        {
            return med; // Valor encontrado en indice med
        }
        else
        {
            // Verifica si es menor o mayor
            if (num < vect[med].key)
            {
                rf = med--;
            }
            else
            {
                ri = med++;
            }
        }
    }

    return -1; // No se encontró
}

// Busca un valor en un arreglo usando el algoritmo optimo
int busqOpt(Tprogra vect[], int n, Tkey num, bool band)
{
    int i;

    if (band)
    {
        i = busqBin(vect, n, num);
    }
    else
    {
        i = busqSeq(vect, n, num);
    }

    return i;
}

// Busca un valor en una matriz de forma secuencial.
int busqSeqMat(int mat[][4], int m, int n, int num)
{
    int i, j;

    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (mat[i][j] == num)
            {
                return i; // Retorna índice
            }
        }
    }

    return -1; // No se encontró
}

/********* IMPRIMIR *********/

// Imprime un vector.
void imprVect(int vect[], int n)
{
    int i;

    for (i = 0; i < n; i++)
    {
        printf("[%3d]\n", vect[i]);
    }
}

// Imprime una matriz.
void imprMat(int mat[][4], int m, int n)
{
    int i, j;

    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("[%2d]", mat[i][j]);
        }
        printf("\n");
    }
}

/********* ORDENAR *********/

// Ordena el vector usando una mezcla de bubble e insertion sort.
bool ordBubble(Tprogra vect[], int n)
{
    int i, j;
    Tprogra temp;

    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (vect[j].key <= vect[i].key)
            {
                temp = vect[i];
                vect[i] = vect[j];
                vect[j] = temp;
            }
        }
    }

    return true;
}

// Ordena el vector usando quick sort.
bool ordQuick(Tprogra vect[], int n)
{
    qs(vect, 0, n - 1);

    return true;
}

void qs(Tprogra vect[], int limite_izq, int limite_der)
{
    int izq, der, pivote;
    Tprogra temp;

    izq = limite_izq;
    der = limite_der;
    pivote = vect[(izq + der) / 2].key;

    do
    {
        while (vect[izq].key < pivote && izq < limite_der)
        {
            izq++;
        }

        while (pivote < vect[der].key && der > limite_izq)
        {
            der--;
        }

        if (izq <= der)
        {
            temp = vect[izq];
            vect[izq] = vect[der];
            vect[der] = temp;
            izq++;
            der--;
        }
    } while (izq <= der);

    if (limite_izq < der)
    {
        qs(vect, limite_izq, der);
    }

    if (limite_der > izq)
    {
        qs(vect, izq, limite_der);
    }
}

// Ordena un vector usando el algoritmo optimo
bool ordOpt(Tprogra vect[], int n)
{
    int i;

    if (n <= 200)
    {
        ordBubble(vect, n);
    }
    else
    {
        ordQuick(vect, n);
    }

    return true;
}

/********* CADENAS *********/

// Convierte la cadena a mayusculas.
void mayus(char cadena[])
{
    // Variables Locales
    int i;

    // Programa
    for (i = 0; cadena[i] != '\0'; i++)
    {
        char caracter = cadena[i];

        if (caracter >= 'a' && caracter <= 'z')
        {
            caracter -= 32; // Convertir a mayúscula (ASCII)
        }

        cadena[i] = caracter;
    }
}

// Retorna la longitud de la cadena.
int largoCadena(char cadena[])
{
    int i;

    for (i = 0; cadena[i] != '\0'; i++)
        ;

    return i - 1;
}

/********* FECHAS *********/
bool valiMes(int mes, int anio)
{
    if (anio == 2023)
    {
        if (mes > 10)
        {
            return false;
        }
    }

    return true;
}

bool esAnioBisiesto(int anio)
{
    if ((anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0))
    {
        return true;
    }

    return false;
}

bool esFechaValida(int dia, int mes, int anio)
{
    if (mes == 4 || mes == 6 || mes == 9 || mes == 11)
    {
        if (dia > 30)
        {
            return false; // Abril, junio, septiembre y noviembre tienen hasta 30 días.
        }
    }
    else if (mes == 2)
    {
        if (dia > 29)
        {
            return false; // Febrero puede tener hasta 29 días en un año bisiesto.
        }

        if (dia == 29 && !esAnioBisiesto(anio))
        {
            return false; // Febrero no puede tener 29 días en años no bisiestos.
        }
    }

    return true;
}

int calculaEdad(Tfecha fecha)
{
    int edad, anioAct, mesAct, diaAct;
    anioAct = 2023, mesAct = 10, diaAct = 28;

    edad = anioAct - fecha.anio;
    if (mesAct < fecha.mes || (mesAct == fecha.mes && diaAct < fecha.mes))
    {
        edad--;
    }

    return edad;
}

/********* DATOS ALEATORIOS *********/

void genNomH(char cadena[])
{
    char nombresH[][30] = {"CARLOS", "JUAN", "LUIS", "JOSE", "MIGUEL", "PEDRO", "DAVID", "JORGE", "FELIPE", "IVAN", "DANIEL", "RAFAEL", "ANDRES", "GABRIEL", "ALEJANDRO", "MARCOS", "JAVIER", "MARTIN", "SERGIO", "EDUARDO", "RICARDO", "MANUEL", "VICTOR", "RAUL", "HUGO", "ESTEBAN", "FRANCISCO", "MARTIN", "GONZALO", "MATEO", "JUAN CARLOS", "FERNANDO", "DIEGO", "ANGEL", "ABEL", "ABELARDO", "ADRIAN", "ALBERTO", "ALFREDO", "ALFONSO", "AMADEO", "ARTURO", "BENJAMIN", "BERNARDO", "BRUNO", "CESAR", "CLAUDIO", "CLEMENTE", "DAMIAN", "DARIO", "JUAN CARLOS", "ANTONIO JOSE", "PEDRO PABLO", "LUIS MIGUEL", "JORGE LUIS", "MANUEL ALEJANDRO", "RAFAEL ENRIQUE", "JUAN MANUEL", "JOSE ANTONIO", "CARLOS ALBERTO", "FRANCISCO JAVIER", "JAVIER ALEJANDRO", "JOSE LUIS", "FELIPE ANDRES", "ALEJANDRO JOSE", "DAVID EDUARDO", "MIGUEL ANGEL", "RICARDO ANDRES", "GABRIEL IVAN", "VICTOR MANUEL", "FRANCISCO JOSE", "ANDRES FELIPE", "CARLOS EDUARDO", "PABLO ESTEBAN", "MARCOS ANTONIO", "IVAN DARIO", "DANIEL ALEJANDRO", "JOSE MANUEL", "JUAN FELIPE", "JOSE EDUARDO", "ANGEL GABRIEL", "HUGO ENRIQUE", "RICARDO ANTONIO", "JUAN ESTEBAN", "VICTOR HUGO", "ALEJANDRO DAVID", "RAUL ANDRES", "FERNANDO JOSE", "MANUEL EDUARDO", "SERGIO IVAN", "EDUARDO ENRIQUE", "GONZALO JOSE", "PABLO ANTONIO", "JUAN DIEGO", "MARTIN ALEJANDRO", "MIGUEL ANDRES", "JUAN PABLO", "FELIPE EDUARDO", "ANDRES MAURICIO", "DANIEL EDUARDO"};
    strcpy(cadena, nombresH[rand() % 100]);
}

void genNomM(char cadena[])
{
    char nombresM[][30] = {"MARIA", "ANA", "LAURA", "SOFIA", "CARMEN", "PATRICIA", "ISABEL", "MARTA", "ELENA", "ROSA", "CLARA", "CAROLINA", "ANDREA", "PAULA", "LUCIA", "BEATRIZ", "ADRIANA", "SILVIA", "LOURDES", "RAQUEL", "TERESA", "RAQUEL", "LORENA", "SUSANA", "INES", "ANA MARIA", "ROSARIO", "NATALIA", "MONICA", "ELISA", "ALMA", "ISABEL", "LIDIA", "SONIA", "YOLANDA", "AURORA", "NURIA", "CARLA", "MIRIAM", "ESTHER", "JULIA", "IRENE", "OLGA", "MARIANA", "SILVANA", "VALERIA", "JUANA", "DIANA", "VERONICA", "GISELA", "MARIA ISABEL", "ANA MARIA", "LAURA SOFIA", "CARMEN ELENA", "PATRICIA ANDREA", "ISABEL MARTA", "CLARA ANTONIA", "CAROLINA EUGENIA", "ANDREA PATRICIA", "PAULA BEATRIZ", "LUCIA SUSANA", "BEATRIZ ADRIANA", "ADRIANA SILVIA", "LOURDES MARIANA", "RAQUEL TERESA", "TERESA LORENA", "LORENA ISABEL", "SUSANA INES", "INES ROSARIO", "ANA TERESA", "ROSARIO EUGENIA", "NATALIA JULIA", "MONICA YOLANDA", "ELISA CARLA", "ALMA VERONICA", "ISABEL LIDIA", "LIDIA SONIA", "SONIA JULIA", "YOLANDA AURORA", "AURORA NURIA", "CARLA MIRIAM", "MIRIAM ESTHER", "ESTHER JULIA", "JULIA IRENE", "IRENE OLGA", "OLGA MARIANA", "MARIANA SILVANA", "SILVANA VALERIA", "VALERIA JUANA", "JUANA DIANA", "DIANA VALENTINA", "VERONICA GISELA", "GISELA REGINA", "REGINA PALOMA", "PALOMA GABRIELA", "GABRIELA CAMILA", "CAMILA CELESTE", "CELESTE RENATA", "RENATA VIVIANA", "VIVIANA ANTONELLA"};
    strcpy(cadena, nombresM[rand() % 100]);
}

void genAp(char cadena[])
{
    char apellidos[][30] = {"LOPEZ", "GARCIA", "MARTINEZ", "RODRIGUEZ", "PEREZ", "FERNANDEZ", "GONZALEZ", "SANCHEZ", "ROMERO", "TORRES", "RAMIREZ", "DIAZ", "RUIZ", "HERRERA", "CASTRO", "RIOS", "VARGAS", "JIMENEZ", "ORTEGA", "SILVA", "RIVERA", "ESPINOZA", "MORALES", "NUNEZ", "REYES", "PERALTA", "ROSALES", "MONTES", "CORDERO", "AGUILAR", "CARDENAS", "VALDEZ", "CASTILLO", "MENDOZA", "ESPINOSA", "FUENTES", "GUZMAN", "CERVANTES", "SOTO", "DELGADO", "NAVARRO", "MORA", "QUINONES", "SOSA", "CARRILLO", "PACHECO", "MIRANDA", "FIGUEROA", "MENDEZ", "LEON", "CALDERON", "NAVA", "TELLEZ", "PAREDES", "BAUTISTA", "CISNEROS", "VILLANUEVA", "CONTRERAS", "PADILLA", "ROJAS", "RIVAS", "SALAZAR", "PANTOJA", "CABELLO", "CHACON", "LUGO", "BAEZ", "GUTIERREZ", "PENA", "ZAVALA", "PONCE", "ESCOBAR", "LARA", "TOVAR", "DUARTE", "PAREDES", "MELENDEZ", "ALVARADO", "SERNA", "OCHOA", "FRIAS", "RUEDA", "ECHEVERRIA", "DURAN", "CORDOVA", "VELA", "REYES", "OSORIO", "LOPEZ DE LA FUENTE", "DAVILA", "DE LA CRUZ", "HIDALGO", "MIRANDA", "DE LA ROSA", "DE LEON", "MEDINA", "GARCIA DE LA TORRE", "PEREZ DE LA VEGA", "RODRIGUEZ DE LA FUENTE", "MARTINEZ DE LOS RIOS", "RAMIREZ DE SOTO", "SANCHEZ DE LA CRUZ", "RUIZ DE LA TORRE", "TORRES DE LEON", "VARGAS DE LA O", "SOTO DE LA ROSA", "HERRERA DE LOS SANTOS", "RIOS DE LA FUENTE", "MENDOZA DE LA CRUZ", "ORTEGA DE LA TORRE", "REYES DE LA VEGA", "CERVANTES DE LA O", "MORA DE LA ROSA", "SILVA DE LOS SANTOS", "ESPINOSA DE LA FUENTE", "FUENTES DE LA CRUZ", "GUZMAN DE LA VEGA", "CARDENAS DE LA O", "MONTES DE LOS SANTOS", "NAVARRO DE LA FUENTE", "NUNEZ DE LA CRUZ", "CASTILLO DE LA VEGA", "PEREZ DE LA TORRE", "RIVAS DE LA ROSA", "CISNEROS DE LA O", "SOSA DE LA CRUZ", "ROJAS DE LA VEGA", "VILLANUEVA DE LA FUENTE", "PANTOJA DE LA TORRE", "CHACON DE LOS SANTOS", "MIRANDA DE LA O", "PACHECO DE LA CRUZ", "BAEZ DE LA VEGA", "TOVAR DE LA FUENTE", "CALDERON DE LA CRUZ", "LARA DE LOS SANTOS", "PONCE DE LA O", "PENA DE LA ROSA", "DELGADO DE LA VEGA", "CORDERO DE LA CRUZ", "BAUTISTA DE LOS SANTOS", "NAVA DE LA FUENTE", "QUINONES DE LA O", "FIGUEROA DE LA CRUZ", "REYES DE LA TORRE", "VELA DE LA VEGA", "CORDOVA DE LOS SANTOS", "RUEDA DE LA FUENTE", "SERNA DE LA O", "CARRILLO DE LA CRUZ", "LUGO DE LA VEGA", "ZAVALA DE LOS SANTOS", "PANTOJA DE LA FUENTE", "SOSA DE LA VEGA", "ESPINOSA DE LA CRUZ", "FUENTES DE LOS SANTOS", "GUZMAN DE LA FUENTE", "CARDENAS DE LA CRUZ", "MONTES DE LA VEGA", "NAVARRO DE LOS SANTOS", "NUNEZ DE LA CRUZ", "PEREZ DE LA VEGA", "RIVAS DE LA CRUZ", "MARTINEZ DE LA FUENTE", "RODRIGUEZ DE LOS SANTOS", "GONZALEZ DE LA O", "FERNANDEZ DE LA CRUZ", "MENDEZ DE LA VEGA", "LEON DE LOS SANTOS", "TOVAR DE LA CRUZ", "PONCE DE LA FUENTE", "SANCHEZ DE LA VEGA", "DIAZ DE LA CRUZ", "PAREDES DE LA O", "CISNEROS DE LA CRUZ", "TORRES DE LA VEGA", "RIOS DE LA FUENTE"};
    strcpy(cadena, apellidos[rand() % 177]);
}
