#pragma once
#include <iostream>

using namespace std;

class ArrayOfInt {
private:
	int size;
	int* arrayOfInt;
protected:

public:
	ArrayOfInt(int size);
	ArrayOfInt(ArrayOfInt &arrayToCopy);

	int getSize();
	
	int &getElement(int pos);
	int& operator[](int pos);

	void setElement(int pos, int vlaue);
	void operator()(int pos, int vlaue);

	void setSize(int newSize);

	void printArray();
	~ArrayOfInt();


};