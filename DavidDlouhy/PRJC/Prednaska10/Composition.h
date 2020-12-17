#pragma once
#include <string>

class CAxles {
private:
	std::string name;
public:
	CAxles(std::string name_) :name(name_) {}
	void turnLeft(int degree);
	void turnRight(int degree);
	void rotate(int kms);
};

class ISteering {//nìvo jako interface
	virtual void trunLeft(int degrees) = 0;
	virtual void trunRight(int degrees) = 0;
};

class IDriving {
public:
	virtual void accelerate(int kms) = 0;
};

class IManufacturer {
public:
	virtual std::string getManufacturer() = 0;
};

class CCar {
private:
	CAxles* front;
	CAxles* rear;

	IManufacturer* manufacturer;
	ISteering* steering;
	IDriving* driving;
public:
	CAxles* getFront;
	void setFront(CAxles* front_);
	CAxles* getRear;
	void setRear(CAxles* rear_);
	void setManufacturer(IManufacturer*);
	IManufacturer* getManufacturt();

	void setSteering(ISteering*steering);
	ISteering* getSteering();


	void setDriving(IDriving* driving);
	IDriving* getDriving();


};

class FrontWheelDrive :public IDriving {
	void accelerate(int kms) override;
};

class ReartWheelDrive :public IDriving {
	virtual void tunrLeft(int degree) override;
	virtual void tunRight(int degree) override;
};

//všechno jsem nestihnul opsat, ale je to v záznamu