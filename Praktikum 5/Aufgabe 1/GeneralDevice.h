// PRAKTIKUM 5

#ifndef GD
#define GD
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class GeneralDevice
{
public:
	virtual GeneralDevice& operator++() = 0; // Muss in abgel. Klasse implementiert werden
	virtual GeneralDevice& operator--() = 0; // Muss in abgel. Klasse implementiert werden
	friend ostream& operator<<(ostream&, GeneralDevice&); // friend Funktion nur in der Basisklasse; greift auf virtuelle toString-Funktion zurück
	virtual ~GeneralDevice(){ std::cout << "GeneralDevice " << devicename << " destructed in baseclass" << std::endl;} // Virtual, damit spezielle Destruktoren aufgerufen werden
private:
	string devicename;
	virtual string toString() = 0; // Warum virtual?
};

#endif // GD