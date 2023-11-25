#include <stdio.h>
#include <stdlib.h>
#include "alexandria.h"

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Error en los argumentos\n");
        return -1;
    }

    FILE *fa;
    char nomArchivo[30];
    int cont = 0;

    strcpy(nomArchivo, argv[1]);
    strcat(nomArchivo, ".dat");

    fa = fopen(nomArchivo, "rb");

    if (fa)
    {
        fseek(fa, 0, SEEK_END);
        long fileSize = ftell(fa);
        cont = fileSize / sizeof(TWrkr);
        fclose(fa);
    }
    else
    {
        printf("No se encontrO el archivo \"%s.dat\" \n", argv[1]);
        system("PAUSE");
    }

    return cont;
}