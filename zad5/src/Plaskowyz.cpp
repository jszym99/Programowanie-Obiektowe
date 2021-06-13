#include "Plaskowyz.hh"

namespace plateau
{
    unsigned int seed = 5; // dla ulatwienia sprawdzania, docelowo mozna uzaleznic od czasu
    unsigned int minVertex = 6;
    unsigned int maxVertex = 12;
    unsigned int minRad = 1;
    unsigned int maxAngle = 360;
}

Plaskowyz::Plaskowyz(Wektor<3> bazS, MacierzObr<3> bazO, std::shared_ptr<drawNS::Draw3DAPI> rys, std::string col, double maxPromien, double wysokosc) : UkladW(bazS, bazO), InterfejsRysowania(rys, col)
{
    std::srand(plateau::seed);
    //Losowanie ilosci wierzcholkow
    unsigned int n = std::rand() % (plateau::maxVertex - plateau::minVertex) + plateau::minVertex;
    //Zakres kata dla kazdego wierzcholka
    unsigned int maxKat = plateau::maxAngle / n;
    //Tworzenie dolnej podstawy
    for (unsigned int i = 0; i < n; i++)
    {
        //Losowanie odleglosci wiercholka od srodka figury
        unsigned int dlugosc = std::rand() % ((int)maxPromien - plateau::minRad) + plateau::minRad;
        //Tworzenie wektora o tej dlugosci
        Wektor<3> wek{dlugosc * 1.0, 0, 0};
        //Losowanie kata obrotu wektora
        unsigned int kat = std::rand() % maxKat + i * maxKat;
        //Obrot wektora o wylosowany kat
        wek = MacierzObr<3>{kat * 1.0} * wek;
        //Wpisanei do tablicy punktow
        punkty.push_back(wek);
    }
    //Tworzenie gornej podstawy
    for (unsigned int i = 0; i < n; i++)
    {
        //punkty.push_back(punkty[i]+Wektor<3>{0,0,wysokosc});
        //Losowanie odleglosci wiercholka od srodka figury
        unsigned int dlugosc = std::rand() % ((int)maxPromien - (int)maxPromien / 2) + maxPromien / 2;
        //Tworzenie wektora o tej dlugosci
        Wektor<3> wek{dlugosc * 1.0, 0, wysokosc};
        //Losowanie kata obrotu wektora
        unsigned int kat = std::rand() % maxKat + i * maxKat;
        //Obrot wektora o wylosowany kat
        wek = MacierzObr<3>{kat * 1.0} * wek;
        //Wpisanei do tablicy punktow
        punkty.push_back(wek);
    }
}

void Plaskowyz::rysuj()
{
    if (id != -1) // Jesli obiekt byl rysowany nalezy go usunac
        rysownik->erase_shape(id);

    Plaskowyz tmp(*this); // Figura pomocnicza do rysowania w globalnym ukladzie wspolrzednych
    tmp.doBazowego();
    for (int i = 0; i < (int)punkty.size(); i++) // Przeliczanie wszystkich punktow na globalny uklad wspolrzednych
    {
        tmp.punkty[i] = tmp.przeliczPunkt(tmp.punkty[i]);
    }
    std::vector<drawNS::Point3D> podstawaDol, podstawaGora;

    for (int i = 0; i < (int)punkty.size() / 2; i++)
    {
        podstawaDol.push_back(konwertuj(tmp.punkty[i]));
        podstawaGora.push_back(konwertuj(tmp.punkty[i + (punkty.size() / 2)]));
    }

    id = rysownik->draw_polyhedron(std::vector<std::vector<drawNS::Point3D>>{podstawaDol, podstawaGora}, kolor);
}

bool Plaskowyz::czy_nad(std::shared_ptr<InterfejsDrona> dron) const
{
    double maxPromien = Wektor<2>{punkty[0][0],punkty[0][1]}.dlugosc();
    for (int i = 1; i < ((int)punkty.size()); i++)
    {
        if (Wektor<2>{punkty[i][0],punkty[i][1]}.dlugosc() > maxPromien)
        {
            maxPromien = Wektor<2>{punkty[i][0],punkty[i][1]}.dlugosc();
        }
    }
    if ((Wektor<2>{dron->getSrdoke()[0], dron->getSrdoke()[1]} - Wektor<2>{srodek[0], srodek[1]}).dlugosc() <= (maxPromien + dron->wielkoscDrona()))
    {
        return true; // Drona nad obiektem
    }
    else
    {
        return false; // Dron nie jest nad obiektem
    }
}

bool Plaskowyz::czy_ladowac(std::shared_ptr<InterfejsDrona> dron, double & wysokosc) const
{
    if (!(*this).czy_nad(dron)) // Dron nie jest nad obiektem
    {
        return true; // Mozna landowac
    }
    else
    {
        double minPromien = Wektor<2>{punkty[(int)punkty.size() / 2][0],punkty[(int)punkty.size() / 2][1]}.dlugosc();
        for (int i = (int)punkty.size() / 2; i < ((int)punkty.size()); i++)
        {
            if (Wektor<2>{punkty[i][0],punkty[i][1]}.dlugosc() < minPromien)
            {
                minPromien = Wektor<2>{punkty[i][0],punkty[i][1]}.dlugosc();
            }
        }
        if((Wektor<2>{dron->getSrdoke()[0], dron->getSrdoke()[1]} - Wektor<2>{srodek[0], srodek[1]}).dlugosc() < abs(minPromien - dron->wielkoscDrona()))
        {
            wysokosc = punkty.back()[2];
            return true; // Mozna landowac
        }
        else
        {
            return false; // Nie mozna landowac
        }
    }
}