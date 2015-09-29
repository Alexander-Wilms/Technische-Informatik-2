// KOMPOSITION

#include <iostream>

class inner
{
public:
	inner(){ std::cout << "inner constructed" << std::endl;}
};

class outer
{
public:
	//outer():innerObject(){ std::cout << "outer constructed" << std::endl; }
	outer(){ std::cout << "outer constructed" << std::endl; inner innerObject;}
private:
	inner innerObject;
};

int main(void)
{
	outer outerObject;
	getchar();
}


/* Output mit der ersten Zeile auskommentiert:

inner constructed
outer constructed
inner constructed

*/