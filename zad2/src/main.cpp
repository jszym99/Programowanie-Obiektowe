#include <iostream>
#include "BazaTestu.hh"
#include "Statystyki.hh"


int main(int argc, char **argv)
{

	//Sprawdzenie czy podano parametr wejsciowy
	if (argc < 2)
	{
		std::cout << std::endl;
		std::cout << " Brak opcji okreslajacej rodzaj testu." << std::endl;
		std::cout << " Dopuszczalne nazwy to:  latwy, trudny." << std::endl;
		std::cout << std::endl;
		return 1;
	}

	BazaTestu BazaT(argv[1]); //Inicjalizacja bazy testu

	std::cout << std::endl;
	std::cout << "Start testu arytmetyki zespolonej: " << argv[1] << std::endl;
	std::cout << std::endl;

	WyrazenieZesp WyrZ_PytanieTestowe; //Zmienna przechowujaca pytanie testowe (wyrazenie zespolone)
	LZespolona Odp; // Zmienna przechowujaca odpowiedz uzytkownika
	Statystyki StatyTestu(0,0); //Inicjalizacja zmiennej zawierajacej statystyki testu


	//Wczytywanie po kolei wszystkich pytan z bazy testu
	while (BazaT.pobierz_pytanie(WyrZ_PytanieTestowe))
	{
		LZespolona PopOdp = WyrZ_PytanieTestowe.Oblicz(); //Wartosc poprawnej odpowiedzi
		
		for(int i = 2; i >= 0; i--) //3 proby przy blednym formacie odpowiedzi
		{
			std::cout << "\n" << WyrZ_PytanieTestowe << " = ";

			std::cin >> Odp; //Sprawdzenie poprawnosci zapisu odpowiedzi
			if(!std::cin.good())
			{
				std::cin.clear();
				std::cin.ignore(1000,'\n');
				std::cout << "Bledny format odpowiedzi. Poprawny format: '(x+yi)'\n Pozostale proby: " << i << std::endl;
			}
			else
				break;
		}
		
		if(Odp == PopOdp)
		{
			std::cout << "Poprawna odpowiedz." << std::endl;
			StatyTestu.DodajPoprawna();
		}
		else
		{
			std::cout << "Bledna odpowiedz.\n Poprawna odpowiedz: " << PopOdp << std::endl;
			StatyTestu.DodajNiepoprawna();
		}


	}

	StatyTestu.Wyswielt();

	std::cout << std::endl;
	std::cout << "Koniec testu" << std::endl;
	std::cout << std::endl;
	
}