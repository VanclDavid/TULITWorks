#pragma once
//Nad�azen� t��da
//chceme aby na�e t��dy byl flexibiln�, proto je skl�d�me z t�eba p�ti t��d (5 otc�)
//imolementace se d� nafixovat aby to vracelo null, ale to je n�m k ni�emu
#include <iostream>
#include <string>
#include <list>
class IObserver {
public:
	virtual void update(const std::string &message_from_subject_) = 0; // nev�m co se m� st�t proto d�m virtula (absract)
	//const je, �e zpr�vu nbudeme m�nit, & je reference a �et��me pam�  jen pos�l�me referenci
	virtual ~IObserver();//vitual zajist�, �e se destruktor zavol� od spr�vn� t��dy (od konkr�tn� instance)
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
	//u� budeme ��kat co se m� st�t - nen� nula
	void update(const std::string& message_from_subject_) override;//overide p�et�ujeme - sp�e n�s upozorn�
private:
	std::string message_from_subject;
	//budeme m�t v�ce observer�, proto si ud�l�me po�itatlo - lvastn� jeho ID
	//statickou hodnotu znaj� v�echny instance mezi sebou
	static int observer_number;
	int number;//Toot je ID
};

//
/*
class Observer_new : public IObserver, public IObserver_new {

};*/
//chceme aby m�l jen metody bez datov�ch slo�ek proto si vytvo��m ISubject a pak a� d�d�c� Subject
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
	void const newMessage(std::string message_="Empty");// pokud nic nedostane, tak se pou�ije defaultn� hodnota
private:
	std::list<IObserver *> observers;//do <> budeme ukl�dat Observery ale budeme d�vat IObserver
	//hv�zdi�ka je kv�li polymorfismu
	std::string message;
};

void clientCode();