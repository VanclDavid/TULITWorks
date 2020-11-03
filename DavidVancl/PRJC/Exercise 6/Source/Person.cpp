#include "Person.h"

void fillPerson(Person* p,int id, char setName[],int age) {
	p->id = id;
	p->age = age;
	p->name = (char*)malloc(strlen(setName) * sizeof(char));
	if (p->name == NULL) return;
	strcpy(p->name, setName);
}

void addCar(Person* p, Car c) {
	Car* realloc_garage = (Car*)realloc(p->garage,(p->carCount + 1) * sizeof(Car));
	if (realloc_garage == NULL) return;
	p->garage = realloc_garage;
	p->garage[p->carCount] = c;
	p->carCount++;
}