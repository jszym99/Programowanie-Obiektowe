#ifndef WEKTOR2D_HH
#define WEKTOR2D_HH

#include <iostream>
#include <vector>
#include <iomanip>
#include <fstream>


/*
 * Modeluje klase wektora dwuwymiarowego 
 */
class Wektor2D {
private:
	std::vector<double> xy;
public:
	Wektor2D() {xy.push_back(0.0); xy.push_back(0.0);};
	Wektor2D(double _x, double _y) {xy.push_back(_x); xy.push_back(_y);};
	const Wektor2D operator + (const Wektor2D & Wek2) const;
	const Wektor2D operator - (const Wektor2D & Wek2) const;
	const double operator * (const Wektor2D & Wek2) const; //iloczyn skalarny
	const Wektor2D operator * (const double & k) const; //mnożenie przez liczbe
	const Wektor2D operator / (const double & k) const; //dzielenie przez liczbe
	const double operator [] (int ind) const; //get
	double & operator [] (int ind); //set
};

//Point2D konwertuj(Wektor2D arg) {return Point2D(arg[0],arg[1]);}


/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt 
 */
std::istream& operator >> (std::istream &Strm, Wektor2D &Wek);

/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt 
 */
std::ostream& operator << (std::ostream &Strm, const Wektor2D &Wek);

#endif
