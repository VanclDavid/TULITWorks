#pragma once
class Pumpkin {
//ZDE
	//nen� tu identifikatro => proto private
//ZDE
private:
	//pouze tato t��da
	int weight;
	static int total_weight;
	static int total_count;
protected:
	//dostupn� v t�to t��d� a v t�ch co ji d�d�
public:
	//konstruktor + inicializace, nem� n�vratov� typ => void
	Pumpkin(int _wight);
	//TO jsou sp�e konstatnty, velmi m�lo pou�iteln�
	// voln� p��stupn� metody
	void print();
	static void print_total();
	void change(Pumpkin &);//to co zmen�m zde, tak se provede v�ude, objekty se p�ed�vaj� referenc�
	//bool operator==(Pumpkin&);//& je reference
	//destruktor, nem� nikdy parametry
	~Pumpkin();
};