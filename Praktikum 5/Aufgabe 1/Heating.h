// PRAKTIKUM 5

#include "GeneralDevice.h"
#include <iostream>





class Heating : public GeneralDevice
{
public:
	virtual Heating& operator++();
	virtual Heating& operator--();

	float temperature;
	Heating(string);
	~Heating();
private:
	string devicename;
	virtual string toString();
};