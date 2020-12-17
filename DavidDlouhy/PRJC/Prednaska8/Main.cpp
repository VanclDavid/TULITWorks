#include "Command.h"
int main()
{
	//bez polymorfimsmu to je nesmysl
	//pužijeme nìco jako šablonu = virtuální metoda
	//e dùležité se umìt nauèit pracovat s externími tídami kteríé už nìdko napsal
	Invoker* invoker = new Invoker;
	invoker->addCommand(new SimpleCommand("Starting jetty..."));//je to pointer proto ->
	invoker->addCommand(new SimpleCommand("Startring db..."));
	invoker->doRunCommands();
	delete invoker;
	std::cin.get();
	return 0;
}