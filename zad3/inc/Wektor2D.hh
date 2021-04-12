#ifndef WEKTOR2D_HH
#define WEKTOR2D_HH

#include <iostream>
#include <vector>
#include <iomanip>
#include <fstream>
#include <cmath>
#include "Dr2D_gnuplot_api.hh"


/*
 * Modeluje klase wektora dwuwymiarowego 
 */
class Wektor2D {
private:
	std::vector<double> xy;
public:
	Wektor2D() {xy.push_back(0.0); xy.push_back(0.0);};
	Wektor2D(double _x, double _y) {xy.push_back(_x); xy.push_back(_y);};
	const Wektor2D operator + (const Wektor2D & Wek2) const; //dodawanie wektorow
	const Wektor2D operator - (const Wektor2D & Wek2) const; //odejmowanie wektorow
	const double operator * (const Wektor2D & Wek2) const; //iloczyn skalarny
	const Wektor2D operator * (const double & k) const; //mnożenie przez liczbe
	const Wektor2D operator / (const double & k) const; //dzielenie przez liczbe
	const double & operator [] (int ind) const; //get
	double & operator [] (int ind); //set
	const double dlugosc () const; //Metoda liczaca dlugosc wektora
};

//Funkcja konwertuje wektor (Wektor2D) do punktu (Punkt2D)
drawNS::Point2D konwertuj(Wektor2D arg);


//Przeciazenie operatora wczytywania realizujace wczytywanien wektora na wejsciu standardowym
std::istream& operator >> (std::istream &Strm, Wektor2D &Wek);

//Przeciazenie operatora wypisywania realizujace wyswietlanie wektora
std::ostream& operator << (std::ostream &Strm, const Wektor2D &Wek);

#endif
