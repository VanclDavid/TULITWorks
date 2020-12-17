#include "Observer.h"

IObserver::~IObserver()
{ ; }

int Observer::observer_number = 0;
Observer::Observer() {
	this->number = observer_number;
	observer_number++;
}
//update(const std::string& message_from_subject) { <- špatnì neøekli jsme od koho je !!!
void Observer::update(const std::string& message_from_subject_) {
	//message_from_subject = message_from_subject; nemùžu ztoto udìlát protože konflikt názvù
	//varianta 1 je, že si to pøejmenuju
	//varianta 2 je s this-> pozor došlo k chybì, problém je že v definici bylo virtual + jme neøeki že to je metoda observeru!
	//Variana 2 jee nebezpeèná na pøepis
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

//pøi prvním spuštìní to nic neudìlalo, objekty nevìdìly o subjectu
void clientCode()
{
	Subject* subject = new Subject();
	Observer* ob1 = new Observer();
	subject->attach(ob1);
	Observer* ob2 = new Observer();
	subject->attach(ob2);
	Observer* ob3 = new Observer();
	subject->attach(ob3);
	//takto nemùže zùstat! mùže obsahovat cokoliv, ne NULL!!!
	//Observer* ob4; 
	//nicménì to stejnì logicky ss NULL nejde
	//Observer* ob4 = NULL;
	Observer* ob4 = new Observer();
	subject->attach(ob4);
	//alternativa
	Observer ob5;
	subject->attach(&ob5);
	//Funguje nám i pøidávání dlašího kódu
	Subject* subject2 = new Subject();
	subject2->attach(ob1);
	subject2->attach(ob2);


	subject->newMessage("Message 1, hello");
	subject->detach(ob2);
	subject->newMessage("Message 2, end");
	//musíme vžy mazat!!! Pøemýšlet co se musí smazat první
	delete ob1;
	delete ob2;
	delete ob3;
	delete ob4;
	//To vlastnì úplnì tak jendoduše samzat jistì nejde
	//delete &ob5;
	delete subject;
	delete subject2;
}