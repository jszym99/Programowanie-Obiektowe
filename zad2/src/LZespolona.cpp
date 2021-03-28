#include "LZespolona.hh"

namespace LZesp
{
	const double epsilon = __DBL_MIN__;
}
// Konstruktory
LZespolona::LZespolona(double arg_re, double arg_im): re(arg_re), im(arg_im) {}
LZespolona::LZespolona(double arg_re): re(arg_re), im(0.0) {}
LZespolona::LZespolona(): re(0.0), im(0.0) {}


/*!
 * Realizuje dodawanie dwoch liczb zespolonych.
 *    \param[in] Skl1 pierwszy skladnik dodawania,
 *    \param[in] Skl2 drugi skladnik dodawania.
 * 
 *    \param[out] Wynik Sume dwoch skladnikow przekazanych jako parametry.
 */
LZespolona LZespolona::operator + (const LZespolona & Skl2) const
{
	LZespolona Wynik;

	Wynik.re = re + Skl2.re;
	Wynik.im = im + Skl2.im;

	return Wynik;
}


/*!
 * Realizuje odejmowanie dwoch liczb zespolonych.
 *    \param[in] Skl1 pierwszy skladnik odejmowania,
 *    \param[in] Skl2 drugi skladnik odejmowania.
 * 
 *    \param[out] Wynik Roznice dwoch skladnikow przekazanych jako parametry.
 */
LZespolona LZespolona::operator - (const LZespolona & Skl2) const
{
	LZespolona Wynik;

	Wynik.re = re - Skl2.re;
	Wynik.im = im - Skl2.im;

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
LZespolona LZespolona::operator * (const LZespolona & Skl2) const
{
	LZespolona Wynik;

	Wynik.re = re * Skl2.re - im * Skl2.im;
	Wynik.im = re * Skl2.im + Skl2.re * im;

	return Wynik;
}	


/*!
 * Realizuje dzielenia liczby zespolonej przez liczbę rzeczywistą.
 *    \param[in] Skl1 pierwszy skladnik dzielenia,
 *    \param[in] dziel drugi skladnik dzielenia.
 * 
 *    \param[out] Wynik Iloraz dwoch skladnikow przekazanych jako parametry.
 */
LZespolona LZespolona::operator / (const double & dziel) const
{
	LZespolona Wynik;
	Wynik.re = re / dziel;
	Wynik.im = im / dziel;

	return Wynik;
}


/*!
 * Realizuje dzielenia liczb zespolonych.
 *    \param[in] Skl1 pierwszy skladnik dzielenia,
 *    \param[in] Skl2 drugi skladnik dzielenia.
 * 
 *    \param[out] Wynik Iloraz dwoch skladnikow przekazanych jako parametry.
 */
LZespolona LZespolona::operator / (const LZespolona & Skl2) const
{
	LZespolona Wynik;
	
	Wynik = (*this * Skl2.sprzezenie() / Skl2.modul2());

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
	strm << "(" << dana.get_re() << std::showpos << dana.get_im() << "i)" << std::noshowpos;

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
	double liczba; //zmienna pomocnicza przechowująca zmienną liczbową

	strm >> znak;
	if(znak != '(')
		strm.setstate(std::ios::failbit);
	strm >> liczba;
	dana.set_re(liczba); // przepisanie wartości liczbowej do zmienne
	strm >> liczba;
	dana.set_im(liczba); // przepisanie wartości liczbowej do zmienne
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
double LZespolona::modul2 () const
{
	return (pow(re, 2) + pow(im, 2));
}


/*!
 * Funkcja obliczajaca sprzezenie liczby zespolonej
 *    \param[in] LZ liczba zespolona
 * 
 *    \param[out] Wynik Sprzezenie liczby zespolonej
 */
LZespolona LZespolona::sprzezenie () const
{
	LZespolona Wynik;

	Wynik.re = re;
	Wynik.im = -im;

	return Wynik;
}


/*!
 * Funkcja porownuje liczby zespolone
 *    \param[in] Skl1 porownywana liczba zespolona
 *    \param[in] Skl2 porownywana liczba zespolona
 * 
 *    \param[out] true/false sa lub nie sa rowne
 */
bool LZespolona::operator == (const LZespolona & Skl2) const
{
	if(sqrt((*this - Skl2).modul2()) <= LZesp::epsilon)
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
bool LZespolona::operator != (const LZespolona & Skl2) const
{
	return !(*this == Skl2);
}


/*!
 * Juz nie potrzebna!
 *
 * Funkcja inicjujaca liczbe zespolona z dwoch liczb rzeczywistych
 *    \param[in] re czesc rzeczywista liczby zespolonej
 *    \param[in] im czesc urojona liczby zespolonej
 * 
 *    \param[out] Wynik Liczba zespolona o zadanje wartosci
 */
/*LZespolona inicjuj (const double & re, const double & im)
{
	LZespolona Wynik;

	Wynik.re = re;
	Wynik.im = im;

	return Wynik;
}*/