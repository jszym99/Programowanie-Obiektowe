#ifndef UKLADW_HH
#define UKLADW_HH

#include "Macierz.hh"

//! Modeluje klase ukladu wspolrzednych
class UkladW
{
protected:
    UkladW* rodzic;
    Wektor<3> srodek;
    MacierzObr<3> orient;
public:
    //! Konstruktor przyjmujacy srodek lokalnego ukladu wspolrzednych, obrot ukladu i wskazni na rodzica
    UkladW(Wektor<3> bazS, MacierzObr<3> bazO, UkladW* pt = nullptr) : srodek(bazS), orient(bazO), rodzic(pt) {}
    
    //! Metora realizująca obrot obiektu w okol lokalnego ukladu wspolrzednych
    void rotacja(MacierzObr<3> obr) {orient = orient * obr;}
    //! Metora realizująca przesuniecie wzgledem lokalnego ukladu wspolrzednych
    void translacja(Wektor<3> wek) {srodek = srodek + wek;}
    //! Metoda przelicza lokalny uklad wspolrzednych inny podany w argumencie
    UkladW przeliczUklad(const UkladW & stary_uklad_bazowy);
    //! Metoda przelicza do ukladu wspolrzednych rodzica
    void doPoprzedniego() {if(rodzic != nullptr) (*this) = przeliczUklad(*rodzic);}
    //! Metoda przelicza do ukladu wsporzednych globalnych
    void doBazowego() {while (rodzic != nullptr) doPoprzedniego();}
    //! Metoda przelicza punkt na wzgledem lokalnego ukladu wspolrzednych
    Wektor<3> przeliczPunkt(const Wektor<3> & wek) {return srodek + orient * wek;}
};

#endif