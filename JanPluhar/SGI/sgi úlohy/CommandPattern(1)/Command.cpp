#pragma once

#include "Command.h"

Command::~Command() {}


SimpleCommand::SimpleCommand(std::string _message) : message(_message) {}
void SimpleCommand::Execute() const {
		std::cout << "SimpleCommand:  {" << this->message << "}\n";
}


void Receiver::DoSomething(const std::string &a) {
		std::cout << "Receiver: Working on {" << a << ".}\n";
}
void Receiver::DoSomethingElse(const std::string &b) {
		std::cout << "Receiver: Also working on {" << b << ".}\n";
}


ComplexCommand::ComplexCommand(Receiver *receiver, std::string a, std::string b) : receiver_(receiver), a_(a), b_(b) {}

void ComplexCommand::Execute() const {
		std::cout << "ComplexCommand: Complex stuff should be done by a receiver object.\n";
		this->receiver_->DoSomething(this->a_);
		this->receiver_->DoSomethingElse(this->b_);
}


Invoker::~Invoker() {
	std::cout << "Bye Bye Commands.\n";
	std::list<Command *>::iterator iterator = commands.begin();
	while (iterator != commands.end()) {
		delete *iterator;
		++iterator;
	}
}

void Invoker::AddCommand(Command *_command) {
	commands.push_back(_command);
}

void Invoker::DoCommands() {
	std::cout << "Lets do the jobs ...\n";
	std::list<Command *>::iterator iterator = commands.begin();
	while (iterator != commands.end()) {
		(*iterator)->Execute();
		++iterator;
	}
}

