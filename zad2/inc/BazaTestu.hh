#ifndef BAZATESTU_HH
#define BAZATESTU_HH


#include "WyrazenieZesp.hh"
#include <fstream>

class BazaTestu
{
private:
	std::fstream strm_pliku_pytan;
public:
	//Metody
	bool pobierz_pytanie(WyrazenieZesp & Wyraz) /*const*/;
	bool otworz_plik(std::string nazwa);
	//Konstruktory
	BazaTestu(std::string nazwa);
	BazaTestu() {};
};


// Stary kod
/*
 * Modeluje pojecie baze testu z zestawem pytan w tablicy
 * oraz informacji o maksymalnej ilosci pytan, jak
 * tez indeksem nastepnego pytania, ktore ma byc pobrane
 * z bazy.
 */
/*struct BazaTestu
{
	WyrazenieZesp *wskTabTestu; // Wskaznik na tablice zawierajaca pytania testu
	unsigned int IloscPytan;	// Ilosc wszystkich pytan
	unsigned int IndeksPytania; // Numer pytania, ktore ma byc pobrane jako nastepne
};*/


/*
 * Inicjalizuje test powiazany z dana nazwa.
 */
//bool InicjalizujTest(BazaTestu *wskBazaTestu, const char *sNazwaTestu);
/*
 * Udostepnia nastepne pytanie z bazy.
*/
//bool PobierzNastpnePytanie(BazaTestu *wskBazaTestu, WyrazenieZesp *wskWyr);

#endif
