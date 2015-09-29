// PRAKTIKUM 5

#include "GeneralDevice.h"
#include <iostream>





class Coffeemachine : public GeneralDevice
{
public:
	virtual Coffeemachine& operator++();
	virtual Coffeemachine& operator--();

	int numberOfCups;
	Coffeemachine(string);
	~Coffeemachine();
private:
	string devicename;
	virtual string toString();
};