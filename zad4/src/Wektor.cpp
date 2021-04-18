#include "Wektor.hh"

template <int ROZMIAR>
Wektor<ROZMIAR>::Wektor()
{
    for(int i = 0; i < ROZMIAR; i++)
        tab.push_back(0.0);
}

template <int ROZMIAR>
Wektor<ROZMIAR> Wektor<ROZMIAR>::operator+(const Wektor<ROZMIAR> &Wek2) const
{
    Wektor<ROZMIAR> wynik;

    for (int i = 0; i < ROZMIAR; i++)
        wynik.tab[i] = tab[i] + Wek2.tab[i];

    return wynik;
}

template <int ROZMIAR>
Wektor<ROZMIAR> Wektor<ROZMIAR>::operator-(const Wektor<ROZMIAR> &Wek2) const
{
    Wektor<ROZMIAR> wynik;

    for (int i = 0; i < ROZMIAR; i++)
        wynik.tab[i] = tab[i] - Wek2.tab[i];

    return wynik;
}

template <int ROZMIAR>
double Wektor<ROZMIAR>::operator*(const Wektor<ROZMIAR> &Wek2) const
{
    double wynik = 0;
    for (int i = 0; i < ROZMIAR; i++)
        wynik += tab[i] * Wek2.tab[i];

    return wynik;
}

template <int ROZMIAR>
Wektor<ROZMIAR> Wektor<ROZMIAR>::operator*(const double &k) const
{
    Wektor<ROZMIAR> wynik;

    for (int i = 0; i < ROZMIAR; i++)
        wynik.tab[i] = k * tab[i];

    return wynik;
}

template <int ROZMIAR>
Wektor<ROZMIAR> Wektor<ROZMIAR>::operator/(const double &k) const
{
    Wektor<ROZMIAR> wynik;

    for (int i = 0; i < ROZMIAR; i++)
        wynik.tab[i] = tab[i] / k;

    return wynik;
}

template <int ROZMIAR>
const double &Wektor<ROZMIAR>::operator[](int ind) const
{
    if (ind < 0 || ind > ROZMIAR)
        std::cerr << "Odwolanie poza pamiec" << std::endl;
    return tab[ind];
}

template <int ROZMIAR>
double &Wektor<ROZMIAR>::operator[](int ind)
{
    if (ind < 0 || ind > ROZMIAR)
        std::cerr << "Odwolanie poza pamiec" << std::endl;
    return tab[ind];
}

template <int ROZMIAR>
double Wektor<ROZMIAR>::dlugosc() const
{
    double wynik = 0;
    for (int i = 0; i < ROZMIAR; i++)
        wynik += pow(tab[i], 2);
    return sqrt(wynik);
}

template class Wektor<2>;
template class Wektor<3>;
template class Wektor<4>;
template class Wektor<5>;
template class Wektor<6>;

template <int ROZMIAR>
std::ostream &operator<<(std::ostream &Strm, const Wektor<ROZMIAR> &Wek)
{
    //Wyswietlanie w ustalonym formacie
    for (int i = 0; i < ROZMIAR; i++)
        Strm << std::setw(16) << std::fixed << std::setprecision(10) << Wek[i];

    Strm << std::endl;
    //<< std::setw(16) << std::fixed << std::setprecision(10) << Wek[1] << std::endl;
    Strm.unsetf(std::ios_base::fixed); //Resetowanie flag ustawnien wyswietlania

    return Strm;
}

template std::ostream &operator<<(std::ostream &Strm, const Wektor<2> &Wek);
template std::ostream &operator<<(std::ostream &Strm, const Wektor<3> &Wek);
template std::ostream &operator<<(std::ostream &Strm, const Wektor<4> &Wek);
template std::ostream &operator<<(std::ostream &Strm, const Wektor<5> &Wek);
template std::ostream &operator<<(std::ostream &Strm, const Wektor<6> &Wek);

template <int ROZMIAR>
std::istream &operator>>(std::istream &Strm, Wektor<ROZMIAR> &Wek)
{
    char znak;
    double liczba;

    Strm >> znak;
    if (znak != '[')
        Strm.setstate(std::ios::failbit);
    Strm >> liczba;
    Wek[0] = liczba;

    for (int i = 1; i < ROZMIAR; i++)
    {
        Strm >> znak;
        if (znak != ',')
            Strm.setstate(std::ios::failbit);
        Strm >> liczba;
        Wek[i] = liczba;
    }
    
    Strm >> znak;
    if (znak != ']')
        Strm.setstate(std::ios::failbit);

    return Strm;
}
template std::istream &operator>>(std::istream &Strm, Wektor<2> &Wek);
template std::istream &operator>>(std::istream &Strm, Wektor<3> &Wek);
template std::istream &operator>>(std::istream &Strm, Wektor<4> &Wek);
template std::istream &operator>>(std::istream &Strm, Wektor<5> &Wek);
template std::istream &operator>>(std::istream &Strm, Wektor<6> &Wek);

/*drawNS::Point2D konwertuj(Wektor arg)
{
	return drawNS::Point2D(arg[0],arg[1]);
}*/