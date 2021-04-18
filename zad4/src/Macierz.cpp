#include "Macierz.hh"

template <int ROZMIAR>
MacierzObr<ROZMIAR>::MacierzObr()
{

    for (int i = 0; i < ROZMIAR; i++)
    {
        Wektor<ROZMIAR> tmp{};
        tmp[i] = 1;
        wiersze.push_back(tmp);
    }
}

template <int ROZMIAR>
MacierzObr<ROZMIAR>::MacierzObr(double deg, Os os_obr) // TODO: doadać sin
{
    int j = os_obr+1;
    double rad = toRad(deg);
    int negate = pow(-1, (os_obr%2)+1);//zmienna negująca

    for (int i = 0; i < ROZMIAR; i++)
    {
        Wektor<ROZMIAR> tmp{};
        if (i == 2-os_obr)
        {
            tmp[i] = 1;
        }
        else
        {
            tmp[i] = cos(rad);
            tmp[j] = negate*sin(rad);
            negate *= -1;
        }
        wiersze.push_back(tmp);
        j--;
    }
}

template <int ROZMIAR>
const MacierzObr<ROZMIAR> MacierzObr<ROZMIAR>::operator*(const MacierzObr<ROZMIAR> &arg2) const
{
    MacierzObr<ROZMIAR> wynik;

    for (int i = 0; i < ROZMIAR; i++)
    {
        for (int j = 0; j < ROZMIAR; j++)
        {
            double tmp = 0;
            for (int k = 0; k < ROZMIAR; k++)
            {
                tmp += wiersze[i][k] * arg2.wiersze[k][j];
            }
            wynik.wiersze[i][j] = tmp;
        }
    }

    return wynik;
}

template <int ROZMIAR>
const Wektor<ROZMIAR> MacierzObr<ROZMIAR>::operator*(const Wektor<ROZMIAR> &wektor) const
{
    Wektor<ROZMIAR> wynik;

    for (int i = 0; i < ROZMIAR; i++)
        wynik[i] = wiersze[i] * wektor;

    return wynik;
}

template <int ROZMIAR>
const Wektor<ROZMIAR> &MacierzObr<ROZMIAR>::operator[](int ind) const
{
    if (ind < 0 || ind > ROZMIAR)
        std::cerr << "Odwolanie poza pamiec" << std::endl;

    return wiersze[ind];
}
template class MacierzObr<2>;
template class MacierzObr<3>;

template <int ROZMIAR>
std::ostream &operator<<(std::ostream &Strm, const MacierzObr<ROZMIAR> &Mac)
{
    for (int i = 0; i < ROZMIAR; i++)
        Strm << Mac[i];

    return Strm;
}
template std::ostream &operator<<(std::ostream &Strm, const MacierzObr<2> &Mac);
template std::ostream &operator<<(std::ostream &Strm, const MacierzObr<3> &Mac);

double toDeg(double rad)
{
    return rad * 180 / M_PI;
}

double toRad(double deg)
{
    return fmod(deg, 360.0) * M_PI / 180;
}