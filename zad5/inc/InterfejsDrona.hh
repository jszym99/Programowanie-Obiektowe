#ifndef INTERFEJSDRONA_HH
#define INTERFEJSDRONA_HH

#include <string>
#include <Wektor.hh>

//! \brief Klasa modeluje interfejs drona
class InterfejsDrona
{
public:
    //!\brief Konstruktor
    InterfejsDrona () {}
    /*! \brief Metoda realizująca animowany lot drona w gore/dol(ujemne)
     * \param[in] wysokosc - wysokosc lotu drona
     */
    virtual void lecPion(double wysokosc) {}
    /*! \brief Metoda realizujaca animowany lot drona do przodu
     * \param[in] dystans - odleglosc, na ktora dron ma poleciec
     */
    virtual void lecPrzod(double dystans) {}
    /*! \brief Metoda realizujaca animowany obrut drona wokol osi Z
     * \param[in] deg - kat(w stopniach) o jako dron ma sie obrocic w miejscu wokol osi Z
     */
    virtual void obrocZ(double deg) {}
    /*! \brief Metoda realizuje pobieranie predkosci obrotu drona
     * \return predkosc predkosc brotu drona
     */
    virtual const double & getPredObr() const = 0;
     /*! \brief Metoda realizuje pobieranie predkosci lotu drona
     * \return predkosc lotu drona
     */
    virtual const double & getPred() const = 0;
    /*! \brief Metoda realizuje wymazanie drona
     */
    virtual void earaseDrone() {}
     /*! \brief Metoda realizuje zmiane koloru drona
     * \param[in] col - kolor docelowy
     */
    virtual void zmienKolor(std::string col) {}
     /*! \brief Metoda realizuje pobieranie wspolrzednych srodka drona
     * \return wspolrzedne srodka drona
     */
    virtual const Wektor<3> & getSrdoke() const = 0;
    /*! \brief Metoda realizuje sprawdzanie wielkosci drona
     * \return wielkosc drona
    */
    virtual double wielkoscDrona() const = 0; 
};

#endif