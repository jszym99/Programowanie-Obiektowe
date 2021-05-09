#ifndef INTRFEJSRYSOWANIA_HH
#define INTRFEJSRYSOWANIA_HH

#include "Dr3D_gnuplot_api.hh"
#include <memory>
#include <string>

class InterfejsRysowania
{
protected:
    std::shared_ptr<drawNS::Draw3DAPI> rysownik;
    int id;
    std::string kolor;
public:
    InterfejsRysowania (std::shared_ptr<drawNS::Draw3DAPI> rys, std::string col) : rysownik(rys), kolor(col) {}
    virtual void rysuj () = 0;
};

#endif