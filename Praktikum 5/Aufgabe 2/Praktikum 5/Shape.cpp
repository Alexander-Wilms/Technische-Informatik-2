#include "Shape.h"

double Shape::operator-(Shape& a)
{
	return getArea() - a.getArea(); // Nutzt die virtuellen getArea-Methoden (*this funktioniert nicht, da Basisklasse abstrakt ist)
}