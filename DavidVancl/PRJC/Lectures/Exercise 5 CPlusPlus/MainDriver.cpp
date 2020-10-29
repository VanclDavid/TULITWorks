#include "Pumpkin.h"
using namespace std;

int main(){
	Pumpkin p(20), p2(5);
	p.print();
	p.printTotal();

	p2.print();
	p2.printTotal();

	Pumpkin* p3;
	p3 = new Pumpkin(15);
	p3->print();
	p3->printTotal();

	delete(p3);

	Pumpkin::printTotal();

	cin.get();
	return 0;
}