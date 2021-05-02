#ifndef UKLADW_HH
#define UKLADW_HH

#include "Macierz.hh"

class UkladW
{
protected:
    Wektor<3> srodek;
    MacierzObr<3> orient;
public:
    UkladW(Wektor<3> bazS, MacierzObr<3> bazO) : srodek(bazS), orient(bazO) {};
    void rotacja(MacierzObr<3> obr) {orient = orient * obr;}
    void translacja(Wektor<3> wek) {srodek = srodek + wek;}
    UkladW przeliczenieUkladu (const UkladW & uklad_przeliczany, const UkladW & stary_uklad_bazowy);

};

#endif