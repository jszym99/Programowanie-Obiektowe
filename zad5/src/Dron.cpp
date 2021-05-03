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
    Wektor<3> wznies{0,0,wys};
    lot = MacierzObr<3>{deg} * lot;
    srodek = srodek + wznies;
    srodek = srodek + lot;
    srodek = srodek - wznies;
}