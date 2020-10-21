#include <malloc.h>
#include "Header.h"
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
void show_array(float* float_p, int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("index [%d] %f \r\n",i,float_p[i]);

	}
	printf("\r\n");
}
void flip_floates(float* float_p, int size)
{
	int index = (size % 2 == 0 ? (size) / 2 : (size) / 2 + 1);
	for (int i = 0; i < size / 2; i++)
	{
		float temp = float_p[i];
		float_p[i] = float_p[index + i];
		float_p[ index + i] = temp;
	}
}