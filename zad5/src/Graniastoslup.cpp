#include "Graniastoslup.hh"

void Graniastoslup6::rysuj(drawNS::Draw3DAPI *rysownik, std::string kolor)
{
    rysownik->draw_polyhedron(std::vector<std::vector<drawNS::Point3D>>{{konwertuj((orient * punkty[0]) + srodek), konwertuj((orient * punkty[1]) + srodek), konwertuj((orient * punkty[2]) + srodek), konwertuj((orient * punkty[3]) + srodek), konwertuj((orient * punkty[4]) + srodek), konwertuj((orient * punkty[5]) + srodek)},
    {konwertuj((orient * punkty[6]) + srodek), konwertuj((orient * punkty[7]) + srodek), konwertuj((orient * punkty[8]) + srodek), konwertuj((orient * punkty[9]) + srodek), konwertuj((orient * punkty[10]) + srodek), konwertuj((orient * punkty[11]) + srodek)}}, kolor);
}