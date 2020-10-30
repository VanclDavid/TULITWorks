#pragma once
#include <iostream>
class Pumpkin {
private:
	int weight;
	static int totalWeight;
	static int totalCount;
protected:

public:
	Pumpkin(int weight);
	void print();
	static void printTotal();

	void change(Pumpkin&);

	~Pumpkin();
};