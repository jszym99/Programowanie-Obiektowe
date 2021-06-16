#ifndef PROSTOPADLOSCIAN_HH
#define PROSTOPADLOSCIAN_HH

#include "UkladW.hh"
#include "InterfejsRysowania.hh"

//! \brief Modeluje klase dla prostopadloscianu
class Prostopadloscian : public UkladW, public InterfejsRysowania
{
private:
	std::array<Wektor<3>, 8> punkty;
public:
    /*! \brief Konstruktor tworzy prostopadloscian o zadanych dlugosciach krawedzi
     * \param[in] bazS - poczatkowy srodek lokalnego ukladu wspolrzednych graniastoslupa
     * \param[in] bazO - poczatkwowa orientacja lokalnego ukladu wspolrzednych graniastoslupa
     * \param[in] wsk - wskaznik na rodzica
     * \param[in] rys - wskaznik na rysownik APIGnuPlot3D
     * \param[in] col - kolor rysowanego tworzonego elementu wykorzystywany przy rysowaniu
     * \param[in] dlugosc - dlugosc (Y) krawedzi prostopadloscianu
     * \param[in] szerokosc - szerokosc (X) krawedzi prostopadloscianu
     * \param[in] wysokosc - wysokosc (Z) prostopadloscianu
     */
    Prostopadloscian(Wektor<3> bazS, MacierzObr<3> bazO, UkladW * wsk, std::shared_ptr<drawNS::Draw3DAPI> rys, std::string col, double dlugosc, double szerokosc, double wysokosc);

    //! \brief Przeciazenie operatora realizuje pobieranie danych z obiektu
    const Wektor<3> &operator[](int ind) const; 

    //! \brief Metoda rysujaca prostopadloscian
    void rysuj() override;
    /*! \brief Metoda realizuje pobieranie id rysowania
     * \return id rysowania elementu
     */
    int getId() const {return id;}
};

#endif