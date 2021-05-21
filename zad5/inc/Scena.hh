#ifndef SCENA_HH
#define SCENA_HH

#include "Dron.hh"
#include <iostream>
#include <thread>
#include <chrono>

//! Modeluje klase sceny lotu dronem
class Scena 
{
protected:
    Dron dron;
public:
    /*! Konstuktor przyjmujacy parametry do budowy drona
     * \param[in] bazS - poczatkowy srodek lokalnego ukladu wspolrzednych drona
     * \param[in] bazO - poczatkwowa orientacja drona
     * \param[in] rys - wskaznik na rysownik APIGnuPlot3D
     * \param[in] col - kolor rysowanego tworzonego elementu wykorzystywany przy rysowaniu
     * \param[in] skala - skala tworzonego drona
     */
    Scena(Wektor<3> bazS, MacierzObr<3> bazO, std::shared_ptr<drawNS::Draw3DAPI> rys, std::string col, double skala = 1) : dron(bazS, bazO, rys, col, skala) {}
    
    //! Metoda realizujaca menu konsolowe
    void Menu();
    /*! Metoda realizujaca animacje ruchu drona
     * \param[in] deg - kat (w stopniach) okresilajacy kierunek lotu drona
     * \param[in] dyst - odleglosc, na ktora dron ma poleciec
     * \param[in] wys - wysokosc lotu drona
     */
    void AnimacjaRuchu(double deg, double dyst, double wys);
};

#endif