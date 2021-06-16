#ifndef INTRFEJSRYSOWANIA_HH
#define INTRFEJSRYSOWANIA_HH

#include "Dr3D_gnuplot_api.hh"
#include <memory>
#include <string>


//! \brief Modeluje klase interfejsu rysowania
class InterfejsRysowania
{
protected:
    std::shared_ptr<drawNS::Draw3DAPI> rysownik;
    int id;
    std::string kolor;
public:
    /*! \brief Konstruktor
     * \param[in] rys - wskaznik na rysownik APIGnuPlot3D
     * \param[in] col - kolor rysowanego tworzonego elementu wykorzystywany przy rysowaniu
     */
    InterfejsRysowania (std::shared_ptr<drawNS::Draw3DAPI> rys, std::string col) : rysownik(rys), kolor(col) {}
    //! \brief Metoda wirtualna realizujaca rysowanie elementu
    virtual void rysuj () = 0;
};

#endif