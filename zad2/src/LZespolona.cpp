#include "LZespolona.hh"

#define DELTA 0,000000001

/*!
 * Realizuje dodanie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik dodawania,
 *    Skl2 - drugi skladnik dodawania.
 * Zwraca:
 *    Sume dwoch skladnikow przekazanych jako parametry.
 */
LZespolona operator + (const LZespolona & Skl1, const LZespolona & Skl2)
{
	LZespolona Wynik;

	Wynik.re = Skl1.re + Skl2.re;
	Wynik.im = Skl1.im + Skl2.im;

	return Wynik;
}


/*!
 * Realizuje odejmowanie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik odejmowania,
 *    Skl2 - drugi skladnik odejmowania.
 * Zwraca:
 *    Roznice dwoch skladnikow przekazanych jako parametry.
 */
LZespolona operator - (const LZespolona & Skl1, const LZespolona & Skl2)
{
	LZespolona Wynik;

	Wynik.re = Skl1.re - Skl2.re;
	Wynik.im = Skl1.im - Skl2.im;

	return Wynik;
}

/*!
 * Realizuje mnożenie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik mnożenia,
 *    Skl2 - drugi skladnik mnożenia.
 * Zwraca:
 *    Iloczyn dwoch skladnikow przekazanych jako parametry.
 */
LZespolona operator * (const LZespolona & Skl1, const LZespolona & Skl2)
{
	LZespolona Wynik;

	Wynik.re = Skl1.re * Skl2.re - Skl1.im * Skl2.im;
	Wynik.im = Skl1.re * Skl2.im + Skl2.re * Skl1.im;

	return Wynik;
}	


/*!
 * Realizuje dzielenia liczby zespolonej przez liczbę rzeczywistą.
 * Argumenty:
 *    Skl1 - pierwszy skladnik dzielenia,
 *    dziel - drugi skladnik dzielenia.
 * Zwraca:
 *    Iloraz dwoch skladnikow przekazanych jako parametry.
 */
LZespolona operator / (const LZespolona &Skl1, const double & dziel)
{
	LZespolona Wynik;
	Wynik.re = Skl1.re / dziel;
	Wynik.im = Skl1.im / dziel;

	return Wynik;
}


/*!
 * Realizuje dzielenia liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik dzielenia,
 *    Skl2 - drugi skladnik dzielenia.
 * Zwraca:
 *    Iloraz dwoch skladnikow przekazanych jako parametry.
 */
LZespolona operator / (const LZespolona & Skl1, const LZespolona & Skl2)
{
	LZespolona Wynik;
	
	Wynik = (Skl1 * sprzezenie(Skl2) / pow(modul(Skl2),2));

	return Wynik;
}


std::ostream & operator << (std::ostream & strm, const LZespolona & dana)
{
	strm << "(" << dana.re << std::showpos << dana.im << "i)" << std::noshowpos;

	return strm;
}

std::istream & operator >> (std::istream & strm, LZespolona & dana)
{
	char znak;
	strm >> znak;
	if(znak != '(')
		strm.setstate(std::ios::failbit);
	strm >> dana.re;
	strm >> dana.im;
	strm >> znak;
	if (znak != 'i')
		strm.setstate(std::ios::failbit);
	strm >> znak;
	if (znak != ')')
		strm.setstate(std::ios::failbit);
	return strm;
}

double modul (const LZespolona & LZ)
{
	return (sqrt(pow(LZ.re, 2) + pow(LZ.im, 2)));
}

LZespolona sprzezenie (const LZespolona & LZ)
{
	LZespolona Wynik;

	Wynik.re = LZ.re;
	Wynik.im = -LZ.im;

	return Wynik;
}

bool operator == (const LZespolona & Skl1, const LZespolona & Skl2)
{
	if(modul(Skl1 - Skl2) <= DELTA)
		return true;
	else
		return false;
}

bool operator != (const LZespolona & Skl1, const LZespolona & Skl2)
{
	return !(Skl1 == Skl2);
}