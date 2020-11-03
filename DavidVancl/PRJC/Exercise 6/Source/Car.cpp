#include "Car.h"

void fillCar(Car* c,int id, char newSpz[]) {
	if (strlen(newSpz) != 7) return;
	c->id = id;
	strcpy(c->spz, newSpz);
}