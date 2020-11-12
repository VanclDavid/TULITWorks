#define _CRT_SECURE_NO_WARNINGS
#include <process.h>
#include <stdio.h>
#include "Triangle.h"

int main() {
	int size = 3; // vyska
	char** triangle = allocateArray(size);

	if (triangle == NULL) {
		printf("Neplatne zadani NEBO FAIL:");
	}

	else {
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < (2 * size) - 1; j++) {
				printf("%c", triangle[i][j]);
			}
			printf("\n");
		}
	}

	int error = testArrayData(triangle, size);
	printf("%c", (error == 0) ? "OK":"NE");

	system("pause");
	return 0;
}