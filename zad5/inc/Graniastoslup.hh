#ifndef GRANIASTOSLUP_HH
#define GRANIASTOSLUP_HH

#include "UkladW.hh"

//! Modeluje klase prostopadloscianu o podstawie szesciokata foremnego
class Graniastoslup6 : public UkladW
{
private:
    int id; //! Numer identyfikacyjny rysunku
    std::array<Wektor<3>,12> punkty;
public:
    //! Konstruktor tworzy graniastoslup o podstawie szesciokata foremnego o zadanym promieniu i wysokosci
    Graniastoslup6(Wektor<3> bazS, MacierzObr<3> bazO, UkladW * wsk, double promien, double wysokosc);

    //! Metoda rysujaca graniastoslup
    void rysuj(drawNS::Draw3DAPI *rysownik, std::string kolor);
};

#endif