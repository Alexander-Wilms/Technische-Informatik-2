#include <iostream>
#include "Mastermind.h"
using namespace std;

void Play();
void Test();

int main()
{
	int choice;
	bool done = false;
	while(!done)
	{
		cout << "Testen(1) oder Spielen(2): ";
		cin >> choice;
		if(choice == 1) { Test(); done = true;}
		else if(choice == 2) { Play(); done = true;}
	}
}

void Play()
{
	MastermindDigits NumberToGuess;
	int givenNumberInt;
	int counter = 0, i = 1;

	while (true)
	{
		cout << i << ". Versuch; Gib Zahl: ";
		cin >> givenNumberInt;
		if(givenNumberInt == -1)
		{
			cout << "Zahl: " << NumberToGuess.cheat() << std::endl;
		} else
		{
			MastermindDigits givenNumber(givenNumberInt);
			if (NumberToGuess.isEqual(givenNumber) == true)
			{
				cout << "Zahl erraten" << std::endl;
				rewind(stdin);
				getchar();
				counter++;
				break;
			}
			else
			{
				cout << NumberToGuess.locationRight(givenNumber) << " an der richtigen Stelle;";
				cout << " sonst " << NumberToGuess.locationWrong(givenNumber) << " richtig" << std::endl << std::endl;
			}
			i++;
		}
	}
}

void Test()
{
	int givenNumberInt, testNumber, counter = 0, i = 1;
	cout << "Testzahl eingeben: " << std::endl;
	cin >> testNumber;
	MastermindDigits NumberToGuess(testNumber);

	while (true)
	{
		cout << i << ". Versuch; Gib Zahl: ";
		cin >> givenNumberInt;
		if(givenNumberInt == -1)
		{
			cout << "Zahl: " << NumberToGuess.cheat() << std::endl << std::endl;
		} else
		{
			MastermindDigits Guess(givenNumberInt);
			if (NumberToGuess.isEqual(Guess) == true)
			{
				cout << "Zahl erraten" << std::endl;
				rewind(stdin);
				getchar();
				counter++;
				break;
			}
			else
			{
				cout << NumberToGuess.locationRight(Guess) << " an der richtigen Stelle;";
				cout << " sonst " << NumberToGuess.locationWrong(Guess) << " richtig" << std::endl << std::endl;
			}
			i++;
		}
	}
}