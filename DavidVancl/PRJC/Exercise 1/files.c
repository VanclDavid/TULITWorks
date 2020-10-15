#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <process.h>

void main() {
	//TEXT FILE
	//FILE * fr = fopen("soubor.txt", "w");
	//fscanf(fr,);
	//fprintf(fr, "%d", 10);
	//fprintf(fr, "%d", 10);
	//fclose(fr);

	//BINARY FILE
	int i = 666;
	FILE* fw = fopen("soubor.bin", "wb");
	//fwrite(&i,sizeof(i), 1, fw);

	int j;
	//fseek(fw, 0, SEEK_SET);
	fread(&j, sizeof(j), 1, fw);
	fclose(fw);

	printf("%d",i);

	system("pause");
	return 0;
}