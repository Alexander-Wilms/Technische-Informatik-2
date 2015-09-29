#include <iostream>
#include "Circle.h"
#include "Rectangle.h"
#include "Square.h"

using std::cout;
using std::endl;

int main()
{
	Circle C(1);
	Rectangle R(1,2);
	Square S(1);

	cout << "Circumferences:" << endl;
	cout << "Circle: " << C.getCircumference() << endl;
	cout << "Rectangle: " << R.getCircumference() << endl;
	cout << "Square: " << S.getCircumference() << endl << endl;

	cout << "Areas:" << endl;
	cout << "Circle: " << C.getArea() << endl;
	cout << "Rectangle: " << R.getArea() << endl;
	cout << "Square: " << S.getArea() << endl << endl;

	cout << "Area differences:" << endl;
	cout << "Circle - Rectangle: " << C-R << endl;
	cout << "Circle - Square: " << C - S << endl;
	cout << "Rectangle - Square: " << R - S << endl;

	getchar();
}