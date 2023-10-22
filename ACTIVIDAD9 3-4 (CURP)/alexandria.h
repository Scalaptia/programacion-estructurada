/********* LIBRERIAS *********/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

/********* STRUCTS *********/
typedef long Tkey;

typedef struct _progra
{
    Tkey key;
} Tprogra;

/********* PROTOTIPOS *********/
int valiNum(int ri, int rf);
int valiEspacios(char cadena[]);
int valiAlfa(char cadena[]);
int valiCad(char cadena[]);

int numAleatorio(int ri, int rf);

int busqSeq(Tprogra vect[], int n, Tkey num);
int busqSeqOrd(Tprogra vect[], int n, Tkey num);
int busqBin(Tprogra vect[], int n, Tkey num);
int busqOpt(Tprogra vect[], int n, Tkey num, bool band);
int busqSeqMat(int mat[][4], int m, int n, int num);

void imprVect(int vect[], int n);
void imprMat(int mat[][4], int m, int n);

bool ordVect(int vect[], int n);

void mayus(char cadena[]);
int largoCadena(char cadena[]);

bool valiMes(int mes, int anio);
bool esAnioBisiesto(int anio);
bool esFechaValida(int dia, int mes, int anio);
void valiChars(char cadena[]);
bool valiCadena(char cadena[]);

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
        if (cadena[i] != ' ')
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
bool ordVect(int vect[], int n)
{
    int i, j;
    int temp;

    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (vect[j] <= vect[i])
            {
                temp = vect[i];
                vect[i] = vect[j];
                vect[j] = temp;
            }
        }
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
            return false;
        }
    }
    else
    {
        if (mes == 2)
        {
            if (dia > 29)
            {
                return false;
            }

            if (dia == 29 && !esAnioBisiesto(anio))
            {
                return false;
            }
        }

        return true;
    }
}

/* CURP */
void valiChars(char cadena[])
{
    int i = 0;
    unsigned char caracter;

    while (cadena[i] != '\0')
    {
        caracter = (unsigned char)cadena[i];
        if (caracter >= 'a' && caracter <= 'z')
        {
            cadena[i] -= 32;
        }
        else
        {
            switch (caracter)
            {
            case 160: // á
            case 181: // Á
            case 132: // ä
            case 142: // Ä
                cadena[i] = 'A';
                break;

            case 130: // é
            case 144: // É
            case 137: // ë
            case 211: // Ë
                cadena[i] = 'E';
                break;

            case 161: // í
            case 214: // Í
            case 139: // ï
            case 216: // Ï
                cadena[i] = 'I';
                break;

            case 162: // ó
            case 224: // Ó
            case 148: // ö
            case 153: // Ö
                cadena[i] = 'O';
                break;

            case 163: // ú
            case 233: // Ú
            case 129: // ü
            case 154: // Ü
                cadena[i] = 'U';
                break;

            case 164: // ñ
            case 165: // Ñ
            case 44:  // ,
            case 45:  // -
            case 46:  // .
            case 47:  // /
            case 39:  // '
            case 239: // ´
                cadena[i] = 'X';
                break;
            }
        }
        i++;
    }
}

bool valiCadena(char cadena[])
{
    valiChars(cadena);

    if (valiAlfa(cadena) == 0)
    {
        return false;
    }

    if (valiEspacios(cadena) == 0)
    {
        return false;
    }

    return true;
}