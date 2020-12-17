#pragma once
class Sigleton {
private:
	Sigleton();//Konstruktor dáme do private
	static Sigleton* instance;
protected:
public:
	static Sigleton*getInstance();
};