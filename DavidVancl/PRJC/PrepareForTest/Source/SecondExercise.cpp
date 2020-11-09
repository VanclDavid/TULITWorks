#include "SecondExercise.h"

int** allocateAdjacencyMatrix(int countOfPoint) {
	int** matrix = (int**)malloc(countOfPoint * sizeof(int*));
	if (matrix == NULL) return NULL;
	for (int i = 0; i < countOfPoint; i++) {
		matrix[i] = (int*)malloc(countOfPoint * sizeof(int));
		if (matrix[i] == NULL) return NULL;
		for (int j = 0; j < countOfPoint; j++) {
			matrix[i][j] = 0;
		}
	}
	return matrix;
}

int** addPointAndConnect(int** adjacencyMatrix,int *size) {
	int ** tmp = (int**)malloc((*size + 1) * sizeof(int*));
	if (tmp == NULL) return NULL;

	for (int i = 0; i < (*size + 1); i++){
		tmp[i] = (int*)malloc((*size + 1) * sizeof(int));
		if (tmp[i] == NULL) return NULL;
	}

	for (int i = 0; i < *size; i++) {
		for (int j = 0; j < *size; j++) {
			tmp[i][j] = adjacencyMatrix[i][j];
		}
	}

	for (int i = 0; i < (*size + 1); i++) {
		tmp[i][*size] = 0;
	}

	for (int i = 0; i < *size; i++) {
		tmp[*size][i] = 1;
	}
	(*size)++;
	return tmp;
}