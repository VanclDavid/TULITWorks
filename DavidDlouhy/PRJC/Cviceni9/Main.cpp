#include <string>
#include "Web.h"
#include <iostream>

int main()
{
	//FormPrvek* fp1;
	//2x input, 1x checkbox a 2x password

	Input *i1 = new Input();
	Input* i2 = new Input();
	ChceckBox* cb1 = new ChceckBox();
	PasswordTag* p1 = new PasswordTag();
	PasswordTag* p2 = new PasswordTag();

	std::cout << "" <<"výpis bez listu" << "\n";
	std::cout << "" << i1->getHtml() << "\n";
	std::cout << "" << i2->getHtml() << "\n";
	std::cout << "" << cb1->getHtml() << "\n";
	std::cout << "" << p1->getHtml() << "\n";
	std::cout << "" << p2->getHtml() << "\n";

	Form* f1 = new Form();
	f1->addFormPrvek(new Input());
	f1->addFormPrvek(new Input());
	f1->addFormPrvek(new ChceckBox());
	f1->addFormPrvek(new PasswordTag());
	f1->addFormPrvek(new PasswordTag());
	std::cout << "\n \n" << "vypis s listem" << "\n";
	f1->renderHtml();

	return 0;
}