#include "Wzgorze.hh"

namespace hill
{
    unsigned int seed = 5;
    unsigned int minVertex = 3;
    unsigned int maxVertex = 10;
    unsigned int minRad = 1;
    unsigned int maxAngle = 360;
}

Wzgorze::Wzgorze(Wektor<3> bazS, MacierzObr<3> bazO, std::shared_ptr<drawNS::Draw3DAPI> rys, std::string col, double maxPromien, double wysokosc) : UkladW(bazS, bazO), InterfejsRysowania(rys, col)
{
    std::srand(hill::seed);
    //Losowanie ilosci wierzcholkow
    unsigned int n = std::rand() % (hill::maxVertex-hill::minVertex) + hill::minVertex;
    //Zakres kata dla kazdego wierzcholka
    unsigned int maxKat = hill::maxAngle/n;
    //Tworzenie podstawy
    for(unsigned int i = 0; i < n; i++)
    {
        //Losowanie odleglosci wiercholka od srodka figury
        unsigned int dlugosc = std::rand() % ((int)maxPromien - hill::minRad) + hill::minRad;
        //Tworzenie wektora o tej dlugosci
        Wektor<3> wek{dlugosc*1.0,0,0};
        //Losowanie kata obrotu wektora
        unsigned int kat = std::rand() % maxKat + i*maxKat;
        //Obrot wektora o wylosowany kat
        wek = MacierzObr<3>{kat*1.0} * wek;
        //Wpisanei do tablicy punktow
        punkty.push_back(wek);
    }
    //Tworzenie gornego wiercholka
    //Losowanie odleglosci od srdoa gornego wierzcholka
    unsigned int dlugosc = std::rand() % ((int)maxPromien - hill::minRad) + hill::minRad;
    //Tworzenie wektora o tej dlugosc
    Wektor<3> wek{dlugosc*1.0,0,wysokosc};
    //Losowanie kata obrotu wektora
    unsigned int kat = std::rand() % hill::maxAngle;
    //Obrot wektora o wylosowany kat
    wek = MacierzObr<3>{kat*1.0} * wek;
    //Wpisanei do tablicy punktow
    punkty.push_back(wek);
    
}

void Wzgorze::rysuj()
{
    if(id != -1) // Jesli obiekt byl rysowany nalezy go usunac
        rysownik->erase_shape(id);

    Wzgorze tmp(*this); // Figura pomocnicza do rysowania w globalnym ukladzie wspolrzednych
    tmp.doBazowego();
    for(int i = 0; i < (int)punkty.size(); i++) // Przeliczanie wszystkich punktow na globalny uklad wspolrzednych
    {
        tmp.punkty[i] = tmp.przeliczPunkt(tmp.punkty[i]);
    }
    std::vector<drawNS::Point3D> wierzcholki,szczyt;

    for (int i = 0; i < (int)punkty.size()-1; i++)
    {
        wierzcholki.push_back(konwertuj(tmp.punkty[i]));
        szczyt.push_back(konwertuj(tmp.punkty[tmp.punkty.size()-1]));
    }
    
    id = rysownik->draw_polyhedron(std::vector<std::vector<drawNS::Point3D>>{wierzcholki,szczyt}, kolor);
}