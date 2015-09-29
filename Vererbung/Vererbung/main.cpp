// VERERBUNG

#include <iostream>

class Baseclass
{
public:
	virtual void talk(){std::cout << "Baseclass" << std::endl;}
};

class DerivedClass : public Baseclass
{
	public:
	// void talk(){std::cout << "Derivedclass" << std::endl;}
};

int main(void)
{
	Baseclass BO;
	BO.talk();

	DerivedClass DO;
	DO.talk();

	getchar();
}