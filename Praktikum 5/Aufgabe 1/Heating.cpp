// PRAKTIKUM 5

#include "Heating.h"

Heating::Heating(string input_devicename)
	: devicename(input_devicename), temperature(0)
{
	std::cout << devicename << " constructed in subclass" << std::endl;
}

Heating::~Heating()
{
	std::cout << "Heating " << devicename << " destructed in subclass" << std::endl;
}

Heating& Heating::operator++()
{
	temperature++;
	return *this;
}

Heating& Heating::operator--()
{
	temperature--;
	if(temperature < 0)
	{
		temperature = 0;
	}
	return *this;
}

string Heating::toString()
{
	stringstream output;
	output << devicename << ": " << temperature;
	return output.str();
}

