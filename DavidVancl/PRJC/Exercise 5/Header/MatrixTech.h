#pragma once
#include <stdlib.h>
#include <stdio.h>

int** allocArray(int rows, int columns);
void dealocArray(int** inputArray, int rows);
void fillArray(int** inputArray, int rows, int columns);
void autoFillArray(int** inputArray, int rows, int columns);
void printArray(int** inputArray, int rows, int columns);
void fillArrayByZero(int** inputArray, int rows, int columns);