// Fernando Haro Calvo  MATR. 372106
// 12-SEP-2023

#include <stdio.h>
#include <stdlib.h>

//*** PROTOTIPOS DE FUNCIONES  ******
int msges();
int msgCiclos();
void menu();
void menuFib(void);
void menuFact(void);
void menuDig(void);
void fibFor(void);
void fibWhile(void);
void fibDoWhile(void);
void factFor(void);
void factWhile(void);
void factDoWhile(void);
void digFor(void);
void digWhile(void);
void digDoWhile(void);

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
	printf("1.- FIBONACCI \n");
	printf("2.- FACTORIAL \n");
	printf("3.- CANTIDAD DE DIGITOS \n");
	printf("0.- SALIR  \n");
	printf("ESCOGE UNA OPCION: ");
	scanf("%d", &op);
	return op;
}
//*********************
int msgCiclos()
{
	int op;
	system("CLS");
	printf("   M  E   N   U \n");
	printf("1.- FOR \n");
	printf("2.- WHILE \n");
	printf("3.- DO WHILE \n");
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
			menuFib();
			break;

		case 2:
			menuFact();
			break;

		case 3:
			menuDig();
			break;
		}
	} while (op != 0);
}
//*********************
void menuFib()
{
	int op;
	do
	{
		op = msgCiclos();
		switch (op)
		{
		case 1:
			fibFor();
			break;

		case 2:
			fibWhile();
			break;

		case 3:
			fibDoWhile();
			break;
		}
	} while (op != 0);
}
//*********************
void menuFact()
{
	int op;
	do
	{
		op = msgCiclos();
		switch (op)
		{
		case 1:
			factFor();
			break;

		case 2:
			factWhile();
			break;

		case 3:
			factDoWhile();
			break;
		}
	} while (op != 0);
}
//*********************
void menuDig()
{
	int op;
	do
	{
		op = msgCiclos();
		switch (op)
		{
		case 1:
			digFor();
			break;

		case 2:
			digWhile();
			break;

		case 3:
			digDoWhile();
			break;
		}
	} while (op != 0);
}

//*********************
// Calcula n numeros de fibonacci y los imprime.
// HCF_ACT6_01_01_932
void fibFor(void)
{
	//  VARIABLES LOCALES
	int n, cont, ant, sig, res;
	system("CLS");

	//	TITULO
	printf("   FIBONACCI (FOR)\n");

	//	PROGRAMA
	printf("Ingrese la cantidad de numeros de fibonacci: ");
	scanf("%d", &n);

	if (n <= 0)
	{
		printf("El numero ingresado debe ser positivo\n");
		system("PAUSE");
		return;
	}

	for (cont = 0, ant = -1, sig = 1, res = 0; cont < n; cont++)
	{
		ant = sig;
		sig = res;

		printf("%d, ", res);
		res = ant + sig;
	}

	printf("\n");
	system("PAUSE");
}

void fibWhile(void)
{
	//  VARIABLES LOCALES
	int n, cont = 0, ant = -1, sig = 1, res = 0;
	system("CLS");

	//	TITULO
	printf("   FIBONACCI (WHILE)\n");

	//	PROGRAMA
	printf("Ingrese la cantidad de numeros de fibonacci: ");
	scanf("%d", &n);

	if (n <= 0)
	{
		printf("El numero ingresado debe ser positivo\n");
		system("PAUSE");
		return;
	}

	while (cont < n)
	{
		ant = sig;
		sig = res;

		printf("%d, ", res);
		res = ant + sig;
		cont++;
	}

	printf("\n");
	system("PAUSE");
}

void fibDoWhile(void)
{
	//  VARIABLES LOCALES
	int n, cont = 0, ant = -1, sig = 1, res = 0;
	system("CLS");

	//	TITULO
	printf("   FIBONACCI (DO WHILE)\n");

	//	PROGRAMA
	printf("Ingrese la cantidad de numeros de fibonacci: ");
	scanf("%d", &n);

	if (n <= 0)
	{
		printf("El numero ingresado debe ser positivo\n");
		system("PAUSE");
		return;
	}

	do
	{
		ant = sig;
		sig = res;

		printf("%d, ", res);
		res = ant + sig;
		cont++;
	} while (cont < n);

	printf("\n");
	system("PAUSE");
}

//*********************
// Calcula el factorial de un numero dado.
// HCF_ACT6_01_02_932
void factFor(void)
{
	//  VARIABLES LOCALES
	int n, i, res;
	system("CLS");

	//	TITULO
	printf("   FACTORIAL (FOR)\n");

	//	PROGRAMA
	printf("Ingrese un numero entero positivo: ");
	scanf("%d", &n);

	if (n <= 0)
	{
		printf("El numero ingresado debe ser positivo\n");
		system("PAUSE");
		return;
	}

	for (i = n - 1, res = n; i > 1; i--)
	{
		res *= i;
	}
	printf("\nEl factorial de %d es: %d", n, res);

	printf("\n");
	system("PAUSE");
}

void factWhile(void)
{
	//  VARIABLES LOCALES
	int n, i, res;
	system("CLS");

	//	TITULO
	printf("   FACTORIAL (WHILE)\n");

	//	PROGRAMA
	printf("Ingrese un numero entero positivo: ");
	scanf("%d", &n);

	if (n <= 0)
	{
		printf("El numero ingresado debe ser positivo\n");
		system("PAUSE");
		return;
	}

	i = n - 1;
	res = n;
	while (i > 1)
	{
		res *= i;
		i--;
	}
	printf("El factorial de %d es: %d", n, res);

	printf("\n");
	system("PAUSE");
}

void factDoWhile(void)
{
	//  VARIABLES LOCALES
	int n, i, res;
	system("CLS");

	//	TITULO
	printf("   FACTORIAL (DO WHILE)\n");

	//	PROGRAMA
	printf("Ingrese un numero entero positivo: ");
	scanf("%d", &n);

	if (n <= 0)
	{
		printf("El numero ingresado debe ser positivo\n");
		system("PAUSE");
		return;
	}

	i = n - 1;
	res = n;
	do
	{
		res *= i;
		i--;
	} while (i > 1);
	printf("El factorial de %d es: %d", n, res);

	printf("\n");
	system("PAUSE");
}

//*********************
// Calcula la cantidad de digitos de un numero.
// HCF_ACT6_01_03_932
void digFor(void)
{
	//  VARIABLES LOCALES
	int n, dig, x;
	system("CLS");

	//	TITULO
	printf("   CANTIDAD DIGITOS (FOR)\n");

	//	PROGRAMA
	printf("Ingrese un numero entero positivo: ");
	scanf("%d", &n);

	if (n <= 0)
	{
		printf("El numero ingresado debe ser positivo\n");
		system("PAUSE");
		return;
	}

	for (dig = 0, x = 1; n >= x; dig++)
	{
		x *= 10;
	}
	printf("El numero %d contiene %d digitos", n, dig);

	printf("\n");
	system("PAUSE");
}

void digWhile(void)
{
	//  VARIABLES LOCALES
	int n, dig, x;
	system("CLS");

	//	TITULO
	printf("   CANTIDAD DIGITOS (WHILE)\n");

	//	PROGRAMA
	printf("Ingrese un numero entero positivo: ");
	scanf("%d", &n);

	if (n <= 0)
	{
		printf("El numero ingresado debe ser positivo\n");
		system("PAUSE");
		return;
	}

	x = 1;
	dig = 0;
	while (n >= x)
	{
		x *= 10;
		dig++;
	}
	printf("El numero %d contiene %d digitos", n, dig);

	printf("\n");
	system("PAUSE");
}

void digDoWhile(void)
{
	//  VARIABLES LOCALES
	int n, dig, x;
	system("CLS");

	//	TITULO
	printf("   CANTIDAD DIGITOS (DO WHILE)\n");

	//	PROGRAMA
	printf("Ingrese un numero entero positivo: ");
	scanf("%d", &n);

	if (n <= 0)
	{
		printf("El numero ingresado debe ser positivo\n");
		system("PAUSE");
		return;
	}

	x = 1;
	dig = 0;
	do
	{
		x *= 10;
		dig++;
	} while (n >= x);
	printf("El numero %d contiene %d digitos", n, dig);

	printf("\n");
	system("PAUSE");
}
