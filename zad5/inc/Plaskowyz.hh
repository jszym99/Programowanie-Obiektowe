#ifndef PLASKOWYZ_HH
#define PLASKOWYZ_HH

#include "InterfejsRysowania.hh"
#include "InterfejsElemPowierzchni.hh"
#include "UkladW.hh"


//! \brief Modeluje klase plaskowyzu
class Plaskowyz : public UkladW, public InterfejsRysowania, public InterfejsElemPowierzchni
{
private:
    std::vector<Wektor<3>> punkty;
public:
    /*! \brief Konstruktor tworzacy plaskowyz o losowym ksztalcie
     * \param[in] bazS - poczatkowy srodek lokalnego ukladu wspolrzednych
     * \param[in] bazO - poczatkwowa orientacja
     * \param[in] rys - wskaznik na rysownik APIGnuPlot3D
     * \param[in] col - kolor rysowanego tworzonego elementu wykorzystywany przy rysowaniu
     * \param[in] maxPromien - maksymalna odleglosc wierzcholkow podstawy od srodka podstawy
     * \param[in] wysokosc - wysokosc graniastoslupa
     */
    Plaskowyz(Wektor<3> bazS, MacierzObr<3> bazO, std::shared_ptr<drawNS::Draw3DAPI> rys, std::string col, double maxPromien, double wysokosc);
    /*! \brief Metoda sprawdzajaca czy dron jest nad tym elementem krajobrazu
     * \param[in] dron - wskaznik na interfejs drona, ktorego kolizja jest sprawdzana
     * \retval false - dron nie jest nad tym obiektem
     * \retval true - dron jest nad tym obiektem
     */
    bool czy_nad(std::shared_ptr<InterfejsDrona> dron) const override;
    /*! \brief Metoda sprawdza czy dron moze ladowac
     * \param[in] dron - wskaznik na interfejs drona, ktorego kolizja jest sprawdzana
     * \param[out] wyokosc - wysokosc, na ktorej dron moze wyladowac
     * \retval false - dron moze ladowac
     * \retval true - dron nie moze ladowac
     */
    bool czy_ladowac(std::shared_ptr<InterfejsDrona> dron, double & wysokosc) const override;
    /*! \brief Metoda realizuje pobieranie id rysowania
     * \return id rysowania elementu
     */
    int getId() const override {return id;}
    /*! \brief Metoda wyswietla dane o obiekcie
     */
    void getInfo() override {std::cout << "Plaskowyz" << srodek;}
    void rysuj() override;
};

#endif