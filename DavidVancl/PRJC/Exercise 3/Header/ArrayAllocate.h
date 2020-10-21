#pragma once

//Main functions
float* getAllocatedArray(int size);
void loadSizeTo(int* size);
void fillArray(float* inputArray, int size);
void printArray(float* inputArray, int size);
void switchArrayValues(float* inputArray, int size);
void dealocateArray(float* inputArray);

//Additional unneeded function {just fun}
int getBit(int number, int move);
void printArrayBits(float* inputArray, int size);