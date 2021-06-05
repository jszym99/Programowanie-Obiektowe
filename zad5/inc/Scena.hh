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

//! Modeluje klase sceny lotu dronem
class Scena
{
protected:
    //! Kolekcja elementow rysowalnych
    //std::vector<std::shared_ptr<InterfejsRysowania>> elemRysowalne;
    //! Kolekcja elementow powierzchni
    std::vector<std::shared_ptr<InterfejsElemPowierzchni>> elemPowierzchni;
    //! Kolekcja dronow
    std::vector<std::shared_ptr<InterfejsDrona>> drony;
    //! Rysownik
    std::shared_ptr<drawNS::Draw3DAPI> rysownik;
public:
    /*! Konstuktor
     * \param[in] rys - wskaznik na rysownik APIGnuPlot3D
     * \param[in] col - kolor rysowanego tworzonego elementu wykorzystywany przy rysowaniu
     */
    Scena(std::shared_ptr<drawNS::Draw3DAPI> rys, std::string col);
    
    void MenuDrona();
    void MenuKrajobrazu();
    //! Metoda realizujaca menu konsolowe
    void Menu();
    
    /*! Metoda realizujaca animacje ruchu drona
     * \param[in] deg - kat (w stopniach) okresilajacy kierunek lotu drona
     * \param[in] dyst - odleglosc, na ktora dron ma poleciec
     * \param[in] wys - wysokosc lotu drona
     */
    void AnimacjaRuchu(double deg, double dyst, double wys, unsigned int nrDrona = 0);
};

#endif