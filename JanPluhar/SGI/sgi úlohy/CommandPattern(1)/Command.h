#pragma once

#include <iostream>
#include <list>
#include <string>

/**
 * The Command interface declares a method for executing a command.
 */
class Command {
public:
	virtual ~Command();
	/*
	The const member functions are the functions which are declared as constant in the program. 
	The object called by these functions cannot be modified. 
	It is recommended to use const keyword so that accidental changes to object are avoided.
	 if you have a const function, all that means is that it guarantees it won't change the object. So just because it is const doesn't mean that non-const objects can't use it.

	As a matter of fact, const functions have a slightly stronger restriction than merely that they cannot modify the data. 
	They must make it so that they cannot be used in a way that would allow you to use them to modify const data. 
	This means that when const functions return references or pointers to members of the class, they must also be const.
	*/
	virtual void Execute() const = 0; 
};
/**
 * Some commands can implement simple operations on their own.
 */
class SimpleCommand : public Command {
private:
	std::string message;

public:
	explicit SimpleCommand(std::string _message);
	void Execute() const override;
};

/**
 * The Receiver classes contain some important business logic. They know how to
 * perform all kinds of operations, associated with carrying out a request. In
 * fact, any class may serve as a Receiver.
 */
class Receiver {
public:
	void DoSomething(const std::string &a);
	void DoSomethingElse(const std::string &b);
};

/**
 * However, some commands can delegate more complex operations to other objects,
 * called "receivers."
 */
class ComplexCommand : public Command {
	/**
	 * @var Receiver
	 */
private:
	Receiver *receiver_;
	/**
	 * Context data, required for launching the receiver's methods.
	 */
	std::string a_;
	std::string b_;
	/**
	 * Complex commands can accept one or several receiver objects along with any
	 * context data via the constructor.
	 */
public:
	ComplexCommand(Receiver *receiver, std::string a, std::string b);
	/**
	 * Commands can delegate to any methods of a receiver.
	 */
	void Execute() const override;
};

/**
 * The Invoker is associated with one or several commands. It sends a request to
 * the command.
 */
class Invoker {
	/**
	 * @var Command
	 */
private:
	/*
	Command *command;
	*/
	std::list<Command *> commands;
	/**
	 * @var Command
	 */
public:
	~Invoker();

	void AddCommand(Command *command);
	/**
	 * The Invoker does not depend on concrete command or receiver classes. The
	 * Invoker passes a request to a receiver indirectly, by executing a command.
	 */
	void DoCommands();
};
