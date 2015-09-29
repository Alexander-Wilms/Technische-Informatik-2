// PRAKTIKUM 5

#include "Radio.h"

Radio::Radio(string input_devicename)
	: devicename(input_devicename), volume(0)
{
	std::cout << "Radio " << devicename << " constructed in subclass" << std::endl;
}

Radio::~Radio()
{
	std::cout << devicename << " destructed in subclass" << std::endl;
}

Radio& Radio::operator++()
{
	volume++;
	return *this;
}

Radio& Radio::operator--()
{
	volume--;
	if(volume < 0)
	{
		volume = 0;
	}
	return *this;
}

string Radio::toString()
{
	stringstream output;
	output << devicename << ": " << volume;
	return output.str();
}

