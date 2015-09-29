#ifndef RECT
#define RECT

#include "Shape.h"

class Rectangle : public Shape
{
public:
	virtual double getCircumference();
	virtual double getArea();
	Rectangle(double, double);

	double a;
	double b;
};

#endif