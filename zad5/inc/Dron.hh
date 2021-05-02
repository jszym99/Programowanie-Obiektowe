#ifndef DRON_HH
#define DRON_HH

#include "Prostopadloscian.hh"
#include "Graniastoslup.hh"

class Dron
{
private:
    Prostopadloscian korpus;
    std::array<Graniastoslup6, 4> wirnik;
};

#endif