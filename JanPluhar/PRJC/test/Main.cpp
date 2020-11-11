#define _CRT_SECURE_NO_WARNINGS  
#include <stdio.h>
#include "functions.h";
int main() {
	int rows = 6;
	rows %= 10;
	char** p_p_char = alocate_pointer_array(rows);
	create_2d_array(p_p_char, rows);
	fill_2d_array(p_p_char, rows);
	testTriangle(p_p_char, rows);
}