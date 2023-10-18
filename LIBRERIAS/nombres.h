#include <stdio.h>
#include <string.h>

/********* DATOS ALEATORIOS *********/

void genNomH(char cadena[]);
void genNomM(char cadena[]);
void genAp(char cadena[]);

void genNomH(char cadena[])
{
    char nombresH[20][30] = {"JUAN", "PEDRO", "LUIS", "CARLOS", "MIGUEL", "JOSE", "ANTONIO", "FRANCISCO", "MANUEL", "JAVIER", "ALEJANDRO", "DAVID", "FERNANDO", "ROBERTO", "RAFAEL", "JOSE LUIS", "DANIEL", "ALBERTO", "MARIO", "ANDRES"};
    strcpy(cadena, nombresH[rand() % 20]);
}

void genNomM(char cadena[])
{
    char nombresM[20][30] = {"MARIA", "ANA", "LAURA", "LUISA", "SOFIA", "ISABEL", "CARMEN", "ROSA", "ELENA", "LUCIA", "PATRICIA", "LOURDES", "MARTA", "RAQUEL", "JULIA", "CLARA", "MONICA", "DIANA", "VALENTINA", "CAROLINA"};
    strcpy(cadena, nombresM[rand() % 20]);
}

void genAp(char cadena[])
{
    char apellidos[40][30] = {"GONZALEZ", "RODRIGUEZ", "PEREZ", "FERNANDEZ", "LOPEZ", "MARTINEZ", "GOMEZ", "SANCHEZ", "DIAZ", "TORRES", "VARGAS", "RUIZ", "RAMIREZ", "HERNANDEZ", "FLORES", "JIMENEZ", "MORENO", "ALVAREZ", "CASTRO", "ORTEGA", "SILVA", "NUNEZ", "MENDOZA", "ROJAS", "VEGA", "CRUZ", "MORALES", "GUERRERO", "ROMERO", "VALDEZ", "GUTIERREZ", "REYES", "SOTO", "CHAVEZ", "NAVARRO", "ZAPATA", "ACOSTA", "FUENTES", "LARA", "YEPIZ"};
    strcpy(cadena, nombresH[rand() % 40]);
}