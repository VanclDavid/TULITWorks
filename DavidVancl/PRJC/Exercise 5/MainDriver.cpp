#define _CRT_SECURE_NO_WARNINGS
#include <process.h>
#include "MatrixTech.h";
#include "MatrixOperations.h";

int main() {
	int M1rows = 3;
	int M1columns = 3;
	int** matrix1 = allocArray(M1rows, M1columns);
	autoFillArray(matrix1, M1rows, M1columns);
	//fillArray(matrix1, M1rows, M1columns);
	printf("Matrix 1: \n");
	printArray(matrix1, M1rows, M1columns);

	int M2rows = 3;
	int M2columns = 3;
	int** matrix2 = allocArray(M2rows, M2columns);
	autoFillArray(matrix2, M2rows, M2columns);
	//fillArray(matrix2, M2rows, M2columns);
	printf("Matrix 2: \n");
	printArray(matrix2, M2rows, M2columns);

	int** sumMatrix = matrixSum(matrix1, matrix2, M1rows, M1columns);
	printf("Sum matrix: \n");
	printArray(sumMatrix, M1rows, M1columns);

	int** multArray = multiplicateMatrix(matrix1, M1rows, M1columns, matrix2, M2rows, M2columns);
	printf("Result matrix: \n");
	printArray(multArray, M1rows, M2columns);

	dealocArray(matrix1, M1rows);
	dealocArray(matrix2, M2rows);
	dealocArray(sumMatrix, M1rows);
	dealocArray(multArray, M1rows);
	system("pause");
	return 0;
}