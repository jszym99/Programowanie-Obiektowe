#ifndef LZESPOLONA_HH
#define LZESPOLONA_HH

#include <iostream>
#include <cmath>

class LZespolona
{
private:
	double re; //Pole repezentuje czesc rzeczywista.
	double im; //Pole repezentuje czesc urojona.
public:
	// Przeciazenia operatorow
	LZespolona operator + (const LZespolona & Skl2) const;
	LZespolona operator - (const LZespolona & Skl2) const;
	LZespolona operator * (const LZespolona & Skl2) const;
	LZespolona operator / (const double & dziel) const;
	LZespolona operator / (const LZespolona & Skl2) const;
	bool operator == (const LZespolona & Skl2) const;
	bool operator != (const LZespolona & Skl2) const;
	// Metody
	double modul2 () const;
	LZespolona sprzezenie () const;
	// Konstruktory
	LZespolona(double arg_re, double arg_im);
	explicit LZespolona(double arg_re);
	LZespolona();
	// Metody pomocnicze
	double get_re() const {return re;};
	double get_im() const {return im;};
	void set_re (double _re) {re = _re;};
	void set_im (double _im) {im = _im;};
};

std::ostream & operator << (std::ostream & strm, const LZespolona & dana);
std::istream & operator >> (std::istream & strm, LZespolona & dana);

#endif
