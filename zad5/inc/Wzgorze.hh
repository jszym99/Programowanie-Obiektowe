#ifndef WZGORZE_HH
#define WZGORZE_HH

#include "InterfejsRysowania.hh"
#include "InterfejsElemPowierzchni.hh"
#include "UkladW.hh"

class Wzgorze : public InterfejsRysowania, public InterfejsElemPowierzchni, public UkladW
{
public:
    Wzgorze();
    bool czy_nad() override;
    bool czy_ladowac() override;
    void rysuj() override;
};

#endif