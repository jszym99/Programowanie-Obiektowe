#ifndef DRON_HH
#define DRON_HH

#include "Prostopadloscian.hh"
#include "Graniastoslup.hh"

class Dron : public UkladW
{
private:
    Prostopadloscian korpus;
    std::array<Graniastoslup6, 4> wirnik;
public:
    Dron(Wektor<3> bazS, MacierzObr<3> bazO, Prostopadloscian korpus_ini, std::array<Graniastoslup6, 4> wirnik_ini) : UkladW(bazS, bazO), korpus(korpus_ini), wirnik(wirnik_ini) {}
    void rysuj(drawNS::Draw3DAPI *rysownik, std::string kolor);
    void lec(double deg, double wys, double odleglosc);
};

#endif