#include <iostream>
#include "BazaTestu.hh"
#include "Statystyki.hh"

using namespace std;




int main(int argc, char **argv)
{

	//Sprawdzenie czy podano parametr wejsciowy
	if (argc < 2)
	{
		cout << endl;
		cout << " Brak opcji okreslajacej rodzaj testu." << endl;
		cout << " Dopuszczalne nazwy to:  latwy, trudny." << endl;
		cout << endl;
		return 1;
	}

	BazaTestu BazaT = {nullptr, 0, 0};

	//Inicjalizacja testu z odpowiedniej bazy pytan
	if (InicjalizujTest(&BazaT, argv[1]) == false) //TODO: problem z inicjalizacja testu trudnego
	{
		cerr << " Inicjalizacja testu nie powiodla sie." << endl;
		return 1;
	}



	cout << endl;
	cout << " Start testu arytmetyki zespolonej: " << argv[1] << endl;
	cout << endl;

	WyrazenieZesp WyrZ_PytanieTestowe;
	LZespolona Odp;
	Statystyki StatyTestu;

	Inicjuj(StatyTestu); //Inicjalizacja zmiennej zawierajacej statystyki testu

	//Wczytywanie po kolei wszystkich pytan z bazy testu
	while (PobierzNastpnePytanie(&BazaT, &WyrZ_PytanieTestowe))
	{
		LZespolona PopOdp = Oblicz(WyrZ_PytanieTestowe); //Wartosc poprawnej odpowiedzi
		
		for(int i = 2; i >= 0; i--) //3 proby przy blednym formacie odpowiedzi
		{
			cout << "\n " << WyrZ_PytanieTestowe << " = ";

			cin >> Odp; //Sprawdzenie poprawnosci zapisu odpowiedzi
			if(!cin.good())
			{
				cin.clear();
				cin.ignore(1000,'\n');
				cout << " Bledny format odpowiedzi. Poprawny format: '(x+yi)'\n Pozostale proby: " << i << endl;
			}
			else
				break;
		}
		
		if(Odp == PopOdp)
		{
			cout << " Poprawna odpowiedz." << endl;
			DodajPoprawna(StatyTestu);
		}
		else
		{
			cout << " Bledna odpowiedz.\n Poprawna odpowiedz: " << PopOdp << endl;
			DodajNiepoprawna(StatyTestu);
		}


	}

	Wyswielt(StatyTestu);

	cout << endl;
	cout << " Koniec testu" << endl;
	cout << endl;
	
}