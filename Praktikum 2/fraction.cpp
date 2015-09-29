// PRAKTIKUM 2

#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include "fraction.h"

void format( Fraction* fPtr ); // Needed for print(), since otherwise the compiler complains

Fraction::Fraction( int num, int denom ) // Constructor
{
	numerator = num;
	denominator = denom;
}

void Fraction::print()
{
	format(this); // always clean up the formatting before printing a fraction
	if ( numerator == denominator)
	{
		cout << "1" << endl;
	} else if (numerator == 0)
	{
		cout << "0" << endl;
	} else if ( denominator == 1 )
	{
		cout << numerator << endl;
	} else
	{
		cout << numerator << "/" << denominator << endl;
	}
}

void Fraction::get()
{
	cout << "Zaehler: ";
	cin >> numerator; // read numerator
	denominator = 0;
	do // only accept the input for denominator if it isn't 0
	{
		cout << "Nenner: ";
		cin >> denominator; // read denominator
		if(denominator == 0) cout << "Nenner darf nicht Null sein!" << endl;
	} while (denominator == 0);
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