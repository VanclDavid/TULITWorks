//SKLAD DÝNÍ, KOLIK VÁŽÍ VŠECHNY CELKEM...

#include "Pumpkin.h"
#include <iostream>



int main()
{
	//C++ není nadmnžina C
	//jsou vìci co jsou jen v c
	//ASCI je v C, UNICODE je v C++
	// v c nebyl komenáø // ale v c++ ano
	//statická promìnná se ukládá do rochu jinéo stacku
	//statická promìnná je taková, že ji všichni sdílejí a zùstávají v aktivní pamìti
	//nesmím jich mít hodnì
	//statická metodda pøitupje ke statické hodnotì
	// statick se dá dìdit 

	//záis 1
	Pumpkin p1(10), p2(20);
	p1.print();
	p1.print_total(); 

	//zápis2
	Pumpkin* p_p3=new Pumpkin(45);
	p_p3->print();
	p_p3->print_total();

	Pumpkin::print_total(); //protože mám statickou metodu

	delete(p_p3);
	//zápis3
	Pumpkin::print_total();
	//delete(&p1);

	//c++ umí pøetžovat operátory
	p1.change(p2);
	p2.print();

	std::cin.get();
	return 0;
}