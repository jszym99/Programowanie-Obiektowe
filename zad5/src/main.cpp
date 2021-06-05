#include <iostream>
#include <iomanip>
#include <fstream>
#include "Wektor.hh"
#include "Macierz.hh"
#include "UkladW.hh"
#include "Prostopadloscian.hh"
#include "Graniastoslup.hh"
#include "Dron.hh"
#include "Powierzchnia.hh"
#include "Scena.hh"
#include "InterfejsDrona.hh"
#include "Dr3D_gnuplot_api.hh"

int main()
{

	std::shared_ptr<drawNS::Draw3DAPI> rysownik(new drawNS::APIGnuPlot3D(-30, 30, -30, 30, -5, 30, 1000));
	rysownik->change_ref_time_ms(0);

	//Punkt i obrot początkowe (0 i macierz jednostkowa)
	MacierzObr<3> obrPocz{};
	Wektor<3> punktPocz{0,0,1};

	//Rysuje powierzchnie
	//Powierzchnia P1(rysownik, "grey");
	//P1.rysuj();

	Scena scena1(rysownik, "black");
	scena1.Menu();

	return 0;
}