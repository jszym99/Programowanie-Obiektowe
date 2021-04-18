#ifndef MACIERZ_HH
#define MACIERZ_HH

#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>
#include <Wektor.hh>

enum Os
{
	Z,
	Y,
	X,
};

/*
 * Modeluje klase dla macierzy dwuwymiarowej
 */
template <int ROZMIAR>
class MacierzObr {
private:
	std::vector<Wektor<ROZMIAR>> wiersze;
public:
	//Konstruktory
	MacierzObr(); //Macierz identycznosciowa
	MacierzObr(double deg, Os os_obrotu = Z);

	//Przeciazenie operatora realizuje mnozenie macierzy
	const MacierzObr<ROZMIAR> operator * (const MacierzObr<ROZMIAR> & arg2) const;
	//Przeciazenie operatora realizuje mnozenie wektora przez macierz
	const Wektor<ROZMIAR> operator * (const Wektor<ROZMIAR> & wektor) const;
	const Wektor<ROZMIAR> & operator [] (int ind) const; //get
};

//Funkcja zamienia wartosc kata w radianach na stopnie
double toDeg (double rad);
//Funkcja zamienia wartosc kata w stopniach na radiany
double toRad (double deg);

//Przeciazenie operatora wypisywania realizuje wyswietlanie macierzy 2x2 na wyjsciu standardowym
template <int ROZMIAR>
std::ostream& operator << (std::ostream &Strm, const MacierzObr<ROZMIAR> &Mac);

#endif
