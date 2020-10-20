#define _CRT_SECURE_NO_WARNINGS
#include <process.h>
#include <stdio.h>

#include "ArrayAllocate.h"
#include "ArrayTest.h"

int main() {
	int input = 1;
	int* inputp = &input;

	printf("1-program, 2-system test, 3-custom test \n");
	scanf_s("%d", inputp);

	switch (*inputp) {
	case 1:
		while (*inputp == 1) {
			int size = 0;
			loadSizeTo(&size);
			float* array_p = getAllocatedArray(size);
			fillArray(array_p, size);
			printArray(array_p, size);
			switchArrayValues(array_p, size);
			printArray(array_p, size);
			dealocateArray(array_p);
			printf("1-continue, 0-end \n");
			scanf_s("%d", inputp);
		}
		break;
	case 2:
		testFunction_switchArrayValues_System();
		break;
	case 3:
		int testSize = 0;
		loadSizeTo(&testSize);
		float* inputArray_p = getAllocatedArray(testSize);
		float* expectedArray_p = getAllocatedArray(testSize);
		printf("Input array:\n");
		fillArray(inputArray_p, testSize);
		printf("Expected array:\n");
		fillArray(expectedArray_p, testSize);
		switchArrayValues(inputArray_p, testSize);
		int result = testFunction_switchArrayValues_CustomData(inputArray_p, expectedArray_p, testSize);
		(result == 0) ? printf("OK") : printf("FAILD");
		dealocateArray(expectedArray_p);
		dealocateArray(inputArray_p);
		break;
	}

	system("pause");
	return 0;
}