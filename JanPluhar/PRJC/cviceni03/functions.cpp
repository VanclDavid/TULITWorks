#include <malloc.h>
#include "functions_header.h"
#include <stdio.h>
float* alocate_array(int size) {
	float* p_float;
	p_float = (float*)malloc(size * sizeof(float));
	return p_float;
}

void fill_float_array(float * float_p,int size)
{
	for (int i = 0; i < size; i++)
	{
		float_p[i] = i;
	}
}
void show_array(char* char_p, int size)
{
	for (int i = 1; i <= size; i++)
	{
		for (int j = 7; 0 <= j; j--) {
			printf("%c", (char_p[i-1] & (1 << j)) ? '1' : '0');
		}
		if (i%4==0)
		{
			printf("\r\n");
		}
		else {
			printf(" ");
		}
	}
	printf("\r\n");
}
void flip_bytes(char* char_p, int size)
{
	int index = (size % 2 == 0 ? (size) / 2 : (size) / 2 + 1);
	for (int i = 0; i < size / 2; i++)
	{
		char temp = char_p[i];
		char_p[i] = char_p[index + i];
		char_p[ index + i] = temp;
	}
}