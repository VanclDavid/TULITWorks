#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int pr2()
{
	//2D pole
	//1D pole char� - znaky
	//1D array
	//char* array1D;
	//array1D = (char*)malloc(3 * sizeof(char));
	//char* array2D;
	//2D pole char� - znaky, pointer na pointer na char
	char** array2D;
	array2D = (char**)malloc(3 * sizeof(char*));
	int i = 0;
	for (int i = 0; i < 3; i++)
	{
		array2D[i] = (char*)malloc(5 * sizeof(char));
		if (array2D[i] == NULL) return 5;
	}
	//array2D[0][5] = 'A';//zapisuje se kam nem� - to necheme
	array2D[0][4] = 'A';
	//dealokace, postupn�
	for (int i = 0; i < 3; i++)
	{
		free((char*)array2D[i]);
	}
	free((char**)array2D);
	return 0;
}
int pr1()
{
	char* string;
	string = (char*)malloc(10 * sizeof(char));
	if (string == NULL) return 1;
	strcpy(string, "AhojAhojAhojAhoj");
	printf("%s", string);

	free((char*)string);//vr�t� chybu kdy� jsem do pam�ti �patn� zapsal, spr�vn� by m�lo ale bez probl�mu prob�hnout
	return 0;
}
//troj rozm�rn� pole je3x pole pole v poli ktere je v poli int *** pole

int ** alloc_array_2D(int cols, int rows)
{
	int** temp_array2D;
	temp_array2D = (int**)malloc(rows * sizeof(int *));
	if (temp_array2D == NULL) return NULL;
	int i;
	for (int i = 0; i < rows; i++)
	{
		temp_array2D[i] = (int*)malloc((i+1)*sizeof(int));
		if (temp_array2D[i] == NULL)return NULL;
	}

	return temp_array2D;
}

void dealloc_array_2D(int **array2D, int rows)
{
	int i;
	for (int i = 0; i++; i < rows)
	{
		free((int*)array2D[i]);
	}
	free((int**)array2D);
}

void fill_array2D(int **array2D, int rows)
{
	int i;
	int j;
	for (int i = 0; i < rows; i++)
	{
		for(int j=0;j++;j<(i+1))
		{
			array2D[i][j] = i;
		}
	}
}

void print_array2D(int** array2D, int rows)
{
	int i;
	int j;
	for (int i = 0; i < rows;i++)
	{
		for (int j = 0;  j < (i + 1);j++)
		{
			printf("%d ", array2D[i][j]);
		}
		printf("\n");
	}
}

int main(int argc, char *argv[])
{
	//pr1();
	//pr2();

	int** array2D;
	int rows = 3;
	//array2D = alloc_array_2D();

	//alokace 2d pole int�
	//int **array=2D
	//vytisknut� pole
	//napln�n� pole
	//uvoln�n� pole





	getchar();
	return 0;
}