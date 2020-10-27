#include "MatrixTech.h";

int** allocArray(int rows, int columns) {
	int** tempArray = (int**)malloc(rows * sizeof(int*));
	if (tempArray == NULL) return NULL;

	for (int i = 0; i < rows; i++) {
		tempArray[i] = (int*)malloc(columns * sizeof(int));
		if (tempArray[i] == NULL) return NULL;
	}
	return tempArray;
}

void dealocArray(int** inputArray, int rows) {
	for (int i = 0; i < rows; i++) {
		free((int*)inputArray[i]);
	}
	free((int**)inputArray);
}

void fillArray(int** inputArray, int rows,int columns) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			int loaded = 1;
			printf("[%d,%d]: \n",i,j);
			scanf_s("%d", &loaded);
			inputArray[i][j] = loaded;
		}
	}
}

void fillArrayByZero(int** inputArray, int rows, int columns) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			inputArray[i][j] = 0;
		}
	}
}

void autoFillArray(int** inputArray, int rows, int columns) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			inputArray[i][j] = rand() % 10 + 1;
		}
	}
}

void printArray(int** inputArray, int rows,int columns) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			printf("%02d ", inputArray[i][j]);
		}
		printf("\n");
	}
}