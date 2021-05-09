#ifndef SCENA_HH
#define SCENA_HH

#include "Dron.hh"

class Scena 
{
protected:
    Dron dron;
public:
    Scena(Dron D1) : dron(D1) {}
    void Menu();
    void Animacja_ruchu();
};

#endif