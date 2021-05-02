#ifndef GRANIASTOSLUP_HH
#define GRANIASTOSLUP_HH

#include "UkladW.hh"

class Graniastoslup6 : public UkladW
{
private:
    std::array<Wektor<3>,12> punkty;
public:
    Graniastoslup6(Wektor<3> bazS, MacierzObr<3> bazO, std::array<Wektor<3>,12> wierzch) : UkladW(bazS, bazO), punkty(wierzch) {}
    void rysuj(drawNS::Draw3DAPI *rysownik, std::string kolor);
};

#endif