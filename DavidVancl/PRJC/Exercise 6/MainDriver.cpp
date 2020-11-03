#include "Person.h"
#include "Car.h"
#include <process.h>
#include <stdio.h>

int main() {
	Person dave;
	fillPerson(&dave, 1, (char *)"Davidsons", 21);

	Person honza;
	fillPerson(&honza, 2, (char*)"HonzaBlazen", 20);

	Car ferrari;
	fillCar(&ferrari, 1, (char*)"6S26003");

	Car skoda;
	fillCar(&skoda, 5, (char*)"1Z27ZZ9");

	addCar(&dave, ferrari);
	addCar(&dave, skoda);

	printf("%s \n", dave.garage[0].spz);
	printf("%s \n", dave.garage[1].spz);

	system("pause");
	return 0;
}