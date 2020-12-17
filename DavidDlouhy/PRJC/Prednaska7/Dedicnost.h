#pragma once
/*
// je o dost komplikovanìjší než v JAVA
class Parent {
private:
	int pa;
protected:
	int procetc;
public:
	int x;
	int y;
	Parent();
	Parent(int _x, int _y);
	~Parent();
};
//public = tak jako bylo v otci
class Child : public /*public private protected*/ /*Parent {
private:
	Parent::x;//tady už není ´public jako v otci, ale je privatnís
public:
	Parent::procetc;
	int z;
	Child();
	Child(int _x, int _y);
	Child(int _x, int _y, int _z);/*více konstruktorù = pøetížení konsruktoru*/
	/*~Child();
};
*/ 
class Parent_1 {
public:
	int a;
};
class Parent_2 {
public:
	int b;
};
//vícenásobná dìdiènost <- v Java je podobné interaface
class Child_1 :public virtual Parent_1 { // virtual znamená, že zaène tøídat bobtnat a dìdíme hodnì a na ty zdììné vìci nnám staèí reference a nepotøebujeme kopie
public:
	int c;
	int f();
};

class Child_2 :public Parent_2, public Child_1 {
public:
	int c;
	int f();
};