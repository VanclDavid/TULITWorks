#pragma once
// r�zn� datov� typy = K
//K bude tak� n�vratov� hodnota
template<class T>
class Element {
private:
	T data;
public:
	Element(T _t);
	T& getValue();//& �et��me m�sto proto�e d�l�me referenci
	void plus(T value);
};


template<typename K>K max(K a, K b);//deklarace