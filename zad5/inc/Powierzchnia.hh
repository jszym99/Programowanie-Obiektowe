#ifndef POWIERZCHNIA_HH
#define POWIERZCHNIA_HH

#include <iostream>
#include <memory>
#include "Draw3D_api_interface.hh"
#include "InterfejsRysowania.hh"

//! \brief Modeluje klase powierzchni
class Powierzchnia : public InterfejsRysowania
{
protected:
    double wysokosc;
public:
    //! \brief Konstuktor bezparametryczny
    Powierzchnia(std::shared_ptr<drawNS::Draw3DAPI> rys, std::string col) : InterfejsRysowania(rys, col), wysokosc{0.0} {}

    //! \brief Metoda rysujaca powierzchnie
    void rysuj() override;
};

#endif