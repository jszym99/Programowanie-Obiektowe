#ifndef WEKTOR_HH
#define WEKTOR_HH

#include <iostream>
#include <vector>
#include <iomanip>
#include <fstream>
#include <cmath>
#include "Dr3D_gnuplot_api.hh"


//! Modeluje klase wektora
template <int ROZMIAR>
class Wektor {
private:
	std::vector<double> tab;
	inline static unsigned int ile_suma = 0;
	inline static unsigned int ile_aktualnie = 0;
public:
	//! Wektor inicjalizowany zerami
	Wektor();
	//! Wektor inicjalizwoany zadanymi wartosciami
	Wektor(std::initializer_list<double> il) : tab(il) {ile_suma++;ile_aktualnie++;};
	//! Konstruktor kopiujący wektora
	Wektor(const Wektor & nowy);

	//! Dodawanie wektorow
	Wektor<ROZMIAR> operator + (const Wektor<ROZMIAR> & Wek2) const;
	//! Odejmowanie wektorow
	Wektor<ROZMIAR> operator - (const Wektor<ROZMIAR> & Wek2) const;
	//! Iloczyn skalarny
	double operator * (const Wektor<ROZMIAR> & Wek2) const;
	//! Mnożenie przez liczbe
	Wektor<ROZMIAR> operator * (const double & k) const;
	//! Dzielenie przez liczbe
	Wektor<ROZMIAR> operator / (const double & k) const;
	//! Przeciazenie operatora realizuje pobieranie danych z obiektu
	const double & operator [] (int ind) const;
	//! Przeciazenie operatora realizuje wpisywanie danych do obiektu
	double & operator [] (int ind);
	//! Metoda liczaca dlugosc wektora
	double dlugosc () const;

	static unsigned int get_suma() {return ile_suma;}
	static unsigned int get_aktualny() {return ile_aktualnie;}

	//! Destruktor
	~Wektor() {ile_aktualnie--;}
};

/*!
 * Funkcja konwertuje wektor (Wektor) do punktu (Punkt2D)
 * \param[in] arg wektor do zamiany na punkt
 * \return punkt 3D
 */
drawNS::Point3D konwertuj(Wektor<3> arg);

/*!
 * Przeciazenie operatora wypisywania realizujace wyswietlanie wektora
 * \param[in] Strm strumien
 * \param[in] Wek wektor do wypisania
 * 
 * \return strumien
 */
template<int ROZMIAR>
std::ostream& operator << (std::ostream &Strm, const Wektor<ROZMIAR> &Wek);

/*!
 * Przeciazenie operatora wczytywania realizujace wczytywanien wektora na wejsciu standardowym
 * \param[in] Strm strumien
 * \param[in] Wek wektor do wczytania
 * 
 * \return strumien
 */
template<int ROZMIAR>
std::istream& operator >> (std::istream &Strm, Wektor<ROZMIAR> &Wek);


#endif
