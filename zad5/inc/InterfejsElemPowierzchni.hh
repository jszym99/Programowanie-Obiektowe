#ifndef INTERFEJSELEMPOWIERZCHNI_HH
#define INTERFEJSELEMPOWIERZCHNI_HH

#include "InterfejsDrona.hh"

//! \brief  Modeluje klase interfejs elementow powierzchni
class InterfejsElemPowierzchni
{
public:
    //!\brief Konstruktor
    InterfejsElemPowierzchni() {}
     /*! \brief Metoda sprawdzajaca czy dron jest nad tym elementem krajobrazu
     * \param[in] dron - wskaznik na interfejs drona, ktorego kolizja jest sprawdzana
     * \retval false - dron nie jest nad tym obiektem
     * \retval true - dron jest nad tym obiektem
     */
    virtual bool czy_nad(std::shared_ptr<InterfejsDrona> dron) const = 0;
    /*! \brief Metoda sprawdza czy dron moze ladowac
     * \param[in] dron - wskaznik na interfejs drona, ktorego kolizja jest sprawdzana
     * \param[out] wyokosc - wysokosc, na ktorej dron moze wyladowac
     * \retval false - dron moze ladowac
     * \retval true - dron nie moze ladowac
     */
    virtual bool czy_ladowac(std::shared_ptr<InterfejsDrona> dron, double & wysokosc) const = 0;
    /*! \brief Metoda realizuje pobieranie id rysowania
     * \return id rysowania elementu
     */
    virtual int getId() const {return 0;}
    /*! \brief Metoda wyswietla dane o obiekcie
     */
    virtual void getInfo() {};

};

#endif