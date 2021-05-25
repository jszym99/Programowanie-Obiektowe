#ifndef WZGORZE_HH
#define WZGORZE_HH

#include "InterfejsRysowania.hh"
#include "InterfejsElemPowierzchni.hh"
#include "UkladW.hh"
#include <cstdlib>

//! Modeluje klase wzgorza
class Wzgorze : public UkladW, public InterfejsRysowania, public InterfejsElemPowierzchni
{
private:
    std::vector<Wektor<3>> punkty;
public:
    /*! Konstruktor tworzacy wzgorze (ostroslup)
     * \param[in] bazS - poczatkowy srodek lokalnego ukladu wspolrzednych
     * \param[in] bazO - poczatkwowa orientacja
     * \param[in] rys - wskaznik na rysownik APIGnuPlot3D
     * \param[in] col - kolor rysowanego tworzonego elementu wykorzystywany przy rysowaniu
     * \param[in] maxPromien - maksymalna odleglosc wierzcholkow podstawy od srodka podstawy
     * \param[in] wysokosc - wysokosc ostroslupa
     */
    Wzgorze(Wektor<3> bazS, MacierzObr<3> bazO, std::shared_ptr<drawNS::Draw3DAPI> rys, std::string col, double maxPromien, double wysokosc);
    bool czy_nad() override {return true;};
    bool czy_ladowac() override {return true;};
    /*! Metoda realizuje pobieranie id rysoania
     * \param[in] this - wzgorze
     * \return id rysowania elementu
     */
    int getId() const override {return id;}
    /*! Metoda wyswietla dane o obiekcie
     * \param[in] this - wzgorze
     * \return nazwa typu obiektu oraz wspolrzedne srodka
     */
    void getInfo() const override {std::cout << "Wzgorze" << srodek;}
    void rysuj() override;
};

#endif