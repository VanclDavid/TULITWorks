#define _CRT_SECURE_NO_WARNINGS  
#include <stdio.h>
#include "Plus.h"
#include "Minus.h"
#include "Counter.h"
#include "Log.h"
//*a1=0 vlož 0 kam ukazuje a1
//&a1 vem adresu a1
//int *p deklaruje pointer
int main() {
	char c=' ';
	int counter_sum = 0;
	int counter_minus = 0;
	while (c !='*') {
		printf("zadej prvni cislo\n");
		int a;
		scanf("%d", &a);
		printf("zadej druhe cislo\n");
		char data[] = "ahojky";
		log(data, "zaznamy.txt");
		int b;
		scanf("%d", &b);
		int op = 0;
		while (op <= 0 || op >2)
		{
			printf("zadej operaci [1 / 2]\n");
			scanf("%d", &op);
			switch (op)
			{
			case 1:
				printf("vysledek scitani je %d\n",plus(a,b));
				break;
			case 2:
				printf("vysledek odcitani je %d\n",minus(a, b));
				break;
			default:
				printf("nevalidni operace\n");
				break;
			}
		}
		counter(&counter_sum, &counter_minus, op);
		printf("pro ukonceni zadejte \"*\"\n");
		scanf(" %c", &c);
	}
	printf("pocet operaci + : %d\n",counter_sum);
	printf("pocet operaci - : %d\n", counter_minus);
	return 0;
}