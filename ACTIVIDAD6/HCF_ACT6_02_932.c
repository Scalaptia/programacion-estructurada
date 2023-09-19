// Fernando Haro Calvo  MATR. 372106
// 12-SEP-2023 - 18-SEP-2023

//*** LIBRERIAS		*******
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALUMNOS 3
#define MAXTURISTAS 10
#define MAXPESO 700

//*** PROTOTIPOS DE FUNCIONES	******
int msges(void);
int msgCiclos(void);
int validar(int ri, int rf);
void menu(void);
void prom(void);
void sumYMed(void);
void turistas(void);
void asig(void);

//*** MAIN PRINCIPAL	*********
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
	printf("2.- TABLAS \n");
	printf("3.- SUMA Y MEDIA \n");
	printf("4.- TURISTAS \n");
	printf("5.- ESTADO ASIGNATURA \n");
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
			tablas();
			break;

		case 3:
			sumYMed();
			break;

		case 4:
			turistas();
			break;

		case 5:
			asig();
			break;
		}
	} while (op != 0);
}
//*********************
// Imprimir un mensaje y validar el numero entero que ingrese el usuario este en un rango dado.
int validar(int ri, int rf)
{
	int num;
	char cadena[10];
	do
	{
		fflush(stdin);
		gets(cadena);
		num = atoi(cadena);
	} while (num < ri || num > rf);

	return num;
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
		puts("Ingrese la calificacion de la unidad 1: ");
		u1 = validar(0, 100);
		puts("Ingrese la calificacion de la unidad 2: ");
		u2 = validar(0, 100);
		puts("Ingrese la calificacion de la unidad 3: ");
		u3 = validar(0, 100);
		puts("Ingrese la calificacion de la unidad 4: ");
		u4 = validar(0, 100);
		puts("Ingrese la calificacion de la unidad 5: ");
		u5 = validar(0, 100);

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
// Imprime las tablas de multiplicar del 1 al 10.
// HCF_ACT6_02_02_932
void tablas(void)
{
	//  VARIABLES LOCALES
	int i, j;
	system("CLS");

	//	TITULO
	printf("   TABLAS\n");

	//	PROGRAMA
	for (i = 1; i <= 10; i++)
	{
		system("CLS");
		printf("TABLA DEL %d\n\n", i);
		for (j = 1; j <= 10; j++)
		{
			printf("%d * %d = %d\n", i, j, i * j);
		}
		system("PAUSE");
	}
}

//*********************
// Leer n cantidad de números dentro de un rango dado, desplegar la suma y media.
// HCF_ACT6_02_03_932
void sumYMed(void)
{
	//  VARIABLES LOCALES
	int n, ri, rf, num, suma = 0;
	system("CLS");

	//	TITULO
	printf("   SUMA Y MEDIA\n");

	// PROGRAMA
	printf("Ingrese la cantidad de numeros a ingresar: ");
	scanf("%d", &n);
	printf("Ingrese el valor minimo del rango: ");
	scanf("%d", &ri);
	printf("Ingrese el valor maximo del rango: ");
	scanf("%d", &rf);

	printf("Ingrese %d numeros:\n", n);
	for (int i = 1; i <= n; i++)
	{
		printf("Numero %d: ", i);
		num = validar(ri, rf);
		suma += num;
	}

	printf("\n");
	printf("La suma es: %d\n", suma);
	printf("La media es: %.2f\n", suma / n + 0.0);

	printf("\n");
	system("PAUSE");
}

//*********************
// Contar turistas que se subiran a un barco y calcular promedio de peso.
// HCF_ACT6_02_04_932
void turistas(void)
{
	//  VARIABLES LOCALES
	float peso, pesoTotal = 0.0;
	int i;
	system("CLS");

	//	TITULO
	printf("   TURISTAS\n");

	//	PROGRAMA
	for (i = 0; i < MAXTURISTAS; i++)
	{
		printf("Ingrese el peso del turista %d: ", i + 1);
		scanf("%f", &peso);

		if ((pesoTotal + peso) > (MAXPESO + MAXPESO * 0.15))
		{
			printf("Sobrepeso permitido excedido\n");
			break;
		}

		pesoTotal += peso;
	}

	printf("\n");
	printf("El promedio de peso de los turistas es: %.2f kg\n", pesoTotal / i);

	if (i == MAXTURISTAS)
	{
		printf("Se llego al maximo de turistas (%d)\n", MAXTURISTAS);
	}
	else
	{
		printf("Se llego al maximo de peso (%d kg)\n", MAXPESO);
		printf("Abordo %d turista(s)\n", i);
	}

	printf("\n");
	system("PAUSE");
}

//*********************
// Determina el estado de un alumno en una asignatura en base a sus calificaciones.
// HCF_ACT6_02_05_932
void asig(void)
{
	//  VARIABLES LOCALES
	int p1, p2, p3, i;
	float prom;

	//	PROGRAMA
	for (i = 0; i < 5; i++)
	{
		system("CLS");
		printf("   ESTADO ASIGNATURA\n");
		puts("Ingrese la calificacion del parcial 1: ");
		p1 = validar(0, 100);
		puts("Ingrese la calificacion del parcial 2: ");
		p2 = validar(0, 100);
		puts("Ingrese la calificacion del parcial 3: ");
		p3 = validar(0, 100);

		prom = (p1 + p2 + p3) / 3.0;

		if (prom >= 60)
		{
			printf("\nAprobado con calificacion de %.2f\n", prom);
			break;
		}

		if (i == 2)
		{
			printf("\nBaja temporal (Maximo de intentos)\n");
			break;
		}

		printf("\nPromedio: %.2f\n", prom);
		printf("Intentos: %d\n", i + 1);
		printf("No has aprobado, debes repetir la materia\n\n");
		system("PAUSE");
	}

	printf("\n");
	system("PAUSE");
}