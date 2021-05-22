#ifndef PLASKOWYZPROST_HH
#define PLASKOWYZPROST_HH

#include "InterfejsElemPowierzchni.hh"
#include "Prostopadloscian.hh"

class PlaskowyzProst : public InterfejsElemPowierzchni, public Prostopadloscian
{
public:
    PlaskowyzProst();
    bool czy_nad() override;
    bool czy_ladowac() override;
};

#endif