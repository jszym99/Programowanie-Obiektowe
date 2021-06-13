#ifndef DRON_HH
#define DRON_HH

#include "Prostopadloscian.hh"
#include "Graniastoslup.hh"
#include "InterfejsDrona.hh"
#include "InterfejsElemPowierzchni.hh"

//! Modeluje klase drona skladajacego sie z korpusu i wirnikow
class Dron : public UkladW, public InterfejsRysowania, public InterfejsDrona, public InterfejsElemPowierzchni
{
private:
    //! prostopadloscian tworzacy korpus drona
    Prostopadloscian korpus;
    //! graniastoslupy tworzace wirniki drona
    std::array<Graniastoslup6, 4> wirnik;
    //! Predkosc lotu drona
    double predkosc;
    //! Predkosc obrotu drona
    double predkoscObrotu;
    double skalaDrona;
public:
    /*! \brief Konstruktor tworzy drona o danej skali
     * \param[in] bazS - poczatkowy srodek lokalnego ukladu wspolrzednych drona
     * \param[in] bazO - poczatkwowa orientacja drona
     * \param[in] rys - wskaznik na rysownik APIGnuPlot3D
     * \param[in] col - kolor rysowanego tworzonego elementu wykorzystywany przy rysowaniu
     * \param[in] skala - skala tworzonego drona
     * \param[in] v - predkosc lotu drona [domyslne 0.5]
     * \param[in] vKat - predkosc obrotu drona [domyslne 15]
     */
    Dron(Wektor<3> bazS, MacierzObr<3> bazO, std::shared_ptr<drawNS::Draw3DAPI> rys, std::string col, double skala = 1, double v = 0.5, double vKat = 15);

    //! Metoda rysuje wszystkie figury bedace czesciami drona (korpus i wirniki)
    void rysuj() override;
    /*! Metoda symuluje lot drona w zadanym kierunku na zadana odleglosc i na zadanej wysokosci
     * \param[in] deg - kat (w stopniach) okresilajacy kierunek lotu drona
     * \param[in] wys - wysokosc lotu drona
     * \param[in] odleglosc - odleglosc, na ktora dron ma poleciec
     */
    void lec(double deg, double wys, double odleglosc);
    /*! Metoda realizująca animowany lot drona w gore/dol(ujemne)
     * \param[in] wysokosc - wysokosc lotu drona
     */
    void lecPion(double wysokosc) override;
    /*! Metoda realizujaca animowany lot drona do przodu
     * \param[in] dystans - odleglosc, na ktora dron ma poleciec
     */
    void lecPrzod(double dystans) override;
    /*! Metoda realizujaca animowany obrut drona wokol osi Z
     * \param[in] deg - kat(w stopniach) o jako dron ma sie obrocic w miejscu wokol osi Z
     */
    void obrocZ(double deg) override;
    /*! Metoda realizujaca obracanie sie wirnikow
     * \param[in] deg - kat (w stopniach) obrotu wirnikow [domyslny = 15]
    */
    void krecWirnikami(double deg = 15);
    /*! Metoda realizuje pobieranie predkosci lotu drona
     * \return predkosc lotu drona
     */
    const double & getPred() const override {return predkosc;}
    /*! Metoda realizuje pobieranie predkosci obrotu drona
     * \return predkosc predkosc brotu drona
     */
    const double & getPredObr() const override {return predkoscObrotu;}
    /*! Metoda sprawdzajaca czy dron jest nad tym dronem
     * \param[in] dron - wskaznik na drona, ktorego kolizja jest sprawdzana
     * \retval false - dron nie jest nad tym obiektem
     * \retval true - dron jest nad tym obiektem
     */
    bool czy_nad(std::shared_ptr<InterfejsDrona> dron) const override;
    /*! Metoda sprawdza czy dron moze ladowac
     * \param[in] dron - wskaznik na drona, ktorego kolizja jest sprawdzana
     * \param[out] wyokosc - wysokosc, na ktorej dron moze wyladowac
     * \retval false - dron moze ladowac
     * \retval true - dron nie moze ladowac
     */
    bool czy_ladowac(std::shared_ptr<InterfejsDrona> dron, double & wysokosc) const override;
    /*! Metoda realizuje wymazanie drona
     */
    void earaseDrone() override;
    /*! Metoda realizuje zmiane koloru drona
     * \param[in] col - kolor docelowy
     */
    void zmienKolor(std::string col) override;
    /*! Metoda realizuje pobieranie wspolrzednych srodka drona
     * \return wspolrzedne srodka drona
     */
    const Wektor<3> & getSrdoke() const {return srodek;}
    /*! Metoda realizuje liczenie wielksci drona
     * \return wielkosc drona
     */
    double wielkoscDrona() const;
};

#endif