// VIRTUELLE FUNKTIONEN

#include <iostream>

class Basisklasse
{
public:
	virtual void virtualPrint()
	{
		std::cout << "virtual Basisklasse \n";
	}
	void print()
	{
		std::cout << "original Basisklasse \n";
	}
};

class AbgeleiteteKlasse : public Basisklasse
{
public:
	virtual void virtualPrint()
	{
		std::cout << "virtual AbgeleiteteKlasse \n";
	}
	void print()
	{
		std::cout << "override AbgeleiteteKlasse \n";
	}
};

int main()
{
	Basisklasse* Objekt;

	Objekt = new Basisklasse;
	Objekt->print();
	Objekt->virtualPrint();

	Objekt = new AbgeleiteteKlasse;
	Objekt->print(); // es wird die print-Methode der Basisklasse aufgerufen
	Objekt->virtualPrint();

	getchar();
}

/* Ausgabe:

original Basisklasse
virtual Basisklasse
original Basisklasse
virtual AbgeleiteteKlasse

*/