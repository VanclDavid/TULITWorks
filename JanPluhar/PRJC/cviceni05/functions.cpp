#include <malloc.h>
#include "functions_header.h"
#include <stdio.h>
#include <stdlib.h>
int* alocate_int_array(int size) {
	int* p_int;
	p_int = (int*)malloc(size * sizeof(int));
	return p_int;
}
int** alocate_pointer_array(int size) {
	int** p_p_int;
	p_p_int = (int**)malloc(size * sizeof(int*));
	return p_p_int;
}
void create_2d_array(int** p_p_int,int m, int n) {
	for (int i = 0; i < m; i++)
	{
		p_p_int[i] = alocate_int_array(n);
	}
}
void fill_2d_array(int** p_p_int, int m, int n) {
	for (int i = 0; i < m; i++)
	{
		fill_int_array(p_p_int[i], n);
	}
}
void fill_int_array(int* int_p,int size) {
	for (int i = 0; i < size; i++)
	{
		int_p[i] = rand() % 10;
	}
}
void print_2d_array(int** p_p_int, int m, int n) {
	printf("\n");
	for (int i = 0; i < m; i++)
	{
		print_int_array(p_p_int[i],n);
	}
	printf("\n");
}
void print_int_array(int* int_p, int size) {
	for (int i = 0; i < size; i++)
	{
		printf(" %d ", int_p[i]);
	}
	printf("\n");
}
void free_2d_array(int** p_p_int, int m, int n) {
	for (int i = 0; i < m; i++)
	{
		free_int_array(p_p_int[i], n);
	}
	free((void*)p_p_int);
	p_p_int = NULL;
}
void free_int_array(int* p_int, int size) {
	for (int i = 0; i < size; i++)
	{
		free((void*)p_int);
		p_int = NULL;
	}
}
int** sum_matrices(int** p_p_int1, int** p_p_int2, int m, int n) {
	int** result_array = alocate_pointer_array(m);
	create_2d_array(result_array, m, n);
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			result_array[i][j] = p_p_int1[i][j] + p_p_int2[i][j];
		}

	}
	return result_array;
}
int ** multiply_matrices(int** p_p_int1, int** p_p_int2, int m1_row, int m1_column,int m2_row, int m2_column) {
	int** result_array = alocate_pointer_array(m1_row);
	create_2d_array(result_array, m1_row, m2_column);
	for (int i = 0; i < m1_row; i++)
	{
		for (int j = 0; j < m2_column; j++)
		{
			int sum = 0;
			for (int k = 0; k < m1_column; k++)
			{
				sum += p_p_int1[i][k] * p_p_int2[k][j];
			}
			result_array[i][j] = sum;
		}
	}
	return result_array;
}


