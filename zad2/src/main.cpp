#include <iostream>
#include "BazaTestu.hh"

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

	while (PobierzNastpnePytanie(&BazaT, &WyrZ_PytanieTestowe))
	{
		LZespolona PopOdp = Oblicz(WyrZ_PytanieTestowe);
		//cout << "\n " << WyrZ_PytanieTestowe << " = ";
		
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
			cout << " Poprawna odpowiedz." << endl;
		else
			cout << " Bledna odpowiedz.\n Poprawna odpowiedz: " << PopOdp << endl;


		//cout << " " << Oblicz(WyrZ_PytanieTestowe) << endl;
		//cout << " Czesc rzeczywista pierwszego argumentu: ";
		//cout << WyrZ_PytanieTestowe.Arg1.re << endl;
	}


	/* Test dzialan
	cout << "\n Test operacji na liczbach zespolonych \n ----------------------------------------------" << endl;

	LZespolona L0, L1, L2, Wynik;
	L0.re = 2;
	L0.im = 0;
	L1.re = 1;
	L1.im = 2;
	L2.re = 3;
	L2.im = 4;

	cout << "\n Oczekikawny wynik: 4+6i \n ";
	Wynik = L1 + L2;
	cout << Wynik << endl;

	cout << "\n Oczekikawny wynik: -2-2i \n ";
	Wynik = L1 - L2;
	cout << Wynik << endl;

	cout << "\n Oczekikawny wynik: -5+10i \n ";
	Wynik = L1 * L2;
	cout << Wynik << endl;

	cout << "\n Oczekikawny wynik: 6+8i \n ";
	Wynik = L0 * L2;
	cout << Wynik << endl;

	cout << "\n Oczekikawny wynik: 0.44+0.08i \n ";
	Wynik = L1 / 2;
	cout << Wynik << endl;

	cout << "\n Oczekikawny wynik: 0.44+0.08i \n ";
	Wynik = L1 / L2;
	cout << Wynik << endl;

	cout << "\n Oczekikawny wynik: 5+6i \n ";
	cout << inicjuj(5,6) << endl;
	//Koniec testu */

	cout << endl;
	cout << " Koniec testu" << endl;
	cout << endl;
	
}
