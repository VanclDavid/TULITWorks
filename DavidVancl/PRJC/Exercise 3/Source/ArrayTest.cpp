#include <stdio.h>
#include "ArrayTest.h"
#include "ArrayAllocate.h"

int testFunction_switchArrayValues_System() {
	int size = 10;
	printf("Example array: \n");
	float exampleData[] = { 1,2,3,4,5,6,7,8,9,10 };
	printArray(&(exampleData[0]), size);
	printf("Actual array after switch: \n");
	float data[] = { 1,2,3,4,5,6,7,8,9,10 };
	switchArrayValues(&(data[0]), size);
	printArray(&(data[0]), size);
	printf("Actual array after switch: \n");
	float expectedData[] = { 6,7,8,9,10,1,2,3,4,5 };
	printArray(&(expectedData[0]), size);

	for (int i = 0; i < size; i++) {
		if (data[i] != expectedData[i]) {
			printf("Arrays are NOT same\n");
			return 1;
		}
	}

	printf("Arrays are same\n");
	return 0;
}

int testFunction_switchArrayValues_CustomData(float* inputArray, float* expectedArray, int size) {
	for (int i = 0; i < size; i++) {
		if (inputArray[i] != expectedArray[i]) {
			return 1;
		}
	}
	return 0;
}