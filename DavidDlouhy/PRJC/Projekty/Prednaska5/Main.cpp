//SKLAD D�N�, KOLIK V��� V�ECHNY CELKEM...

#include "Pumpkin.h"
#include <iostream>



int main()
{
	//C++ nen� nadmn�ina C
	//jsou v�ci co jsou jen v c
	//ASCI je v C, UNICODE je v C++
	// v c nebyl komen�� // ale v c++ ano
	//statick� prom�nn� se ukl�d� do rochu jin�o stacku
	//statick� prom�nn� je takov�, �e ji v�ichni sd�lej� a z�st�vaj� v aktivn� pam�ti
	//nesm�m jich m�t hodn�
	//statick� metodda p�itupje ke statick� hodnot�
	// statick se d� d�dit 

	//z�is 1
	Pumpkin p1(10), p2(20);
	p1.print();
	p1.print_total(); 

	//z�pis2
	Pumpkin* p_p3=new Pumpkin(45);
	p_p3->print();
	p_p3->print_total();

	Pumpkin::print_total(); //proto�e m�m statickou metodu

	delete(p_p3);
	//z�pis3
	Pumpkin::print_total();
	//delete(&p1);

	//c++ um� p�et�ovat oper�tory
	p1.change(p2);
	p2.print();

	std::cin.get();
	return 0;
}