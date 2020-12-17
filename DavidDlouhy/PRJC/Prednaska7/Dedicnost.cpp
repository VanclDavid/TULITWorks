#include "Dedicnost.h"
#include <iostream>
using namespace std;
/*/
Parent::Parent()
{
	cout << "Parent()" << endl;
}
Parent::Parent(int _x, int _y) :x(_x), y(_y)
{
	cout << "Parent(x,y)" << _x << _y << endl;
}
Parent::~Parent()
{
	cout << "delete par" << endl;
}
Child::Child():z(0)
{
	this->procetc = 10;
}
Child::Child(int _x, int _y, int _z):z(_z*10), Parent(_x, _y) //takto se dìdí
{

}
Child::~Child()
{
	cout << "delete child" << endl;
}
*/

int Child_1::f()
{
	cout << this->f() << " " << this->a << " " << this->c << endl;
	return c;
}

int Child_2::f()
{
	//cout << this->f() << " " << this->a << " " << this->c << endl;
	Child_1:f();
	cout << "XXX" << endl;
	return Child_1::c;
}