#ifndef PROSTOPADLOSCIAN_HH
#define PROSTOPADLOSCIAN_HH

#include "UkladW.hh"

//! Modeluje klase dla prostopadloscianu
class Prostopadloscian : public UkladW
{
private:
	std::array<Wektor<3>, 8> punkty;
public:
    //! Konstruktory przyjmuje 8 wartosci (punktow)
    Prostopadloscian(Wektor<3> bazS, MacierzObr<3> bazO, std::array<Wektor<3>,8> wierzch) : UkladW(bazS, bazO), punkty(wierzch) {}

    /*//! Metoda obracajaca prostopadloscian o macierz obrotu
    Prostopadloscian rotacja (MacierzObr<3> obrot) const;
    //! Metoda przesuwajaca prostopadloscian o wektor
    Prostopadloscian translacja (Wektor<3> wektor) const;
    //! Metoda sprawdza czy figura jest prostopadloscianem
    bool sprawdz();*/
    //! Metoda rysujaca prostopadloscian
    void rysuj(drawNS::Draw3DAPI *rysownik, std::string kolor);
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
//bool prostokat(const Wektor<3> & P1, const Wektor<3> & P2, const Wektor<3> & P3, const Wektor<3> & P4);

#endif
