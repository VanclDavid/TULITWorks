#pragma once
#include <iostream>
#include <string>
#include <list>
class Command {
public:
	//void execute(); //norm�l
	//virtual void execute(); //virtu�ln�
	virtual void execute() const = 0;//�ist� vidtu�ln�, ned� se zavlat zde, ale v potomkovi - const znamen�, �e t��da kter� nemodifikuje nic jin�ho
	//cosnt -> nebude m�nit vlastnosti objektu
	virtual ~Command();//�ist� virtu�ln� to nen� pot�eba, destrutor je pro v�echny stejn� (ni�� ale jen jeden)
};
//��� co by m�li potomci um�t
class SimpleCommand : public Command {
	//u� m�m destruktor
	//pokud si chceme upravit tak mus�me ude�lat p�et�en�
private:
		std::string message;
public:
	SimpleCommand(std::string message_);
	//Ted nadefinujeme execue
	void execute() const override; //��k�me, �e p�et�ujeme
};

class Invoker {
	//chcme n commandu
private:
	//std::list<SimpleCommand> commands; nesmysl
	//std::list<Command> commands;//p�ejdi do pam�ti a n�co ud�laej -> po�ebujeme pointer
	std::list<Command *> commands;//Polymorfismu = pointer
public:
	//std::list<> commands; nemysl pro� t je public
	void addCommand(Command * command_);
	void doRunCommands();
	~Invoker();
};