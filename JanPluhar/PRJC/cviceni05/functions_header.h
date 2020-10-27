#pragma once
int* alocate_int_array(int size);
int** alocate_pointer_array(int size);
void create_2d_array(int** p_p_int, int m, int n);
void fill_2d_array(int** p_p_int, int m, int n);
void fill_int_array(int* int_p, int size);
void print_2d_array(int** p_p_int, int m, int n);
void print_int_array(int* int_p, int size);
void free_2d_array(int** p_p_int, int m, int n);
void free_int_array(int* p_int, int size);
int** sum_matrices(int** p_p_int1, int** p_p_int2,int m,int n);
int** multiply_matrices(int** p_p_int1, int** p_p_int2, int m1, int n1, int m2, int n2);
