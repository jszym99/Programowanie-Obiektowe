#include "Graniastoslup.hh"

Graniastoslup6::Graniastoslup6(Wektor<3> bazS, MacierzObr<3> bazO, UkladW * wsk, double promien, double wysokosc) : UkladW(bazS, bazO, wsk)
{
	Wektor<3> wierzcholek{0,promien,0}; //wektor pomocniczy reprezentujacy wierzcholek obracany wokol osi graniastoslupu
    //Tworzrenie dolnej podstawy graniastoslupa
	for(int i = 0; i < 6; i++)
	{
		punkty[i] = MacierzObr<3>{60*(i*1.0)} * wierzcholek;
	}
    
	wierzcholek = {0,promien,wysokosc}; //wektor pomocniczy przesuniety o wysokosc
    //Tworzrenie dolnej podstawy graniastoslupa
	for(int i = 6; i < 12; i++)
	{
		punkty[i] = MacierzObr<3>{60*(i*1.0)} * wierzcholek;
	}
    
    id = -1; // Ustawia identyfikator rysownika (obiek nie byl jeszcze rysowany)
}

void Graniastoslup6::rysuj(drawNS::Draw3DAPI *rysownik, std::string kolor)
{
    if(id != -1) // Jesli obiekt byl rysowany nalezy go usunac
        rysownik->erase_shape(id);

    Graniastoslup6 tmp(*this); // Figura pomocnicza do rysowania w globalnym ukladzie wspolrzednych
    tmp.doBazowego();
    for(int i = 0; i < 12; i++) // Przeliczanie wszystkich punktow na globalny uklad wspolrzednych
    {
        tmp.punkty[i] = tmp.przeliczPunkt(tmp.punkty[i]);
    }
    id = rysownik->draw_polyhedron(std::vector<std::vector<drawNS::Point3D>>{{konwertuj((tmp.punkty[0])), konwertuj((tmp.punkty[1])), konwertuj((tmp.punkty[2])), konwertuj((tmp.punkty[3])), konwertuj((tmp.punkty[4])), konwertuj((tmp.punkty[5]))},
    {konwertuj((tmp.punkty[6])), konwertuj((tmp.punkty[7])), konwertuj((tmp.punkty[8])), konwertuj((tmp.punkty[9])), konwertuj((tmp.punkty[10])), konwertuj((tmp.punkty[11]))}}, kolor);
}