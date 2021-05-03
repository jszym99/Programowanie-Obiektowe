#ifndef UKLADW_HH
#define UKLADW_HH

#include "Macierz.hh"

class UkladW
{
protected:
    UkladW* rodzic;
    Wektor<3> srodek;
    MacierzObr<3> orient;
public:
    UkladW(Wektor<3> bazS, MacierzObr<3> bazO, UkladW* pt = nullptr) : srodek(bazS), orient(bazO), rodzic(pt) {};
    void rotacja(MacierzObr<3> obr) {orient = orient * obr;}
    void translacja(Wektor<3> wek) {srodek = srodek + wek;}
    UkladW przeliczUklad(const UkladW & stary_uklad_bazowy);
    void doPoprzedniego() {if(rodzic != nullptr) (*this) = przeliczUklad(*rodzic);}
    void doBazowego() {while (rodzic != nullptr) doPoprzedniego();}
};

#endif