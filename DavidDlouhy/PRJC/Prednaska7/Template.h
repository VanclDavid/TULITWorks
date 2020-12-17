#pragma once
// rùzné datové typy = K
//K bude také návratová hodnota
template<class T>
class Element {
private:
	T data;
public:
	Element(T _t);
	T& getValue();//& šetøíme místo protože dìláme referenci
	void plus(T value);
};


template<typename K>K max(K a, K b);//deklarace