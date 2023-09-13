// Fernando Haro Calvo  MATR. 372106
// 12-SEP-2023

#include <stdio.h>
#include <stdlib.h>

#define ALUMNOS 40

//*** PROTOTIPOS DE FUNCIONES  ******
int msges();
int msgCiclos();
void menu();
void prom();

//****  MAIN PRINCIPAL  *********
int main()
{
	menu();

	return 0;
}

//  *** DESARROLLO DE LAS FUNCIONES  ******
//*********************
int msges()
{
	int op;
	system("CLS");
	printf("   M  E   N   U \n");
	printf("1.- PROMEDIOS \n");
	printf("2.-  \n");
	printf("3.-  \n");
	printf("0.- SALIR  \n");
	printf("ESCOGE UNA OPCION: ");
	scanf("%d", &op);
	return op;
}
//*********************
void menu()
{
	int op;
	do
	{
		op = msges();
		switch (op)
		{
		case 1:
			prom();
			break;

		case 2:
			// ();
			break;

		case 3:
			// ();
			break;
		}
	} while (op != 0);
}

//*********************
// Calcula el promedio de 40 alumnos y escribe cuantos no tienen derecho a examen.
// HCF_ACT6_02_01_932
void prom(void)
{
	//  VARIABLES LOCALES
	int i, sd, u1, u2, u3, u4, u5;
	float prom;
	system("CLS");

	//	TITULO
	printf("   PROMEDIO ALUMNOS\n");

	//	PROGRAMA
	for (i = 1, sd = 0; i <= ALUMNOS; i++)
	{
		printf("ALUMNO %d\n", i);
		printf("Ingrese la calificacion de la unidad 1: ");
		scanf("%d", &u1);
		printf("Ingrese la calificacion de la unidad 2: ");
		scanf("%d", &u2);
		printf("Ingrese la calificacion de la unidad 3: ");
		scanf("%d", &u3);
		printf("Ingrese la calificacion de la unidad 4: ");
		scanf("%d", &u4);
		printf("Ingrese la calificacion de la unidad 5: ");
		scanf("%d", &u5);

		prom = (u1 + u2 + u3 + u4 + u5) / 5.0;
		printf("\nPROM = %.2f\n", prom);

		if (prom < 50)
		{
			printf("SIN DERECHO\n");
			sd++;
		}
		system("PAUSE");
		system("CLS");
	}

	printf("Hay %d alumnos sin derecho a examen (PROM < 50)", sd);

	printf("\n");
	system("PAUSE");
}

//*********************
// Calcula el promedio de 40 alumnos y escribe cuantos no tienen derecho a examen.
// HCF_ACT6_02_02_932
void tablas(void)
{
	//  VARIABLES LOCALES
	int i;
	system("CLS");

	//	TITULO
	printf("   TABLAS\n");

	//	PROGRAMA

	printf("\n");
	system("PAUSE");
}