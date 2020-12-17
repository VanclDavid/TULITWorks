#include "AnimalObj.h"
#include <string>
#include <iostream>


void RybaObj::udelej_zvuk()
{
	std::cout << "mlcim" << "\n";
}

void PtakObj::udelej_zvuk()
{
	std::cout << "pisky pisk " << "\n";
}

void RybaObj::udelej_pohyb()
{
	std::cout << "plavu" << "\n";
}

void PtakObj::udelej_pohyb()
{
	std::cout << "litam fr fr" << "\n";
}

PtakObj::PtakObj()
{

}

RybaObj::RybaObj()
{

}

LitaciRybaObj::LitaciRybaObj()
{

}
void LitaciRybaObj::udelej_pohyb()
{
	std::cout << "litam fr fr" << "\n";
}

void LitaciRybaObj::udelej_zvuk()
{
	std::cout << "mlcim" << "\n";
}