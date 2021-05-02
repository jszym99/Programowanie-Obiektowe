#include "Graniastoslup.hh"

void Graniastoslup6::rysuj(drawNS::Draw3DAPI *rysownik, std::string kolor)
{
    rysownik->draw_polyhedron(std::vector<std::vector<drawNS::Point3D>>{{konwertuj(punkty[0]), konwertuj(punkty[1]), konwertuj(punkty[2]), konwertuj(punkty[3]), konwertuj(punkty[4]), konwertuj(punkty[5])}, {konwertuj(punkty[6]), konwertuj(punkty[7]), konwertuj(punkty[8]), konwertuj(punkty[9]), konwertuj(punkty[10]), konwertuj(punkty[11])}}, kolor);
}