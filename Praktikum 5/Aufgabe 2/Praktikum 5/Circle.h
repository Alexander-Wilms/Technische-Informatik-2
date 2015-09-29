#include "Shape.h"

class Circle : public Shape
{
public:
	virtual double getCircumference();
	virtual double getArea();
	Circle(double);

	double radius;
};