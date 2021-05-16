#ifndef DRON_HH
#define DRON_HH

#include "Prostopadloscian.hh"
#include "Graniastoslup.hh"

//! Modeluje klase drona skladajacego sie z korpusu i wirnikow
class Dron : public UkladW, public InterfejsRysowania
{
private:
    Prostopadloscian korpus;
    std::array<Graniastoslup6, 4> wirnik;
public:
    //! Konstruktor tworzy drona o danej skali
    Dron(Wektor<3> bazS, MacierzObr<3> bazO, std::shared_ptr<drawNS::Draw3DAPI> rys, std::string col, double skala = 1);

    //! Metoda rysuje wszystkie figury bedace czesciami drona (korpus i wirniki)
    void rysuj() override;
    //! Metoda symuluje lot drona w zadanym kierunku na zadana odleglosc i na zadanej wysokosci
    void lec(double deg, double wys, double odleglosc);
    //! Metoda realizująca animowany lot drona w gore/dol(ujemne)
    void lecPion(double wysokosc);
    //! Metoda realizujaca animowany lot drona do przodu
    void lecPrzod(double dystans);
    //! Metoda realizujaca animowany obrut drona w okol osi Z
    void obrocZ(double deg);
    //! Metoda realizujaca obracanie sie wirnikow
    void krecWirnikami(double deg = 15);
};

#endif