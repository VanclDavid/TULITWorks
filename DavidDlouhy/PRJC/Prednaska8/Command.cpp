#include "Command.h"
Command::~Command()
{
	;
}

SimpleCommand::SimpleCommand(std::string message_) :message(message_)
{
	;//byl by tu t�eba v�pis na obrazovku
}

void SimpleCommand::execute() const {
	std::cout << "SimpleCommand: {" << "}"<<std::endl;
}

void Invoker::addCommand(Command* command_) {
	commands.push_back(command_);//vlo�� na konec seznamu
}

void Invoker::doRunCommands()
{
	std::cout << "Do run commands..." << std::endl;
	std::list<Command*>::iterator iterator = commands.begin();//iterov�n� listu
	while (iterator != commands.end())
	{
		(*iterator)->execute();
		++iterator;
	}
}
Invoker::~Invoker()
{
	std::cout << "Bye, bye commands..." << std::endl;
	std::list<Command*>::iterator iterator = commands.begin();//iterov�n� listu
	while (iterator != commands.end())
	{
		delete((*iterator));
		++iterator;
	}
 }