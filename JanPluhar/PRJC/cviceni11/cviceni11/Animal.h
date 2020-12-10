#pragma once
class Animal {
public:
	Animal();

};
class Imove {

};
class Isound {

};
class swim : Imove {

};
class fish : public Animal {
public:
	Imove swim;
};