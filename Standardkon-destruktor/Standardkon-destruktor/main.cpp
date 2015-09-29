// STANDARDKONSRUKTOR UND STANDARDDESTRUKTOR

#include <iostream>

class Test
{
public:
	void ping ();
	//Test(); // Wenn alles Auskommentierungen aufgehoben werden, dann werden spezielle Kon- & Destruktoren genutzt
	//~Test();
};

/*Test::Test()
{
	std::cout << "constructed" << std::endl;
}

Test::~Test()
{
	std::cout << "destructed" << std::endl;
}*/

void Test::ping()
	 { std::cout << "pong" << std::endl; }

int main(void)
{
	Test* TestObject = new Test;
	TestObject->ping();
	delete TestObject;
	getchar();

	Test TestObject2;
	TestObject2.ping();
	getchar();
}