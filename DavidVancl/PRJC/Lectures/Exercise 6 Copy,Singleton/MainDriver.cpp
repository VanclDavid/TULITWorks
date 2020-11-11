#define _CRT_SECURE_NO_WARNINGS
#include "CopyConstructor.h"
#include <iostream>
#include <process.h>
#include "Singleton.h"

using namespace std;

int main() {
	//ArrayOfInt arrayofint(10);
	//arrayofint.setElement(5, 10);
	//arrayofint.printArray();

	////int i = arrayofint[5];
	//ArrayOfInt arr2(arrayofint);


	Singleton* s = Singleton::getInstance();

	return 0;
}