#define MAX 1000
#include <stdio.h>
#define DEBUG
void ukazkaProhod(); //deklarace (mùže se dát i do hlavièkového souboru)
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
	//logování
	printf("a=%d \n", a);
	printf("b=%d \n", b);
	//lepší logování pomocí preprocesoru
	//if x ifdef vezme to celé a vymaže to celé, if zbyde 
	#ifdef DEBUG
		printf("a=%d \n", a);
		printf("b=%d \n", b);
	#endif
	c = a + b;
}
void ukazkaProhodProhod(int a, int b)
{
	/*
	//ZMÌNÍ POUZE LOKÁLNÌ
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
	p_a = &a; // hodnota  p_a je adresa ukazující na adresu promìnné a
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
	printf("a = %d, b = %d", a, b);// šlo by nahradit funkcí mám to 2x
}
