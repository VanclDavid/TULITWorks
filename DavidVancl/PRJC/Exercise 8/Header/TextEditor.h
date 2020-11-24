#pragma once
#include <algorithm>
#include <iostream>
#include <list>
#include "CharacterObject.h"

using namespace std;

class TextEditor
{
public:
	TextEditor();
	~TextEditor();
	void addCharacter(char character, int size, int r, int g, int b, float a);
	void display();

private:
	list<CharacterObject> characters = {};
};