// PRAKTIKUM 2

#include <iostream>
using std::cout;
using std::endl;
#include "fraction.h"

int main()
{
	// local variables!
	Fraction f1;
	Fraction f2;
	Fraction result;
	char cont = 'y';

	do{
		f1.get();
		f2.get();

		f1.print();
		f2.print();

		result = f1.add( f2 );
		cout << "Addition:" << endl;
		result.print();

		result = f1.subtract( f2 );
		cout << "Subtraktion:" << endl;
		result.print();

		result = f1.multiply( f2 );
		cout << "Multiplikation:" << endl;
		result.print();

		result = f1.divide( f2 );
		cout << "Division:" << endl;
		result.print();

		cout <<  endl << "Repeat? y/n" << endl;
		rewind(stdin);
		cont = 'y';
		do{
			if(cont != 'y' && cont != 'n') cout << "Enter either 'y' to continue or 'n' to exit" << endl;
			rewind(stdin);
			cont = getchar();
		} while (cont != 'y' && cont != 'n');
	} while (cont == 'y');
}