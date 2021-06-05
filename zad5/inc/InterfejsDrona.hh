#ifndef INTERFEJSDRONA_HH
#define INTERFEJSDRONA_HH

class InterfejsDrona
{
public:
    InterfejsDrona () {}
    virtual void lecPion(double wysokosc) {}
    virtual void lecPrzod(double dystans) {}
    virtual void obrocZ(double deg) {}
    virtual const double & getPredObr() const = 0;
    virtual const double & getPred() const = 0;
};

#endif