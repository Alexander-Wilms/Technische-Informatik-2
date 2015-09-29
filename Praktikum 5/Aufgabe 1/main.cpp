// PRAKTIKUM 5

#include <iostream>
#include <string>
#include <vector>
#include "Coffeemachine.h"
#include "Radio.h"

using std::cout;
using std::endl;

bool valid(char);
void choosedvice(char option);
void choose(char option);
void status();

std::vector< GeneralDevice* > devices; // Vector mit Zeigern des Basisklassentyps
GeneralDevice* actualDevice; // Zeiger des Basisklassentyps
GeneralDevice* StatusPtr; // dito

int main()
{
	// Den Vector mit den Geräten füllen
	devices.push_back(new Coffeemachine("Tchibo KM 3"));
	devices.push_back(new Radio("Radio WZ"));
	devices.push_back(new Radio("Radio Kueche"));
	devices.push_back(new Coffeemachine("Heizung OG"));
	devices.push_back(new Coffeemachine("Heizung EG"));

	actualDevice = nullptr;
	cout << "First, choose a device (1 to 5), then choose + or - or ? or 0" << endl;
	char option = 0;
	while((option = getchar()) != EOF)
	{
		if(valid(option))
		{
			if(option =='?')
			{
				status();
			} else
			{
				if(actualDevice == nullptr) // Noch kein Device ausgewählt
				{
					if(option == '+' || option == '-' || option == '0') // Sinnlos
					{
						cout << "Choose a Device" << endl;
					} else {
						//choosedvice(option);
						choose(option);
					}
				} else // Device ist bereits ausgewählt
				{
					choose(option);
				} 
			}
		} else
		{
			cout << "Input \"" << option << "\" invalid" << endl;
		}
		cout << "Enter command:" << endl;
		rewind(stdin);

	}
	rewind(stdin);
	getchar();
}

bool valid(char option) {
return (option == '+' || option == '-' || option == '1' || option == '2' || option == '3' || option == '4' || option == '5' || option == '?' || option == '0');
}

void choose(char option) { // Wenn es ein Gerät noch nicht gibt (nullptr), wird es erzeugt und die Adresse im Vector und in Zeiger actualDevice gespeichert
	switch(option)
	{
		case '1':
			if(devices[0] == nullptr)
				devices[0] = new Coffeemachine("Tchibo KM 3");
			actualDevice = devices[0];
			break;
		case '2':
			if(devices[1] == nullptr)
				devices[1] = new Radio("Radio WZ");
			actualDevice = devices[1];
			break;
		case '3':
			if(devices[2] == nullptr)
				devices[2] = new Radio("Radio Kueche");
			actualDevice = devices[2];
			break;
		case '4':
			if(devices[3] == nullptr)
				devices[3] = new Coffeemachine("Heizung OG");
			actualDevice = devices[3];
			break;
		case '5':
			if(devices[4] == nullptr)
				devices[4] = new Coffeemachine("Heizung EG");
			actualDevice = devices[4];
			break;
		case '+':
			++*actualDevice; // Präinkrement
			break;
		case '-':
			--*actualDevice; // Prädekrement
			break;
		case '?':
			status();
			break;
		case '0': // Momentan ausgewähltes Gerät löschen
			for(size_t i = 0; i < devices.size(); i++)
			{
				if(actualDevice == devices[i]) // Wenn Beide auf das gleiche Objekt zeigen
				{
					delete devices[i];
					devices[i] = nullptr;
					actualDevice = nullptr;
				}
			}
	}
	if(option == '1' || option == '2' || option == '3' || option == '4' || option == '5' )
		cout << "Device " << *actualDevice << " selected" << endl;
}

void status() // Wenn der StatusPtr auf ein Gerät zeigt: Gerät wird über derefenzierten Zeiger ausgegeben
{
StatusPtr = devices[0];
if(StatusPtr != nullptr)
	cout << *StatusPtr << endl;

StatusPtr = devices[1];
if(StatusPtr != nullptr)
	cout << *StatusPtr << endl;

StatusPtr = devices[2];
if(StatusPtr != nullptr)
	cout << *StatusPtr << endl;

StatusPtr = devices[3];
if(StatusPtr != nullptr)
	cout << *StatusPtr << endl;

StatusPtr = devices[4];
if(StatusPtr != nullptr)
	cout << *StatusPtr << endl;
}