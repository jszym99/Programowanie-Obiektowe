#include "Macierz2x2.hh"

MacierzObr2x2::MacierzObr2x2 ()
{
    wiersze.push_back(Wektor2D(1.0, 0.0));
    wiersze.push_back(Wektor2D(0.0, 1.0));
}

MacierzObr2x2::MacierzObr2x2 (double deg)
{

    wiersze.push_back(Wektor2D(cos(toRad(deg)), -sin(toRad(deg))));
    wiersze.push_back(Wektor2D(sin(toRad(deg)), cos(toRad(deg))));
}

const MacierzObr2x2 MacierzObr2x2::operator * (const MacierzObr2x2 & arg2) const
{
    MacierzObr2x2 wynik;

    wynik.wiersze[0][0] = wiersze[0][0] * arg2.wiersze[0][0] + wiersze[0][1] * arg2.wiersze[1][0];
    wynik.wiersze[0][1] = wiersze[0][0] * arg2.wiersze[0][1] + wiersze[0][1] * arg2.wiersze[1][1];
    wynik.wiersze[1][0] = wiersze[1][0] * arg2.wiersze[0][0] + wiersze[1][1] * arg2.wiersze[1][0];
    wynik.wiersze[1][1] = wiersze[1][0] * arg2.wiersze[0][1] + wiersze[1][1] * arg2.wiersze[1][1];

    return wynik;
}

const Wektor2D MacierzObr2x2::operator* (const Wektor2D & wektor) const
{
    Wektor2D wynik;

    wynik[0] = wiersze[0] * wektor;
    wynik[1] = wiersze[1] * wektor;

    return wynik;
}

const Wektor2D & MacierzObr2x2::operator [] (int ind) const
{
    if (ind < 0 || ind > 1)
        std::cerr << "Odwolanie poza pamiec" << std::endl;
    return wiersze[ind];
}

std::ostream& operator << (std::ostream &Strm, const MacierzObr2x2 &Mac)
{
    Strm << Mac[0] << Mac[1];
    return Strm;
}

double toDeg (double rad)
{
    return rad * 180/M_PI;
}

double toRad (double deg)
{
    /*while(fmod(deg,10e20))
        deg /= 10e20;*/
    return fmod(deg, 360.0) * M_PI/180;
}