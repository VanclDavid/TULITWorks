#include "ThirdExercise.h"

float** allocateTriangle(int countLines) {
	float** triangle = (float**)malloc(countLines * sizeof(float*));
	if (triangle == NULL) return NULL;

	int windowBoxes = 1;
	for (int i = 0; i < countLines; i++) {
		triangle[i] = (float*)malloc(windowBoxes * sizeof(float));
		if (triangle[i] == NULL)return NULL;
		for (int j = 0; j < windowBoxes; j++) {
			triangle[i][j] = 0;
		}
		windowBoxes += 2;
	}

	return triangle;
}

void fillDataToTriangle(float ** triangle,int lines) {
	int windowBoxes = 1;
	int index = 0;
	for (int i = 0; i < lines; i++) {
		for (int j = 0; j < windowBoxes; j++) {
			triangle[i][j] = index;
			index++;
		}
		windowBoxes += 2;
	}
}

void printTriangle(float ** triangle, int lines) {
	int windowBoxes = 1;
	for (int i = 0; i < lines; i++) {
		for (int j = 0; j < windowBoxes; j++) {
			printf("%.1f,", triangle[i][j]);
		}
		windowBoxes += 2;
		printf("\n");
	}
}