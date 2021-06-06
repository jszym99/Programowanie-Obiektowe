#ifndef GRANIASTOSLUP_HH
#define GRANIASTOSLUP_HH

#include "UkladW.hh"
#include "InterfejsRysowania.hh"

//! Modeluje klase prostopadloscianu o podstawie szesciokata foremnego
class Graniastoslup6 : public UkladW, public InterfejsRysowania
{
private:
    std::array<Wektor<3>,12> punkty;
public:
    /*! Konstruktor tworzy graniastoslup o podstawie szesciokata foremnego o zadanym promieniu i wysokosci
     * \param[in] bazS - poczatkowy srodek lokalnego ukladu wspolrzednych graniastoslupa
     * \param[in] bazO - poczatkwowa orientacja lokalnego ukladu wspolrzednych graniastoslupa
     * \param[in] wsk - wskaznik na rodzica
     * \param[in] rys - wskaznik na rysownik APIGnuPlot3D
     * \param[in] col - kolor rysowanego tworzonego elementu wykorzystywany przy rysowaniu
     * \param[in] promien - promien szesciokata foremengo bedacego podstawa graniastuslupa
     * \param[in] wysokosc - wysokosc graniastoslupa
     */
    Graniastoslup6(Wektor<3> bazS, MacierzObr<3> bazO, UkladW * wsk, std::shared_ptr<drawNS::Draw3DAPI> rys, std::string col, double promien, double wysokosc);

    //! Metoda rysujaca graniastoslup
    void rysuj() override;
    /*! Metoda realizuje pobieranie id rysowania
     * \param[in] this - graniastoslup
     * \return id rysowania elementu
     */
    int getId() const {return id;}
};

#endif