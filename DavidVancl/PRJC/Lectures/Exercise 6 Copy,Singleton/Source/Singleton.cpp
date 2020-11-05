#include "Singleton.h"
#include <iostream>

Singleton* Singleton::instance = NULL;

Singleton * Singleton::getInstance() {
	if (!instance) {
		instance = new Singleton();
	}
	return instance;
}

Singleton::Singleton() {}