#ifndef WEKTOR_HH
#define WEKTOR_HH

#include <iostream>
#include <vector>
#include <iomanip>
#include <fstream>
#include <cmath>
#include "Dr3D_gnuplot_api.hh"


//! \brief Modeluje klase wektora
template <int ROZMIAR>
class Wektor {
private:
	//! \brief Tablica liczb tworzacych wekto 
	std::vector<double> tab;
	//! \brief Calkowita liczba wektorow stworzonych podczas dzialania programu
	inline static unsigned int ile_suma = 0;
	//! \brief Liczba aktualnie istniejacych wektorow
	inline static unsigned int ile_aktualnie = 0;
public:
	//! \brief Wektor inicjalizowany zerami
	Wektor();
	/*! \brief Wektor inicjalizwoany zadanymi wartosciami
	 * \param[in] il - lista inicjalizująca zawierajaca wartosci pol wektora
	 */
	Wektor(std::initializer_list<double> il) : tab(il) {ile_suma++;ile_aktualnie++;};
	/*! \brief Konstruktor kopiujący wektora
	 * \param[in] nowy - wektor, ktorego zawartosc jest kopiowana
	 */
	Wektor(const Wektor & nowy);

	/*! \brief Dodawanie wektorow
	 * \param[in] Wek2 - drugi skladnik dodawania
	 * \return suma dwoch wektorow
	 */
	Wektor<ROZMIAR> operator + (const Wektor<ROZMIAR> & Wek2) const;
	/*! \brief Odejmowanie wektorow
	 * \param[in] Wek2 - drugi skladnik odejmowania
	 * \return roznica dwoch wektorow
	 */
	Wektor<ROZMIAR> operator - (const Wektor<ROZMIAR> & Wek2) const;
	/*! \brief Iloczyn skalarny
	 * \param[in] Wek2 - drugi skladnik mnozenia skalarnego
	 * \return iloczyn skalarny dwoch wektorow
	 */
	double operator * (const Wektor<ROZMIAR> & Wek2) const;
	/*! \brief Mnożenie przez liczbe
	 * \param[in] k - liczba, przez ktora mnozony (skalowany) jest wektor
	 * \return wektor przemnozony (przeskalowany) przez liczbe k
	 */
	Wektor<ROZMIAR> operator * (const double & k) const;
	/*! \brief Dzielenie przez liczbe
	 * \param[in] k - liczba, przez ktora dzielony (skalowany) jest wektor
	 * \return wektor podzielony (przeskalowany) przez liczbe k
	 */
	Wektor<ROZMIAR> operator / (const double & k) const;
	/*! \brief Przeciazenie operatora realizuje pobieranie danych z obiektu
	 * \param[in] ind - indek danych do pobrania
	 * \return liczba w polu o danym indeksie
	 */
	const double & operator [] (int ind) const;
	/*! \brief Przeciazenie operatora realizuje wpisywanie danych do obiektu
	 * \param[in] ind - indeks pola, do ktorego wpisywane sa dane
	 */
	double & operator [] (int ind);
	/*! \brief Metoda liczaca dlugosc wektora
	 * \return dlugosc wektora
	 */
	double dlugosc () const;
	/*! \brief Metoda realizujaca pobieranie liczby stworzonych wektorow
	 * \return ilosc wektorow stworzonych od poczatku dzialania programu
	 */
	static unsigned int get_suma() {return ile_suma;}
	/*! \brief Metoda realizujaca pobieranie liczby aktualnie istniejacych wektorow
	 * \return ilosc aktualnie istniejacych wektorow
	 */
	static unsigned int get_aktualny() {return ile_aktualnie;}

	//! \brief Destruktor
	~Wektor() {ile_aktualnie--;}
};

/*!
 * \brief Funkcja konwertuje wektor (Wektor) do punktu (Punkt2D)
 * \param[in] arg - wektor do zamiany na punkt
 * \return punkt 3D
 */
drawNS::Point3D konwertuj(Wektor<3> arg);

/*!
 * \brief Przeciazenie operatora wypisywania realizujace wyswietlanie wektora
 * \param[in] Strm - strumien
 * \param[in] Wek - wektor do wypisania
 * 
 * \return strumien
 */
template<int ROZMIAR>
std::ostream& operator << (std::ostream &Strm, const Wektor<ROZMIAR> &Wek);

/*!
 * \brief Przeciazenie operatora wczytywania realizujace wczytywanien wektora na wejsciu standardowym
 * \param[in] Strm - strumien
 * \param[in] Wek - wektor do wczytania
 * 
 * \return strumien
 */
template<int ROZMIAR>
std::istream& operator >> (std::istream &Strm, Wektor<ROZMIAR> &Wek);


#endif
