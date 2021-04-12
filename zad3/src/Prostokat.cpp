#include "Prostokat.hh"

namespace pros
{
	const double epsilon = 0.000001; // __DBL_MIN__;
	int rozmiar = 4;				 //ilosc pol (liczac od 0 + 1 do zamkniecia lancucha)
}

//Konstruktor
Prostokat::Prostokat(Wektor2D p1, Wektor2D p2, Wektor2D p3, Wektor2D p4)
{
	if ((p2 - p1).dlugosc() - (p4 - p3).dlugosc() < pros::epsilon && (p3 - p2).dlugosc() - (p1 - p4).dlugosc() < pros::epsilon //rownosc dlugosci przeciwleglych bokow
		&& (p2 - p1) * (p3 - p2) < pros::epsilon && (p3 - p2) * (p4 - p3) < pros::epsilon)									   //prostopadlosc bokow
	{
		punkty.push_back(p1);
		punkty.push_back(p2);
		punkty.push_back(p3);
		punkty.push_back(p4);
	}
	else
		std::cerr << "To nie jest prostokat." << std::endl;
}

/*Prostokat Prostokat::rotacja (MacierzObr2x2 obrot) const
{
	return Prostokat(obrot*punkty[0],obrot*punkty[1],obrot*punkty[2],obrot*punkty[3]);
}

Prostokat Prostokat::translacja (Wektor2D wektor) const
{
	return Prostokat(wektor+punkty[0],wektor+punkty[1],wektor+punkty[2],wektor+punkty[3]);

}*/

const Wektor2D &Prostokat::operator[](int ind) const
{
	if (ind < 0 && ind > 3)
		std::cerr << "Odwolanie poza pamiec" << std::endl;
	return punkty[ind];
}

std::ostream &operator<<(std::ostream &Strm, const Prostokat &Pr)
{
	for (int i = 0; i < pros::rozmiar; i++)
		Strm << Pr[i];
	return Strm;
}

void Prostokat::rysuj(drawNS::Draw2DAPI *rysownik)
{
	if(id_rysunku != 0)
		rysownik->erase_shape(id_rysunku);
		
	id_rysunku = rysownik->draw_polygonal_chain(std::vector<drawNS::Point2D>{konwertuj(punkty[0]), konwertuj(punkty[1]), konwertuj(punkty[2]), konwertuj(punkty[3]), konwertuj(punkty[0])});
}
