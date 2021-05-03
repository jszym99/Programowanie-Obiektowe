#ifndef POWIERZCHNIA_HH
#define POWIERZCHNIA_HH

#include "Draw3D_api_interface.hh"

class Powierzchnia
{
protected:
    double wysokosc;
public:
    Powierzchnia() : wysokosc(0.0) {}
    void rysuj(drawNS::Draw3DAPI *rysownik, std::string kolor);
};

#endif