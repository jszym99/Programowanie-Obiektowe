#ifndef PLASKOWYZPROST_HH
#define PLASKOWYZPROST_HH

#include "InterfejsElemPowierzchni.hh"
#include "Prostopadloscian.hh"

//! Modeluje klase plaskowyzu prostopadlosciennego
class PlaskowyzProst : public Prostopadloscian, public InterfejsElemPowierzchni
{
private:
    //! Prostopadloscian tworzacy plaskowyz prostopadloscienny
    //Prostopadloscian plasProst;
public:
    /*! Konstruktor tworzacy plaskowyz prostopadloscienny
     * \param[in] bazS - poczatkowy srodek lokalnego ukladu wspolrzednych
     * \param[in] bazO - poczatkwowa orientacja
     * \param[in] wsk - wskaznik na rodzica
     * \param[in] rys - wskaznik na rysownik APIGnuPlot3D
     * \param[in] col - kolor rysowanego tworzonego elementu wykorzystywany przy rysowaniu
     * \param[in] dlugosc - dlugosc (Y) krawedzi prostopadloscianu
     * \param[in] szerokosc - szerokosc (X) krawedzi prostopadloscianu
     * \param[in] wysokosc - wysokosc (Z) prostopadloscianu
     */
    PlaskowyzProst(Wektor<3> bazS, MacierzObr<3> bazO, std::shared_ptr<drawNS::Draw3DAPI> rys, std::string col, double dlugosc, double szerokosc, double wysokosc) : Prostopadloscian(bazS+Wektor<3>{0,0,wysokosc/2}, bazO, nullptr, rys, col, dlugosc, szerokosc, wysokosc) {}
    bool czy_nad() override {return true;};
    bool czy_ladowac() override {return true;};
    /*! Metoda realizuje pobieranie id rysoania
     * \param[in] this - plaskowyz prostopadloscienny
     * \return id rysowania elementu
     */
    int getId() const override {return id;}
    /*! Metoda wyswietla dane o obiekcie
     * \param[in] this - plaskowyz prostopadloscienny
     * \return nazwa typu obiektu oraz wspolrzedne srodka
     */
    void getInfo() const override {std::cout << "Plaskowyz prostopadloscienny" << srodek;}
};

#endif