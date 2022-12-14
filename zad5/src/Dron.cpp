#include "Dron.hh"


// Parametry budowy elementow drona
namespace drone
{
    double dl_korp = 5;
    double szer_korp = 5;
    double wys_korp = 2;
    double r_wirnika = 2.5;
    double wys_wirnika = 1;
    double pochyl = 10;           //kat nachylenia podczas lotu
}

Dron::Dron(Wektor<3> bazS, MacierzObr<3> bazO, std::shared_ptr<drawNS::Draw3DAPI> rys, std::string col, double skala,double v, double vKat) : UkladW(bazS, bazO, nullptr), InterfejsRysowania(rys, col), korpus(Wektor<3>{0,0,0},bazO,this,rysownik,kolor,skala*drone::dl_korp,skala*drone::szer_korp,skala*drone::wys_korp),
    wirnik({Graniastoslup6(Wektor<3>{-skala*drone::szer_korp/2,-skala*drone::dl_korp/2,skala*drone::wys_korp/2},bazO,this,rysownik,kolor,skala*drone::r_wirnika, skala*drone::wys_wirnika),
            Graniastoslup6(Wektor<3>{-skala*drone::szer_korp/2,skala*drone::dl_korp/2,skala*drone::wys_korp/2},bazO,this,rysownik,kolor,skala*drone::r_wirnika, skala*drone::wys_wirnika),
            Graniastoslup6(Wektor<3>{skala*drone::szer_korp/2,skala*drone::dl_korp/2,skala*drone::wys_korp/2},bazO,this,rysownik,kolor,skala*drone::r_wirnika, skala*drone::wys_wirnika),
            Graniastoslup6(Wektor<3>{skala*drone::szer_korp/2,-skala*drone::dl_korp/2,skala*drone::wys_korp/2},bazO,this,rysownik,kolor,skala*drone::r_wirnika, skala*drone::wys_wirnika)})
            {predkosc = v; predkoscObrotu = vKat; skalaDrona = skala;}

void Dron::rysuj()
{
    //Rysuj korpus (prostopadloscian)
    korpus.rysuj();
    //Rysuje kazdy wirnik po kolei
    for(int i = 0; i < 4; i++)
        wirnik[i].rysuj();
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

void Dron::lecPion (double wysokosc)
{
    translacja(Wektor<3>{0,0,wysokosc});
    krecWirnikami();
    rysuj();
}

void Dron::lecPrzod (double dystnas)
{
    Wektor<3> wek{dystnas, 0, 0};
    wek = orient * wek;

    translacja(wek);
    krecWirnikami();
    rotacja(MacierzObr<3>{drone::pochyl, Y}); // Pochylenie tylko do rysowania 
    rysuj();
    rotacja(MacierzObr<3>{-drone::pochyl, Y}); // Pochylenie tylko do rysowania
}

void Dron::obrocZ (double deg)
{
    rotacja(MacierzObr<3>{deg,Z});
    krecWirnikami();
    rysuj();
}

void Dron::krecWirnikami (double deg)
{
    for(int i = 0; i < 4; i++)
    {
        if(i%2) // Wirniki obracacaj?? si?? w przeciwn?? stron?? po przek??tnej
        {
            wirnik[i].rotacja(MacierzObr<3>{-deg,Z});
        }else
        {
            wirnik[i].rotacja(MacierzObr<3>{deg,Z});
        }
    }
}
void Dron::earaseDrone()
{
    rysownik->erase_shape(korpus.getId());
    for(int i = 0; i < 4; i++)
        rysownik->erase_shape(wirnik[i].getId());
}

void Dron::zmienKolor(std::string col)
{
    rysownik->change_shape_color(korpus.getId(),col);
    for(int i = 0; i < 4; i++)
        rysownik->change_shape_color(wirnik[i].getId(),col);
}

double Dron::wielkoscDrona() const
{
    return (Wektor<3>{skalaDrona*drone::szer_korp/2,skalaDrona*drone::dl_korp/2,0}).dlugosc();
}

bool Dron::czy_nad(std::shared_ptr<InterfejsDrona> dron) const
{
    /*double maxPromien = this->wielkoscDrona();
    for (int i = 1; i < ((int)punkty.size()); i++)
    {
        if (Wektor<2>{punkty[i][0],punkty[i][1]}.dlugosc() > maxPromien)
        {
            maxPromien = Wektor<2>{punkty[i][0],punkty[i][1]}.dlugosc();
        }
    }*/
    if ((Wektor<2>{dron->getSrdoke()[0], dron->getSrdoke()[1]} - Wektor<2>{this->getSrdoke()[0], this->getSrdoke()[1]}).dlugosc() <= (this->wielkoscDrona() + dron->wielkoscDrona()))
    {
        return true; // Drona nad obiektem
    }
    else
    {
        return false; // Dron nie jest nad obiektem
    }
}

bool Dron::czy_ladowac(std::shared_ptr<InterfejsDrona> dron, double & wysokosc) const
{
    if (!(*this).czy_nad(dron)) // Dron nie jest nad obiektem
    {
        return true; // Mozna landowac
    }
    else
    {
        return false; // Nie mozna landowac
    }
}