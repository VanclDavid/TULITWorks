#include "Counter.h"
void counter(int* sum_counter, int* minus_counter,int operation) {
	switch (operation)
	{
	case 1:
		(*sum_counter)++;
		break;
	case 2:
		(*minus_counter)++;
		break;
	}
}