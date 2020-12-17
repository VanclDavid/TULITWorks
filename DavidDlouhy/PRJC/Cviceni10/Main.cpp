#include "Animal.h"
#include "AnimalObj.h"
#include <iostream>
int main()
{

	std::cout << "SEKCE DEDICNOST" << "\n";
	std::cout << ">PTAK" << "\n";
	PtakObj* po1 = new PtakObj();
	po1->udelej_pohyb();
	po1->udelej_zvuk();
	std::cout << ">RYBA" << "\n";
	RybaObj* ro1 = new RybaObj();
	ro1->udelej_pohyb();
	ro1->udelej_zvuk();
	std::cout << "\n";

	std::cout << "SEKCE KOMPOZICE" << "\n";
	std::cout << ">RYBA" << "\n";
	Ryba* r1 = new Ryba();
	r1->pohyb->udelej_pohyb();
	r1->zvuk->udelej_zvuk();
	std::cout << ">PTAK" << "\n";
	Ptak* p1 = new Ptak();
	p1->pohyb->udelej_pohyb();
	p1->zvuk->udelej_zvuk();
	std::cout << "\n";

	std::cout << "SEKCE LITACI RYBA" << "\n";
	std::cout << ">DEDICNOST" << "\n";
	LitaciRybaObj* Lro1 = new LitaciRybaObj();
	Lro1->udelej_pohyb();
	Lro1->udelej_zvuk();
	std::cout << "\n";
	std::cout << ">KOMPOZICE" << "\n";
	LitaciRyba* lr1 = new LitaciRyba();
	lr1->pohyb->udelej_pohyb();
	lr1->zvuk->udelej_zvuk();


	return 0;
}