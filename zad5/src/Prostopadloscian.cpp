#include "Prostopadloscian.hh"

namespace pros
{
	const double epsilon = 0.000001;
	int rozmiar = 7;				 //ilosc pol
}

/*Prostopadloscian Prostopadloscian::rotacja (MacierzObr<3> obrot) const
{
    return Prostopadloscian{obrot * punkty[0],obrot * punkty[1],obrot * punkty[2],obrot * punkty[3],obrot * punkty[4],obrot * punkty[5],obrot * punkty[6],obrot * punkty[7]};
}

Prostopadloscian Prostopadloscian::translacja (Wektor<3> wektor) const
{
    return Prostopadloscian{wektor + punkty[0],wektor + punkty[1],wektor + punkty[2],wektor + punkty[3],wektor + punkty[4],wektor + punkty[5],wektor + punkty[6],wektor + punkty[7]};
}

bool Prostopadloscian::sprawdz()
{
    return (prostokat(punkty[0],punkty[1],punkty[2],punkty[3]) && prostokat(punkty[4],punkty[5],punkty[6],punkty[7])    //pierwsza para bokow
         && prostokat(punkty[0],punkty[1],punkty[5],punkty[4]) && prostokat(punkty[2],punkty[3],punkty[7],punkty[6])    //druga para bokow
         && prostokat(punkty[0],punkty[3],punkty[7],punkty[4]) && prostokat(punkty[1],punkty[2],punkty[6],punkty[5]));  //trzecia para bokow
}*/

void Prostopadloscian::rysuj(drawNS::Draw3DAPI *rysownik, std::string kolor)
{
    rysownik->draw_polyhedron(std::vector<std::vector<drawNS::Point3D>>{{konwertuj(punkty[0]), konwertuj(punkty[1]), konwertuj(punkty[2]), konwertuj(punkty[3])}, {konwertuj(punkty[4]), konwertuj(punkty[5]), konwertuj(punkty[6]), konwertuj(punkty[7])}}, kolor);
}

/*bool prostokat(const Wektor<3> & P1, const Wektor<3> & P2, const Wektor<3> & P3, const Wektor<3> & P4)
{
    return ((P2 - P1).dlugosc() - (P4 - P3).dlugosc() < pros::epsilon && (P3 - P2).dlugosc() - (P1 - P4).dlugosc() < pros::epsilon //rownosc dlugosci orzeciwleglych bokow
		&& (P2 - P1) * (P3 - P2) < pros::epsilon && (P3 - P2) * (P4 - P3) < pros::epsilon);									   //prostopadlosc bokow
}*/