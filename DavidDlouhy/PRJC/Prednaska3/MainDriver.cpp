#include <stdio.h>
#include <stdlib.h>

void pr()
{
	float* p_prf;
	float prf = 3.14; //ukazuje staticky
	//p_f=&f; // ukazuje dynamicky
	//na jiných architektùrách jsu rùzné délky adres 32 a 64
	//p_f = 10.1; špatnì, musíme dát adresu!
	//*p_f = 10.1; špatnì, pointr ukazuje nìkam kam nevíme kde to je
	//&p_f = 10.1; špatnì, dej mi adresu a ulož do adresy hodnotu
	printf("%p", &p_prf);// 
}

void pointAritmetika()
{
	//pøetypování adresního prostoru
	//pøetypovat se dá delší  na kratší
	char* p_c;
	int* p_i;
	//p_c = p_i; pozor
	p_c = (char*)p_i;
}

void korektniPrace()
{
	float* p_f;
	float f = 3.14;
	p_f = &f;
	printf("%e", *p_f);
}

void add(int *counter)
{
	(*counter)++;
}

void ukazkaPredavani()
{
	//uloží se jen na jendo místo a nezabere tolik místa
	int a = 0;
	//pøedává se adresa
	add(&a);
}

void fillAsci(char *ascii)
{
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		ascii[i]='a';
	}
}
void pole()
{
	int size = 10;
	int stat_pole[10]; //statické
	//dynamické
	char* ascii;
	ascii=(char *)malloc(sizeof(char)*size);//potøebuje poèet bajtù, který chci alokovat, vrací pointr na void
	//malloc neví jak je velké pole, musím si nìkam celou dobu ukládat velikost pole
	ascii[1] = 'a';
	//uvolní z pamìti
	free((char*)ascii); //dealokuje
	ascii = NULL; //a zruší reference
	//mùžu si ukládat velikost pole na první poici v poli
}
int main()
{	
	return 1;
}
