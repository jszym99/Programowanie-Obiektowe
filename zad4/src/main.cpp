#include <iostream>
#include <iomanip>
#include <fstream>
#include "Wektor.hh"
#include "Macierz.hh"
#include "Prostopadloscian.hh"
#include "Dr3D_gnuplot_api.hh"

#define PRZESUN 1
#define DL_KROTKI_BOK 5
#define DL_SREDNI_BOK 10
#define DL_DLUGI_BOK 15

int main()
{

	drawNS::Draw3DAPI *rysownik = new drawNS::APIGnuPlot3D(-20, 20, -20, 20, -20, 20, 1000);
	rysownik->change_ref_time_ms(0);

	//Prostopadloscian poczatkowy
	Prostopadloscian startProst{Wektor<3>{PRZESUN,PRZESUN,PRZESUN},Wektor<3>{PRZESUN + DL_SREDNI_BOK,PRZESUN,PRZESUN},
								Wektor<3>{PRZESUN + DL_SREDNI_BOK,PRZESUN + DL_KROTKI_BOK,PRZESUN},Wektor<3>{PRZESUN,PRZESUN + DL_KROTKI_BOK,PRZESUN},
								Wektor<3>{PRZESUN,PRZESUN,PRZESUN + DL_DLUGI_BOK},Wektor<3>{PRZESUN + DL_SREDNI_BOK,PRZESUN,PRZESUN + DL_DLUGI_BOK},
								Wektor<3>{PRZESUN + DL_SREDNI_BOK,PRZESUN + DL_KROTKI_BOK,PRZESUN + DL_DLUGI_BOK},Wektor<3>{PRZESUN,PRZESUN + DL_KROTKI_BOK,PRZESUN + DL_DLUGI_BOK}};

	

	//Lista kolorow
	std::string kol [5] = {"blue","orange","yellow","green","red"};
	int kolNum = 0;

	
	Prostopadloscian tmp = startProst;
	MacierzObr<3> obrot{};
	MacierzObr<3> tmpObr{};


	std::cout << "Wspolrzedne poczatkowego prostokata\n" << startProst << std::endl;
	startProst.rysuj(rysownik, "black");

	std::cout << "Menu:";

	int opcje = 0;

	do
	{
		std::cout << "\n[1] Obrot\n[2] Powtorzenie poprzedniego obrotu\n[3] Wyswietlenie macierzy obrotu\n[4] Translacja\n[5] Wyswietl wsporzedne\n[6] Sprawdzanie dlugosci bokow\n[7] Koniec" << std::endl;
		std::cin >> opcje;
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(1000, '\n');
			opcje = 0;
		}

		switch (opcje)
		{
		case 1: //Obrot
			double deg, powtorzenia;
			char znak;
			obrot = MacierzObr<3> {};

			//Rozpoczecie wczytywania sekwencji obrotow
			std::cout << "Podaj sekwencje obrotu\n";
			do{
				std::cout << "Podaj os obrotu (X, Y lub Z) lub . aby zakonczyc sekwencje: ";
				std::cin >> znak;

				//Sprawdzeniew arunku zakonczenia sekwencji
				if(znak == '.')
				{
					break;
				}
				
				//Sprawdzenie poprawnosci danych wejsciowych
				if(std::cin.fail() && znak != 'X' && znak != 'Y' && znak != 'Z'&& znak != 'x' && znak != 'y' && znak != 'z')
				{
					std::cout << znak << std::endl;
					std::cin.clear();
					std::cin.ignore(1000, '\n');
					std::cout << "Niepoprawny format danych\n";
					continue;
				}
				std::cout << "Podaj kat obrotu: ";
				std::cin >> deg;
				if (std::cin.fail())
				{
					std::cin.clear();
					std::cin.ignore(1000, '\n');
					std::cout << "Niepoprawny format danych\n";
					continue;
				}

				//Sprawdzenie osi obrotu
				switch(znak)
				{
					case 'X':
					case 'x':
						obrot = MacierzObr<3>(deg, X) * obrot;
						break;
					case 'Y':
					case 'y':
						obrot = MacierzObr<3>(deg, Y) * obrot;
						break;
					case 'Z':
					case 'z':
						obrot = MacierzObr<3>(deg, Z) * obrot;
						break;
				}
			}while(znak != '.');

			if(znak != '.') //Wyjscie spowodowane bledem danych
				continue;

			std::cout << "Podaj liczbe powtorzen: ";
			std::cin >> powtorzenia;
			if (std::cin.fail())
			{
				std::cin.clear();
				std::cin.ignore(1000, '\n');
				std::cout << "Niepoprawny format danych\n";
				continue;
			}

			//Powielenie sekwencji obrotow o ilosc powtorzen
			for(int i = 0; i < fmod(powtorzenia, 360.0); i++)
				tmpObr = tmpObr * obrot;
			
			obrot = tmpObr;
			tmp = tmp.rotacja(obrot);
			break;
		case 2: //Powtorzenie ostatniej sekwencji obrotow
			tmp = tmp.rotacja(obrot);
			break;
		case 3: //Wyswietlenie macierzy obrotu
			std::cout << obrot;
			continue;
		case 4: //Przesuniecie
			{
				Wektor<3> przesun{};
				std::cout << "Podaj wektor przesuniecia (w postaci [x,y,z]): ";
				std::cin >> przesun;
				if (std::cin.fail())
				{
					std::cin.clear();
					std::cin.ignore(1000, '\n');
					std::cout << "Niepoprawny format danych\n";
					continue;
				}
				tmp = tmp.translacja(przesun);
			}
			break;
		case 5: //Wyswietlanie wspolrzednych
			std::cout << tmp << std::endl;
			continue;
		case 6: //Sprawdzenie bledow numerycznych
			tmp.porownanie();
			continue;
		case 7: //Zakonczenie programu
			continue;
		default:
			std::cout << "Bledna opcja!" << std::endl;
			continue;
		}

		//Rysuj prostopadloscian
		tmp.rysuj(rysownik, kol[kolNum]);
        
		//Iteracja po kolorach
        if(kolNum >= 4)
			kolNum = 0;
		else
			kolNum++;

	} while (opcje != 7);

	delete rysownik;
	return 0;
}
