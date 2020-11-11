#include <iostream>
#include "Pumpkin.h"

//uinicializace orom�nn�ch
int Pumpkin::total_count=0;
int Pumpkin::total_weight = 0;

void Pumpkin::change(Pumpkin &pumpkin){pumpkin.weight=0;}

//kostruktorr
//::��k� �e tady je t��da a ta m� v sob� n�jak� metody
//pat�� ke t��d� => ::
Pumpkin::Pumpkin(int _weight)
{
	if(_weight>=0){
	this->weight = _weight;
	total_count++;
	total_weight+=_weight;
	}
}

void Pumpkin::print()
{
	std::cout << "This one weights " << this->weight << std::endl;
}

void Pumpkin::print_total()
{
	std::cout << "Total weight is " << total_weight << std::endl << "Total count is " << total_count << std::endl;
}

Pumpkin::~Pumpkin()
{
	std::cout << "Dest call" << std::endl;
	total_count--;
	total_weight -= this->weight;
}