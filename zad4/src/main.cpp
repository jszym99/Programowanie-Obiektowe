#include <iostream>
#include <iomanip>
#include <fstream>
#include "Wektor.hh"
#include "Macierz.hh"
//#include "Prostokat.hh"
//#include "Dr2D_gnuplot_api.hh"

using namespace std;

#define PRZESUN 1
#define DL_KROTKI_BOK 5
#define DL_DLUGI_BOK 10

int main()
{
	// Testowanie wektorow
	std::cout << "Testowanie wektorow\n";
	Wektor<2> W2{1, 2}; //Wektor 2-wymiarowy
	Wektor<3> W3{1, 2, 3}; //Wektor 3-wymiarowy
	Wektor<6> W6{1, 2, 3, 4, 5, 6}; //Wektor 6-wymiarowy
	std::cout << W2 << W3 << W6;
	// Dodawanie
	std::cout << "Dodawanie\n";
	std::cout << W2 + W2;
	std::cout << W3 + W3;
	std::cout << W6 + W6;
	// Odejmowanie
	std::cout << "Odejmowanie\n";
	std::cout << W2 - W2;
	std::cout << W3 - W3;
	std::cout << W6 - W6;
	// Mnożenie skalarne
	std::cout << "Mnożenie skalarne\n";
	std::cout << W2 * W2 << std::endl;
	std::cout << W3 * W3 << std::endl;
	std::cout << W6 * W6 << std::endl;

	// Wczytywanie
	std::cin >> W2;
	std::cin >> W3;
	std::cin >> W6;
	std::cout << W2 << W3 << W6;

	// Testowanie macierzy
	std::cout << "Testowanie macierzy\n";
	//Macierz 2-wymiarowa
	MacierzObr<2> M2{30}; //Inicjalizacja
	std::cout << M2 << std::endl; //wyswietlanie
	std::cout << M2 * M2; //Mnozenie

	//Macierz 3-wymiarowa
	MacierzObr<3> M3X{30,X}; //Inicjalizacja dla 30 stopni X
	std::cout << M3X << std::endl;
	MacierzObr<3> M3Y{30,Y}; //Inicjalizacja dla 30 stopni Y
	std::cout << M3Y << std::endl;
	MacierzObr<3> M3Z{30,Z}; //Inicjalizacja dla 30 stopni Z
	std::cout << M3Z << std::endl;

	std::cout << M3X*M3X; //Mnozenie


	/*
	drawNS::Draw2DAPI *rysownik = new drawNS::APIGnuPlot2D(-20, 20, -20, 20, 1000);
	rysownik->change_ref_time_ms(0);

	std::string kol [5] = {"blue","orange","yellow","green","red"};
	int kolNum = 0;

	//Tworzenie prostokata na ktorym beda wykonywane operacje
	Prostokat Pr(Wektor2D(PRZESUN,PRZESUN), Wektor2D(PRZESUN + DL_DLUGI_BOK,PRZESUN), Wektor2D(PRZESUN + DL_DLUGI_BOK,PRZESUN + DL_KROTKI_BOK), Wektor2D(PRZESUN,PRZESUN + DL_KROTKI_BOK));
	Prostokat tmp = Pr;
	Pr.rysuj(rysownik, "black");

	std::cout << "Wspolrzedne poczatkowego prostokata\n" << Pr << std::endl;

	std::cout << "Menu:";

	int opcje = 0;

	do
	{
		std::cout << "\n[1] Obrot\n[2] Translacja\n[3] Wyswietl wsporzedne\n[4] Koniec" << std::endl;
		std::cin >> opcje;
		if (cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(1000, '\n');
			opcje = 0;
		}

		switch (opcje)
		{
		case 1: //Obrot
			double deg, powtorzenia;
			std::cout << "Podaj kat obrotu: ";
			std::cin >> deg;
			if (cin.fail())
			{
				std::cin.clear();
				std::cin.ignore(1000, '\n');
				std::cout << "Niepoprawny format danych\n";
				continue;
			}
			std::cout << "Podaj liczbe powtorzen: ";
			std::cin >> powtorzenia;
			if (cin.fail())
			{
				std::cin.clear();
				std::cin.ignore(1000, '\n');
				std::cout << "Niepoprawny format danych\n";
				continue;
			}
			tmp = tmp.rotacja(MacierzObr2x2(deg*powtorzenia)); //Przy 10^23 kat w radianach zaczyna sie rozjezdzac
			break;
		case 2: //Przesuniecie
			{
				Wektor2D przesun(0, 0);
				std::cout << "Podaj wektor przesuniecia (w postaci [x,y]): ";
				std::cin >> przesun;
				if (cin.fail())
				{
					std::cin.clear();
					std::cin.ignore(1000, '\n');
					std::cout << "Niepoprawny format danych\n";
					continue;
				}
				tmp = tmp.translacja(przesun);
			}
			break;
		case 3: //Wyswietlanie wspolrzednych
			std::cout << tmp << std::endl;
			break;
		case 4:
			continue;
		default:
			std::cout << "Bledna opcja!" << std::endl;
			continue;
		}

		std::cout << "Roznica dlugosci bokow wzgledem oryginalu:\n" << std::fixed << std::setprecision(std::numeric_limits<double>::max_digits10+1);
		std::cout << "|P1 P2| " << (tmp[0]-tmp[1]).dlugosc() - (Pr[0]-Pr[1]).dlugosc() << std::endl;
		std::cout << "|P2 P3| " << (tmp[1]-tmp[2]).dlugosc() - (Pr[1]-Pr[2]).dlugosc() << std::endl;
		std::cout << "|P3 P4| " << (tmp[2]-tmp[3]).dlugosc() - (Pr[2]-Pr[3]).dlugosc() << std::endl;
		std::cout << "|P4 P1| " << (tmp[3]-tmp[0]).dlugosc() - (Pr[3]-Pr[0]).dlugosc() << std::endl;

		std::cout << "\nDluzsze boki ";
		if((tmp[0]-tmp[1]).dlugosc() == (tmp[2]-tmp[3]).dlugosc())
			std::cout << "sa rowne.\n";
		else
			std::cout << "nie sa rowne.\n";
		std::cout << "|P1 P2| = " << (tmp[0]-tmp[1]).dlugosc() << std::endl;
		std::cout << "|P3 P4| = " << (tmp[2]-tmp[3]).dlugosc() << std::endl;
		
		std::cout << "\nKrotsze boki ";
		if((tmp[1]-tmp[2]).dlugosc() == (tmp[3]-tmp[0]).dlugosc())
			std::cout << "sa rowne.\n";
		else
			std::cout << "nie sa rowne.\n";
		std::cout << "|P2 P3| = " << (tmp[1]-tmp[2]).dlugosc() << std::endl;
		std::cout << "|P4 P1| = " << (tmp[3]-tmp[0]).dlugosc() << std::endl;

		tmp.rysuj(rysownik, kol[kolNum]);
        
        if(kolNum >= 4)
			kolNum = 0;
		else
			kolNum++;

	} while (opcje != 4);

	delete rysownik;*/
	return 0;
}
