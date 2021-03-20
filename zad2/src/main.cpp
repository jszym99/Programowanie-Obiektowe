#include <iostream>
#include "BazaTestu.hh"
#include "Statystyki.hh"

using namespace std;




int main(int argc, char **argv)
{

	if (argc < 2)
	{
		cout << endl;
		cout << " Brak opcji okreslajacej rodzaj testu." << endl;
		cout << " Dopuszczalne nazwy to:  latwy, trudny." << endl;
		cout << endl;
		return 1;
	}

	BazaTestu BazaT = {nullptr, 0, 0};

	if (InicjalizujTest(&BazaT, argv[1]) == false)
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


	while (PobierzNastpnePytanie(&BazaT, &WyrZ_PytanieTestowe))
	{
		LZespolona PopOdp = Oblicz(WyrZ_PytanieTestowe);
		
		for(int i = 2; i >= 0; i--)
		{
			cout << "\n " << WyrZ_PytanieTestowe << " = ";

			cin >> Odp;
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