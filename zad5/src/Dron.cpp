#include "Dron.hh"


// Parametry budowy elementow drona
namespace drone
{
    double dl_korp = 5;
    double szer_korp = 5;
    double wys_korp = 2;
    double r_wirnika = 2.5;
    double wys_wirnika = 1;
}

Dron::Dron(Wektor<3> bazS, MacierzObr<3> bazO, double skala) : UkladW(bazS, bazO, nullptr), korpus(Wektor<3>{0,0,0},bazO,this,skala*drone::dl_korp,skala*drone::szer_korp,skala*drone::wys_korp),
    wirnik({Graniastoslup6(Wektor<3>{-skala*drone::szer_korp/2,-skala*drone::dl_korp/2,skala*drone::wys_korp/2},bazO,this,skala*drone::r_wirnika, skala*drone::wys_wirnika),
            Graniastoslup6(Wektor<3>{-skala*drone::szer_korp/2,skala*drone::dl_korp/2,skala*drone::wys_korp/2},bazO,this,skala*drone::r_wirnika, skala*drone::wys_wirnika),
            Graniastoslup6(Wektor<3>{skala*drone::szer_korp/2,skala*drone::dl_korp/2,skala*drone::wys_korp/2},bazO,this,skala*drone::r_wirnika, skala*drone::wys_wirnika),
            Graniastoslup6(Wektor<3>{skala*drone::szer_korp/2,-skala*drone::dl_korp/2,skala*drone::wys_korp/2},bazO,this,skala*drone::r_wirnika, skala*drone::wys_wirnika)}) {}

void Dron::rysuj(drawNS::Draw3DAPI *rysownik, std::string kolor)
{
    //Rysuj korpus (prostopadloscian)
    korpus.rysuj(rysownik, kolor);
    //Rysuje kazdy wirnik po kolei
    for(int i = 0; i < 4; i++)
        wirnik[i].rysuj(rysownik, kolor);
}

void Dron::lec(double deg, double wys, double odleglosc)
{
    Wektor<3> lot{odleglosc,0,0}; //wektor o dlugosci odleglosci lotu
    Wektor<3> wznies{0,0,wys}; //wektor o dlugosci rownej wysokosci lotu
    lot = MacierzObr<3>{deg} * lot; //obrot dlugosci lotu o wektor
    srodek = srodek + wznies; //wzlot
    srodek = srodek + lot; //lot
    srodek = srodek - wznies; //londowanie (powierchnia jest plaska)
}