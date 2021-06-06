#ifndef INTERFEJSDRONA_HH
#define INTERFEJSDRONA_HH

#include <string>
#include <Wektor.hh>
class InterfejsDrona
{
public:
    InterfejsDrona () {}
    virtual void lecPion(double wysokosc) {}
    virtual void lecPrzod(double dystans) {}
    virtual void obrocZ(double deg) {}
    virtual const double & getPredObr() const = 0;
    virtual const double & getPred() const = 0;
    virtual void earaseDrone() {}
    virtual void zmienKolor(std::string col) {}
    virtual const Wektor<3> & getSrdoke() const = 0;
    virtual double wielkoscDrona() = 0; 
};

#endif