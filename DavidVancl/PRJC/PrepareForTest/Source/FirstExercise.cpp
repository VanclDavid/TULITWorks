#include "FirstExercise.h"

int* createOneDimensionArray(int size) {
	int* allocated = (int*)malloc(size * sizeof(int));
	if (allocated == NULL) return NULL;
	for (int i = 0; i < size; i++) {
		allocated[i] = 0;
	}
	return allocated;
}

int** getEvenAndOdd(int* array, int size) {
	int resSize = 2;
	int** result = (int**)malloc(resSize * sizeof(int*));
	if (result == NULL) return NULL;
	for (int i = 0; i < resSize; i++) {
		result[i] = (int*)malloc((size + 1) * sizeof(int));
		if (result[i] == NULL) return NULL;
		for (int j = 0; j < (size + 1); j++) {
			result[i][j] = 0;
		}
	}
	int indexEven = 1;
	int indexOdd = 1;
	for (int i = 0; i < size; i++) {
		if ((array[i] % 2) == 0) {
			result[0][indexEven++] = array[i];
		}
		else {
			result[1][indexOdd++] = array[i];
		}
	}
	result[0][0] = indexEven;
	result[1][0] = indexOdd;
	return result;
}