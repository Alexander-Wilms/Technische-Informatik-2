// PRAKTIKUM 5

#include "GeneralDevice.h"
#include <iostream>





class Radio : public GeneralDevice
{
public:
	virtual Radio& operator++();
	virtual Radio& operator--();

	double volume;
	Radio(string);
	~Radio();
private:
	string devicename;
	virtual string toString();
};