#include "Singleton.h"
#include <iostream>

Sigleton *Sigleton::instance = NULL;

Sigleton* Sigleton::getInstance()//static tu být nemusí, :: je že je to od té tøídy
{
	if (!instance)//není instance? vytvoøí novou 
	{
		instance = new Sigleton();
	}
	return instance; //vrátí instanci
}

Sigleton::Sigleton(){} //musí být tatto deklarace, je to prázdný konstruktor, který tam musí být když tam je