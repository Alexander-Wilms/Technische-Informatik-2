// POLYMORPHIE BENÖTIGT VERERBUNGSHIERARCHIE, VIRTUELLE FUNKTIONEN; ZEIGER VOM TYP DER BASISKLASSE

#include <iostream>

class Basisklasse
{
public:
	void toString() // Bi Polymorpie ist die basisklasse abstrakt, also müssete hier eigentlich "= 0" stehen
	{
		std::cout << "Basisklasse \n" ;
	}
};

class abgeleiteteKlasse1 : public Basisklasse
{
public:
	void toString()
	{
		std::cout << "abgeleiteteKlasse1 \n" ;
	}
};

class abgeleiteteKlasse2 : public Basisklasse
{
public:
	void toString()
	{
		std::cout << "abgeleiteteKlasse2 \n" ;
	}
};

int main()
{
	Basisklasse BasisklassenObjekt; // Das ginge bei echter Polymorphie nicht
	abgeleiteteKlasse1 abgeleiteteKlasse1Objekt;
	abgeleiteteKlasse2 abgeleiteteKlasse2Objekt;

	Basisklasse* BasisklassePtr;
	abgeleiteteKlasse1* abgeleiteteKlasse1Ptr;
	abgeleiteteKlasse2* abgeleiteteKlasse2Ptr;

	BasisklassePtr = &BasisklassenObjekt; // Das auch nicht
	BasisklassePtr->toString();

	BasisklassePtr = &abgeleiteteKlasse1Objekt; // Das ist echte Polymorphie
	BasisklassePtr->toString();

	BasisklassePtr = &abgeleiteteKlasse2Objekt; // Und das hier
	BasisklassePtr->toString();
	
	// abgeleiteteKlassePtr = &BasisklassenObjekt;
	// Zeiger kann nicht auf Objekt einer höheren Klasse zeigen

	abgeleiteteKlasse1Ptr = &abgeleiteteKlasse1Objekt; // Keine Polymorphie
	abgeleiteteKlasse1Ptr->toString();

	abgeleiteteKlasse2Ptr = &abgeleiteteKlasse2Objekt; // Das auch nicht
	abgeleiteteKlasse2Ptr->toString();

	getchar();
}