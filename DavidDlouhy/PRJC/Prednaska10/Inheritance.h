#pragma once
#include <iostream>
#include <string>
//dìláme Toyota Corolla

class Axles {
private:
	std::string name;
public:
	Axles(std::string name_):name(name_){}
	void turnLeft(int degree);
	void turnRight(int degree);
	void rotate(int kms);
};

class Car {
private:
	
	Axles *front;
	Axles *rear;
public:
	void setFront(Axles* front);
	void setRear(Axles* rear);
	Axles* getFront();
	Axles* getRear();
	//void setManufacturer(std::string manufacturer_);
	virtual std::string getManufacturer()=0;

	void accelerate(int kms);
	void turnLeft(int degrees);
	void turnRight(int degrees);

	~Car();
};

class ToyotaCorolla:public FrontWheelDrive
{
public:
	std::string getManufacturer() override;

private:

};
//toyota corola sports má náhon na zadní nápravu

class ToyotaCorollaSports :public RearWheelDrive {
public:
	std::string getManufacturer() override;
	void accelerate(int kms);
};

class FrontWheelDrive:public Car {

};

class RearWheelDrive:public Car {

};

class AWDrive :public Car {

};

class HondaCivic : public FrontWheelDrive
{
public:
	std::string getManufacturer() override;
};

class AWDToyota : public AWDrive
{

};
