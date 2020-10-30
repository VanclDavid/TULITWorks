#pragma once
class Pumpkin {
//ZDE
	//není tu identifikatro => proto private
//ZDE
private:
	//pouze tato tøída
	int weight;
	static int total_weight;
	static int total_count;
protected:
	//dostupné v této tøídì a v tìch co ji dìdí
public:
	//konstruktor + inicializace, nemá návratový typ => void
	Pumpkin(int _wight);
	//TO jsou spíše konstatnty, velmi málo použitelné
	// volnì pøístupné metody
	void print();
	static void print_total();
	void change(Pumpkin &);//to co zmením zde, tak se provede všude, objekty se pøedávají referencí
	//bool operator==(Pumpkin&);//& je reference
	//destruktor, nemá nikdy parametry
	~Pumpkin();
};