#ifndef PROSTOPADLOSCIAN_HH
#define PROSTOPADLOSCIAN_HH

#include "UkladW.hh"

//! Modeluje klase dla prostopadloscianu
class Prostopadloscian : public UkladW
{
private:
    int id; //! Numer identyfikacyjny rysunku
	std::array<Wektor<3>, 8> punkty;
public:
    //! Konstruktor tworzy prostopadloscian o zadanych dlugosciach krawedzi
    Prostopadloscian(Wektor<3> bazS, MacierzObr<3> bazO, UkladW * wsk, double dlugosc, double szerokosc, double wysokosc);

    //! Metoda rysujaca prostopadloscian
    void rysuj(drawNS::Draw3DAPI *rysownik, std::string kolor);
};

#endif
