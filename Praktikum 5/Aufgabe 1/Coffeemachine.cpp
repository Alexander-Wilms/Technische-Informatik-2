// PRAKTIKUM 5

#include "Coffeemachine.h"

Coffeemachine::Coffeemachine(string input_devicename)
	: devicename(input_devicename), numberOfCups(0)
{
	std::cout << devicename << " constructed in subclass" << std::endl;
}

Coffeemachine::~Coffeemachine()
{
	std::cout << "Coffeemachine " << devicename << " destructed in subclass" << std::endl;
}

Coffeemachine& Coffeemachine::operator++()
{
	numberOfCups++;
	return *this;
}

Coffeemachine& Coffeemachine::operator--()
{
	numberOfCups--;
	if(numberOfCups < 0)
	{
		numberOfCups = 0;
	}
	return *this;
}

string Coffeemachine::toString()
{
	stringstream output;
	output << devicename << ": " << numberOfCups;
	return output.str();
}

