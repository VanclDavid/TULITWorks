#pragma once
#include "Editor.h"
#include <iostream>
Editor::Editor() {
	this->chars = {};
}
void Editor::add(Char fchar) {
	chars.push_back(fchar);
}
void Editor::display() {
	for (Char c : chars) {
		c.print();
	}
}
Char::Char(char fchar, int size,Color color)
{
	this->fchar = fchar;
	this->size = size;
	this->color = &color;
}
Color::Color(int r, int g, int b) {
	this->r = r;
	this->g = g;
	this->b = b;
}
void Color::print() {
	std::cout << r << " " << g << " " << b;
}
int Color::getR() {
	return r;
}
int Color::getG() {
	return g;
}
int Color::getB() {
	return b;
}
void Char::print() {
	color->print();
	std::cout << size << " " << fchar << "\n";
}
void Color_aplha::print() {
	std::cout << getR() << " " << getG() << " " << getB() << " "<< alpha;
}
Color_aplha::Color_aplha(int r, int g, int b, int alpha) : Color(r, g, b)
{
	this->alpha = alpha;
}

