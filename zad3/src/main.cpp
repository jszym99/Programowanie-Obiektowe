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

#define DL_KROTKI_BOK 100
#define DL_DLUGI_BOK 150

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
	//drawNS::Draw2DAPI *rysownik = new drawNS::APIGnuPlot2D(-200, 200, -200, 200, 1000);

	//Testowanie zaimplementowanych metod
	Wektor2D w1, w2, w3, w4;

	w1[0] = w1[1] = 10;
	w2[0] = w1[0] + DL_DLUGI_BOK;
	w2[1] = w1[1];
	w3[0] = w2[0];
	w3[1] = w2[1] + DL_KROTKI_BOK;
	w4[0] = w3[0] - DL_DLUGI_BOK;
	w4[1] = w3[1];

	Prostokat Pr(w1, w2, w3, w4);

	Prostokat tmp = Pr;

	std::cout << "Menu:" << std::endl;

	int opcje = 0;

	do
	{
		std::cout << "[1] Obrot\n[2] Translacja\n[3] Wyswietl wsporzedne\n[4] Koniec" << std::endl;
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
				std::cerr << "Blad\n";
			}
			std::cout << "Podaj liczbe powtorzen: ";
			std::cin >> powtorzenia;
			if (cin.fail())
			{
				std::cin.clear();
				std::cin.ignore(1000, '\n');
				std::cerr << "Blad\n";
			}
			std::cout << MacierzObr2x2(deg) << std::endl;
			tmp = tmp.rotacja(MacierzObr2x2(deg * powtorzenia));
			break;
		case 2: //Przesuniecie
			{
				Wektor2D przesun(0, 0);
				std::cout << "Podaj wektor przesuniecia: ";
				std::cin >> przesun;
				if (cin.fail())
				{
					std::cin.clear();
					std::cin.ignore(1000, '\n');
					std::cerr << "Blad\n";
				}
				std::cout << przesun << std::endl;
				tmp = tmp.translacja(przesun);
			}
			break;
		case 3: //Wyswietlanie wspolrzednych
			std::cout << tmp << std::endl;
			break;
		case 4:
			break;
		default:
			std::cout << "Bledna opcja!" << std::endl;
		}

		//std::cout << tmp << std::endl;

	} while (opcje != 4);

	//delete rysownik;
	return 0;

	/*//Operacje na wektorze
	cout << "\n";
	cout << w1 + w1;
	cout << w1 - w1;
	cout << w1 * w1 << endl;
	cout << w1 * 2;
	cout << w1 / 2;

	//Operacje na macierzy
	MacierzObr2x2 obrot(45);
	cout << "\n" << obrot;

	obrot = obrot * obrot;

	cout << "\n" << obrot;

	cout << "\n" <<obrot * w1 << endl;

	Prostokat Pr(w1,w2,w3,w4);

	std::cout << Pr;

	Pr.rysuj(rysownik);

	delete rysownik;

	return 0;*/

	/*//Prostokat             Pr;   // To tylko przykladowe definicje zmiennej
  PzG::LaczeDoGNUPlota  Lacze;  // Ta zmienna jest potrzebna do wizualizacji
                                // rysunku prostokata

   //-------------------------------------------------------
   //  Wspolrzedne wierzcholkow beda zapisywane w pliku "prostokat.dat"
   //  Ponizsze metody powoduja, ze dane z pliku beda wizualizowane
   //  na dwa sposoby:
   //   1. Rysowane jako linia ciagl o grubosci 2 piksele
   //
  Lacze.DodajNazwePliku("prostokat.dat",PzG::RR_Ciagly,2);
   //
   //   2. Rysowane jako zbior punktow reprezentowanych przez kwadraty,
   //      których połowa długości boku wynosi 2.
   //
  Lacze.DodajNazwePliku("prostokat.dat",PzG::RR_Punktowy,2);
   //
   //  Ustawienie trybu rysowania 2D, tzn. rysowany zbiór punktów
   //  znajduje się na wspólnej płaszczyźnie. Z tego powodu powoduj
   //  jako wspolrzedne punktow podajemy tylko x,y.
   //
  Lacze.ZmienTrybRys(PzG::TR_2D);

  
  PrzykladZapisuWspolrzednychDoStrumienia(cout,0);
  if (!PrzykladZapisuWspolrzednychDoPliku("prostokat.dat",0)) return 1;
  Lacze.Rysuj(); // <- Tutaj gnuplot rysuje, to co zapisaliśmy do pliku
  cout << "Naciśnij ENTER, aby kontynuowac" << endl;
  cin.ignore(100000,'\n');

   //----------------------------------------------------------
   // Ponownie wypisuje wspolrzedne i rysuje prostokąt w innym miejscu.
   //
  PrzykladZapisuWspolrzednychDoStrumienia(cout,50);
  if (!PrzykladZapisuWspolrzednychDoPliku("prostokat.dat",50)) return 1;
  Lacze.Rysuj(); // <- Tutaj gnuplot rysuje, to co zapisaliśmy do pliku
  cout << "Naciśnij ENTER, aby kontynuowac" << endl;
  cin.ignore(100000,'\n');*/
}
