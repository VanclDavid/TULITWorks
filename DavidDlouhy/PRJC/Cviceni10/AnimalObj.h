#pragma once
//Dìiènost
//- do listu dáme
// - jsou konkrétní metody
//zvíøe -> pohyb(èistì Virtuální), zvuk(èistì virtuální)
//ryba ->zvíøe
class AnimalObj {
public:
	virtual void udelej_zvuk()=0;
	virtual void udelej_pohyb()=0;
};

class PtakObj : public AnimalObj {
public:
	PtakObj();
	void udelej_pohyb();
	void udelej_zvuk();
	~PtakObj();
};

class RybaObj: public AnimalObj {
public:
	RybaObj();
	void udelej_pohyb();
	void udelej_zvuk();
	~RybaObj();
};

class LitaciRybaObj :public AnimalObj {
public:
	LitaciRybaObj();
	void udelej_pohyb();
	void udelej_zvuk();
	~LitaciRybaObj();
};