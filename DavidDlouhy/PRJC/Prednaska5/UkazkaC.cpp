#include <stdio.h>
#include <stdlib.h>

typedef struct {
	char street[10];
	char psc[10];
}ADRESA;
typedef struct {
	int vaha;
	char znak;
	ADRESA adresa;
}LIDE2;

typedef struct polozal {
	int hodnota;
	polozal* dalsi;
}SEZNAM;

typedef struct {
	int vaha;
	char znak;
}LIDE;

typedef struct {
	int pole[10];
}POLE;

typedef struct {
	int* pole;
	int velikost;
}POLE2;

void ukazaka1()
{
	LIDE c1;
	c1.vaha = 10;
	c1.znak = 'A';
}

void ukazaka2()
{

	int* p_a1 = (int*)malloc(10 * sizeof(int));
	int* p_a2 = (int*)malloc(10 * sizeof(int));
	p_a2 = p_a1;

	p_a2[1] = 20;
	p_a1[1] = 10;
}

void ukazaka3()
{
	POLE2 p2;
	p2.velikost = 10;
	p2.pole = (int*)malloc(p2.velikost * sizeof(int));

	LIDE* p_clovek;
	p_clovek = (LIDE*)malloc(1 * sizeof(LIDE));
	p_clovek->vaha = 10;
}
