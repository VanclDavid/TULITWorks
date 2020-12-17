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
	//Refactoring je d�le�it� ��st
	//k�d je pot�eba upravit (napravujeme napravit nepo��dek p�i sp�ch�n�)
	//Sna��me se dos�hnout �ist�ho k�du
	//-p�e�te ho i jin� program�tor
	//-neobsahuje duplicity - kop�rov�n�
	//-minim�ln� o�et ��d a dal��ch ��st�
	//-V�echny testy projdou
	//-k�d tedy udr�ujeme na pohodi�ku
	//Ne�it k�d p�eme proto, �e m�me tlak zadavatele, ned�le�itost a nepochopen� refactoringu,
	//D�l�me syst�m po mal�ch kosc�ch lega ne jako monolit
	//nedodstatek test�, dokumentac� a komunikace
	// V gitu si d�t pozor na to, aby se pracovalo tk, �e vememe mal� v�ve a ty mergujeme
	//V�t�inou si k�d tak jako ta prjdeme , vr�t�me se a refaktorujeme
	
	//bloaters - dlouh� metody a t��dy, spatn� se hledaj� chyby a h��e se vyzn�me, moc pou��v�me �primitivn� datov� typy, dlouh� seznam parametr�
	//Object-rientation Abuseres - moc switch�, nesm� se stat to, �e d�d�me od otce, ale v�e to co d�d�me nepo�tebujeme
	//Change prevents 
	//Dispensables - zbyte�nosti v k=odu, ��sti, kter� ani nepot�ebujeme + to sam� obohacen� o to �e se je�t� o to zbyte�n� star�me
	//Couplers - spoj� se n�m to �o necheme, kupl��i, dv�t�idy si po��vaj� data jak cht�j�, ale ne jak chceme my, 

	//Jak refaktorovat???
	/*
	Probl�m - k�d kter� obashuje v�ce funk�nost�
	- rozd�l�me na funce

	- je tobr� si zjendu�it if tak, �e si ud�l�me booleancy jako prom�nn� kter� se mi vyhodnot� a a� ty pak dosad�m do ifu
	- nemus�me vytv��et ve funkci zbyte�n� nov� double, sta�� ho jen prost� rovnou hned vr�tit
	- m�sto n�ajk�ho vyo��t�v�n�, ud�l�me pouze vr�cen� + funkci a vlastn� to v�bec nikam nemus�me ulo�it
	- nem�chat do sebe 2 r�zn� prom�nn�, nap��klad ukl�d�m si 2 v�po�ty do stejn�ho tempu -> to nechceme
	*/
	//Vl�kna
	//deadlock=nap��klad echceme aby do jedn� metody sahalo najednou v�ce vl�ken, p��klad 2 lidi kabinka se zachodem a s duh� s pap�rem, jeden chce 
	//na z�chod a m� pap�r, druh� chce pap�r, ale je na z�chdo� a oba jsou zam�en� -> deadlock


	raceConditionLocks();
	//std::cin.get();
	return 0;
}