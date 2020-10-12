#define _CRT_SECURE_NO_WARNINGS  
#include <stdio.h>
FILE* fr; 
FILE* fw;
long index;
int main() {
	fr = fopen("SOUBOR.TXT", "r");
	fseek(fr, 0, SEEK_END);
	index = ftell(fr);
	rewind(fr);
	fw = fopen("SOUBOR_OUT1.TXT", "wb");
	char read;
	for (long i = 0; i < index/2; i++)
	{
		read = getc(fr);
		fwrite(&read, sizeof(read), 1, fw);
	}
	fclose(fw);
	fw = fopen("SOUBOR_OUT2.TXT", "wb");
	for (long i = index / 2; i < index; i++)
	{
		read = getc(fr);
		fwrite(&read, sizeof(read), 1, fw);
	}
	fclose(fr);
	fclose(fw);

}