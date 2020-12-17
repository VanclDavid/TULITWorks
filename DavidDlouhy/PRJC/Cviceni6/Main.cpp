/*
Napište program, realizující jednoduchý databázový systém.

uložte data o lidech (id [int], jméno [char[]], vek [int])
autech (id[int], spz[char[]] )
umožnìte uložení vazby èlovìk - auto, kde jeden èlovìk mùže mít více aut
umožnìte vyhledání osoby podle id a následný výpis jak jména a vìku osoby tak i dat všech aut, která vlastní
*/

#define _CRT_SECURE_NO_WARNINGS

#include "StringWorker.h"
#include "Strucures.h"
#include <corecrt_malloc.h>
#include <stdio.h>
#include <string.h>

int main()
{
	Car car1;
	car1.id = 10;
	char str[] = "6H8-8058";
	int strLn = sizeof(str);
	int* p_strLn = &strLn;
	car1.spz = (char*)malloc(sizeof(char) * (sizeof(str)));
	car1.spz= strtok(str, "");
	/*printf("\nAuto 1:\n");
	printf("  ID: %d\n", car1.id);
	printf(" SPZ: ");
	printString(car1.spz, p_strLn);
	
	printf(" \n");*/

	Human human1;
	human1.id = 1;
	char name[] = "Jan Novak";
	int nameln = sizeof(name);
	human1.jmeno = (char*)malloc(sizeof(char) * (sizeof(name)));
	human1.jmeno=strtok(name, "");
	human1.vek = 30;
	human1.auta = (Car*)malloc(sizeof(Car) * 1);
	human1.auta[0] = car1;
	printf("\nClovek 1:\n");
	printf("   ID: %d\n", human1.id);
	printf("   Jmeno: ");
	printString(human1.jmeno, &nameln);
	printf("\n   Vek: %d\n", human1.vek);
	printf("   Auto 1:\n");
	printf("      ID: %d\n", human1.auta[0].id);
	printf("      SPZ: ");
	printString(human1.auta[0].spz, p_strLn);
	printf(" \n");

	return 0;

}