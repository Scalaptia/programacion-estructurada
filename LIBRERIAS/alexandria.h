//*** LIBRERIAS *****
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//*** PROTOTIPOS *****
int valiNum(int ri, int rf);
int numAleatorio(int ri, int rf);
void llenarVectSinRep(int vect[], int n, int ri, int rf);
int busqSeq(int vect[], int n, int num);

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
        } while (busqSeq(vect, i, num) != -1);

        vect[i] = num;
    }
}

// Busca un número en un arreglo de forma secuencial.
int busqSeq(int vect[], int n, int num)
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