#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void log(char data[]) {
	FILE* file = fopen("log.txt", "a");
	fwrite(&*data, sizeof(data), 1, file);
	fclose(file);
}