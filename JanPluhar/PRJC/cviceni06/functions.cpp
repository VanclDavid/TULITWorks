#include <malloc.h>
#include "functions.h"
Person* alocate_person_array(int size) {
	Person* p_person;
	p_person = (Person*)malloc(size * sizeof(Person));
	return p_person;
}
Car* alocate_car_array(int size) {
	Car* p_car;
	p_car = (Car*)malloc(size * sizeof(Car));
	return p_car;
}
void free_person_array(Person* p_person, int size) {
	for (int i = 0; i < size; i++)
	{
		free((void*)p_person);
		p_person = NULL;
	}
}
void free_car_array(Car* p_car, int size) {
	for (int i = 0; i < size; i++)
	{
		free((void*)p_car);
		p_car = NULL;
	}
}