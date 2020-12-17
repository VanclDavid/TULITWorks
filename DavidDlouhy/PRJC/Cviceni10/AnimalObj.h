#pragma once
//D�i�nost
//- do listu d�me
// - jsou konkr�tn� metody
//zv��e -> pohyb(�ist� Virtu�ln�), zvuk(�ist� virtu�ln�)
//ryba ->zv��e
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