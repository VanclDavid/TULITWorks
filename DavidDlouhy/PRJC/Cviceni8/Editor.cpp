#include "Editor.h"

Editor::Editor() {
	this->fullText = {};
}
void Editor::addTextChar(TextChar character) {
	this->fullText.push_back(character);
}
void Editor::display() {
	for (TextChar character: this->fullText)
	{
		character.print();
	}
}

TextChar::TextChar(char textChar, Color color, int size) {
	this->textChar = textChar;
	this->color = &color;
	this->size = size;
}

Color::Color(int r, int g, int b)
{
	this->r = r;
	this->g = g;
	this->b = b;
}

