// PRAKTIKUM 5

#include "GeneralDevice.h"

ostream& operator<<(ostream& out, GeneralDevice& device)
{
	out << device.toString();
	return out;
}