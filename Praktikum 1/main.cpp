// PRAKTIKUM 1

#include <stdio.h>

typedef struct { // numerator and denominator are relatively prime
int numerator;
int denominator;
} Fraction;

// Prototypes
void printFraction( Fraction f );
void getFraction( Fraction* fPtr );
int gcd( int p, int q );
void cancel( Fraction* fPtr );
void format( Fraction* fPtr );
Fraction add( Fraction f1, Fraction f2 );
Fraction subtract( Fraction f1, Fraction f2 );
Fraction multiply( Fraction f1, Fraction f2 );
Fraction divide( Fraction f1, Fraction f2 );

int main( void )
{
	// local variables!
	Fraction f1;
	Fraction f2;
	Fraction result;

	getFraction( &f1 );
	getFraction( &f2 );

	printFraction( f1 );
	printFraction( f2 );

	result = add( f1, f2 );
	printf( "Addition: " );
	printFraction( result );

	result = subtract( f1, f2 );
	printf( "Subtraktion: " );
	printFraction( result );

	result = multiply( f1, f2 );
	printf( "Multiplikation: " );
	printFraction( result );

	result = divide( f1, f2 );
	printf( "Division: " );
	printFraction( result );
}

void printFraction( Fraction f )
{
	format(&f); // always clean up the formatting before printing a fraction
	if( f.numerator == f.denominator)
	{
		puts("1");
	} else if (f.numerator == 0)
	{
		puts("0");
	} else
	{
		printf("%d/%d \n", f.numerator, f.denominator);
	}
}

void getFraction( Fraction* fPtr )
{
	printf("Zaehler: ");
	scanf("%d", &fPtr->numerator); // read numerator
	fPtr->denominator = 0;
	do // only accept the input for denominator if it isn't 0
	{
		printf("Nenner: ");
		scanf("%d", &fPtr->denominator); // reaad denominator
		if(fPtr->denominator == 0) puts("Nenner darf nicht Null sein!");
	} while (fPtr->denominator == 0);
}

int gcd( int p, int q )
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

void cancel( Fraction* fPtr )
{
int gcdNumDenom = gcd( fPtr->numerator, fPtr->denominator); // find gdc of numerator & denominator
fPtr->numerator /= gcdNumDenom; // cancel the fraction
fPtr->denominator /= gcdNumDenom;
}

void format( Fraction* fPtr )
{
	cancel(fPtr); // cancel the fraction
	if(fPtr->denominator < 0) // get rid of duplicate minui or move minus into the numerator
	{
		fPtr->numerator = fPtr->numerator * -1;
		fPtr->denominator = fPtr->denominator * -1;
	}
}

Fraction add( Fraction f1, Fraction f2 )
{
	int tmp1, tmp2;
	tmp1 = f1.denominator;
	tmp2 = f2.denominator;
	f1.numerator *= tmp2; // expand fraction so that it has the same denominator as f2
	f1.denominator *= tmp2;
	f2.numerator *= tmp1; // expand fraction so that it has the same denominator as f1
	f2.denominator *= tmp1;
	Fraction result;
	result.numerator = f1.numerator + f2.numerator; // do the addition
	result.denominator = f1.denominator;
	return result;
}

Fraction subtract( Fraction f1, Fraction f2 )
{
	int tmp1, tmp2;
	tmp1 = f1.denominator;
	tmp2 = f2.denominator;
	f1.numerator *= tmp2; // expand fraction so that it has the same denominator as f2
	f1.denominator *= tmp2;
	f2.numerator *= tmp1; // expand fraction so that it has the same denominator as f1
	f2.denominator *= tmp1;
	Fraction result;
	result.numerator = f1.numerator - f2.numerator; // do the subtraction
	result.denominator = f1.denominator;
	return result;
}

Fraction multiply( Fraction f1, Fraction f2 )
{
	Fraction result;
	result.numerator = f1.numerator * f2.numerator; // multiply
	result.denominator = f1.denominator * f2.denominator;
	return result;
}

Fraction divide( Fraction f1, Fraction f2 )
{
	Fraction result;
	result.numerator = f1.numerator * f2.denominator; // multiply with the inverse
	result.denominator = f1.denominator * f2.numerator;
	return result;
}
