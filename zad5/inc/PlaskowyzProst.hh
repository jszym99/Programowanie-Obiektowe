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
    /*! Metoda sprawdzajaca czy dron jest nad tym elementem krajobrazu
     * \param[in] dron - wskaznik na interfejs drona, ktorego kolizja jest sprawdzana
     * \retval false - dron nie jest nad tym obiektem
     * \retval true - dron jest nad tym obiektem
     */
    bool czy_nad(std::shared_ptr<InterfejsDrona> dron) const override;
    /*! Metoda sprawdza czy dron moze ladowac
     * \param[in] dron - wskaznik na interfejs drona, ktorego kolizja jest sprawdzana
     * \param[out] wyokosc - wysokosc, na ktorej dron moze wyladowac
     * \retval false - dron moze ladowac
     * \retval true - dron nie moze ladowac
     */
    bool czy_ladowac(std::shared_ptr<InterfejsDrona> dron, double & wysokosc) const override;
    /*! Metoda realizuje pobieranie id rysowania
     * \return id rysowania elementu
     */
    int getId() const override {return id;}
    /*! Metoda wyswietla dane o obiekcie
     */
    void getInfo() override {std::cout << "Plaskowyz prostopadloscienny" << srodek;}
};

#endif