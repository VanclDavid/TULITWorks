#define _CRT_SECURE_NO_WARNINGS  
#include <stdio.h>
#include "functions.h"
#include <malloc.h>
#include <string>

int main() {
	Person p1; p1.id = 1; strcpy(p1.name, "Josef"); p1.age = 32;
	Person p2; p2.id = 2; strcpy(p2.name, "Jiri");	p2.age = 57;
	Person p3; p3.id = 3; strcpy(p3.name, "Karel");	p3.age = 15;
	int person_count = 3;

	Car c1; c1.id = 1; c1.id_owner = &p1.id; strcpy(c1.spz, "6A544H8");
	Car c2; c2.id = 2; c2.id_owner = &p1.id; strcpy(c2.spz, "5H3B234");
	Car c3; c3.id = 3; c3.id_owner = &p2.id; strcpy(c3.spz, "8C14H87");
	Car c4; c4.id = 4; c4.id_owner = &p3.id; strcpy(c4.spz, "1S789J2");
	int car_count = 4;

	Person* person_array = alocate_person_array(person_count);
	person_array[0] = p1; person_array[1] = p2;	person_array[2] = p3;
	Car* car_array = alocate_car_array(car_count);
	car_array[0] = c1; car_array[1] = c2; car_array[2] = c3; car_array[3] = c4;

	for (int i = 0; i < person_count; i++)
	{
		printf("[id:%d name: %s age:%d] -> ", person_array[i].id, person_array[i].name, person_array[i].age);
		for (int j = 0; j < car_count; j++)
		{	
			if (person_array[i].id==*(car_array[j].id_owner))
			{
				printf(" [id:%d SPZ: %s]", car_array[j].id, car_array[j].spz);
			}
		}
		printf("\n");
	}

}