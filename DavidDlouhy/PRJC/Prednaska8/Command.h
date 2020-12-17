#pragma once
#include <iostream>
#include <string>
#include <list>
class Command {
public:
	//void execute(); //normál
	//virtual void execute(); //virtuální
	virtual void execute() const = 0;//èistì vidtuální, nedá se zavlat zde, ale v potomkovi - const znamená, že tøída která nemodifikuje nic jiného
	//cosnt -> nebude mìnit vlastnosti objektu
	virtual ~Command();//èistì virtuální to není potøeba, destrutor je pro všechny stejný (nièí ale jen jeden)
};
//øíá co by mìli potomci umìt
class SimpleCommand : public Command {
	//už mám destruktor
	//pokud si chceme upravit tak musíme udeìlat pøetížení
private:
		std::string message;
public:
	SimpleCommand(std::string message_);
	//Ted nadefinujeme execue
	void execute() const override; //øíkáme, že pøetìžujeme
};

class Invoker {
	//chcme n commandu
private:
	//std::list<SimpleCommand> commands; nesmysl
	//std::list<Command> commands;//pøejdi do pamìti a nìco udìlaej -> poøebujeme pointer
	std::list<Command *> commands;//Polymorfismu = pointer
public:
	//std::list<> commands; nemysl proè t je public
	void addCommand(Command * command_);
	void doRunCommands();
	~Invoker();
};