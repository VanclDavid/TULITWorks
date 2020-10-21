#define _CRT_SECURE_NO_WARNINGS  
#include <stdio.h>
#include "Plus.h"
#include "Minus.h"
#include "Counter.h"
#include "Log.h"
#define DEBUG
int main() {
	char c=' ';
	int counter_sum = 0;
	int counter_minus = 0;
	#if defined (DEBUG)
	char data[BUFSIZ];
	printf("logging is ON\r\n");
	#endif
	while (c !='*') {
		printf("zadej prvni cislo\n");
		int a;
		scanf("%d", &a);
		#if defined (DEBUG)
		sprintf(data, "user input a: %d\n\r", a);
		log(data, "zaznamy.txt");
		#endif
		printf("zadej druhe cislo\n");
		int b;
		scanf("%d", &b);
		#if defined (DEBUG)
				sprintf(data, "user input b: %d\n\r", b);
				log(data, "zaznamy.txt");
		#endif
		int op = 0;
		while (op <= 0 || op >2)
		{
			printf("zadej operaci [1 / 2]\n");
			scanf("%d", &op);
			#if defined (DEBUG)
						sprintf(data, "user operation: %d\n\r", op);
						log(data, "zaznamy.txt");
			#endif
			int output;
			switch (op)
			{
			case 1:
				output = plus(a, b);
				printf("vysledek scitani je %d\n",output);
				#if defined (DEBUG)
								sprintf(data, "output %d\n\r", output);
								log(data, "zaznamy.txt");
				#endif
				break;
			case 2:
				output = minus(a, b);
				printf("vysledek odcitani je %d\n",output);
				#if defined (DEBUG)
								sprintf(data, "output %d\n\r", output);
								log(data, "zaznamy.txt");
				#endif
				break;
			default:
				printf("nevalidni operace\n");
				#if defined (DEBUG)
								sprintf(data, "invalid operation\n\r");
								log(data, "zaznamy.txt");
				#endif
				break;
			}
		}
		counter(&counter_sum, &counter_minus, op);
		printf("pro ukonceni zadejte \"*\"\n");
		scanf(" %c", &c);
	}
	printf("pocet operaci + : %d\n",counter_sum);
	printf("pocet operaci - : %d\n", counter_minus);
		#if defined (DEBUG)
			sprintf(data, "n of plus %d\n\r", counter_sum);
			log(data, "zaznamy.txt");
			sprintf(data, "n of minus %d\n\r", counter_minus);
			log(data, "zaznamy.txt");
		#endif
	return 0;
}