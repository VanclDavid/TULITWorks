#include "Inheritance.h"
int main()
{
	ToyotaCorolla *tc;
	Axles* front = new Axles("Front");
	Axles* rear = new Axles("Rear");
	tc->setFront(front);
	tc->setRear(rear);
	tc->accelerate(100);
	tc->turnRight(10);
	std:: cout<<tc->getManufacturer()<<std::endl;
	delete tc;
	std::cin.get();
	return 0;
}