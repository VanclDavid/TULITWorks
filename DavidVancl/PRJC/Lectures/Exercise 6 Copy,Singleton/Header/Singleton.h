#pragma once

class Singleton {
private:
	Singleton();
	static Singleton* instance;
protected:
public:
	static Singleton* getInstance();
};