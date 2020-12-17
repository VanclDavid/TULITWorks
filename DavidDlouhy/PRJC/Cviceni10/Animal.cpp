#include "Animal.h"
#include <string>
#include <iostream>

void Zpivej::udelej_zvuk()
{
	std::cout <<"pisky pisk" << "\n";
}

void Litej::udelej_pohyb()
{
	std::cout << "litam fr fr" << "\n";
}

void Mlc::udelej_zvuk()
{
	std::cout << "mlcim" << "\n";
}

void Plavej::udelej_pohyb()
{
	std::cout << "plavu" << "\n";
}

Ptak::Ptak()
{
	this->pohyb = new Litej();
	this->zvuk = new Zpivej();
}

Ryba::Ryba()
{
	this->pohyb = new Plavej();
	this->zvuk = new Mlc();
}

LitaciRyba::LitaciRyba()
{
	this->pohyb = new Litej();
	this->zvuk = new Mlc();
}