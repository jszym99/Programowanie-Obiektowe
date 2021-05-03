#include "Powierzchnia.hh"

void Powierzchnia::rysuj(drawNS::Draw3DAPI *rysownik, std::string kolor)
{
    
    std::vector<std::vector<drawNS::Point3D>> surface; // pomocnicza dwuwymiarowa tablica punktow
    int zakres = 50; //zakres plaszczyszny w kazda strone
    int rozstaw = 5; //rozstaw kratki
    for(int i = -zakres; i <= zakres; i+=rozstaw)
    {
        std::vector<drawNS::Point3D> line; // zmienna pomocnicza przechowujaca punkty w jednej linii
        for(int j = -zakres; j <= zakres; j+=rozstaw)
        {
            line.push_back(drawNS::Point3D(i,j,wysokosc));
        }
        surface.push_back(line);
    }

    rysownik->draw_surface(std::vector<std::vector<drawNS::Point3D>> {surface},kolor);
}