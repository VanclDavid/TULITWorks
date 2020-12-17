//:: je k tøídì
//. nebo -> (u šipky to pointer) je k objektu
/*#include "CopyConstructor.h";
#include <iostream>;

ArrayOfInt::ArrayOfInt(int _size)
{
	this->size = _size;
	arrayOfInt = new int[_size];
	for (int i = 0; i < _size; i++)
	{
		arrayOfInt[i] = i;
	}
}
ArrayOfInt::~ArrayOfInt()
{
	delete(arrayOfInt);
	this->size = 0;
	arrayOfInt = NULL;
}
void ArrayOfInt::print()
{
	for (int i = 0; i < this->size; i++)
	{
		std::cout << this->arrayOfInt[i] << std::endl;
	}
}
int &ArrayOfInt::getElement(int index)
{
	return this->arrayOfInt[index];
}

void ArrayOfInt::setElement(int index, int value)
{
	this->arrayOfInt[index] = value;
}*/