#include "TextEditor.h"

TextEditor::TextEditor(){}

TextEditor::~TextEditor(){}

void TextEditor::addCharacter(char character,int size, int r,int g,int b, float a) {
	this->characters.push_back(CharacterObject(character,size,CharacterColor(r,g,b,a)));
}

void TextEditor::display() {
    list<CharacterObject>::iterator it;

    for (it = this->characters.begin(); it != this->characters.end(); it++)
    {
        int* clr = it->getColor();
        cout << "value: " << it->getValue() << " -> size: " << it->getSize() << " -> color{R:" << clr[0] << "G:" << clr[1] << "B:" << clr[2] << "A:" << clr[3] << "}" << endl;
    }
}