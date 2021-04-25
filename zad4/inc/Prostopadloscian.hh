#ifndef PROSTOPADLOSCIAN_HH
#define PROSTOPADLOSCIAN_HH

#include <iostream>
#include "Macierz.hh"


class Prostopadloscian
{
private:
	std::vector<Wektor<3>> punkty;
public:
    //Konstruktory
    Prostopadloscian(std::initializer_list<Wektor<3>> il); //! konstruktory przyjmuje 8 wartosci (punktow)
    Prostopadloscian rotacja (MacierzObr<3> obrot) const;
    Prostopadloscian translacja (Wektor<3> wektor) const;
    //! Przeciazenie operatora realizuje pobieranie danych z obiektu
    const Wektor<3> &operator[](int ind) const; 
    //! Metoda sprawdza czy figura jest prostopadloscianem
    bool sprawdz();
    //! Metoda rysujaca prostopadloscian
    void rysuj(drawNS::Draw3DAPI *rysownik, std::string kolor);
    //! Metoda sprawdza rownosc krawedzi prostopadloscianu i wyswietla bledy numeryczne
    void porownanie();
};

/*!
 *
 * Funkcja sprawdza czy figura o zadanych wierzcholkach jest prostokatem
 * \param[in] P1 pierwszy wierzcholek
 * \param[in] P2 drugi wierzcholek
 * \param[in] P3 trzeci wierzcholek
 * \param[in] P4 czwarty wierzcholek
 * 
 * \retval  false jesli figura nie jest prostokatem
 * \retval  true jesli figura jest prostokatem
 */
bool prostokat(const Wektor<3> & P1, const Wektor<3> & P2, const Wektor<3> & P3, const Wektor<3> & P4);

/*!
 * Przeciazenie operatora wypisywania realizuje wyswietlanie prostopadloscianu na wyjsciu standardowym
 * \param[in] Strm strumien
 * \param[in] Pr prostopadloscian do wypisania
 * 
 * \return strumien
 */
std::ostream &operator<<(std::ostream &Strm, const Prostopadloscian &Pr);

#endif
