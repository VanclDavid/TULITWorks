// ignorov�n� warningu
#define _CRT_SECURE_NO_WARNINGS
//obdoba java import, knihovny
#include <stdio.h>
#include <process.h>
void ukazaka1()
{
	//p�ehledn� si pojmenov�vat prom�nn� a ps�t k nim pozn�mku
	//CamelCase nebo snake_case vybrat si jeden a ten pou��vat
	// nepou��vat 2 r�zn� prom�nn� Promenna a promenna
	//Na za��tek nikdy nepou��vat podtr��tko (m��e b�t syst�mov� prom�nn�)
	// /*je jen v c++*/ poozn�mka
	//int i, 
	//int j;
	//j = i++;
	//j = ++i;
	//Stream je nap��klad monitor, kl�vesnice, termin�l
	//C nem� v�jimky a chybov� stav si zobraz�me n�vratovou hodnotou
	// * je pointer, 
	//... je funkce s libovoln�m po�tem parametr� 
	int i;
	int j = 10;
	i = j;
	printf("Ahoj\n");
	printf("i = %d \nj = %d \n", i, j);
	//dej mi adresu kam m��u ulo�it int, & je kam se d� ulo�it 
	scanf("%d", &i);
	printf("i = %d \nj = %d \n", i, j);
	//getchar(); po�k� na sisk kl�vesy
	//Ne v�dy kompatibiln�, ale je dobr� pou��vat
	//(i>0&&...) jde se zleva do prava a vykon�v� se postupn�
	//p�etypov�n� je - m�me 2x int a d�len� je float
	int a = 3;
	int b = 10;
	if (a > 0)
	{
		printf("%f\n", b / (float)a);
	}
	//kdy� nev�m co, tak p�u z�vorky
	//pou��vat tern�rn� oper�tor
}
void cteniZeSouboru()
{
	//Cesta je v ko�enov�m adres��i - ��k� se mu pracovn� adres��
	//V�dy se mus� soubor otev��t, ale taky zav��t
	//warning je v c z�sadn�
	FILE*fr=fopen("soubor.txt","r");
	//fscanf("fr",);
	fclose(fr);
}
void zapisDoSouboru()
{
	int i = 10;
	FILE* fw = fopen("soubor.txt", "w");
	//%d je d�le�it� 
	fprintf(fw,"%d",i);
	fclose(fw);
}
void zapisDoSouboruBinarne()
{
	int i = 10;
	FILE* fw = fopen("soubor.bin","wb");
	// buffer je velikost ��ka, &i je �e se za��n� ��st tam, kde je ��ko
	fwrite(&i,sizeof(i),1, fw);
}
void ctiZeSouboruBinarne()
{
	int i;
	FILE* fr = fopen("soubor.bin", "rb");
	//m� se posunout na 0 znak� od za��tku (na za��tek)
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