#define _CRT_SECURE_NO_WARNINGS

#include "stdio.h";

#include "Cviceni3.h";

#include <malloc.h>

//mùžu si ukládat velikost pole na první poici v poli

int main()
{
	//hlavní smyèka programu
	int end = 0;
	while (end == 0)
	{
		int input;
		printf("Mlavni menu\n");
		printf("-----------\n");
		printf("1 = Spustit\n");
		printf("2 = Testy\n");
		printf("0 = Konec\n");
		printf("Zadejte volbu...\n");
		scanf("%d", &input); 
		switch (input)
		{
		case 0:
			end = 1;
			break;

		case 2:
			(testeArraySwitch() == 0) ? (printf("Test prosel\n")) : (printf("Test neprosel\n"));
			break;
		case 1:
			//získat rozmìr pole
			int sizeOfArray;
			printf("Zadejte velikost pole...\n");
			scanf("%d", &sizeOfArray);
			//vytvoøit pole (alokovat)
			float* p_array = createArray(sizeOfArray);
			//naplnit pole
			insertValueArray(p_array, sizeOfArray);
			printf("Stav pred otocenim\n");
			printArray(p_array, sizeOfArray);
			printf("\n");
			//prohodit pole
			switchArrayValues(p_array, sizeOfArray);
			printf("Stav po otoceni\n");
			printArray(p_array, sizeOfArray);
			printf("\n");
			//uvolneni pameti
			clearArray(p_array);
			break;
		}
	}
	return 0;
}