#pragma once
#include "Car.h"
#include <string.h>
#include <malloc.h>

typedef struct Persons {
	int id;
	char* name;
	int age;
	int carCount = 0;
	Car* garage = (Car*)malloc(1 * sizeof(Car));
} Person;

void fillPerson(Person* p, int id, char setName[], int age);
void addCar(Person* p, Car c);