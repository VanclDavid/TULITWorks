#pragma once
#include <list>
class Editor {
private:
	std::list<Char> chars;
public:
	void display();
	void add(Char fchar);
};
class Char {
private:
	int size;
	Color *color;
	char fchar;
public:
	Char(char fchar,int size, Color color);
	void print();
};
class Color {
private:
	int r;
	int g;
	int b;
public:
	Color(int r, int g, int b);
	void print();
	int getR();
	int getG();
	int getB();
};
class Color_aplha : public Color {
private:
	int alpha;

public:
	Color_aplha(int r, int g, int b, int alpha) : Color(r, g, b){}
	void print();
};

