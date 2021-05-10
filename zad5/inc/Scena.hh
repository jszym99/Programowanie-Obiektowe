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
    //! Konstuktor przyjmujacy parametry do budowy drona
    Scena(Wektor<3> bazS, MacierzObr<3> bazO, std::shared_ptr<drawNS::Draw3DAPI> rys, std::string col, double skala = 1) : dron(bazS, bazO, rys, col, skala) {}
    
    //! Metoda realizujaca menu konsolowe
    void Menu();
    //! Metoda realizujaca animacje ruchu drona
    void AnimacjaRuchu(double deg, double dyst, double wys);
};

#endif