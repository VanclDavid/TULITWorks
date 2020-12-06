#include "Command.h"
/**
 * The client code can parameterize an invoker with any commands.
 */

int main() {
	Invoker *invoker = new Invoker;
	std::string s("Say Hi!");
	invoker->AddCommand(new SimpleCommand("Starting DB ..."));
	invoker->AddCommand(new SimpleCommand("Starting jetty..."));
	Receiver *receiver = new Receiver;
	invoker->AddCommand(new ComplexCommand(receiver, "Send email", "Save report"));
	
	invoker->DoCommands();

	delete invoker;
	delete receiver;

	std::cin.get();
	return 0;
}