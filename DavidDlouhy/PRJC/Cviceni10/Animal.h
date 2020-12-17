#pragma once

//KOmpozuce
//- do listu nedáme, ale když pøidáme nadøazenu tøídu, která to obalí, tak funguje
//- je flexibilnìjší na úravy
// - jsou atributy nìjakého typu
//zvuk ->
//Pohyb -> 
//ryba->zvuk, pohyb


class Zvuk {
public:
	virtual void udelej_zvuk()=0;
};

class Zpivej :public Zvuk {
public:
	void udelej_zvuk();
};

class Mlc :public Zvuk {
public:
	void udelej_zvuk();
};

class Pohyb {
public:
	virtual void udelej_pohyb() = 0;
};

class Litej : public Pohyb {
public:
	void udelej_pohyb();
};

class Plavej : public Pohyb {
public:
	void udelej_pohyb();
};

class Animal {
public:
	Zvuk* zvuk;
	Pohyb* pohyb;
};


class Ptak : public Animal {
public:
	Ptak();
	~Ptak();
};


class Ryba : public Animal {
public:
	Ryba();
	~Ryba();
};

class LitaciRyba : public Animal {
public:
	LitaciRyba();
	~LitaciRyba();
};