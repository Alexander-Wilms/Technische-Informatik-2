// PRAKTIKUM 4

#include <iostream>
#include <sstream>
#include <string>
#include "fraction.h"
using namespace std;

void format( Fraction* fPtr ); // Needed for print(), since otherwise the compiler complains

Fraction::Fraction( int num, int denom ) // Konstruktor
{
	numerator = num;
	denominator = denom;
}

Fraction::Fraction( const Fraction& input) // Kopierkonstruktor
{
	numerator = input.numerator;
	denominator = input.denominator;
}

Fraction::~Fraction() // Destruktor
{
}

const Fraction& Fraction::operator=(const Fraction& input) // Zuweisungsoperator
{
	numerator = input.numerator;
	denominator = input.denominator;
	return *this;
}

string Fraction::toString()
{
	stringstream output;

	format(this); // always clean up the formatting before printing a fraction
	if ( numerator == denominator)
	{
		output << "1" << endl;
	} else if (numerator == 0)
	{
		output << "0" << endl;
	} else if ( denominator == 1 )
	{
		output << numerator << endl;
	} else
	{
		output << numerator << "/" << denominator << endl;
	}
	return output.str();
}

ostream& operator<<(ostream& out, const Fraction& f1) // Ausgabeoperator
{
	Fraction mem(f1);
	out << mem.toString();
	return out;
}

istream& operator>>(istream& in, Fraction& f1) // Eingabeoperator
{
	f1.numerator = 0;
	f1.denominator = 0;
	char a;
	while((a = getchar()) != '/') // Getline funktioniert nicht
	{
		f1.numerator = f1.numerator * 10 + a - '0'; // KLAUSUR!!!!
	}
	while((a = getchar()) != '\n')
	{
		f1.denominator = f1.denominator * 10 + a - '0';
	}
	if (f1.denominator == 0)
	{
		f1.denominator = 1;
		cerr << "Nenner darf nicht Null sein!" << endl;
	}
	return in;
}

Fraction operator+(Fraction& f1, Fraction& f2)
{
	return f1.add(f2);
}

Fraction operator-(Fraction& f1, Fraction& f2)
{
	return f1.subtract(f2);
}

Fraction operator*(Fraction& f1, Fraction& f2)
{
	return f1.multiply(f2);
}

Fraction operator/(Fraction& f1, Fraction& f2)
{
	return f1.divide(f2);
}

Fraction Fraction::add( const Fraction& f )
{
	int numeratorcopy = numerator; // A copy of "this" resulted in a compiler error
	int denominatorcopy = denominator;
	Fraction fcopy = f;

	if ( denominator != f.denominator) // Check whether fractions have a common denominator
	{
		numerator *= f.denominator; // expand fraction so that it has the same denominator as f2
		denominator *= f.denominator;
		
		fcopy.numerator *= denominatorcopy; // expand fraction so that it has the same denominator as f1
		fcopy.denominator *= denominatorcopy;
	}

	Fraction result;
	result.numerator = numerator + fcopy.numerator; // do the addition
	result.denominator = denominator;
	return result;
}

Fraction Fraction::subtract( const Fraction& f )
{
	int numeratorcopy = numerator;
	int denominatorcopy = denominator;
	Fraction fcopy = f;

	if ( denominator != f.denominator)
	{
		numerator *= f.denominator; // expand fraction so that it has the same denominator as f2
		denominator *= f.denominator;
		
		fcopy.numerator *= denominatorcopy; // expand fraction so that it has the same denominator as f1
		fcopy.denominator *= denominatorcopy;
	}

	Fraction result;
	result.numerator = numerator - fcopy.numerator; // do the substraction
	result.denominator = denominator;
	return result;
}

Fraction Fraction::multiply( const Fraction& f )
{
	Fraction result;
	result.numerator = numerator * f.numerator; // multiply
	result.denominator = denominator * f.denominator;
	return result;
}

Fraction Fraction::divide( const Fraction& f )
{
	Fraction result;
	result.numerator = numerator * f.denominator; // multiply with the inverse
	result.denominator = denominator * f.numerator;
	return result;
}

int Fraction::gcd( int p, int q )
{
	int rest = 1;
	rest = p % q;
	while (rest != 0)
	{
		p = q;
		q = rest;
		rest = p % q;
	}
	return q;
}

void Fraction::cancel( Fraction* fPtr )
{
int gcdNumDenom = gcd( fPtr->numerator, fPtr->denominator); // find gdc of numerator & denominator
fPtr->numerator /= gcdNumDenom; // cancel the fraction
fPtr->denominator /= gcdNumDenom;
}

void Fraction::format( Fraction* fPtr )
{
	cancel(fPtr); // cancel the fraction
	if(fPtr->denominator < 0) // get rid of duplicate minui or move minus into the numerator
	{
		fPtr->numerator = fPtr->numerator * -1;
		fPtr->denominator = fPtr->denominator * -1;
	}
}