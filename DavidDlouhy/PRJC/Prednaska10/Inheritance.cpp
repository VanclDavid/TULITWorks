#include "Inheritance.h"
void Axles::turnLeft(int degree)
{
	std::cout << name << " turning left " << degree<<std::endl;
}
void Axles::turnRight(int degree)
{
	std::cout << name << " turning right " << degree << std::endl;
}
void Axles::rotate(int kms)
{
	std::cout << name << " rotating " << kms << std::endl;
}

void Car::setFront(Axles* front_)
{
	this->front = front_;
}
void Car::setRear(Axles* rear_)
{
	this->rear = rear_;
}

Axles* Car::getFront()
{
	return front;
}
Axles* Car::getRear()
{
	return rear;
}

void Car::accelerate(int kms)
{
	this->front->rotate(kms);
}
void Car::turnLeft(int degrees)
{
	this->front->turnLeft(degrees);
}
void Car::turnRight(int degrees)
{
	this->front->turnRight(degrees);
}

Car::~Car()
{
	delete this->front;
	delete this->rear;
}

std::string ToyotaCorolla::getManufacturer()
{
	return "Toyota Corolla";
}

void ToyotaCorollaSports::accelerate(int kms)
{
	this->getRear()->rotate(kms);
}