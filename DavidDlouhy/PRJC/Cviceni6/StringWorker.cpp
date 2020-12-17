#include <corecrt_malloc.h>
#include <stdio.h>

char* alcString(int* length)
{
	return (char*)malloc(sizeof(char)*(*length));
}

void printString(char* string, int* length)
{
	for (int i = 0; i < *length; i++)
	{
		printf("%c", string[i]);
	}
}