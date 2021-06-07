#include "PlaskowyzProst.hh"

bool PlaskowyzProst::czy_nad(std::shared_ptr<InterfejsDrona> dron)
{
    double maxPromien = Wektor<2>{(*this)[0][0],(*this)[0][1]}.dlugosc();
    for (int i = 1; i < 4; i++)
    {
        if (Wektor<2>{(*this)[i][0],(*this)[i][1]}.dlugosc() > maxPromien)
        {
            maxPromien = Wektor<2>{(*this)[i][0],(*this)[i][1]}.dlugosc();
        }
    }
    if ((Wektor<2>{dron->getSrdoke()[0], dron->getSrdoke()[1]} - Wektor<2>{srodek[0], srodek[1]}).dlugosc() <= (maxPromien + dron->wielkoscDrona()))
    {
        return true; // Drona nad obiektem
    }
    else
    {
        return false; // Dron nie jest nad obiektem
    }
}

bool PlaskowyzProst::czy_ladowac(std::shared_ptr<InterfejsDrona> dron, double & wysokosc)
{
    if (!(*this).czy_nad(dron)) // Dron nie jest nad obiektem
    {
        return true; // Mozna landowac
    }
    else
    {
        double minPromien = Wektor<2>{(*this)[0][0],(*this)[0][1]}.dlugosc();
        /*for (int i = 1; i < 4; i++)
        {
            if (Wektor<2>{(*this)[i][0],(*this)[i][1]}.dlugosc() < minPromien)
            {
                minPromien = Wektor<2>{(*this)[i][0],(*this)[i][1]}.dlugosc();
            }
        }*/
        if((Wektor<2>{dron->getSrdoke()[0], dron->getSrdoke()[1]} - Wektor<2>{srodek[0], srodek[1]}).dlugosc() < abs(minPromien - dron->wielkoscDrona()))
        {
            wysokosc = 2*(*this)[7][2];
            return true; // Mozna landowac
        }
        else
        {
            return false; // Nie mozna landowac
        }
    }
}