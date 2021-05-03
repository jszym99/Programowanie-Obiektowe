#ifndef DRON_HH
#define DRON_HH

#include "Prostopadloscian.hh"
#include "Graniastoslup.hh"

//! Modeluje klase drona skladajacego sie z korpusu i wirnikow
class Dron : public UkladW
{
private:
    Prostopadloscian korpus;
    std::array<Graniastoslup6, 4> wirnik;
public:
    //! Konstruktor tworzy drona o danej skali
    Dron(Wektor<3> bazS, MacierzObr<3> bazO, double skala = 1);

    //! Metoda rysuje wszystkie figury bedace czesciami drona (korpus i wirniki)
    void rysuj(drawNS::Draw3DAPI *rysownik, std::string kolor);
    //! Metoda symuluje lot drona w zadanym kierunku na zadana odleglosc i na zadanej wysokosci
    void lec(double deg, double wys, double odleglosc);
};

#endif