#define MAX 1000
#include <stdio.h>
#define DEBUG
void ukazkaProhod(); //deklarace (m��e se d�t i do hlavi�kov�ho souboru)
void ukazkaMakra()
{
	int a = 10;
	a = a + MAX;
}
void ukazkaDebug()
{
	int a = 10;
	int b = 30;
	int c = 0;
	//logov�n�
	printf("a=%d \n", a);
	printf("b=%d \n", b);
	//lep�� logov�n� pomoc� preprocesoru
	//if x ifdef vezme to cel� a vyma�e to cel�, if zbyde 
	#ifdef DEBUG
		printf("a=%d \n", a);
		printf("b=%d \n", b);
	#endif
	c = a + b;
}
void ukazkaProhodProhod(int a, int b)
{
	/*
	//ZM�N� POUZE LOK�LN�
	int c = b;
	b = a;
	a = c;*/
	
}
int main()
{
	ukazkaProhod();
	//Toto ukazuje nesmysl
	int a = 1;
	int* p_a;
	p_a = &a; // hodnota  p_a je adresa ukazuj�c� na adresu prom�nn� a
	*p_a = 30;
	//
	return 0;
}
void ukazkaProhod()//definice
{
	int a = 10;
	int b = 30;
	printf("a = %d, b = %d", a, b);
	ukazkaProhodProhod(a, b);
	printf("a = %d, b = %d", a, b);// �lo by nahradit funkc� m�m to 2x
}
