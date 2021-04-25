#include "Prostopadloscian.hh"

namespace pros
{
	const double epsilon = 0.000001;
	int rozmiar = 7;				 //ilosc pol
}

Prostopadloscian::Prostopadloscian(std::initializer_list<Wektor<3>> il) : punkty(il)
{
    /*if (il.size() == 8 && sprawdz())
    {
        std::cout << "Rozmiar jest 8\n";
    }
    else if (il.size() == 5 && prostokat(punkty[0],punkty[1],punkty[2],punkty[3]))
    {
        std::cout << "Rozmiar jest 5\n";
    }
    else
        std::cerr << "To nie jest prostopadloscian\n";*/

    if(il.size() < 8)
        throw std::invalid_argument("Za malo wierzocholkow\n");
}

Prostopadloscian Prostopadloscian::rotacja (MacierzObr<3> obrot) const
{
    return Prostopadloscian{obrot * punkty[0],obrot * punkty[1],obrot * punkty[2],obrot * punkty[3],obrot * punkty[4],obrot * punkty[5],obrot * punkty[6],obrot * punkty[7]};
}

Prostopadloscian Prostopadloscian::translacja (Wektor<3> wektor) const
{
    return Prostopadloscian{wektor + punkty[0],wektor + punkty[1],wektor + punkty[2],wektor + punkty[3],wektor + punkty[4],wektor + punkty[5],wektor + punkty[6],wektor + punkty[7]};
}

const Wektor<3> &Prostopadloscian::operator[](int ind) const
{
    if (ind < 0 && ind > pros::rozmiar)
        std::cerr << "Odwolanie poza pamiec" << std::endl;
    return punkty[ind];
}

bool Prostopadloscian::sprawdz()
{
    return (prostokat(punkty[0],punkty[1],punkty[2],punkty[3]) && prostokat(punkty[4],punkty[5],punkty[6],punkty[7])    //pierwsza para bokow
         && prostokat(punkty[0],punkty[1],punkty[5],punkty[4]) && prostokat(punkty[2],punkty[3],punkty[7],punkty[6])    //druga para bokow
         && prostokat(punkty[0],punkty[3],punkty[7],punkty[4]) && prostokat(punkty[1],punkty[2],punkty[6],punkty[5]));  //trzecia para bokow
}

void Prostopadloscian::rysuj(drawNS::Draw3DAPI *rysownik, std::string kolor)
{
    rysownik->draw_polyhedron(std::vector<std::vector<drawNS::Point3D>>{{konwertuj(punkty[0]), konwertuj(punkty[1]), konwertuj(punkty[2]), konwertuj(punkty[3])}, {konwertuj(punkty[4]), konwertuj(punkty[5]), konwertuj(punkty[6]), konwertuj(punkty[7])}}, kolor);
}

void Prostopadloscian::porownanie()
{
    double kr[4], sr[4], dl[4]; //Krawedzie

    //Obliczenie dlugosci krawedzi prostopadloscianu
    kr[0] = (punkty[0] - punkty[1]).dlugosc();
    kr[1] = (punkty[2] - punkty[3]).dlugosc();
    kr[2] = (punkty[4] - punkty[5]).dlugosc();
    kr[3] = (punkty[6] - punkty[7]).dlugosc();

    sr[0] = (punkty[1] - punkty[2]).dlugosc();
    sr[1] = (punkty[3] - punkty[0]).dlugosc();
    sr[2] = (punkty[5] - punkty[6]).dlugosc();
    sr[3] = (punkty[7] - punkty[4]).dlugosc();

    dl[0] = (punkty[0] - punkty[4]).dlugosc();
    dl[1] = (punkty[1] - punkty[5]).dlugosc();
    dl[2] = (punkty[2] - punkty[6]).dlugosc();
    dl[3] = (punkty[3] - punkty[7]).dlugosc();

    //Porowanie krotkich krawedzi
    if(kr[0] == kr[1] && kr[1] == kr[2] && kr[2] == kr[3])
        std::cout << "Krotkie krawedzi sa rowne\n";
    else
        std::cout << "Krotkie krawedzi nie sa rowne\n";

    for(int i = 0; i < 4; i++)
    {
        std::cout << std::setw(16) << std::fixed << std::setprecision(10) << kr[i] << std::endl;
    }

    //Porownanie srednich krawedzi
    if(sr[0] == sr[1] && sr[1] == sr[2] && sr[2] == sr[3])
        std::cout << "Srednie krawedzi sa rowne\n";
    else
        std::cout << "Srednie krawedzi nie sa rowne\n";
    
    for(int i = 0; i < 4; i++)
    {
        std::cout << std::setw(16) << std::fixed << std::setprecision(10) << sr[i] << std::endl;
    }

    //Porownanie dlugich krawedzi
    if(dl[0] == dl[1] && dl[1] == dl[2] && dl[2] == dl[3])
        std::cout << "Dlugie krawedzi sa rowne\n";
    else
        std::cout << "Dlugie krawedzi nie sa rowne\n";
    
    for(int i = 0; i < 4; i++)
    {
        std::cout << std::setw(16) << std::fixed << std::setprecision(10) << dl[i] << std::endl;
    }

    std::cout.unsetf(std::ios_base::fixed);
}

bool prostokat(const Wektor<3> & P1, const Wektor<3> & P2, const Wektor<3> & P3, const Wektor<3> & P4)
{
    return ((P2 - P1).dlugosc() - (P4 - P3).dlugosc() < pros::epsilon && (P3 - P2).dlugosc() - (P1 - P4).dlugosc() < pros::epsilon //rownosc dlugosci orzeciwleglych bokow
		&& (P2 - P1) * (P3 - P2) < pros::epsilon && (P3 - P2) * (P4 - P3) < pros::epsilon);									   //prostopadlosc bokow
}

std::ostream &operator<<(std::ostream &Strm, const Prostopadloscian &Pr)
{
    for (int i = 0; i <= pros::rozmiar; i++)
        Strm << Pr[i];
    return Strm;
}