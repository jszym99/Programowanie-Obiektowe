#ifndef PLASKOWYZ_HH
#define PLASKOWYZ_HH

#include "InterfejsRysowania.hh"
#include "InterfejsElemPowierzchni.hh"
#include "UkladW.hh"

class Plaskowyz : public UkladW, public InterfejsRysowania, public InterfejsElemPowierzchni
{
private:
    std::vector<Wektor<3>> punkty;
public:
    /*! Konstruktor tworzacy plaskowyz o losowym ksztalcie
     * \param[in] bazS - poczatkowy srodek lokalnego ukladu wspolrzednych
     * \param[in] bazO - poczatkwowa orientacja
     * \param[in] rys - wskaznik na rysownik APIGnuPlot3D
     * \param[in] col - kolor rysowanego tworzonego elementu wykorzystywany przy rysowaniu
     * \param[in] maxPromien - maksymalna odleglosc wierzcholkow podstawy od srodka podstawy
     * \param[in] wysokosc - wysokosc graniastoslupa
     */
    Plaskowyz(Wektor<3> bazS, MacierzObr<3> bazO, std::shared_ptr<drawNS::Draw3DAPI> rys, std::string col, double maxPromien, double wysokosc);
    bool czy_nad() override {return true;};
    bool czy_ladowac() override {return true;};
    void rysuj() override;
};

#endif