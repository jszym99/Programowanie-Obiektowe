#ifndef MACIERZ2X2_HH
#define MACIERZ2X2_HH


#include <iostream>
#include <cmath>
#include <Wektor2D.hh>


/*
 * Modeluje klase dla macierzy dwuwymiarowej
 */
class Macierz2x2 {
private:
	std::vector<Wektor2D> wiersze;
public:
	Macierz2x2(); //Macierz identycznosciowa
	Macierz2x2(double kat);
	const Macierz2x2 operator * (const Macierz2x2 & arg2) const;
	const Wektor2D operator * (const Wektor2D & wektor) const;
	const Wektor2D & operator [] (int ind) const;
};


/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt 
 *
 * Przeciążenie to może być użyteczne w trakcie debugowania programu.
 */
std::ostream& operator << (std::ostream &Strm, const Macierz2x2 &Mac);

#endif
