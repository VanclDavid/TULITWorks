#pragma once
//Nadøazená tøída
//chceme aby naše tøídy byl flexibilní, proto je skládáme z tøeba pìti tøíd (5 otcù)
//imolementace se dá nafixovat aby to vracelo null, ale to je nám k nièemu
#include <iostream>
#include <string>
#include <list>
class IObserver {
public:
	virtual void update(const std::string &message_from_subject_) = 0; // nevím co se má stát proto dám virtula (absract)
	//const je, e zprávu nbudeme mìnit, & je reference a šetøíme pamì  jen posíláme referenci
	virtual ~IObserver();//vitual zajistí, e se destruktor zavolá od správné tøídy (od konkrétní instance)
private:
};

//pridano
/*
class IObserver_new {
public:
	virtual void info()=0;
};
*/
//pridano


//implementace observeru

class Observer : public IObserver {
public:
	//virtual void update(const std::string& message_from_subject) = 0;
	Observer();
	//u budeme øíkat co se má stít - není nula
	void update(const std::string& message_from_subject_) override;//overide pøetìujeme - spíše nás upozorní
private:
	std::string message_from_subject;
	//budeme mít více observerù, proto si udìláme poèitatlo - lvastnì jeho ID
	//statickou hodnotu znají všechny instance mezi sebou
	static int observer_number;
	int number;//Toot je ID
};

//
/*
class Observer_new : public IObserver, public IObserver_new {

};*/
//chceme aby mìl jen metody bez datovıch sloek proto si vytvoøím ISubject a pak a dìdící Subject
class ISubject {
public:
	virtual ~ISubject();
	virtual void notify() = 0;
	virtual void attach(Observer* observer) = 0;
	virtual void detach(Observer* observer) = 0;
private:
};

class Subject : public ISubject {
public:
	void notify() override;
	virtual void attach(Observer* observer) override;
	virtual void detach(Observer* observer) override;
	void const newMessage(std::string message_="Empty");// pokud nic nedostane, tak se pouije defaultní hodnota
private:
	std::list<IObserver *> observers;//do <> budeme ukládat Observery ale budeme dávat IObserver
	//hvìzdièka je kvùli polymorfismu
	std::string message;
};

void clientCode();