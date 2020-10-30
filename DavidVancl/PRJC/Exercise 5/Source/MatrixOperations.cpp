#include "MatrixOperations.h"

int** matrixSum(int** matrix1, int** matrix2,int rows,int columns) {
	int** tempArray = allocArray(rows, columns);
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			tempArray[i][j] = ((int)matrix1[i][j] + (int)matrix2[i][j]);
		}
	}
	return tempArray;
}

int** multiplicateMatrix(int** matrix1, int M1rows, int M1columns, int** matrix2, int M2rows, int M2columns) {
	if (M1columns != M2rows) return NULL;
	int** tmpArray = allocArray(M1rows, M2columns);
	fillArrayByZero(tmpArray, M1rows, M2columns);
	for (int i = 0; i < M1columns; i++) {
		for (int j = 0; j < M2columns; j++) {
			for (int k = 0; k < M2rows; k++) {
				tmpArray[i][j] += matrix1[i][k] * matrix2[k][j];
			}
		}
	}
	return tmpArray;
}