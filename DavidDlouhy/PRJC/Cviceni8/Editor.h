#pragma once
#include <list>
class Editor
{
private:
	std::list <TextChar> fullText;
public:
	void display();
	void addTextChar(TextChar character);
};

class TextChar
{
private:
	int size;
	Color *color;
	char textChar;
public:
	TextChar(char textChar, Color color,  int size);
	void print();
	void setColor(Color color);
};

class Color
{
private:
	int r;
	int g;
	int b;
public:
	Color(int r, int g, int b);
	int getR();
	int getG();
	int getB();
	void print();
};

//udìlat tøídu která dìdí od color a je to alpha color
/*
class ColorAlpha : public Color{
private:
	int a;
public:
	ColorAlpha(int r, int g, int b, int a) : Color(r, g, b) {}
	void print();
};*/