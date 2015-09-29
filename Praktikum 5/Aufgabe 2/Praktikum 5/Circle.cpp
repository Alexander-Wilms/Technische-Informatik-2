#include "Circle.h"
#define _USE_MATH_DEFINES
#include <math.h>

Circle::Circle(double input_radius)
	: radius(input_radius) // Elementinitialisierer
{
}

double Circle::getCircumference()
{
	return 2*M_PI*radius;
}

double Circle::getArea()
{
	return M_PI*radius*radius;
}