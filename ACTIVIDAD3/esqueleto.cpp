// Fernando Haro Calvo  MATR. 372106
// 05-SEP-2023

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//*** PROTOTIPOS DE FUNCIONES  ******
int msges();
void menu();
void calif(void);
void ppt1(void);
void ppt2(void);
void mayor(void);
void medio(void);
void ascendente(void);
void signo(void);

//****  main principal  *********
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
	printf("1.- CALIFICACIONES \n");
	printf("2.- PIEDRA PAPEL TIJERA 1 \n");
	printf("3.- PIEDRA PAPEL TIJERA 2 \n");
	printf("4.- NUMERO MAYOR \n");
	printf("5.- NUMERO MEDIO \n");
	printf("6.- NUMEROS ASCENDENTES \n");
	printf("7.- SIGNO ZODIACAL \n");
	printf("0.- SALIR  \n");
	printf("ESCOGE UNA OPCION: ");
	scanf("%d", &op);
	return op;
}
//****************
void menu()
{
	int op;
	do
	{
		op = msges();
		switch (op)
		{
		case 1:
			calif();
			break;
		case 2:
			ppt1();
			break;
		case 3:
			ppt2();
			break;
		case 4:
			mayor();
			break;
		case 5:
			medio();
			break;
		case 6:
			ascendente();
			break;
		case 7:
			signo();
			break;
		}

	} while (op != 0);
}

//*********************
// Lee 3 calificaciones y calcula su promedio y el resultado.
// HCF_ACT3_01_932
void calif(void)
{
	//  VARIALES LOCALES
	int cal1, cal2, cal3;
	float prom;
	system("CLS");

	//	TITULO
	printf("   CALIFICACIONES\n");

	//	PROGRAMA
	printf("Ingrese la 1ra calificacion: ");
	scanf("%d", &cal1);
	printf("Ingrese la 2da calificacion: ");
	scanf("%d", &cal2);
	printf("Ingrese la 3ra calificacion: ");
	scanf("%d", &cal3);
	prom = (cal1 + cal2 + cal3) / 3.0;

	if (prom < 80)
	{
		if (prom < 60)
		{
			if (prom < 30)
			{
				printf("Repetir");
			}
			else
			{
				printf("Extraordinario");
			}
		}
		else
		{
			printf("Suficiente");
		}
	}
	else
	{
		if (prom < 98)
		{
			if (prom < 90)
			{
				printf("Bien");
			}
			else
			{
				printf("Muy Bien");
			}
		}
		else
		{
			printf("Excelente");
		}
	}
	printf("\n");
	system("PAUSE");
}

//*************************
// Piedra papel y Tijeras con condiciones anidadas.
// HCF_ACT3_02_932
void ppt1(void)
{
	//  VARIALES LOCALES
	int jugador, computadora;
	system("CLS");

	//  TITULO
	printf("   PIEDRA PAPEL TIJERA 1\n");

	//	PROGRAMA
	srand(time(NULL)); // Generar semilla aleatoria
	computadora = rand() % 3 + 1;

	printf("Ingresa tu jugada (1: Piedra, 2: Papel, 3: Tijera): ");
	scanf("%d", &jugador);

	if (!(jugador >= 1 && jugador <= 3))
	{
		printf("Jugada ingresada no valida\n");
		system("PAUSE");
		return;
	}

	if (jugador == 1)
	{
		if (computadora == 1)
		{
			printf("Empate (J: Piedra, C: Piedra)");
		}
		else
		{
			if (computadora == 2)
			{
				printf("Gana computadora (J: Piedra, C: Papel)");
			}
			else
			{
				printf("Gana jugador (J: Piedra, C: Tijeras)");
			}
		}
	}
	else
	{
		if (jugador == 2)
		{
			if (computadora == 1)
			{
				printf("Gana jugador (J: Papel, C: Piedra)");
			}
			else
			{
				if (computadora == 2)
				{
					printf("Empate (J: Papel, C: Papel)");
				}
				else
				{
					printf("Gana computadora (J: Papel, C: Tijeras)");
				}
			}
		}
		else
		{
			if (computadora == 1)
			{
				printf("Gana computadora (J: Tijeras, C: Piedra)");
			}
			else
			{
				if (computadora == 2)
				{
					printf("Gana jugador (J: Tijeras, C: Papel)");
				}
				else
				{
					printf("Empate (J: Tijeras, C: Tijeras)");
				}
			}
		}
	}

	printf("\n");
	system("PAUSE");
}
//****************************
// Piedra papel y Tijeras con condiciones múltiples.
// HCF_ACT3_03_932
void ppt2(void)
{
	//  VARIALES LOCALES
	int jugador, computadora;
	system("CLS");

	//  TITULO
	printf("   PIEDRA PAPEL TIJERA 2\n");

	// PROGRAMA
	srand(time(NULL)); // Generar semilla aleatoria
	computadora = rand() % 3 + 1;

	printf("Ingresa tu jugada (1: Piedra, 2: Papel, 3: Tijera): ");
	scanf("%d", &jugador);

	if (!(jugador >= 1 && jugador <= 3))
	{
		printf("Jugada ingresada no valida\n");
		system("PAUSE");
		return;
	}

	switch (jugador)
	{
	case 1:
		switch (computadora)
		{
		case 1:
			printf("Empate (J: Piedra, C: Piedra)");
			break;

		case 2:
			printf("Gana computadora (J: Piedra, C: Papel)");
			break;

		case 3:
			printf("Gana jugador (J: Piedra, C: Tijeras)");
			break;
		}
		break;

	case 2:
		switch (computadora)
		{
		case 1:
			printf("Gana jugador (J: Papel, C: Piedra)");
			break;

		case 2:
			printf("Empate (J: Papel, C: Papel)");
			break;

		case 3:
			printf("Gana computadora (J: Papel, C: Tijeras)");
			break;
		}
		break;

	case 3:
		switch (computadora)
		{
		case 1:
			printf("Gana computadora (J: Tijeras, C: Piedra)");
			break;

		case 2:
			printf("Gana jugador (J: Tijeras, C: Papel)");
			break;

		case 3:
			printf("Empate (J: Tijeras, C: Tijeras)");
			break;
		}
		break;
	}

	printf("\n");
	system("PAUSE");
}
//****************************
// Lee 3 numeros y determina el valor mayor.
// HCF_ACT3_04_932
void mayor(void)
{
	//  VARIALES LOCALES
	int num1, num2, num3;
	system("CLS");

	//	TITULO
	printf("   NUMERO MAYOR\n");

	//  PROGRAMA
	printf("Ingrese el primer numero: ");
	scanf("%d", &num1);
	printf("Ingrese el segundo numero: ");
	scanf("%d", &num2);
	printf("Ingrese el tercer numero: ");
	scanf("%d", &num3);

	if (num1 > num2 && num1 > num3)
	{
		printf("El primer numero: %d es el mayor", num1);
	}

	if (num2 > num1 && num2 > num3)
	{
		printf("El segundo numero: %d es el mayor", num2);
	}

	if (num3 > num1 && num3 > num2)
	{
		printf("El tercer numero: %d es el mayor", num3);
	}

	printf("\n");
	system("PAUSE");
}
//****************************
// Lee 3 numeros y determina el valor medio.
// HCF_ACT3_05_932
void medio(void)
{
	//  VARIALES LOCALES
	int num1, num2, num3;
	system("CLS");

	//	TITULO
	printf("   NUMERO MEDIO\n");

	//  PROGRAMA
	printf("Ingrese el primer numero: ");
	scanf("%d", &num1);
	printf("Ingrese el segundo numero: ");
	scanf("%d", &num2);
	printf("Ingrese el tercer numero: ");
	scanf("%d", &num3);

	if ((num1 > num2 && num1 < num3) || (num1 < num2 && num1 > num3))
	{
		printf("El primer numero: %d es el medio", num1);
	}

	if ((num2 > num1 && num2 < num3) || (num2 < num1 && num2 > num3))
	{
		printf("El segundo numero: %d es el medio", num2);
	}

	if ((num3 > num1 && num3 < num2) || (num3 < num1 && num3 > num2))
	{
		printf("El tercer numero: %d es el medio", num3);
	}

	printf("\n");
	system("PAUSE");
}
//****************************
// Lee 3 numeros y los muestra en orden ascendente.
// HCF_ACT3_06_932
void ascendente(void)
{
	//  VARIALES LOCALES
	int num1, num2, num3;
	system("CLS");

	//	TITULO
	printf("   NUMEROS ASCENDENTES\n");

	//  PROGRAMA
	printf("Ingrese el primer numero: ");
	scanf("%d", &num1);
	printf("Ingrese el segundo numero: ");
	scanf("%d", &num2);
	printf("Ingrese el tercer numero: ");
	scanf("%d", &num3);

	if (num1 < num2 && num2 < num3)
	{
		printf("%d, %d, %d", num1, num2, num3);
	}

	if (num1 < num3 && num3 < num2)
	{
		printf("%d, %d, %d", num1, num3, num2);
	}

	if (num2 < num1 && num1 < num3)
	{
		printf("%d, %d, %d", num2, num1, num3);
	}

	if (num2 < num3 && num3 < num1)
	{
		printf("%d, %d, %d", num2, num3, num1);
	}

	if (num3 < num1 && num1 < num2)
	{
		printf("%d, %d, %d", num3, num1, num2);
	}

	if (num3 < num2 && num2 < num1)
	{
		printf("%d, %d, %d", num3, num2, num1);
	}

	printf("\n");
	system("PAUSE");
}
//****************************
void signo(void)
{
	//  VARIALES LOCALES
	system("CLS");

	//  TITULO
	printf("   SIGNO ZODIACAL\n");

	//  PROGRAMA
	printf("Ingresa tu mes de nacimiento (1- Enero, 2- Febrero, ... 12- Diciembre)");

	printf("\n");
	system("PAUSE");
}