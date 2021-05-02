#include <iostream>
#include <iomanip>
#include <fstream>
#include "Wektor.hh"
#include "Macierz.hh"
#include "UkladW.hh"
#include "Prostopadloscian.hh"
#include "Graniastoslup.hh"
#include "Dron.hh"
#include "Dr3D_gnuplot_api.hh"

#define PRZESUN 1
#define DL_KROTKI_BOK 5
#define DL_SREDNI_BOK 10
#define DL_DLUGI_BOK 15

namespace drone
{
    double dl_boku = 5;
    double wys_korpusu = 3;
    double r_wirnika = 2.5; 
    double wys_wirnika = 1;
}

int main()
{

	drawNS::Draw3DAPI *rysownik = new drawNS::APIGnuPlot3D(-20, 20, -20, 20, -20, 20, 1000);
	rysownik->change_ref_time_ms(0);

	MacierzObr<3> obrPocz{};
	Wektor<3> punktPocz{};

	// Budowanie korpusu drona
	std::array<Wektor<3>,8> wierzchKorp = {Wektor<3>{0,0,0}, Wektor<3>{0,drone::dl_boku,0},Wektor<3>{drone::dl_boku,drone::dl_boku,0},Wektor<3>{drone::dl_boku,0,0},
	Wektor<3>{0,0,drone::wys_korpusu}, Wektor<3>{0,drone::dl_boku,drone::wys_korpusu},Wektor<3>{drone::dl_boku,drone::dl_boku,drone::wys_korpusu},Wektor<3>{drone::dl_boku,0,drone::wys_korpusu}};

	Prostopadloscian prostKorp{punktPocz, obrPocz, wierzchKorp};

	// Budowanie graniastoslupu o podstawie szesciokata foremengo (wirniki)
	/////////////////////////////////////////////////////////////
	std::array<Wektor<3>,12> gran;
	Wektor<3> wierzcholek{0,drone::r_wirnika,0};
	for(int i = 0; i < 6; i++)
	{
		gran[i] = MacierzObr<3>{60*i} * wierzcholek;
	}
	wierzcholek = {0,drone::r_wirnika,drone::wys_wirnika};
	for(int i = 6; i < 12; i++)
	{
		gran[i] = MacierzObr<3>{60*i} * wierzcholek;
	}
	/////////////////////////////////////////////////////////////

	//Tworzenie tablicy grianiastoslupow 
	std::array<Graniastoslup6, 4> granWir = {Graniastoslup6{Wektor<3>{0,0,drone::wys_korpusu}, obrPocz, gran},Graniastoslup6{Wektor<3>{0,drone::dl_boku,drone::wys_korpusu}, obrPocz, gran},Graniastoslup6{Wektor<3>{drone::dl_boku,drone::dl_boku,drone::wys_korpusu}, obrPocz, gran},Graniastoslup6{Wektor<3>{drone::dl_boku,0,drone::wys_korpusu}, obrPocz, gran}};

	Dron D1(punktPocz, obrPocz, prostKorp, granWir);
	D1.rysuj(rysownik, "black");

	D1.translacja(Wektor<3>{20,20,0});
	D1.rysuj(rysownik, "blue");
	while(true);

	/*MacierzObr<3> startObr{};
	Wektor<3> punktPocz{};
	std::array<Wektor<3>,8> prost =  {Wektor<3>{PRZESUN,PRZESUN,PRZESUN},Wektor<3>{PRZESUN + DL_SREDNI_BOK,PRZESUN,PRZESUN},
								Wektor<3>{PRZESUN + DL_SREDNI_BOK,PRZESUN + DL_KROTKI_BOK,PRZESUN},Wektor<3>{PRZESUN,PRZESUN + DL_KROTKI_BOK,PRZESUN},
								Wektor<3>{PRZESUN,PRZESUN,PRZESUN + DL_DLUGI_BOK},Wektor<3>{PRZESUN + DL_SREDNI_BOK,PRZESUN,PRZESUN + DL_DLUGI_BOK},
								Wektor<3>{PRZESUN + DL_SREDNI_BOK,PRZESUN + DL_KROTKI_BOK,PRZESUN + DL_DLUGI_BOK},Wektor<3>{PRZESUN,PRZESUN + DL_KROTKI_BOK,PRZESUN + DL_DLUGI_BOK}};

	Prostopadloscian startProst(punktPocz, startObr, prost);

	std::array<Wektor<3>,12> rogi = {Wektor<3>{0,0,0}, Wektor<3>{4,3,0}, Wektor<3>{4,8,0},Wektor<3>{0,11,0}, Wektor<3>{-4,8,0}, Wektor<3>{-4,3,0},
	Wektor<3>{0,0,5}, Wektor<3>{4,3,5}, Wektor<3>{4,8,5},Wektor<3>{0,11,5}, Wektor<3>{-4,8,5}, Wektor<3>{-4,3,5}};

	Graniastoslup6 gran(punktPocz, startObr, rogi);

	Dron D1(startProst);

	D1.rysuj(rysownik, "black");
	while(true);*/

	

	/*//Prostopadloscian poczatkowy
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
*/
	delete rysownik;
	return 0;
}
