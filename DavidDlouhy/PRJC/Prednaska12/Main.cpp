#include <iostream>
#include <thread>
#include <mutex>

class RaceCondition {
public:
	int n;
	RaceCondition() :n(0) {};
	void inc() {
		++n;
	}
};

void raceCondition() {
	RaceCondition racer;
	std::thread t1([&racer] {
		for (int i = 0; i < 100000; i++)
		{
			racer.inc();
		}
		});
	std::thread t2([&racer] {
		for (int i = 0; i < 100000; i++)
		{
			racer.inc();
		}
		});
	t1.join();
	t2.join();
	std::cout << racer.n << std::endl;
}

//locks

class RaceConditionLocks
{
public:
	int n;
	std::mutex mutex;
	RaceConditionLocks() :n(0) {};
	void inc() {
		std::lock_guard<std::mutex> lock(mutex);
		++n;
	}

};
void raceConditionLocks() {
	RaceConditionLocks racer;
	std::thread t1([&racer] {
		for (int i = 0; i < 100000; i++)
		{
			racer.inc();
		}
		});
	std::thread t2([&racer] {
		for (int i = 0; i < 100000; i++)
		{
			racer.inc();
		}
		});
	t1.join();
	t2.join();
	std::cout << racer.n << std::endl;
}

int main()
{
	//Refactoring je dùležitá èást
	//kód je potøeba upravit (napravujeme napravit nepoøádek pøi spìchání)
	//Snažíme se dosáhnout èistého kódu
	//-pøeète ho i jiný programátor
	//-neobsahuje duplicity - kopírování
	//-minimální oèet øíd a dalších èástí
	//-Všechny testy projdou
	//-kód tedy udržujeme na pohodièku
	//Neèit kód píšeme proto, že máme tlak zadavatele, nedùležitost a nepochopení refactoringu,
	//Dìláme systém po malých koscích lega ne jako monolit
	//nedodstatek testù, dokumentací a komunikace
	// V gitu si dát pozor na to, aby se pracovalo tk, že vememe malé vìve a ty mergujeme
	//Vìtšinou si kód tak jako ta prjdeme , vrátíme se a refaktorujeme
	
	//bloaters - dlouhé metody a tøídy, spatnì se hledají chyby a hùøe se vyznáme, moc používáme ´primitivní datové typy, dlouhý seznam parametrù
	//Object-rientation Abuseres - moc switchù, nesmí se stat to, že dìdíme od otce, ale vše to co dìdíme nepoøtebujeme
	//Change prevents 
	//Dispensables - zbyteènosti v k=odu, èásti, které ani nepotøebujeme + to samé obohacené o to že se ještì o to zbyteènì staráme
	//Couplers - spojí se nám to æo necheme, kuplíøi, dvìtøidy si požívají data jak chtìjí, ale ne jak chceme my, 

	//Jak refaktorovat???
	/*
	Problém - kód který obashuje více funkèností
	- rozdìlíme na funce

	- je tobré si zjendušit if tak, že si udìláme booleancy jako promìnné které se mi vyhodnotí a až ty pak dosadím do ifu
	- nemusíme vytváøet ve funkci zbyteènì nový double, staèí ho jen prostì rovnou hned vrátit
	- místo nìajkého vyoèítávání, udìláme pouze vrácení + funkci a vlastnì to vùbec nikam nemusíme uložit
	- nemíchat do sebe 2 rùzné promìnné, napøíklad ukládám si 2 výpoèty do stejného tempu -> to nechceme
	*/
	//Vlákna
	//deadlock=napøíklad echceme aby do jedné metody sahalo najednou více vláken, pøíklad 2 lidi kabinka se zachodem a s duhá s papírem, jeden chce 
	//na záchod a má papír, druhý chce papír, ale je na záchdoì a oba jsou zamèení -> deadlock


	raceConditionLocks();
	//std::cin.get();
	return 0;
}