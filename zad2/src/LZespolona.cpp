#include "LZespolona.hh"

#define DELTA 0,000000001

/*!
 * Realizuje dodawanie dwoch liczb zespolonych.
 *    \param[in] Skl1 pierwszy skladnik dodawania,
 *    \param[in] Skl2 drugi skladnik dodawania.
 * 
 *    \param[out] Wynik Sume dwoch skladnikow przekazanych jako parametry.
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
 *    \param[in] Skl1 pierwszy skladnik odejmowania,
 *    \param[in] Skl2 drugi skladnik odejmowania.
 * 
 *    \param[out] Wynik Roznice dwoch skladnikow przekazanych jako parametry.
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
 *
 *    \param[in] Skl1 pierwszy skladnik mnożenia,
 *    \param[in] Skl2 drugi skladnik mnożenia.
 * 
 *    \param[out] Wynik Iloczyn dwoch skladnikow przekazanych jako parametry.
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
 *    \param[in] Skl1 pierwszy skladnik dzielenia,
 *    \param[in] dziel drugi skladnik dzielenia.
 * 
 *    \param[out] Wynik Iloraz dwoch skladnikow przekazanych jako parametry.
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
 *    \param[in] Skl1 pierwszy skladnik dzielenia,
 *    \param[in] Skl2 drugi skladnik dzielenia.
 * 
 *    \param[out] Wynik Iloraz dwoch skladnikow przekazanych jako parametry.
 */
LZespolona operator / (const LZespolona & Skl1, const LZespolona & Skl2)
{
	LZespolona Wynik;
	
	Wynik = (Skl1 * sprzezenie(Skl2) / modul2(Skl2));

	return Wynik;
}


/*!
 * Realizuje wypisywanie liczby zespolonej na strumieniu standardowym
 *    \param[in] strm strumien
 *    \param[in] dana liczba zespolona do wypisania
 * 
 *    \param[out] strm strumien
 */
std::ostream & operator << (std::ostream & strm, const LZespolona & dana)
{
	strm << "(" << dana.re << std::showpos << dana.im << "i)" << std::noshowpos;

	return strm;
}


/*!
 * Realizuje wczytywanie liczby zespolonej ze strumienia standardowego
 *    \param[in] strm strumien
 *    \param[in] dana liczba zespolona wczytania
 * 
 *    \param[out] strm strumien
 */
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


/*!
 * Funkcja obliczajaca modul^2 liczby zespolonej
 *    \param[in] LZ liczba zespolona
 * 
 *    \param[out] |LZ|^2 Kwadrat modulu liczby zespolonej
 */
double modul2 (const LZespolona & LZ)
{
	return (pow(LZ.re, 2) + pow(LZ.im, 2));
}


/*!
 * Funkcja obliczajaca sprzezenie liczby zespolonej
 *    \param[in] LZ liczba zespolona
 * 
 *    \param[out] Wynik Sprzezenie liczby zespolonej
 */
LZespolona sprzezenie (const LZespolona & LZ)
{
	LZespolona Wynik;

	Wynik.re = LZ.re;
	Wynik.im = -LZ.im;

	return Wynik;
}


/*!
 * Funkcja porownuje liczby zespolone
 *    \param[in] Skl1 porownywana liczba zespolona
 *    \param[in] Skl2 porownywana liczba zespolona
 * 
 *    \param[out] true/false sa lub nie sa rowne
 */
bool operator == (const LZespolona & Skl1, const LZespolona & Skl2)
{
	if(sqrt(modul2(Skl1 - Skl2)) <= DELTA)
		return true;
	else
		return false;
}


/*!
 * Funkcja sprawdza nierownosc liczb zespolonych
 *    \param[in] Skl1 porownywana liczba zespolona
 *    \param[in] Skl2 porownywana liczba zespolona
 * 
 *    \param[out] true/false nie sa lub sa rowne
 */
bool operator != (const LZespolona & Skl1, const LZespolona & Skl2)
{
	return !(Skl1 == Skl2);
}


/*!
 * Funkcja inicjujaca liczbe zespolona z dwoch liczb rzeczywistych
 *    \param[in] re czesc rzeczywista liczby zespolonej
 *    \param[in] im czesc urojona liczby zespolonej
 * 
 *    \param[out] Wynik Liczba zespolona o zadanje wartosci
 */
LZespolona inicjuj (const double & re, const double & im)
{
	LZespolona Wynik;

	Wynik.re = re;
	Wynik.im = im;

	return Wynik;
}