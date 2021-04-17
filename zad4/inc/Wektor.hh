#ifndef WEKTOR_HH
#define WEKTOR_HH

#include <iostream>
#include <vector>
#include <iomanip>
#include <fstream>
#include <cmath>
//#include "Dr2D_gnuplot_api.hh"


/*
 * Modeluje klase wektora dwuwymiarowego 
 */
template <int ROZMIAR>
class Wektor {
private:
	std::array<double, ROZMIAR> tab;
public:
	Wektor();
	//Wektor(double _x, double _y) {xy.push_back(_x); xy.push_back(_y);};
	//Wektor(std::initializer_list<double> il) : tab(il) {};
	Wektor(std::array<double, ROZMIAR> ini) : tab(ini) {};
	Wektor<ROZMIAR> operator + (const Wektor<ROZMIAR> & Wek2) const; //dodawanie wektorow
	Wektor<ROZMIAR> operator - (const Wektor<ROZMIAR> & Wek2) const; //odejmowanie wektorow
	double operator * (const Wektor<ROZMIAR> & Wek2) const; //iloczyn skalarny
	Wektor<ROZMIAR> operator * (const double & k) const; //mnożenie przez liczbe
	Wektor<ROZMIAR> operator / (const double & k) const; //dzielenie przez liczbe
	const double & operator [] (int ind) const; //get
	double & operator [] (int ind); //set
	double dlugosc () const; //Metoda liczaca dlugosc wektora
};

//Funkcja konwertuje wektor (Wektor) do punktu (Punkt2D)
//drawNS::Point2D konwertuj(Wektor arg);


//Przeciazenie operatora wczytywania realizujace wczytywanien wektora na wejsciu standardowym
template<int ROZMIAR>
std::istream& operator >> (std::istream &Strm, Wektor<ROZMIAR> &Wek);

//Przeciazenie operatora wypisywania realizujace wyswietlanie wektora
template<int ROZMIAR>
std::ostream& operator << (std::ostream &Strm, const Wektor<ROZMIAR> &Wek);

#endif
