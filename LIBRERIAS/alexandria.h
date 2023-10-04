//*** LIBRERIAS *****
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//*** PROTOTIPOS *****
int valiNum(int ri, int rf);
int numAleatorio(int ri, int rf);
void llenarVectSinRep(int vect[], int n, int ri, int rf);
void llenarMatSinRep(int mat[][50], int m, int n, int ri, int rf);
int busqSeqVect(int vect[], int n, int num);
int busqSeqMat(int mat[][50], int m, int n, int num);
void imprVect(int vect[], int n);
void imprMat(int mat[][50], int m, int n);

//*** FUNCIONES *****

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

// Genera un numero aleatorio en un rango de numeros enteros.
int numAleatorio(int ri, int rf)
{
    int rango = (rf - ri + 1);

    return rand() % rango + ri;
}

// Llena el vector con valores aleatorio dentro de un rango de numeros sin repetir.
void llenarVectSinRep(int vect[], int n, int ri, int rf)
{
    int i, num, rango;
    rango = rf - ri + 1;

    for (i = 0; i < n; i++)
    {
        do
        {
            num = (rand() % rango) + ri;
        } while (busqSeqVect(vect, i, num) != -1);

        vect[i] = num;
    }
}

// Llena una matriz con numeros aleatorios sin repetir.
void llenarMatSinRep(int mat[][50], int m, int n, int ri, int rf)
{
    int i, j, cont, num, largo;

    largo = m * n;
    int vect[largo];
    llenarVectSinRep(vect, largo, ri, rf);

    for (i = 0, cont = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++, cont++)
        {
            mat[i][j] = vect[cont];
        }
    }
}

// Busca un número en un arreglo de forma secuencial.
int busqSeqVect(int vect[], int n, int num)
{
    int i;

    for (i = 0; i < n; i++)
    {
        if (vect[i] == num)
        {
            return i; // Retorna índice
        }
    }

    return -1; // No se encontró
}

// Busca un número en una matriz de forma secuencial.
int busqSeqMat(int mat[][50], int m, int n, int num)
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
void imprMat(int mat[][50], int m, int n)
{
    int i, j;

    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("[%3d]", mat[i][j]);
        }
        printf("\n");
    }
}