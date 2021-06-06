#ifndef INTERFEJSELEMPOWIERZCHNI_HH
#define INTERFEJSELEMPOWIERZCHNI_HH

#include "InterfejsDrona.hh"
class InterfejsElemPowierzchni
{
public:
    InterfejsElemPowierzchni() {}
    virtual bool czy_nad(std::shared_ptr<InterfejsDrona> dron) = 0;
    virtual bool czy_ladowac(std::shared_ptr<InterfejsDrona> dron, double & wysokosc) = 0;
    virtual int getId() const {return 0;}
    virtual void getInfo() const {};

};

#endif