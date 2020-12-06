#pragma once
#include "Form.h"
#include <string>
Form::Form(std::string name) {
	this->name = name;
}
HtmlElement::HtmlElement(std::string name) {
	this->name = name;
}
std::string HtmlElement::getName() const{
	return this->name;
}
Input::Input(std::string name) : HtmlElement(name){
}
CheckBox::CheckBox(std::string name) : HtmlElement(name) {
}
InputPswd::InputPswd(std::string name) : HtmlElement(name) {
}
std::string Input::generate() const {
	return ("<input name=" + this->getName() + ">");
}
std::string CheckBox::generate() const {
	return ("<input name=" + this->getName() + ">");
}
std::string InputPswd::generate()  const{
	return ("<input type=\"password\" name=" + this->getName() + ">");
}