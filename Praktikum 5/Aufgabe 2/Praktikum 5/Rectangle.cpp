#include "Rectangle.h"

Rectangle::Rectangle(double input_a, double input_b)
	: a(input_a), b(input_b)
{
}

double Rectangle::getCircumference()
{
	return 2*a+2*b;
}

double Rectangle::getArea()
{
	return a*b;
}