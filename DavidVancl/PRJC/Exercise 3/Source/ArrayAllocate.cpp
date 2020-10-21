#include "ArrayAllocate.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void loadSizeTo(int* size) {
	int tempValue = 0;
	printf("Get size of array: ");
	scanf_s("%d", &tempValue);
	if (tempValue < 0) {
		*size = 0;
	} else {
		*size = tempValue;
	}
}

float* getAllocatedArray(int size) {
	if (size < 0) return 0;
	float* newArray = (float*)malloc(size * sizeof(float));
	return (newArray != NULL) ? newArray : 0;
}

void fillArray(float* inputArray, int size) {
	for (int i = 0; i < size; i++) {
		printf("Insert number [%d]: \n", (i + 1));
		float loadedData = 0;
		float* d_p = &loadedData;
		scanf_s("%f", d_p);
		inputArray[i] = loadedData;
	}
}

void printArray(float* inputArray, int size) {
	for (int i = 0; i < size; i++) {
		printf("%f ", inputArray[i]);
		if (i == (size - 1)) printf("\n");
	}
}

void switchArrayValues(float* inputArray, int size) {
	for (int i = 0; i < (size / 2); i++) {
		float tempValue = inputArray[i];
		int otherSideIndex = ( ( ( size % 2 ) == 0) ? (size / 2) + i : ((size / 2) + 1) + i);
		inputArray[i] = inputArray[otherSideIndex];
		inputArray[otherSideIndex] = tempValue;
	}
}
void dealocateArray(float* inputArray) {
	*inputArray = NULL;
	inputArray = NULL;
	free(inputArray);
}

//Additional unneeded function {just fun}
int getBit(int number, int move) {
	int buffer = number & 1 << move;
	if (buffer == 0) return 0;
	return 1;
}

void printArrayBits(float* inputArray, int size) {
	for (int i = 0; i < size; i++) {
		for (int j = ((sizeof(float) * 8) - 1); j >= 0; j--) {
			printf("%d", getBit(*(int*)&inputArray[i], j));
			if (j == 0) printf("\n");
		}
	}
}