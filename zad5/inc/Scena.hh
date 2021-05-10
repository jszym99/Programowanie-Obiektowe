#ifndef SCENA_HH
#define SCENA_HH

#include "Dron.hh"
#include <iostream>

class Scena 
{
protected:
    Dron dron;
public:
    Scena(Dron D1) : dron(D1) {}
    void Menu();
    void AnimacjaRuchu(double deg, double dyst, double wys);
};

#endif