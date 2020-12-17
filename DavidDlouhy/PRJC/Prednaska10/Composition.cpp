#include "Composition.h"
CAxles* CCar::getFront
{
	return front;
}
void CCar::setFront(CAxles* front_)
{
	this->front = front_;
}
CCar::CAxles* getRear;
{
	return rear;
}
void CCar::setRear(CAxles* rear_)
{
	this->rear = rear_;
}
void CCar::setManufacturer(IManufacturer*)
{

}

IManufacturer* getManufacturt();

void setSteering(ISteering* steering);
ISteering* getSteering();


void setDriving(IDriving* driving);
IDriving* getDriving();