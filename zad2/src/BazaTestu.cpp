#include <iostream>
#include <cstring>
#include <cassert>
#include "BazaTestu.hh"


bool BazaTestu::pobierz_pytanie (WyrazenieZesp & Wyraz)
{
	strm_pliku_pytan >> Wyraz;
	if(strm_pliku_pytan.good())
		return true;
	else if(strm_pliku_pytan.eof())
	{
		strm_pliku_pytan.close();
		return false;
	}
	else
	{
		//Jesli dane w pliku sa bledne
		std::cerr << "Bledne dane w pliku" << std::endl;
		//Pomija cala linijke
		strm_pliku_pytan.clear();
		strm_pliku_pytan.ignore(1000,'\n');
		//Proboje wczytac kolejna linijke
		return pobierz_pytanie(Wyraz);
	}
}

bool BazaTestu::otworz_plik (std::string nazwa)
{
	strm_pliku_pytan.open(nazwa, std::fstream::in);
	if(!strm_pliku_pytan.is_open())
	{
		std::cerr << "Nie udalo sie otworzyc pliku" << std::endl;
		return false;
	}
	else
		return true;
}

BazaTestu::BazaTestu(std::string nazwa)
{
	//Sprawdz czy naszwa w argumencie zawiera ".txt"
	if(nazwa.find(".txt") == std::string::npos)
		nazwa.append(".txt");

	otworz_plik(nazwa);
}


// Stary kod
//using namespace std;

/*
 * Tablica, ktora jest widoczna tylko w tym module.
 * Zawiera ona tresc latwego testu.
 */
/*static WyrazenieZesp TestLatwy[] =
	{
		{{2, 1}, Op_Dodaj, {1, 2}},
		{{1, 0}, Op_Odejmij, {0, 1}},
		{{3, 0}, Op_Mnoz, {0, 3}},
		{{4, 8}, Op_Dziel, {1, 0}},
};*/

/*
 * Analogicznie zdefiniuj test "trudne"
 *
 */
/*static WyrazenieZesp TestTrudny[] =
	{
		{{2, 0}, Op_Dodaj, {1, 2}},
		{{1, 1}, Op_Odejmij, {0, 1}},
		{{3, 2}, Op_Mnoz, {0, 3}},
		{{4, 8}, Op_Dziel, {2, 0}},
};*/




/*
 * W bazie testu ustawia wybrany test jako biezacy test i indeks pytania
 * ustawia na pierwsze z nich.
 * Parametry:
 *    wskBazaTestu - wskaznik na zmienna reprezentujaca baze testu,
 *    wskTabTestu  - wskaznik na tablice zawierajaca wyrazenia arytmetyczne
 *                   bedace przedmiotem testu,
 *    IloscElemTab - ilosc pytan w tablicy.
 *   
 * Warunki wstepne:
 *      - Parametr wskBazaTestu nie moze byc pustym wskaznikiem. Musi zawierac adres
 *        zmiennej reprezentujacej baze testu, ktora wczesniej zostal poprawnie
 *        zainicjalizowany poprzez wywolanie funkcji InicjalizujTest.
 *      - Parametr wskTabTestu zawiera wskaznik na istniejaca tablice.
 *      - Parametr IloscPytan zawiera wartosc, ktora nie przekracza ilosci elementow
 *        w tablicy dostepnej poprzez wskTabTestu.
 */
/*void UstawTest(BazaTestu *wskBazaTestu, WyrazenieZesp *wskTabTestu, unsigned int IloscPytan)
{
	wskBazaTestu->wskTabTestu = wskTabTestu;
	wskBazaTestu->IloscPytan = IloscPytan;
	wskBazaTestu->IndeksPytania = 0;
}*/




/*
 * Inicjalizuje test kojarzac zmienna dostepna poprzez wskaznik wskBazaTestu
 * z dana tablica wyrazen, ktora reprezentuje jeden z dwoch dopuszczalnych 
 * testow.
 * Parametry:
 *    wskBazaTestu - wskaznik na zmienna reprezentujaca baze testu.
 *    sNazwaTestu  - wskaznik na napis wybranego typu testu.
 *
 * Warunki wstepne:
 *      - Parametr wskBazaTestu nie moze byc pustym wskaznikiem. Musi zawierac adres
 *        zmiennej reprezentujacej baze testu, ktora wczesniej zostal poprawnie
 *        zainicjalizowany poprzez wywolanie funkcji InicjalizujTest.
 *      - Parametr sNazwaTestu musi wskazywac na jedna z nazw tzn. "latwe" lub "trudne".
 *       
 * Zwraca:
 *       true - gdy operacja sie powiedzie i test zostanie poprawnie
 *              zainicjalizowany,
 *       false - w przypadku przeciwnym.
 */
/*bool InicjalizujTest(BazaTestu *wskBazaTestu, const char *sNazwaTestu)
{
	if (!strcmp(sNazwaTestu, "latwy"))
	{
		UstawTest(wskBazaTestu, TestLatwy, sizeof(TestLatwy) / sizeof(WyrazenieZesp));
		return true;
	}
	else if (!strcmp(sNazwaTestu, "trudny"))
	{
		UstawTest(wskBazaTestu, TestTrudny, sizeof(TestTrudny) / sizeof(WyrazenieZesp));
		return true;
	}

	cerr << "Otwarcie testu '" << sNazwaTestu << "' nie powiodlo sie." << endl;
	return false;
}*/



/*!
 * Funkcja udostepnia nastepne pytania o ile jest odpowiednia ich ilosc.
 * Parametry:
 *       wskBazaTestu - wskaznik na zmienna reprezentujaca baze testu.
 *       wskWyrazenie - wskaznik na zmienna, do ktorej zostanie wpisane
 *                      kolejne wyrazenie z bazy testu.
 *
 * Warunki wstepne:
 *      - Parametr wskBazaTestu nie moze byc pustym wskaznikiem. Musi zawierac adres
 *        zmiennej reprezentujacej baze testu, ktora wczesniej zostal poprawnie
 *        zainicjalizowany poprzez wywolanie funkcji InicjalizujTest.
 *      - Parametr wskWyrazenie nie moze byc pustym wskaznikiem. Musi wskazywac na
 *        istniejaca zmienna.
 *
 * Zwraca:
 *       true - gdy operacja sie powiedzie i parametrowi *wskWyrazenie zostanie
 *              przypisane nowe wyrazenie zespolone z bazy,
 *       false - w przypadku przeciwnym.
 */
/*bool PobierzNastpnePytanie(BazaTestu *wskBazaTestu, WyrazenieZesp *wskWyrazenie)
{
	if (wskBazaTestu->IndeksPytania >= wskBazaTestu->IloscPytan)
		return false;

	*wskWyrazenie = wskBazaTestu->wskTabTestu[wskBazaTestu->IndeksPytania];
	++wskBazaTestu->IndeksPytania;
	return true;
}*/
