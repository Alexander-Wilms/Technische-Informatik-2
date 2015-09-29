// PRAKTIKUM 4

#include <iostream>
#include "fraction.h"
using namespace std;

int main()
{
	Fraction f1, f2, result;

	cin >> f1;
	cin >> f2;

	cout << f1;
	cout << f2;

	result = f1 + f2;
	cout << "Addition: "
		<< result;

	result = f1 - f2;
	cout << "Subtraktion: "
		<< result;

	result = f1 * f2;
	cout << "Multiplikation: "
		<< result;

	result = f1 / f2;
	cout << "Division: "
		<< result;

	rewind(stdin);
	getchar();

}