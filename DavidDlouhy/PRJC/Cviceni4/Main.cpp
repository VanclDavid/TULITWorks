#include "Array.h"
#include <stdio.h>
#include "Math.h"

int main()
{
	int m;
	int n;
	m = 4;
	n = 4;

	float** matrixA = createFloatArray(&m, &n);
	float** matrixB = createFloatArray(&m, &n);
	float** sumMatrix = createFloatArray(&m, &n);
	float** multipleMatrix = createFloatArray(&m, &n);

	int counter = 1;
	for (int row = 0; row < m; row++)
	{
		for (int col = 0; col < n; col++)
		{
			matrixA[row][col] = counter;
			counter++;
		}
	}
	counter = 1;
	for (int row = m-1; row >= 0; row--)
	{
		for (int col = n-1; col >= 0; col--)
		{
			matrixB[row][col] = counter;
			counter++;
		}
	}
	printf("MATICE A:\n");
	floatArrayToText(matrixA, &m, &n);
	printf("\nMATICE B:\n");
	floatArrayToText(matrixB, &m, &n);
	printf("\nMATICE A+B:\n");
	countSumMatrix(matrixA, matrixB, sumMatrix, &m, &n);
	floatArrayToText(sumMatrix, &m, &n);
	printf("\nMATICE A*B:\n");
	countMultipleMatrix(matrixA, matrixB, multipleMatrix, &m);
	floatArrayToText(multipleMatrix, &m, &n);
	
	clearFloatArray2D(matrixA, &m);
	clearFloatArray2D(matrixB, &m);
	clearFloatArray2D(sumMatrix, &m);
	clearFloatArray2D(multipleMatrix, &m);

	//dealokace A až D

	return 0;
}
