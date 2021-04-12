#ifndef MACIERZ2X2_HH
#define MACIERZ2X2_HH

#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>
#include <Wektor2D.hh>


/*
 * Modeluje klase dla macierzy dwuwymiarowej
 */
class MacierzObr2x2 {
private:
	std::vector<Wektor2D> wiersze;
public:
	//Konstruktory
	MacierzObr2x2(); //Macierz identycznosciowa
	MacierzObr2x2(double deg);

	//Przeciazenie operatora realizuje mnozenie macierzy
	const MacierzObr2x2 operator * (const MacierzObr2x2 & arg2) const;
	//Przeciazenie operatora realizuje mnozenie wektora przez macierz
	const Wektor2D operator * (const Wektor2D & wektor) const;
	const Wektor2D & operator [] (int ind) const; //get
};

//Funkcja zamienia wartosc kata w radianach na stopnie
double toDeg (double rad);
//Funkcja zamienia wartosc kata w stopniach na radiany
double toRad (double deg);

//Przeciazenie operatora wypisywania realizuje wyswietlanie macierzy 2x2 na wyjsciu standardowym
std::ostream& operator << (std::ostream &Strm, const MacierzObr2x2 &Mac);

#endif
