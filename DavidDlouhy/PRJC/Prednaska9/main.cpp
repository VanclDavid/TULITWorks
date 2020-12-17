//Ukážeme si návrrhový vzro který reaguje na zmìny
//Máme Subject (to je cokoliv co generuje data - fórum)

/*
- na to jsou napojení klienti (pøidání zprávy)
- dojde-li ke zmìnì dojde k informování klientù (odeslání notifikace)
- máme tedy Subjject, Client a nìajou realizaci vazby
- v klientu je instance Subejctu a klient se ptá
- nebo v Subjectu máme list klientù kterým posílám informace pøi zmenì a to je rozhodnì lepší

- observer je ten co je povìšený a poslouchá

*/

#include "Observer.h"
int main()
{
	clientCode();
	
	return 0;
}