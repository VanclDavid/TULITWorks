//Napi�te program, realizuj�c� jednoduch� datab�zov� syst�m.															XX
//ulo�te data o lidech(id[int], jm�no[char[]], vek[int])																OK
//autech(id[int], spz[char[]])																							OK
//umo�n�te ulo�en� vazby �lov�k - auto, kde jeden �lov�k m��e m�t v�ce aut												XX
//umo�n�te vyhled�n� osoby podle id a n�sledn� v�pis jak jm�na a v�ku osoby tak i dat v�ech aut, kter� vlastn�			XX
#define _CRT_SECURE_NO_WARNINGS
#include <malloc.h>
#include "stdio.h"

void test();

typedef struct {
	int id;
	char* name;
	int old;
}HUMAN;

typedef struct {
	int id;
	char* spz;
}CAR;

int main()
{
	printf("Zadejte ID...");
	
	int selected_id;
	int *p_selected_id= &selected_id;
	scanf("%d", *p_selected_id);
	printf("%d",&selected_id);
	test();
	return 0;
}

void test()
{
	HUMAN human_1;
	human_1.id = 1;
	int length = 3;
	char* p_text = (char*)malloc(length * sizeof(char));
	p_text[0] = 'J';
	p_text[1] = 'a';
	p_text[2] = 'n';
	human_1.old = 18;
	printf("%c%c%c",p_text[0], p_text[1], p_text[2]);

	CAR car_1;

}