#ifndef PROSTOPADLOSCIAN_HH
#define PROSTOPADLOSCIAN_HH

#include "UkladW.hh"
#include "InterfejsRysowania.hh"

//! Modeluje klase dla prostopadloscianu
class Prostopadloscian : public UkladW, public InterfejsRysowania
{
private:
	std::array<Wektor<3>, 8> punkty;
public:
    //! Konstruktor tworzy prostopadloscian o zadanych dlugosciach krawedzi
    Prostopadloscian(Wektor<3> bazS, MacierzObr<3> bazO, UkladW * wsk, std::shared_ptr<drawNS::Draw3DAPI> rys, std::string col, double dlugosc, double szerokosc, double wysokosc);

    //! Metoda rysujaca prostopadloscian
    void rysuj() override;
};

#endif