#include "Wektor.hh"

template<int ROZMIAR>
Wektor<ROZMIAR> Wektor<ROZMIAR>::operator + (const Wektor<ROZMIAR> & Wek2) const
{
    Wektor<ROZMIAR> wynik;

    for(int i = 0; i < ROZMIAR; i++)
        wynik.tab[i] = tab[i] +  Wek2.tab[i];

    return wynik;
}

template<int ROZMIAR>
Wektor<ROZMIAR> Wektor<ROZMIAR>::operator - (const Wektor<ROZMIAR> & Wek2) const
{
    Wektor<ROZMIAR> wynik;

    for(int i = 0; i < ROZMIAR; i++)
        wynik.tab[i] = tab[i] -  Wek2.tab[i];

    return wynik;
}

template<int ROZMIAR>
double Wektor<ROZMIAR>::operator * (const Wektor<ROZMIAR> & Wek2) const
{
    double wynik = 0;
    for(int i = 0; i < ROZMIAR; i++)
        wynik += tab[i] * Wek2.tab[i];
    
    return wynik;
}

template<int ROZMIAR>
Wektor<ROZMIAR> Wektor<ROZMIAR>::operator * (const double & k) const
{
    Wektor<ROZMIAR> wynik;

    for(int i = 0; i < ROZMIAR; i++)
        wynik.tab[i] = k * tab[i];

    return wynik;
}

template<int ROZMIAR>
Wektor<ROZMIAR> Wektor<ROZMIAR>::operator / (const double & k) const
{
    Wektor<ROZMIAR> wynik;

    for(int i = 0; i < ROZMIAR; i++)
        wynik.tab[i] = tab[i] / k;

    return wynik;
}

template<int ROZMIAR>
const double & Wektor<ROZMIAR>::operator [] (int ind) const
{
    if (ind < 0 || ind > ROZMIAR)
        std::cerr << "Odwolanie poza pamiec" << std::endl;
    return tab[ind];
}

template<int ROZMIAR>
double & Wektor<ROZMIAR>::operator [] (int ind)
{
    if (ind < 0 || ind > ROZMIAR)
        std::cerr << "Odwolanie poza pamiec" << std::endl;
    return tab[ind];
}

template<int ROZMIAR>
double Wektor<ROZMIAR>::dlugosc () const
{
    double wynik = 0;
    for(int i = 0; i < ROZMIAR; i++)
        wynik += pow(tab[i],2);
    return sqrt(wynik);
}

template<> class Wektor<2>;
template<> class Wektor<3>;
template<> class Wektor<4>;

/*
std::ostream& operator << (std::ostream &Strm, const Wektor &Wek)
{
	//Wyswietlanie w ustalonym formacie
    Strm << std::setw(16) << std::fixed << std::setprecision(10) << Wek[0] 
         << std::setw(16) << std::fixed << std::setprecision(10) << Wek[1] << std::endl;
    Strm.unsetf(std::ios_base::fixed); //Resetowanie flag ustawnien wyswietlania
    
    return Strm;
}

std::istream& operator >> (std::istream &Strm, Wektor &Wek)
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
}*/

/*drawNS::Point2D konwertuj(Wektor arg)
{
	return drawNS::Point2D(arg[0],arg[1]);
}*/