#pragma once
class Sigleton {
private:
	Sigleton();//Konstruktor d�me do private
	static Sigleton* instance;
protected:
public:
	static Sigleton*getInstance();
};