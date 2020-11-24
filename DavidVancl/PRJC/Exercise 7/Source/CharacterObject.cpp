#include "CharacterObject.h"

int CharacterObject::getSize() {
	return this->size;
}

float CharacterColor::getA() {
	return this->a;
}

int BaseColor::getB() {
	return this->b;
}

int BaseColor::getG() {
	return this->g;
}

int BaseColor::getR() {
	return this->r;
}

int * CharacterObject::getColor() {
	int* colArray = new int[4];
	colArray[0] = this->color.getR();
	colArray[1] = this->color.getG();
	colArray[2] = this->color.getB();
	colArray[3] = this->color.getA();
	return colArray;
}

CharacterObject::~CharacterObject(){}

BaseColor::BaseColor(int r, int g, int b):r(r),g(g),b(b) {}

BaseColor::~BaseColor(){}

CharacterColor::CharacterColor(int r, int g, int b, float a) :a(a), BaseColor(r, g, b) {}

CharacterColor::~CharacterColor(){}

CharacterObject::CharacterObject(char character, int size, CharacterColor color) :value(character), size(size), color(color) {}

char CharacterObject::getValue() {
	return this->value;
}
