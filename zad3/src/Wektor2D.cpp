#include "Wektor2D.hh"

const Wektor2D Wektor2D::operator + (const Wektor2D & Wek2) const
{
    Wektor2D wynik;

    wynik.xy[0] = xy[0] +  Wek2.xy[0];
    wynik.xy[1] = xy[1] +  Wek2.xy[1];

    return wynik;
}

const Wektor2D Wektor2D::operator - (const Wektor2D & Wek2) const
{
    Wektor2D wynik;

    wynik.xy[0] = xy[0] -  Wek2.xy[0];
    wynik.xy[1] = xy[1] -  Wek2.xy[1];

    return wynik;
}

const double Wektor2D::operator * (const Wektor2D & Wek2) const
{
    double wynik;

    wynik = xy[0] * Wek2.xy[0] + xy[1] * Wek2.xy[1];

    return wynik;
}

const Wektor2D Wektor2D::operator * (const double & k) const
{
    Wektor2D wynik;

    wynik.xy[0] = k * xy[0];
    wynik.xy[1] = k * xy[1];

    return wynik;
}

const Wektor2D Wektor2D::operator / (const double & k) const
{
    Wektor2D wynik;

    wynik.xy[0] = xy[0] / k;
    wynik.xy[1] = xy[1] / k;

    return wynik;
}

const double & Wektor2D::operator [] (int ind) const
{
    if (ind < 0 || ind > 1)
        std::cerr << "Odwolanie poza pamiec" << std::endl;
    return xy[ind];
}

double & Wektor2D::operator [] (int ind)
{
    if (ind < 0 || ind > 1)
        std::cerr << "Odwolanie poza pamiec" << std::endl;
    return xy[ind];
}

const double Wektor2D::dlugosc () const
{
    return sqrt(pow(xy[0],2)+pow(xy[1],2));
}

std::ostream& operator << (std::ostream &Strm, const Wektor2D &Wek)
{
    Strm << std::setw(16) << std::fixed << std::setprecision(10) << Wek[0] 
         << std::setw(16) << std::fixed << std::setprecision(10) << Wek[1] << std::endl;
    Strm.unsetf(std::ios_base::fixed);
    
    return Strm;
}

std::istream& operator >> (std::istream &Strm, Wektor2D &Wek)
{
    char znak;
    double liczba;

    Strm >> znak;
    if(znak != '[')
        Strm.setstate(std::ios::failbit);
    Strm >> liczba;
    Wek[0] = liczba;
    Strm >> znak;
    if(znak != ',')
        Strm.setstate(std::ios::failbit);
    Strm >> liczba;
    Wek[1] = liczba;
    Strm >> znak;
    if(znak != ']')
        Strm.setstate(std::ios::failbit);
    
    return Strm;
}

drawNS::Point2D konwertuj(Wektor2D arg)
{
	return drawNS::Point2D(arg[0],arg[1]);
}