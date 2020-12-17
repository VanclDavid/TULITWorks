#include "Web.h"
#include <iostream>
/*Input::Input()
{
	//this->setHtml("<tag></tag>");
	this->html = "<tag></tag>";
}*/

void Form::renderHtml()
{
	std::list<FormPrvek*>::iterator iterator = list_formprvek.begin();
	while (iterator != list_formprvek.end()) {
		std::cout<<(*iterator)->getHtml()<<"\n";
		++iterator;
	}
}

void Form::addFormPrvek(FormPrvek* fp)
{
	list_formprvek.push_back(fp);
}


std::string Input::getHtml()
{
	return this->html;
}

std::string PasswordTag::getHtml()
{
	return this->html;
}

std::string ChceckBox::getHtml()
{
	return this->html;
}

/*
void Input::setHtml(std::string newHtml)
{
	this->html = newHtml;
}*/

