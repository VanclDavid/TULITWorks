#include "Template.h"
template<class T>
Element<T>::Element(T _t):data(_t)
{

}
template<class T>
T& Element<T>::getValue()
{
	return data;
}

template<class T>
void Element<T>::plus(T value)
{
	data += value;
}

template<typename K>
K max(K a, K b)
{
	return a > b ? a : b;
}