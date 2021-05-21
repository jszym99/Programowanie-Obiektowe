#ifndef UKLADW_HH
#define UKLADW_HH

#include "Macierz.hh"

//! Modeluje klase ukladu wspolrzednych
class UkladW
{
protected:
    //! Srodek lokalnego ukladu wspolrzednych
    Wektor<3> srodek;
    //! Orientacja lokalnego ukladu wspolrzednych
    MacierzObr<3> orient;
    //! Wskaznik na rodzica
    UkladW* rodzic;
public:
    /*! \brief Konstruktor
     * \param[in] bazS - poczatkowy srodek lokalnego ukladu wspolrzednych
     * \param[in] bazO - poczatkwowa orientacja lokalnego ukladu wspolrzednych
     * \param[in] pt - wskaznik na rodzica
     */
    UkladW(Wektor<3> bazS, MacierzObr<3> bazO, UkladW* pt = nullptr) : srodek(bazS), orient(bazO), rodzic(pt) {}
    
    /*! Metora realizująca obrot obiektu w okol lokalnego ukladu wspolrzednych
     * \param[in] obr - macierz obrotu ,o ktora obracany jest lokalny uklad wspolrzednych
     */
    void rotacja(MacierzObr<3> obr) {orient = orient * obr;}
    /*! Metora realizująca przesuniecie wzgledem lokalnego ukladu wspolrzednych
     * \param[in] wek - wektor, o ktory przesuwany jest srodek ukladu wspolrzednych
     */
    void translacja(Wektor<3> wek) {srodek = srodek + wek;}
    /*! Metoda przelicza lokalny uklad wspolrzednych inny podany w argumencie
     * \param[in] stary_uklad_bazowy - inny uklad wspolrzednych, wzgledem ktorego obliczamy lokalny uklad wspolrzednych tego obiektu
     * \return uklad wspolrzedny przeliczony wzgledem drugiego ukladu wspolrzednych
     */
    UkladW przeliczUklad(const UkladW & stary_uklad_bazowy);
    //! Metoda przelicza do ukladu wspolrzednych rodzica
    void doPoprzedniego() {if(rodzic != nullptr) (*this) = przeliczUklad(*rodzic);}
    //! Metoda przelicza do ukladu wsporzednych globalnych
    void doBazowego() {while (rodzic != nullptr) doPoprzedniego();}
    /*! Metoda przelicza punkt na wzgledem lokalnego ukladu wspolrzednych
     * \param[in] wek - wspolrzedne punktu, ktorego wspolrzedne maja zostac przeliczone
     * \return wpolrzedne punktu przeliczone o lokalny uklad wspolrzednych
     */
    Wektor<3> przeliczPunkt(const Wektor<3> & wek) {return srodek + orient * wek;}
};

#endif