#include "Observer.h"

IObserver::~IObserver()
{ ; }

int Observer::observer_number = 0;
Observer::Observer() {
	this->number = observer_number;
	observer_number++;
}
//update(const std::string& message_from_subject) { <- �patn� ne�ekli jsme od koho je !!!
void Observer::update(const std::string& message_from_subject_) {
	//message_from_subject = message_from_subject; nem��u ztoto ud�l�t proto�e konflikt n�zv�
	//varianta 1 je, �e si to p�ejmenuju
	//varianta 2 je s this-> pozor do�lo k chyb�, probl�m je �e v definici bylo virtual + jme ne�eki �e to je metoda observeru!
	//Variana 2 jee nebezpe�n� na p�epis
	//this->message_from_subject = message_from_subject;
	message_from_subject = message_from_subject_;
	std::cout <<"Observer no."<< number << "New message" << message_from_subject << std::endl;
};

ISubject::~ISubject() {};
void Subject::notify()
{
	std::list<IObserver*>::iterator it = observers.begin();
	while (it!=observers.end())
	{
		(*it)->update(message);
		it++;
	}
}

void const Subject::newMessage(std::string message_)
{
	message = message_;
	notify();
}
void Subject::attach(Observer * observer) {
	observers.push_back(observer);
};
void Subject::detach(Observer* observer) {
	observers.remove(observer);
};

//p�i prvn�m spu�t�n� to nic neud�lalo, objekty nev�d�ly o subjectu
void clientCode()
{
	Subject* subject = new Subject();
	Observer* ob1 = new Observer();
	subject->attach(ob1);
	Observer* ob2 = new Observer();
	subject->attach(ob2);
	Observer* ob3 = new Observer();
	subject->attach(ob3);
	//takto nem��e z�stat! m��e obsahovat cokoliv, ne NULL!!!
	//Observer* ob4; 
	//nicm�n� to stejn� logicky ss NULL nejde
	//Observer* ob4 = NULL;
	Observer* ob4 = new Observer();
	subject->attach(ob4);
	//alternativa
	Observer ob5;
	subject->attach(&ob5);
	//Funguje n�m i p�id�v�n� dla��ho k�du
	Subject* subject2 = new Subject();
	subject2->attach(ob1);
	subject2->attach(ob2);


	subject->newMessage("Message 1, hello");
	subject->detach(ob2);
	subject->newMessage("Message 2, end");
	//mus�me v�y mazat!!! P�em��let co se mus� smazat prvn�
	delete ob1;
	delete ob2;
	delete ob3;
	delete ob4;
	//To vlastn� �pln� tak jendodu�e samzat jist� nejde
	//delete &ob5;
	delete subject;
	delete subject2;
}