#ifndef SCENA_HH
#define SCENA_HH

#include "Dron.hh"
#include "InterfejsRysowania.hh"
#include "InterfejsElemPowierzchni.hh"
#include "PlaskowyzProst.hh"
#include "Plaskowyz.hh"
#include "Wzgorze.hh"
#include <iostream>
#include <thread>
#include <chrono>
#include <vector>

//! Modeluje klase sceny lotu dronem
class Scena : public InterfejsRysowania//, public InterfejsElemPowierzchni
{
protected:
    //! Kolekcja elementow rysowalnych
    std::vector<std::shared_ptr<InterfejsRysowania>> elemRysowalne;
    //! Kolekcja elementow powierzchni
    //std::vector<std::shared_ptr<InterfejsElemPowierzchni>> elemPowierzchni;
    Dron dron;
    std::vector<PlaskowyzProst> plasProst;
public:
    /*! Konstuktor przyjmujacy parametry do budowy drona
     * \param[in] rys - wskaznik na rysownik APIGnuPlot3D
     * \param[in] col - kolor rysowanego tworzonego elementu wykorzystywany przy rysowaniu
     */
    Scena(std::shared_ptr<drawNS::Draw3DAPI> rys, std::string col);
    
    //! Metoda realizujaca menu konsolowe
    void Menu();
    /*! Metoda realizujaca animacje ruchu drona
     * \param[in] deg - kat (w stopniach) okresilajacy kierunek lotu drona
     * \param[in] dyst - odleglosc, na ktora dron ma poleciec
     * \param[in] wys - wysokosc lotu drona
     */
    void AnimacjaRuchu(double deg, double dyst, double wys);

    void rysujWszystkie();
    
    void rysuj() override {};
    //bool czy_nad() override;
    //bool czy_ladowac() override;
};

#endif