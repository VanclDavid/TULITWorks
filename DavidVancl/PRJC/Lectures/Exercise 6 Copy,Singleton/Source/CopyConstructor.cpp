#include "CopyConstructor.h"

ArrayOfInt::ArrayOfInt(int size) {
	this->size = size;
	this->arrayOfInt = new int[size];
	for (int i = 0; i < this->size; i++) {
		this->arrayOfInt[i] = 0;
	}
}

ArrayOfInt::ArrayOfInt(ArrayOfInt& arrayToCopy) {
	this->size = arrayToCopy.getSize();
	this->arrayOfInt = new int[arrayToCopy.getSize()];
	for (int i = 0; i < arrayToCopy.getSize(); i++) {
		this->arrayOfInt[i] = arrayToCopy.getElement(i);
	}
}

ArrayOfInt::~ArrayOfInt() {
	delete this->arrayOfInt;
	this->size = 0;
}

int ArrayOfInt::getSize() {
	return this->size;
}

int &ArrayOfInt::getElement(int pos) {
	if (pos >= this->size || pos < 0) return this->arrayOfInt[0];
	return this->arrayOfInt[pos];
}

void ArrayOfInt::printArray() {
	for (int i = 0; i < this->size; i++) {
		cout << this->getElement(i) << ",";
	}
	cout << endl;
}

void ArrayOfInt::setElement(int pos, int value) {
	if (pos >= this->size || pos < 0) return;
	this->arrayOfInt[pos] = value;
}

int& ArrayOfInt::operator[](int index) {
	return this->getElement(index);
}

void ArrayOfInt::operator()(int pos, int value) {
	this->setElement(pos, value);
}

void ArrayOfInt::setSize(int newSize) {
	this->size = newSize;
}