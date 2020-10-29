#include "intMatrixFunctions.h"
#include "int2DArray.h"

int** addIntMat(int** matA, int** matB)
{
	int width = getWidthInt2DArray(matA);
	int height = getHeightInt2DArray(matA);

	if (width != getWidthInt2DArray(matB) || height != getHeightInt2DArray(matB))
	{
		return nullptr;
	}
	int** resultMat = getInt2DArray(width, height);

	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			resultMat[x][y] = matA[x][y] + matB[x][y];
			
		}
	}
	return resultMat;

}

int** multiplyIntMat(int** matA, int** matB)
{
	int matAWidth = getWidthInt2DArray(matA);
	int matAHeight = getHeightInt2DArray(matA);
	int matBWidth = getWidthInt2DArray(matB);
	int matBHeight = getHeightInt2DArray(matB);

	if (matAWidth != matBHeight)
	{
		return nullptr;
	}
	int** resultMat = getInt2DArray(matAHeight, matBWidth);
	fillZerosInt2DArray(resultMat);

	for (int y = 0; y < matAHeight; y++)
	{
		for (int x = 0; x < matBWidth; x++)
		{
			int suma = 0;
			for (int i = 0; i < matAWidth; i++)
			{
				suma += matA[i][y] * matB[x][i];;
			}
			resultMat[x][y] = suma;
		}
	}
	return resultMat;
}
