#include "Singleton.h"
#include <iostream>

Sigleton *Sigleton::instance = NULL;

Sigleton* Sigleton::getInstance()//static tu b�t nemus�, :: je �e je to od t� t��dy
{
	if (!instance)//nen� instance? vytvo�� novou 
	{
		instance = new Sigleton();
	}
	return instance; //vr�t� instanci
}

Sigleton::Sigleton(){} //mus� b�t tatto deklarace, je to pr�zdn� konstruktor, kter� tam mus� b�t kdy� tam je