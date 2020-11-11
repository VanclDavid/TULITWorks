#pragma once
struct Person
{
	int id;
	char name[30];
	int age;
};
struct Car
{
	int id;
	int* id_owner;
	char spz[8]; //7+1
};
Car* alocate_car_array(int size);
Person* alocate_person_array(int size);
void free_person_array(Person* p_person, int size);
void free_car_array(Car* p_car, int size);