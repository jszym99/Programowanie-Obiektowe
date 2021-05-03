#ifndef POWIERZCHNIA_HH
#define POWIERZCHNIA_HH

#include <iostream>
#include "Draw3D_api_interface.hh"

//! Modeluje klase powierzchni
class Powierzchnia
{
protected:
    double wysokosc;
public:
    //! Konstuktor bezparametryczny
    Powierzchnia() : wysokosc(0.0) {}

    //! Metoda rysujaca powierzchnie
    void rysuj(drawNS::Draw3DAPI *rysownik, std::string kolor);
};

#endif