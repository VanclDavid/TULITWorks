#include <iostream>
using namespace std;
#include "Template.h"
//je pot�eba naicludovat ten cpp soubor kv�li tomu template
#include "Template.cpp"
#include "Dedicnost.h"

int main()
{
	/*
	int a = 10;
	int b = 20;
	//v�hoodu je �e m��u poslat int i double
	cout << max(a, b) << endl;
	double da = 100.1, db = 1000.1;
	cout << max(da, db) << endl;*/
	/*********************************************************************************************************/
	/*
	Element<int> element(10);//��k�me konkr�tn� parametr co chceme ulo�it a tak� konkr�tn� datov� typ
	element.plus(10);
	cout << element.getValue() << endl;

	Element<float> elementFloat(3.14);
	elementFloat.plus(10);
	cout << elementFloat.getValue() << endl;
	*/
	/*********************************************************************************************************/
	/*
	Child* a = new Child();
	//cout << a->x << " - " << a->y << " - " << a->z << endl;
	delete a;
	Child aa(10, 20, 30);
	//cout << aa.x << " - " << aa.y << " - " << aa.z << endl;
	Parent p(10, 20);
	p.x;
	/*/
	//KOnflikt jmen

	cin.get();
	return 0;
}