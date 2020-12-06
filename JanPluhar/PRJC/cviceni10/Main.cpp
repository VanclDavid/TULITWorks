#include "Form.h"
#include <iostream>
int main() {
	CheckBox *cb = new CheckBox("checkbox1");
	Input *input = new Input("Input1");
	InputPswd* input_pswd = new InputPswd("inputPswd1");
	std::cout << cb->getName() <<"\r\n";
	std::cout << input->getName() << "\r\n";
	std::cout << input_pswd->getName() << "\r\n";
	std::cout << "---" << "\r\n";
	std::cout << cb->generate() << "\r\n";
	std::cout << input->generate() << "\r\n";
	std::cout << input_pswd->generate() << "\r\n";
}