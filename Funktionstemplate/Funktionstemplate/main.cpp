// FUNKTIONSTEMPLATE

#include <iostream>

template < typename T >
T maximum ( T value1, T value2, T value3); // Prototyp, damit dem Kompiler die Funktion bekannt ist

int main( void )
{
	int a = 1, b = 2, c = 3;
	std::cout << maximum<int>(a,b,c); // Spezialisierungstyp angeben
	std::cout << maximum<char>('a','b','c');
	getchar();
}

template < typename T > // oder template < class T >
T maximum ( T value1, T value2, T value3)
{
	T maximumValue = value1;
	if ( value2 > maximumValue )
		maximumValue = value2;
	if ( value3 > maximumValue )
		maximumValue = value3;
	return maximumValue;
}