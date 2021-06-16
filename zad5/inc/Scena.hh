#ifndef SCENA_HH
#define SCENA_HH

#include "Dron.hh"
#include "InterfejsRysowania.hh"
#include "InterfejsElemPowierzchni.hh"
#include "PlaskowyzProst.hh"
#include "Plaskowyz.hh"
#include "Wzgorze.hh"
#include "Powierzchnia.hh"
#include "InterfejsDrona.hh"
#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
#include <cmath>
#include <typeinfo>

//! \brief Modeluje klase sceny lotu dronem
class Scena
{
protected:
    //! \brief Kolekcja elementow powierzchni
    std::vector<std::shared_ptr<InterfejsElemPowierzchni>> elemPowierzchni;
    //! \brief Kolekcja dronow
    std::vector<std::shared_ptr<InterfejsDrona>> drony;
    //! \brief Rysownik
    std::shared_ptr<drawNS::Draw3DAPI> rysownik;
public:
    /*! \brief Konstuktor
     * \param[in] rys - wskaznik na rysownik APIGnuPlot3D
     * \param[in] col - kolor rysowanego tworzonego elementu wykorzystywany przy rysowaniu
     */
    Scena(std::shared_ptr<drawNS::Draw3DAPI> rys, std::string col);
    
    //! \brief Metoda realizuje menu drona
    void MenuDrona();
    //! \brief Metoda realizuje menu elementow krajobrazu
    void MenuKrajobrazu();
    //! \brief Metoda realizujaca menu konsolowe
    void Menu();
    
    /*! \brief Metoda realizujaca animacje ruchu drona
     * \param[in] deg - kat (w stopniach) okresilajacy kierunek lotu drona
     * \param[in] dyst - odleglosc, na ktora dron ma poleciec
     * \param[in] wys - wysokosc lotu drona
     */
    void AnimacjaRuchu(double deg, double dyst, double wys, unsigned int nrDrona = 0);
};

#endif