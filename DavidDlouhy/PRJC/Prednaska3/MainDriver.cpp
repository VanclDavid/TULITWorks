#include <stdio.h>
#include <stdlib.h>

void pr()
{
	float* p_prf;
	float prf = 3.14; //ukazuje staticky
	//p_f=&f; // ukazuje dynamicky
	//na jin�ch architekt�r�ch jsu r�zn� d�lky adres 32 a 64
	//p_f = 10.1; �patn�, mus�me d�t adresu!
	//*p_f = 10.1; �patn�, pointr ukazuje n�kam kam nev�me kde to je
	//&p_f = 10.1; �patn�, dej mi adresu a ulo� do adresy hodnotu
	printf("%p", &p_prf);// 
}

void pointAritmetika()
{
	//p�etypov�n� adresn�ho prostoru
	//p�etypovat se d� del��  na krat��
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
	//ulo�� se jen na jendo m�sto a nezabere tolik m�sta
	int a = 0;
	//p�ed�v� se adresa
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
	int stat_pole[10]; //statick�
	//dynamick�
	char* ascii;
	ascii=(char *)malloc(sizeof(char)*size);//pot�ebuje po�et bajt�, kter� chci alokovat, vrac� pointr na void
	//malloc nev� jak je velk� pole, mus�m si n�kam celou dobu ukl�dat velikost pole
	ascii[1] = 'a';
	//uvoln� z pam�ti
	free((char*)ascii); //dealokuje
	ascii = NULL; //a zru�� reference
	//m��u si ukl�dat velikost pole na prvn� poici v poli
}
int main()
{	
	return 1;
}
