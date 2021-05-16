#ifndef GRANIASTOSLUP_HH
#define GRANIASTOSLUP_HH

#include "UkladW.hh"
#include "InterfejsRysowania.hh"

//! Modeluje klase prostopadloscianu o podstawie szesciokata foremnego
class Graniastoslup6 : public UkladW, public InterfejsRysowania
{
private:
    std::array<Wektor<3>,12> punkty;
public:
    //! Konstruktor tworzy graniastoslup o podstawie szesciokata foremnego o zadanym promieniu i wysokosci
    Graniastoslup6(Wektor<3> bazS, MacierzObr<3> bazO, UkladW * wsk, std::shared_ptr<drawNS::Draw3DAPI> rys, std::string col, double promien, double wysokosc);

    //! Metoda rysujaca graniastoslup
    void rysuj() override;
};

#endif