#include <iostream>
#include <iomanip>
#include <fstream>
#include "Wektor2D.hh"
#include "Macierz2x2.hh"
#include "Prostokat.hh"
//#include "lacze_do_gnuplota.hh"
#include "Dr2D_gnuplot_api.hh"

using namespace std;

/*
 * Tu definiujemy pozostale funkcje.
 * Lepiej jednak stworzyc dodatkowy modul
 * i tam je umiescic. Ten przyklad pokazuje
 * jedynie absolutne minimum.
 */

#define PRZESUN 1
#define DL_KROTKI_BOK 5
#define DL_DLUGI_BOK 10

/*!
 * Przyklad zapisu wspolrzednych zbioru punktow do strumienia wyjściowego.
 * Dane sa odpowiednio sformatowane, tzn. przyjęto notację stałoprzecinkową
 * z dokładnością do 10 miejsca po przecinku. Szerokość wyświetlanego pola 
 * to 16 miejsc, sposób wyrównywania - do prawej strony.
 * \param[in] StrmWy - strumien wyjsciowy, do ktorego maja zostac zapisane
 *                     kolejne wspolrzedne.
 * \param[in] Przesuniecie - ten parameter jest tylko po to, aby pokazać
 *                          mozliwosc zmiany wspolrzednych i prostokata
 *                          i zmiane jego polorzenia na okienku graficznym
 *                         rysownym przez gnuplota.
 * \retval true - gdy operacja zapisu powiodła się,
 * \retval false - w przypadku przeciwnym.
 */
/*void PrzykladZapisuWspolrzednychDoStrumienia( ostream&     StrmWy, 
                                              double       Przesuniecie
                                            )
{
   //---------------------------------------------------------------
   // To tylko przyklad !!!
   // W programie nalezy uzywać pojęcia wektora, a nie oddzielnych 
   // zmiennych do reprezentowania wspolrzednych!
   //
  double  x1, y1, x2, y2, x3, y3, x4, y4; 

  x1 = y1 = 10;
  x2 = x1 + DL_DLUGI_BOK;  y2 = y1;
  x3 = x2;  y3 = y2 + DL_KROTKI_BOK;
  x4 = x3 - DL_DLUGI_BOK; y4 = y3;


  StrmWy << setw(16) << fixed << setprecision(10) << x1+Przesuniecie 
         << setw(16) << fixed << setprecision(10) << y1+Przesuniecie << endl;
  StrmWy << setw(16) << fixed << setprecision(10) << x2+Przesuniecie 
         << setw(16) << fixed << setprecision(10) << y2+Przesuniecie << endl;
  StrmWy << setw(16) << fixed << setprecision(10) << x3+Przesuniecie 
         << setw(16) << fixed << setprecision(10) << y3+Przesuniecie << endl;
  StrmWy << setw(16) << fixed << setprecision(10) << x4+Przesuniecie 
         << setw(16) << fixed << setprecision(10) << y4+Przesuniecie << endl;
  StrmWy << setw(16) << fixed << setprecision(10) << x1+Przesuniecie 
         << setw(16) << fixed << setprecision(10) << y1+Przesuniecie << endl; 
                             // Jeszcze raz zapisujemy pierwszy punkt,
                             // aby gnuplot narysowal zamkniętą linię.



	Wektor2D w1, w2, w3, w4, przesun(Przesuniecie, Przesuniecie);

	w1[0] = w1[1] = 10;
	w2[0] = w1[0] + DL_DLUGI_BOK;  w2[1] = w1[1];
	w3[0] = w2[0];  w3[1] = w2[1] + DL_KROTKI_BOK;
	w4[0] = w3[0] - DL_DLUGI_BOK; w4[1] = w3[1];

	StrmWy << w1+przesun;
	StrmWy << w2+przesun;
	StrmWy << w3+przesun;
	StrmWy << w4+przesun;
	StrmWy << w1+przesun;
}*/

/*!
 * Przyklad zapisu wspolrzednych zbioru punktow do pliku, z ktorego
 * dane odczyta program gnuplot i narysuje je w swoim oknie graficznym.
 * \param[in] sNazwaPliku - nazwa pliku, do którego zostana zapisane
 *                          wspolrzędne punktów.
 * \param[in] Przesuniecie - ten parameter jest tylko po to, aby pokazać
 *                          mozliwosc zmiany wspolrzednych i prostokata
 *                          i zmiane jego polorzenia na okienku graficznym
 *                         rysownym przez gnuplota.
 * \retval true - gdy operacja zapisu powiodła się,
 * \retval false - w przypadku przeciwnym.
 */
/*bool PrzykladZapisuWspolrzednychDoPliku( const char  *sNazwaPliku,
                                         double       Przesuniecie
                                       )
{
  ofstream  StrmPlikowy;

  StrmPlikowy.open(sNazwaPliku);
  if (!StrmPlikowy.is_open())  {
    cerr << ":(  Operacja otwarcia do zapisu \"" << sNazwaPliku << "\"" << endl
	 << ":(  nie powiodla sie." << endl;
    return false;
  }

  PrzykladZapisuWspolrzednychDoStrumienia(StrmPlikowy,Przesuniecie);

  StrmPlikowy.close();
  return !StrmPlikowy.fail();
}*/

int main()
{
	//drawNS::Draw2DAPI *rysownik = new drawNS::APIGnuPlot2D(-20, 20, -20, 20, 1000);
	//rysownik->change_ref_time_ms(0);

	//Tworzenie prostokata na ktorym beda wykonywane operacje
	Wektor2D w1, w2, w3, w4;

	w1[0] = w1[1] = 1;
	w2[0] = w1[0] + DL_DLUGI_BOK;
	w2[1] = w1[1];
	w3[0] = w2[0];
	w3[1] = w2[1] + DL_KROTKI_BOK;
	w4[0] = w3[0] - DL_DLUGI_BOK;
	w4[1] = w3[1];

	Prostokat Pr(Wektor2D(PRZESUN,PRZESUN), Wektor2D(PRZESUN + DL_DLUGI_BOK,PRZESUN), Wektor2D(PRZESUN + DL_DLUGI_BOK,PRZESUN + DL_KROTKI_BOK), Wektor2D(PRZESUN,PRZESUN + DL_KROTKI_BOK));
	Prostokat tmp = Pr;

	//std::cout << "Wspolrzedne poczatkowego prostokata\n" << Pr << std::endl;

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
			//std::cout << MacierzObr2x2(deg*powtorzenia) << std::endl;
			//for(int i = 0; i < powtorzenia; i++)
			tmp = tmp.rotacja(MacierzObr2x2(deg*powtorzenia));
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

		std::cout << "Roznica dlugosci bokow wzgledem oryginalu\n";
		std::cout << "|P1 P2| " << (tmp[0]-tmp[1]).dlugosc() - (Pr[0]-Pr[1]).dlugosc() << std::endl;
		std::cout << "|P2 P3| " << (tmp[1]-tmp[2]).dlugosc() - (Pr[1]-Pr[2]).dlugosc() << std::endl;
		std::cout << "|P3 P4| " << (tmp[2]-tmp[3]).dlugosc() - (Pr[2]-Pr[3]).dlugosc() << std::endl;
		std::cout << "|P4 P1| " << (tmp[3]-tmp[0]).dlugosc() - (Pr[3]-Pr[0]).dlugosc() << std::endl;

		//std::cout << tmp << std::endl;

	} while (opcje != 4);

	//delete rysownik;
	return 0;
}
