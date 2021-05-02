#ifndef MACIERZ_HH
#define MACIERZ_HH

#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>
#include "Wektor.hh"

enum Os
{
	Z,
	Y,
	X,
};

//! Modeluje klase dla macierzy
template <int ROZMIAR>
class MacierzObr {
private:
	std::vector<Wektor<ROZMIAR>> wiersze;
public:
	//! Tworzy macierz identycznosciowa
	MacierzObr();
	/*!
	 * Towrzy macierz obrotu względem zadanej osi o zadany kat (w stopniach)
	 * \param[in] deg kat obrotu
	 * \param[in] os_obrotu os wzdluz ktorej odbywa sie obracanie
	 */
	MacierzObr(double deg, Os os_obrotu = Z);

	//! Przeciazenie operatora realizuje mnozenie macierzy
	const MacierzObr<ROZMIAR> operator * (const MacierzObr<ROZMIAR> & arg2) const;
	//! Przeciazenie operatora realizuje mnozenie wektora przez macierz
	const Wektor<ROZMIAR> operator * (const Wektor<ROZMIAR> & wektor) const;
	//! Przeciazenie operatora realizuje pobieranie danych z obiektu
	const Wektor<ROZMIAR> & operator [] (int ind) const;
};

/*! 
 * Funkcja zamienia wartosc kata w radianach na stopnie
 * 
 * \param[in] rad kat w radianach
 * \return kat w stopniach
 */
double toDeg (double rad);
/*!
 * Funkcja zamienia wartosc kata w stopniach na radiany
 * \param[in] deg kat w stopniach
 * \return kat w radianach
 */
double toRad (double deg);

/*!
 * Przeciazenie operatora wypisywania realizuje wyswietlanie macierzy na wyjsciu standardowym
 *
 * \param[in] Strm strumien
 * \param[in] Mac macierz do wypisania
 * 
 * \return strumien
 */
template <int ROZMIAR>
std::ostream& operator << (std::ostream &Strm, const MacierzObr<ROZMIAR> &Mac);

#endif
