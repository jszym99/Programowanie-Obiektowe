#ifndef PLASKOWYZPROST_HH
#define PLASKOWYZPROST_HH

#include "InterfejsElemPowierzchni.hh"
#include "Prostopadloscian.hh"

class PlaskowyzProst : public Prostopadloscian//, public InterfejsElemPowierzchni
{
private:
    //! Prostopadloscian tworzacy plaskowyz prostopadloscienny
    //Prostopadloscian plasProst;
public:
    PlaskowyzProst(Wektor<3> bazS, MacierzObr<3> bazO, UkladW * wsk, std::shared_ptr<drawNS::Draw3DAPI> rys, std::string col, double dlugosc, double szerokosc, double wysokosc) : Prostopadloscian(bazS+Wektor<3>{0,0,wysokosc/2}, bazO, wsk, rys, col, dlugosc, szerokosc, wysokosc) {}
    //bool czy_nad() override;
    //bool czy_ladowac() override;
};

#endif