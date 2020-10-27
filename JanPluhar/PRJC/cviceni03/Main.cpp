#define _CRT_SECURE_NO_WARNINGS  
#include <stdio.h>
#include "functions_header.h"
#include <malloc.h>
int main() {
	int size;
	printf("zadej velikost pole\n\r");
	scanf("%d", &size);
	float* array=alocate_array(size);
	fill_float_array(array,size);
	show_array((char*)(array), size * sizeof(float));
	flip_bytes((char*)(array), size* sizeof(float));
	show_array((char*)(array), size * sizeof(float));
	free((void *)array);
	array = NULL;
}