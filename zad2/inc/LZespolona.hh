#ifndef LZESPOLONA_HH
#define LZESPOLONA_HH

#include <iostream>
#include <cmath>

/*!
 *  Plik zawiera definicje struktury LZesplona oraz zapowiedzi
 *  przeciazen operatorow arytmetycznych dzialajacych na tej 
 *  strukturze.
 */


/*!
 * Modeluje pojecie liczby zespolonej
 */
struct LZespolona
{
	double re; /*! Pole repezentuje czesc rzeczywista. */
	double im; /*! Pole repezentuje czesc urojona. */
};


/*
 * Dalej powinny pojawic sie zapowiedzi definicji przeciazen operatorow
 */

LZespolona operator + (const LZespolona & Skl1, const LZespolona & Skl2);

LZespolona operator - (const LZespolona & Skl1, const LZespolona & Skl2);

LZespolona operator * (const LZespolona & Skl1, const LZespolona & Skl2);

LZespolona operator / (const LZespolona & Skl1, const double & dziel);

LZespolona operator / (const LZespolona & Skl1, const LZespolona & Skl2);

std::ostream & operator << (std::ostream & strm, const LZespolona & dana);

std::istream & operator >> (std::istream & strm, LZespolona & dana);

double modul2 (const LZespolona & LZ);

LZespolona sprzezenie (const LZespolona & LZ);

bool operator == (const LZespolona & Skl1, const LZespolona & Skl2);

bool operator != (const LZespolona & Skl1, const LZespolona & Skl2);

LZespolona inicjuj (const double & re, const double & im);

#endif
