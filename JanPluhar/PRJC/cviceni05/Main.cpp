#define _CRT_SECURE_NO_WARNINGS  
#include <stdio.h>
#include "functions_header.h"
#include <malloc.h>
int main() {
	int m1;
	int n1;
	int m2;
	int n2;
	printf("zadej velikost 1. matice M: \n\r");
	scanf("%d", &m1);
	printf("zadej velikost 1. matice N: \n\r");
	scanf("%d", &n1);
	printf("zadej velikost 2. matice M: \n\r");
	scanf("%d", &m2);
	printf("zadej velikost 2. matice N: \n\r");
	scanf("%d", &n2);
	int** p_array1 = alocate_pointer_array(m1);
	int** p_array2 = alocate_pointer_array(m2);
	create_2d_array(p_array1, m1, n1);
	create_2d_array(p_array2, m2, n2);
	fill_2d_array(p_array1, m1, n1);
	fill_2d_array(p_array2, m2, n2);
	printf("1. matrix\n\n");
	print_2d_array(p_array1, m1, n1);
	printf("2. matrix\n\n");
	print_2d_array(p_array2, m2, n2);
	int** sum_array=NULL;
	int** mult_array=NULL;
	if (m1 == m2 && n1 == n2)
	{
		sum_array = sum_matrices(p_array1, p_array2, m1, m2);
	}
	if (n1==m2)
	{
		mult_array = multiply_matrices(p_array1, p_array2, m1, n1,m2,n2);
	}
	printf("summation\n");
	if (sum_array !=NULL)
	{
		print_2d_array(sum_array, m1, n1);
		free_2d_array(sum_array, m1, n1);
	}
	else {
		printf("incompatible matrices\n\n");
	}
	printf("multiplication\n");
	if (mult_array != NULL)
	{
		print_2d_array(mult_array, m1, n2);
		free_2d_array(mult_array, m1, n2);
	}
	else {
		printf("incompatible matrices\n\n");
	}
	free_2d_array(p_array1, m1, n1);
	free_2d_array(p_array2, m2, n2);
}