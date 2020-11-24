#pragma once
#include <string>

class BaseColor
{
public:
	BaseColor(int r,int g,int b);
	~BaseColor();
	int getR();
	int getG();
	int getB();

protected:
	int r;
	int g;
	int b;
};

class CharacterColor : public BaseColor
{
public:
	CharacterColor(int r, int g, int b, float a);
	~CharacterColor();
	float getA();

private:
	float a;
};

class CharacterObject
{
public:
	CharacterObject(char character,int size,CharacterColor color);
	~CharacterObject();
	char getValue();
	int getSize();
	int * getColor();

private:
	char value;
	int size;
	CharacterColor color;
};