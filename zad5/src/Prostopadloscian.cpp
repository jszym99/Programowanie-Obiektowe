#include "Prostopadloscian.hh"

Prostopadloscian::Prostopadloscian(Wektor<3> bazS, MacierzObr<3> bazO, UkladW * wsk, std::shared_ptr<drawNS::Draw3DAPI> rys, std::string col, double dlugosc, double szerokosc, double wysokosc) : UkladW(bazS, bazO, wsk), InterfejsRysowania(rys, col)
{
    //Tworzymy prostopadloscian o zadanych dlugosciach krawedzi
    //Dolna podstawa
    punkty[0] = Wektor<3>{-szerokosc/2, -dlugosc/2, -wysokosc/2};
    punkty[1] = Wektor<3>{-szerokosc/2, dlugosc/2, -wysokosc/2};
    punkty[2] = Wektor<3>{szerokosc/2, dlugosc/2, -wysokosc/2};
    punkty[3] = Wektor<3>{szerokosc/2, -dlugosc/2, -wysokosc/2};
    //Gorna podstawa
    punkty[4] = Wektor<3>{-szerokosc/2, -dlugosc/2, wysokosc/2};
    punkty[5] = Wektor<3>{-szerokosc/2, dlugosc/2, wysokosc/2};
    punkty[6] = Wektor<3>{szerokosc/2, dlugosc/2, wysokosc/2};
    punkty[7] = Wektor<3>{szerokosc/2, -dlugosc/2, wysokosc/2};

    id = -1; // Ustawia identyfikator rysownika (obiek nie byl jeszcze rysowany)
}

void Prostopadloscian::rysuj()
{
    if(id != -1) // Jesli obiekt byl rysowany nalezy go usunac
        rysownik->erase_shape(id);

    Prostopadloscian tmp(*this); // Figura pomocnicza do rysowania w globalnym ukladzie wspolrzednych
    tmp.doBazowego();
    for(int i = 0; i < 8; i++) // Przeliczanie wszystkich punktow na globalny uklad wspolrzednych
    {
        tmp.punkty[i] = tmp.przeliczPunkt(tmp.punkty[i]);
    }
    id = rysownik->draw_polyhedron(std::vector<std::vector<drawNS::Point3D>>{{konwertuj((tmp.punkty[0])), konwertuj((tmp.punkty[1])), konwertuj((tmp.punkty[2])), konwertuj((tmp.punkty[3]))}, {konwertuj((tmp.punkty[4])), konwertuj((tmp.punkty[5])), konwertuj((tmp.punkty[6])), konwertuj((tmp.punkty[7]))}}, kolor);
}