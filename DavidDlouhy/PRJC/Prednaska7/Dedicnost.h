#pragma once
/*
// je o dost komplikovan�j�� ne� v JAVA
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
	Parent::x;//tady u� nen� �public jako v otci, ale je privatn�s
public:
	Parent::procetc;
	int z;
	Child();
	Child(int _x, int _y);
	Child(int _x, int _y, int _z);/*v�ce konstruktor� = p�et�en� konsruktoru*/
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
//v�cen�sobn� d�di�nost <- v Java je podobn� interaface
class Child_1 :public virtual Parent_1 { // virtual znamen�, �e za�ne t��dat bobtnat a d�d�me hodn� a na ty zd��n� v�ci nn�m sta�� reference a nepot�ebujeme kopie
public:
	int c;
	int f();
};

class Child_2 :public Parent_2, public Child_1 {
public:
	int c;
	int f();
};