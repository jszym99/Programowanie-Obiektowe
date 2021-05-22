#ifndef PLASKOWYZ_HH
#define PLASKOWYZ_HH

#include "InterfejsRysowania.hh"
#include "InterfejsElemPowierzchni.hh"
#include "UkladW.hh"

class Plaskowyz : public InterfejsRysowania, public InterfejsElemPowierzchni, public UkladW
{
public:
    Plaskowyz();
    bool czy_nad() override;
    bool czy_ladowac() override;
    void rysuj() override;
};

#endif