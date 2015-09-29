#ifndef SHAPE
#define SHAPE

class Shape
{
public:
	virtual double getCircumference() = 0;
	virtual double getArea() = 0;
	double operator-(Shape&);
};

#endif