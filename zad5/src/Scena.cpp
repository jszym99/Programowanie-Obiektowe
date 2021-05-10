#include "Scena.hh"

void Scena::Menu()
{
    double kat, dystans, wysokosc;
    std::cout << "Podaj kierunek lotu (w stopniach): ";
    std::cin >> kat;
    std::cout << "Podaj odleglosc lotu: ";
    std::cin >> dystans;
    std::cout << "Podaj wysokosc lotu: ";
    std::cin >> wysokosc;

    AnimacjaRuchu(kat, dystans, wysokosc);
}

void Scena::AnimacjaRuchu(double deg, double dyst, double wys)
{
    
}