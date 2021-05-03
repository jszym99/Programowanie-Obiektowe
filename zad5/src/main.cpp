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
#include "Dr3D_gnuplot_api.hh"

void wait4key() {
  do {
    std::cout << "\n Press a key to continue..." << std::endl;
  } while(std::cin.get() != '\n');
}

int main()
{

	drawNS::Draw3DAPI *rysownik = new drawNS::APIGnuPlot3D(-20, 20, -20, 20, -20, 20, 1000);
	rysownik->change_ref_time_ms(0);

	//Punkt i obrot początkowe (0 i macierz jednostkowa)
	MacierzObr<3> obrPocz{};
	Wektor<3> punktPocz{};

	//Rysuje powierzchnie
	Powierzchnia P1;
	P1.rysuj(rysownik, "grey");

	//Lot drona
	Dron D1(Wektor<3>{0,0,1}, obrPocz);
	D1.rysuj(rysownik, "black");
	wait4key();
	D1.lec(30,10,20);
	D1.rysuj(rysownik, "black");
	wait4key();
	
	//Test metod
	D1.translacja(Wektor<3>{-5,-5,10});
	D1.rysuj(rysownik, "black");
	wait4key();
	D1.rotacja(MacierzObr<3>{30,X});
	D1.rysuj(rysownik, "black");
	wait4key();

	delete rysownik;
	return 0;
}