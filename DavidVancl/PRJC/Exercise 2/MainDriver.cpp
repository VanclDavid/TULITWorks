#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <process.h>

#include "Sum.h"
#include "Diff.h"
#include "Counter.h"
#include "Logger.h"

int main() {
	float a,b,operation = 0;
	float* ap = &a;
	float* bp = &b;
	float* op = &operation;

	int sumCounter = 0;
	int* sumCP = &sumCounter;
	int diffCounter = 0;
	int* diffCP = &diffCounter;

	int input = 1;
	int* inputp = &input;

	printf("1-continue, 0-end \n");
	scanf_s("%d", inputp);

	while (*inputp != 0) {
		printf("Set number A: ");
		scanf_s("%f", ap);
		printf("Set number B: ");
		scanf_s("%f", bp);
		printf("Select operation: 1-sum, 2-diff ");
		scanf_s("%f", op);

		float result;
		if (*op == 1) {
			result = sum(a, b);
			increase(sumCP);
			char data[] = "sum A and B";
			log(data);
		}
		else {
			result = diff(a, b);
			increase(diffCP);
			char data[] = "diff A and B";
			log(data);
		}
		printf("Result is: %.5f \n", result);
		printf("1-continue, 0-end \n");
		scanf_s("%d", inputp);
	}

	printf("Sum counter is: %d \n", *sumCP);
	printf("Diff counter is: %d \n", *diffCP);
	system("pause");
	return 0;
}