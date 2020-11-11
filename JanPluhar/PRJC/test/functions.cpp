#include <malloc.h>
#include <stdio.h>
char* alocate_char_array(int size) {
	char* p_char;
	p_char = (char*)malloc(size * sizeof(char));
	return p_char;
}
char** alocate_pointer_array(int size) {
	char** p_p_char;
	p_p_char = (char**)malloc(size * sizeof(char*));
	return p_p_char;
}
void create_2d_array(char** p_p_char, int row) {
	int index = 1;
	for (int i = 0; i < row; i++)
	{
		p_p_char[i] = alocate_char_array(index);
		index += 2;
	}
}
void fill_char_array(char* p_char, int size) {
	for (int i = 0; i < size; i++)
	{
		p_char[i] = 'a' + i;
	}
}
void fill_2d_array(char** p_p_char, int row) {
	int index = 1;
	for (int i = 0; i < row; i++)
	{
		fill_char_array(p_p_char[i], index);
		index += 2;
	}
}
void testTriangle(char** p_p_char, int row) {
	int index = 1;
	for (int i = 0; i < row; i++)
	{
		printf("radek: %d:", i);
		for (int j = 0; j < (index); j++)
		{
			printf("%c ", p_p_char[i][j]);	
		}
		index += 2;
		printf("\n");
	}
}
