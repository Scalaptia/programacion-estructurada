// Fernando Haro Calvo  MATR. 372106
// 07-SEP-2023

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 35

//*** PROTOTIPOS DE FUNCIONES  ******
int msges();
void menu();
void descendente(void);
void numParImpar(void);
void numMayMen(void);
void tablas(void);

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
	printf("1.- NUMEROS DESCENDENTES \n");
	printf("2.- NUMEROS ALEATORIOS (PARES, IMPARES) \n");
	printf("3.- NUMEROS ALEATORIOS (MAYOR, MENOR) \n");
	printf("4.- TABLA DE MULTIPLICAR \n");
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
			descendente();
			break;

		case 2:
			numParImpar();
			break;

		case 3:
			numMayMen();
			break;

		case 4:
			tablas();
			break;
		}
	} while (op != 0);
}

//*********************
// Lee un numero n y despliega todos los numeros menores que n en orden descendente.
// HCF_ACT5_01_932
void descendente(void)
{
	//  VARIALES LOCALES
	int n;
	system("CLS");

	//	TITULO
	printf("   NUMEROS DESCENDENTES\n");

	//	PROGRAMA
	printf("Ingrese un numero entero positivo: ");
	scanf("%d", &n);

	if (n <= 0)
	{
		printf("El numero ingresado debe ser positivo\n");
		system("PAUSE");
		return;
	}

	while (n > 1)
	{
		n--;
		printf("%d\n", n);
	}

	printf("\n");
	system("PAUSE");
}
//*********************
// Genera 40 números aleatorios entre 0 y 200 y muestra si son par o impar, despliega cantidad total de pares e impares.
// HCF_ACT5_02_932
void numParImpar(void)
{
	//  VARIALES LOCALES
	int num, i;
	int pares = 0, impares = 0;
	int sumPares = 0, sumImpares = 0;
	system("CLS");

	//	TITULO
	printf("   NUMEROS ALEATORIOS (PARES, IMPARES)\n");

	//	PROGRAMA
	srand(time(NULL)); // Inicializar la semilla para la generación de números aleatorios

	printf("Numeros generados aleatoriamente entre 0 y 200:\n");

	for (i = 0; i < 40; i++)
	{
		num = rand() % 201;
		printf("%d ", num);

		if (num % 2 == 0)
		{
			printf("(Par)\n");
			pares++;
			sumPares += num;
		}
		else
		{
			printf("(Impar)\n");
			impares++;
			sumImpares += num;
		}
	}

	printf("\nCantidad de pares: %d\n", pares);
	printf("Cantidad de impares: %d\n", impares);
	printf("Suma de pares: %d\n", sumPares);
	printf("Suma de impares: %d\n", sumImpares);
	printf("\n");
	system("PAUSE");
}
//*********************
// Genera N números aleatorios entre 100 y 200, muestra el mayor y el menor.
// HCF_ACT5_03_932
void numMayMen(void)
{
	//  VARIALES LOCALES
	int num, i;
	int maximo = 100, minimo = 200;
	system("CLS");

	//	TITULO
	printf("   NUMEROS ALEATORIOS (PARES, IMPARES)\n");

	//	PROGRAMA
	srand(time(NULL));

	for (i = 0; i < N; i++)
	{
		num = rand() % 101 + 100;
		printf("%d ", num);

		if (num > maximo)
		{
			maximo = num;
		}

		if (num < minimo)
		{
			minimo = num;
		}
	}

	printf("\n");
	printf("Numero mayor: %d\n", maximo);
	printf("Numero menor: %d\n", minimo);

	printf("\n");
	system("PAUSE");
}
//*********************
// Genera las tablas de multiplicar del 1 al 10 de un numero dado entre el 1 y el 20.
// HCF_ACT5_03_932
void tablas(void)
{
	//  VARIALES LOCALES
	int n, i;
	system("CLS");

	//	TITULO
	printf("   NUMEROS ALEATORIOS (PARES, IMPARES)\n");

	//	PROGRAMA
	printf("Ingresa el numero entero positivo de la tabla deseada: ");
	scanf("%d", &n);

	if (n < 1 || n > 20)
	{
		printf("El numero ingresado debe estar en el rango del 0-20\n");
		system("PAUSE");
		return;
	}

	for (i = 1; i <= 10; i++)
	{
		printf("%d * %d = %d\n", n, i, n * i);
	}

	printf("\n");
	system("PAUSE");
}