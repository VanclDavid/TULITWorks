// ignorování warningu
#define _CRT_SECURE_NO_WARNINGS
//obdoba java import, knihovny
#include <stdio.h>
#include <process.h>
void ukazaka1()
{
	//pøehlednì si pojmenovávat promìnné a psát k nim poznámku
	//CamelCase nebo snake_case vybrat si jeden a ten používat
	// nepoužívat 2 rùzné promìnné Promenna a promenna
	//Na zaèátek nikdy nepoužívat podtržítko (mùže být systémová promìnná)
	// /*je jen v c++*/ pooznámka
	//int i, 
	//int j;
	//j = i++;
	//j = ++i;
	//Stream je napøíklad monitor, klávesnice, terminál
	//C nemá výjimky a chybový stav si zobrazíme návratovou hodnotou
	// * je pointer, 
	//... je funkce s libovolným poètem parametrù 
	int i;
	int j = 10;
	i = j;
	printf("Ahoj\n");
	printf("i = %d \nj = %d \n", i, j);
	//dej mi adresu kam mùžu uložit int, & je kam se dá uložit 
	scanf("%d", &i);
	printf("i = %d \nj = %d \n", i, j);
	//getchar(); poèká na sisk klávesy
	//Ne vždy kompatibilní, ale je dobré používat
	//(i>0&&...) jde se zleva do prava a vykonává se postupnì
	//pøetypování je - máme 2x int a dìlení je float
	int a = 3;
	int b = 10;
	if (a > 0)
	{
		printf("%f\n", b / (float)a);
	}
	//když nevím co, tak píšu závorky
	//používat ternární operátor
}
void cteniZeSouboru()
{
	//Cesta je v koøenovém adresáøi - øíká se mu pracovní adresáø
	//Vždy se musí soubor otevøít, ale taky zavøít
	//warning je v c zásadní
	FILE*fr=fopen("soubor.txt","r");
	//fscanf("fr",);
	fclose(fr);
}
void zapisDoSouboru()
{
	int i = 10;
	FILE* fw = fopen("soubor.txt", "w");
	//%d je dùležité 
	fprintf(fw,"%d",i);
	fclose(fw);
}
void zapisDoSouboruBinarne()
{
	int i = 10;
	FILE* fw = fopen("soubor.bin","wb");
	// buffer je velikost íèka, &i je že se zaèíná èíst tam, kde je íèko
	fwrite(&i,sizeof(i),1, fw);
}
void ctiZeSouboruBinarne()
{
	int i;
	FILE* fr = fopen("soubor.bin", "rb");
	//má se posunout na 0 znakù od zaèátku (na zaèátek)
	fseek(fr, 0, SEEK_SET);
	fread(&i, sizeof(i), 1, fr);
	fclose(fr);
	printf("%d\n", i);
}
int main()
{
	ctiZeSouboruBinarne();
	system("pause");
	return 0;
}