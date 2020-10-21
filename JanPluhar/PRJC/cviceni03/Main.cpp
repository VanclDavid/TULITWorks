#define _CRT_SECURE_NO_WARNINGS  
#include <stdio.h>
#include "Header.h"
#include <malloc.h>
int main() {
	int size;
	printf("zadej velikost pole\n\r");
	scanf("%d", &size);
	float* array=alocate_array(size);
	fill_float_array(array,size);
	show_array(array, size);
	flip_floates(array, size);
	show_array(array, size);
	free((void *)array);
	array = NULL;
}