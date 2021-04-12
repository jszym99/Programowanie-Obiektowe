#ifndef PROSTOKAT_HH
#define PROSTOKAT_HH

#include <iostream>
#include "Macierz2x2.hh"

/*
 *  Tutaj trzeba opisac klase. Jakie pojecie modeluje ta klasa
 *  i jakie ma glowne cechy.
 */
class Prostokat
{
private:
	int id_rysunku;
	std::vector<Wektor2D> punkty;

public:
	Prostokat(Wektor2D p1, Wektor2D p2, Wektor2D p3, Wektor2D p4);
	//Metoda obracajaca prostokat o macierz obrotu
	Prostokat rotacja(MacierzObr2x2 obrot) const { return Prostokat(obrot * punkty[0], obrot * punkty[1], obrot * punkty[2], obrot * punkty[3]); }
	//Metoda przesuwajaca prostokat o wektor
	Prostokat translacja(Wektor2D wektor) const { return Prostokat(wektor + punkty[0], wektor + punkty[1], wektor + punkty[2], wektor + punkty[3]); }
	const Wektor2D &operator[](int ind) const; //get
	void rysuj(drawNS::Draw2DAPI *rysownik, std::string kolor);// { id_rysunku = rysownik->draw_polygonal_chain(std::vector<drawNS::Point2D>{konwertuj(punkty[0]), konwertuj(punkty[1]), konwertuj(punkty[2]), konwertuj(punkty[3]), konwertuj(punkty[0])}); }
};

//Przeciazenie operatora wypisywania realizuje wyswietlanie prostokata na wyjsciu standardowym
std::ostream &operator<<(std::ostream &Strm, const Prostokat &Pr);

#endif
