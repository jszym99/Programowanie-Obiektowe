#include "Macierz2x2.hh"

Macierz2x2::Macierz2x2 ()
{
    wiersze.push_back(Wektor2D(1.0, 0.0));
    wiersze.push_back(Wektor2D(0.0, 1.0));
}

Macierz2x2::Macierz2x2 (double kat)
{

    wiersze.push_back(Wektor2D(cos(kat), -sin(kat)));
    wiersze.push_back(Wektor2D(sin(kat), cos(kat)));
}

const Macierz2x2 Macierz2x2::operator * (const Macierz2x2 & arg2) const
{
    Macierz2x2 wynik;

    wynik.wiersze[0][0] = wiersze[0][0] * arg2.wiersze[0][0] + wiersze[0][1] * arg2.wiersze[1][0];
    wynik.wiersze[0][1] = wiersze[0][0] * arg2.wiersze[0][1] + wiersze[0][1] * arg2.wiersze[1][1];
    wynik.wiersze[1][0] = wiersze[1][0] * arg2.wiersze[0][0] + wiersze[1][1] * arg2.wiersze[1][0];
    wynik.wiersze[1][1] = wiersze[1][0] * arg2.wiersze[0][1] + wiersze[1][1] * arg2.wiersze[1][1];

    return wynik;
}

const Wektor2D Macierz2x2::operator* (const Wektor2D & wektor) const
{
    Wektor2D wynik;

    wynik[0] = wiersze[0][0] * wektor[0] + wiersze[0][1] * wektor[1];
    wynik[1] = wiersze[1][0] * wektor[0] + wiersze[1][1] * wektor[1];

    return wynik;
}

const Wektor2D Macierz2x2::operator [] (int ind) const
{
    return wiersze[ind];
}

std::ostream& operator << (std::ostream &Strm, const Macierz2x2 &Mac)
{
    Strm << Mac[0] << Mac[1];
}