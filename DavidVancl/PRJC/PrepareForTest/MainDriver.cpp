#define _CRT_SECURE_NO_WARNINGS
#include <process.h>
#include <stdio.h>
#include "FirstExercise.h"
#include "SecondExercise.h"
#include "ThirdExercise.h"
#include "FourthExercise.h"

//int main() {
//	//PART 1 - A
//	int size = 5;
//	int* array = createOneDimensionArray(size);
//	for (int i = 0; i < size; i++) {
//		printf("%d,", array[i]);
//	}
//
//	//PART 1 - B
//	int sizeData = 5;
//	int* arrayData = createOneDimensionArray(sizeData);
//	for (int i = 0; i < sizeData; i++) {
//		arrayData[i] = (i + 1);
//	}
//
//	int** data = getEvenAndOdd(arrayData, sizeData);
//	printf("SUDA:\n");
//	for (int i = 1; i < data[0][0]; i++)
//	{
//		printf("%d,", data[0][i]);
//	}
//	printf("\n LICHA: \n");
//	for (int i = 1; i < data[1][0]; i++)
//	{
//		printf("%d,", data[1][i]);
//	}
//	printf("\n");
//
//	system("pause");
//	return 0;
//}

//int main() {
//  // PART 2 - A
//	int aSize = 5;
//	int** matrix = allocateAdjacencyMatrix(aSize);
//
//	for (int i = 0; i < aSize; i++) {
//		for (int j = 0; j < aSize; j++) {
//			printf("%d", matrix[i][j]);
//		}
//		printf("\n");
//	}
//  // PART 2 - B
//	printf("\n");
//	matrix = addPointAndConnect(matrix, &aSize);
//
//	for (int i = 0; i < aSize; i++) {
//		for (int j = 0; j < aSize; j++) {
//			printf("%d", matrix[i][j]);
//		}
//		printf("\n");
//	}
//
//	system("pause");
//	return 0;
//}

//int main() {
//
//	//PART - 3 - A
//	int trSize = 5;
//	float** triangle = allocateTriangle(trSize);
//
//	printTriangle(triangle, trSize);
//
//	//PART - 3 - B
//	fillDataToTriangle(triangle, trSize);
//
//	printTriangle(triangle, trSize);
//
//	system("pause");
//	return 0;
//}

int main() {

	//PART 4 - B
	unsigned int maximal = getMaxByteMemory();
	printf("[%d] bytes in one block\n", maximal);


	//PART 4 - C
	int res = canIFillItThere(10, 10);
	printf("%s", (res == 1) ? "I can." : "I cant WTF!");

	int res2 = canIFillItThere(50, 50);
	printf("%s", (res2 == 1) ? "I can." : "I cant WTF!");

	system("pause");
	return 0;
}