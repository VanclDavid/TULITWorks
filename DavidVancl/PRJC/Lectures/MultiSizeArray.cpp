#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <process.h>

int dynamicMultiArrayByIndex() {
	char** array2D;
	array2D = (char**)malloc(3 * sizeof(char*));
	if (array2D == NULL) return 500;

	for (int i = 0; i < 3; i++) {
		array2D[i] = (char*)malloc(5 * sizeof(char));
		if (array2D[i] == NULL) return 500;
	}

	for (int i = 0; i < 3; i++) {
		free((char*)array2D[i]);
	}
	free((char**)array2D);
	return 0;
}

int** allocArray(int rows) {
	int** tempArray = (int**)malloc(rows * sizeof(int*));
	if (tempArray == NULL) return NULL;
	for (int i = 0; i < rows; i++) {
		tempArray[i] = (int*)malloc((i + 1) * sizeof(int));
		if (tempArray[i] == NULL) return NULL;
	}
	return tempArray;
}

void dealocArray(int** inputArray, int size) {
	for (int i = 0; i < size; i++) {
		free((int*)inputArray[i]);
	}
	free((int**)inputArray);
}

void fillArray(int** inputArray, int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < i; j++) {
			inputArray[i][j] = (i + j);
		}
	}
}

void printArray(int** inputArray, int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < i; j++) {
			printf("%d ", inputArray[i][j]);
		}
		printf("\n");
	}
}

int main() {
	int rows = 5;

	int** array2D;
	array2D = allocArray(rows);
	
	fillArray(array2D, rows);
	printArray(array2D, rows);
	dealocArray(array2D, rows);

	system("pause");
	return 0;
}