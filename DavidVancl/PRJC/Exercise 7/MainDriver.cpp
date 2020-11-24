#include <process.h>
#include "TextEditor.h"

int main() {
	TextEditor texter;
	texter.addCharacter('A', 14, 255, 255, 255, 0.5);
	texter.addCharacter('H', 13, 255, 0, 255, 0.5);
	texter.addCharacter('O', 12, 255, 255, 0, 0.5);
	texter.addCharacter('J', 11, 0, 255, 255, 0.5);

	texter.display();

	system("pause");
	return 0;
}