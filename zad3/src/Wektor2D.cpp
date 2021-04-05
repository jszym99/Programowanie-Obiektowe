#include "Wektor2D.hh"

const Wektor2D & Wektor2D::operator + (const Wektor2D & Wek2) const
{
    Wektor2D wynik;

    wynik.xy[0] = xy[0] +  Wek2.xy[0];
    wynik.xy[1] = xy[1] +  Wek2.xy[1];

    return wynik;
}

const Wektor2D & Wektor2D::operator - (const Wektor2D & Wek2) const
{
    Wektor2D wynik;

    wynik.xy[0] = xy[0] -  Wek2.xy[0];
    wynik.xy[1] = xy[1] -  Wek2.xy[1];

    return wynik;
}

const double & Wektor2D::operator * (const Wektor2D & Wek2) const
{
    double wynik;

    wynik = xy[0] * Wek2.xy[0] + xy[1] * Wek2.xy[1];

    return wynik;
}

const Wektor2D & Wektor2D::operator * (const double & k) const
{
    Wektor2D wynik;

    wynik.xy[0] = k * xy[0];
    wynik.xy[1] = k * xy[1];

    return wynik;
}

const Wektor2D & Wektor2D::operator / (const double & k) const
{
    Wektor2D wynik;

    wynik.xy[0] = k / xy[0];
    wynik.xy[1] = k / xy[1];

    return wynik;
}

const double & Wektor2D::operator [] (int ind) const
{
    return xy[ind];
}

double & Wektor2D::operator [] (int ind)
{
    if (ind < 0 || ind > 1)
        std::cerr << "Odwolanie poza pamiec" << std::endl;
    return xy[ind];
}