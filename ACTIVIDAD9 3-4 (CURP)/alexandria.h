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
            caracter -= 32;
        }
        else
        {
            if ((unsigned char)caracter == 142 || (unsigned char)caracter == 132 || (unsigned char)caracter == 160 || (unsigned char)caracter == 181)
            {
                caracter = 'A';
            }
            else
            {
                if ((unsigned char)caracter == 211 || (unsigned char)caracter == 137 || (unsigned char)caracter == 130 || (unsigned char)caracter == 144)
                {
                    caracter = 'E';
                }
                else
                {
                    if ((unsigned char)caracter == 216 || (unsigned char)caracter == 139 || (unsigned char)caracter == 161 || (unsigned char)caracter == 214)
                    {
                        caracter = 'I';
                    }
                    else
                    {
                        if ((unsigned char)caracter == 153 || (unsigned char)caracter == 148 || (unsigned char)caracter == 162 || (unsigned char)caracter == 224)
                        {
                            caracter = 'O';
                        }
                        else
                        {
                            if ((unsigned char)caracter == 154 || (unsigned char)caracter == 129 || (unsigned char)caracter == 163 || (unsigned char)caracter == 233)
                            {
                                caracter = 'U';
                            }
                            else
                            {
                                if (caracter == -91 || caracter == -92 || (caracter >= 44 && caracter <= 47) || caracter == 39 || (unsigned char)caracter == 239) // ñ Ñ , - . / ' ´
                                {
                                    caracter = 'X';
                                }
                            }
                        }
                    }
                }
            }
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

/********* CURP *********/

// Busca la primera consonante en una cadena
char buscaCons(char cad[])
{
    int i;
    int n = largoCadena(cad);
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