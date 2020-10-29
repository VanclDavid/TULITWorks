#include "Pumpkin.h"
using namespace std;

int Pumpkin::totalCount = 0;
int Pumpkin::totalWeight = 0;

Pumpkin::Pumpkin(int _weight) {
	this->weight = _weight;
	totalCount++;
	totalWeight += _weight;
}

void Pumpkin::print() {
	cout << "Total weight is: " << Pumpkin::weight << endl;
}

void Pumpkin::printTotal() {
	cout << "Total weight is: " << Pumpkin::totalWeight << " Total count is: " << Pumpkin::totalCount << endl;
}

Pumpkin::~Pumpkin() {
	cout << "Dest call" << endl;
	totalCount--;
	totalWeight -= this->weight;
}

void Pumpkin::change(Pumpkin &pumpkin){
	pumpkin.weight = 0;
}