// PRAKTIKUM 4

#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>
#include <string>
using namespace std;

class Fraction
{
	public:
		Fraction( int num = 0, int denom = 1 ); // Standardkonstruktor
		Fraction( const Fraction&);
		~Fraction();
		const Fraction& operator=(const Fraction&);
		string toString();

		friend ostream& operator<<(ostream&, const Fraction&);
		friend istream& operator>>(istream&, Fraction&);

		friend Fraction operator+(Fraction&, Fraction&);
		friend Fraction operator-(Fraction&, Fraction&);
		friend Fraction operator*(Fraction&, Fraction&);
		friend Fraction operator/(Fraction&, Fraction&);
		
	private:
		void get();
		Fraction add( const Fraction& );
		Fraction subtract( const Fraction& );
		Fraction multiply( const Fraction& );
		Fraction divide( const Fraction& );
		int gcd( int, int );
		void cancel( Fraction* fPtr );
		void format( Fraction* fPtr );

		int numerator;
		int denominator;
};



#endif // FRACTION_H
