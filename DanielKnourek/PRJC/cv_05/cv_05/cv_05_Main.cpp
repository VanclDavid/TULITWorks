#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>;
#include "int2DArray.h"
#include "intMatrixFunctions.h"



int main() {

	int ArrWidth = 3;
	int ArrHeight = 2;

	//Adding

	int** MatA = getInt2DArray(ArrWidth, ArrHeight);
	fillInt2DArray(MatA);
	int** MatB = getInt2DArray(ArrWidth, ArrHeight);
	fillZerosInt2DArray(MatB);
	
	printf("Adding\n");
	printf("MatA\n");
	printInt2DArray(MatA);

	int** MatC = addIntMat(MatA, MatB);
	printf("MatC\n");
	printInt2DArray(MatC);

	MatC = addIntMat(MatA, MatC); // ztracený pointer pro pùvodní MatC
	printf("MatC\n");
	printInt2DArray(MatC);

	getchar();
	removeInt2DArray(MatA);
	removeInt2DArray(MatB);
	removeInt2DArray(MatC);

	//Multiplying

	MatA = getInt2DArray(ArrWidth, ArrHeight);
	fillInt2DArray(MatA);
	MatB = getInt2DArray(ArrHeight, ArrWidth);
	fillInt2DArray(MatB);


	printf("Multiplying\n");
	printf("MatA\n");
	printInt2DArray(MatA);
	printf("MatB\n");
	printInt2DArray(MatB);

	MatC = multiplyIntMat(MatA, MatB);
	printf("MatC\n");
	printInt2DArray(MatC);

	getchar();

	removeInt2DArray(MatA);
	removeInt2DArray(MatB);
	removeInt2DArray(MatC);

	return 0;
}