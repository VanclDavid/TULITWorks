#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h";
#include "Math.h";
int main()
{
	int numB;
	int numA;
	int operation;
	int counter_plus=0;
	int counter_minus=0;
	char debug;
	char exit;
	printf("Menu:\n");
	printf("Enter = Pokracovat...\n");
	printf("d = Pokracovat s logem\n");
	printf("x = Konec\n");
	scanf("%c", &debug);
	exit = debug;
	while (exit!='x')
	{
		printf("Cislo A?\n");
		scanf("%d", &numA);
		printf("Cislo B?\n");
		scanf("%d", &numB);
		printf("Operace?\n");
		printf("1 = plus\n");
		printf("2 = minus\n");
		scanf("%d", &operation);
		if (operation == 1)
		{
			printf("Soucet je:\n");
			printf("%d\n", plus(&numA, &numB));
			counter_up(&counter_plus);
		}
		else if (operation == 2)
		{
			printf("Rozdil je:\n");
			printf("%d\n",minus(&numA, &numB));
			counter_up(&counter_minus);
		}
		else
		{
			printf("Vadny vstup\n");
		}
		printf("Menu:\n");
		printf("Enter = Pokracovat...\n");
		printf("x = Konec\n");
		scanf("%c", &exit);
		scanf("%c", &exit);
	}
	if(debug=='d')
	{
		printf("Statistika:\n");
		printf("+ = %d\n", counter_plus);
		printf("- = %d\n", counter_minus);
		FILE* fa = fopen("log.txt", "a");
		char actualChar;
		int posision = 0;
		fprintf(fa, "Celkem bylo %d souctu a %d rozdilu\n", counter_plus, counter_minus);
		fclose(fa);
	}
	// smyèka
	//jednoduché logování do textového souboru
	return 0;
}

// budeme ukládat tam kde ukazuje pointer ->  *a1=10
//1. pøípad int * p; <- deklarace pointu (hodnota bude adresa)
//*p = 0; tam kam ukazuje p tak tam vlo 0
//& vrátí adresu kde je zapaná hodnota
//p=10 vloí adresu 10
//int *p; *p=0; ukazuje do nìkam a my nevíme kam -> p=&a;