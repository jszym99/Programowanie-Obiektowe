#include "Dron.hh"

void Dron::rysuj(drawNS::Draw3DAPI *rysownik, std::string kolor)
{
    korpus.rysuj(rysownik, kolor);
    for(int i = 0; i < 4; i++)
        wirnik[i].rysuj(rysownik, kolor);
}

void Dron::lec(double deg, double wys, double odleglosc)
{
    Wektor<3> lot{odleglosc,0,0};
}