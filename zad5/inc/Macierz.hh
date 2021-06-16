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

//! \brief Modeluje klase dla macierzy
template <int ROZMIAR>
class MacierzObr {
private:
	//! \brief Tablica wektorow tworzaca macierz
	std::vector<Wektor<ROZMIAR>> wiersze;
public:
	//! \brief Tworzy macierz identycznosciowa
	MacierzObr();
	/*!
	 * \brief Towrzy macierz obrotu względem zadanej osi o zadany kat (w stopniach)
	 * \param[in] deg - kat obrotu (w stopniach)
	 * \param[in] os_obrotu - os wzdluz ktorej odbywa sie obracanie
	 */
	MacierzObr(double deg, Os os_obrotu = Z);

	/*! \brief Przeciazenie operatora realizuje mnozenie dwoch macierzy obrotu
	 * \param[in] arg2 - macierz obrotu przez ktota mnozony jest obiekt
	 * \return macierz obrotu bedaca iloczynem dwoch macierzy obrotu (suma obrotow/katow)
	 */
	const MacierzObr<ROZMIAR> operator * (const MacierzObr<ROZMIAR> & arg2) const;
	/*! \brief Przeciazenie operatora realizuje mnozenie macierzy obrotu przez wektor
	 * \param[in] wektor - wektro obracany macierza obrotu
	 * \return wektor obrocony o macierz obrotu (o zadanym kacie)
	 */
	const Wektor<ROZMIAR> operator * (const Wektor<ROZMIAR> & wektor) const;
	/*! \brief Przeciazenie operatora realizuje pobieranie danych z obiektu
	 * \param[in] ind - indeks danych do pobrania
	 * \return wektor w polu o numerze ind 
	 */
	const Wektor<ROZMIAR> & operator [] (int ind) const;
};

/*! 
 * \brief Funkcja zamienia wartosc kata w radianach na stopnie
 * 
 * \param[in] rad kat w radianach
 * \return kat w stopniach
 */
double toDeg (double rad);
/*!
 * \brief Funkcja zamienia wartosc kata w stopniach na radiany
 * \param[in] deg - kat w stopniach
 * \return kat w radianach
 */
double toRad (double deg);

/*!
 * \brief Przeciazenie operatora wypisywania realizuje wyswietlanie macierzy na wyjsciu standardowym
 *
 * \param[in] Strm - strumien
 * \param[in] Mac - macierz do wypisania
 * 
 * \return strumien
 */
template <int ROZMIAR>
std::ostream& operator << (std::ostream &Strm, const MacierzObr<ROZMIAR> &Mac);

#endif
