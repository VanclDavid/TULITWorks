#pragma once
#include "Malloc.h"
#include <stdio.h>

float** allocateTriangle(int countLines);
void fillDataToTriangle(float** triangle, int lines);
void printTriangle(float** triangle, int lines);