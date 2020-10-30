#include "int2DArray.h"
#include <stdlib.h>
#include <stdio.h>

int ** getInt2DArray(int width, int height)
{
	//  ##########|############ <-- header (p2DArray)
	//width/hight |^ ptr int **
	int ** p2DArray = (int **)malloc(width * sizeof(int *) + 2 * sizeof(int));
	if (p2DArray == NULL) return NULL;

	p2DArray = (int **) ((char *)p2DArray + 2 * sizeof(int));
	*((char*)p2DArray - 2 * sizeof(int)) = width;
	*((char*)p2DArray - 1 * sizeof(int)) = height;

	int * p1DArray = (int *)malloc( (width * height) * sizeof(int));
	if (p1DArray == NULL) return NULL;

	for (int x = 0; x < width; x++)
	{
		p2DArray[x] = (int *) (p1DArray + (x * height));
	}
	return p2DArray;
}

int getWidthInt2DArray(int** p2DArray)
{
	return (int) *((char *)p2DArray - 2 * sizeof(int));
	//return 0;
}

int getHeightInt2DArray(int** p2DArray)
{
	return (int)*((char*)p2DArray - 1 * sizeof(int));
	//return 0;
}

void fillZerosInt2DArray(int** p2DArray)
{
	int width = getWidthInt2DArray(p2DArray);
	int height = getHeightInt2DArray(p2DArray);

	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			p2DArray[x][y] = 0;
		}
	}
}

void fillInt2DArray(int** p2DArray)
{
	int width = getWidthInt2DArray(p2DArray);
	int height = getHeightInt2DArray(p2DArray);

	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			//*(*(p2DArray + row) + col) = row * col;
			//p2DArray[y][x] = y + x;
			p2DArray[x][y] = x +  y * width;
		}
	}
}

void printInt2DArray(int** p2DArray)
{
	int width = getWidthInt2DArray(p2DArray);
	int height = getHeightInt2DArray(p2DArray);

	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			//printf("%d ", *(*(p2DArray + row) + col));
			//printf("%d ", p2DArray[y][x]);
			printf("%d ", p2DArray[x][y]);
		}
		printf("\n---\n ");
	}
}

void removeInt2DArray(int** p2DArray)
{
	// Free value block
	free(p2DArray[0]);
	// Free header
	free( (int **)((char *)p2DArray - 2 * sizeof(int)) );

	p2DArray = NULL;
}