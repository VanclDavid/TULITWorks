#include "Command.h"
int main()
{
	//bez polymorfimsmu to je nesmysl
	//pu�ijeme n�co jako �ablonu = virtu�ln� metoda
	//e d�le�it� se um�t nau�it pracovat s extern�mi t�dami kter�� u� n�dko napsal
	Invoker* invoker = new Invoker;
	invoker->addCommand(new SimpleCommand("Starting jetty..."));//je to pointer proto ->
	invoker->addCommand(new SimpleCommand("Startring db..."));
	invoker->doRunCommands();
	delete invoker;
	std::cin.get();
	return 0;
}