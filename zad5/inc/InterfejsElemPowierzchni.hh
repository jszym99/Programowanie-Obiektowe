#ifndef INTERFEJSELEMPOWIERZCHNI_HH
#define INTERFEJSELEMPOWIERZCHNI_HH

class InterfejsElemPowierzchni
{
public:
    InterfejsElemPowierzchni();
    virtual bool czy_nad() = 0;
    virtual bool czy_ladowac() = 0;

};

#endif