#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <string.h>

typedef struct Cars {
	int id;
	char spz[7];
} Car;

void fillCar(Car* p,int id, char newSpz[]);