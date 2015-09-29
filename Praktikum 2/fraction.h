// PRAKTIKUM 2

#ifndef FRACTION_H
#define FRACTION_H

class Fraction
{
    public:
        Fraction( int num = 0, int denom = 1 ); // auch Standardkonstruktor!
        void print();
        void get();
        Fraction add( const Fraction& f );
        Fraction subtract( const Fraction& f );
        Fraction multiply( const Fraction& f );
        Fraction divide( const Fraction& f );
    private:
        int gcd( int p, int q );
        void cancel( Fraction* fPtr );
        void format( Fraction* fPtr );
        int numerator;
        int denominator;
};

#endif // FRACTION_H
