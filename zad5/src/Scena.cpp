#include "Scena.hh"

namespace scene
{
    double v = 0.5; // jednostki na klatke
    double vKat = 15; // stopnie na klatke
    unsigned int frameTime = 100; // milisekundy
    double pochyl = 15; //kat nachylenia podczas lotu
}

void Scena::Menu()
{
    dron.rysuj();
    
    while (true)
    {
        double kat, dystans, wysokosc;
        std::cout << "Podaj kierunek lotu (w stopniach [-180;180]) lub [1111] aby zakonczyc program: ";
        std::cin >> kat;
        if (std::cin.fail() || kat < -180 || kat > 180)
		{
            if(kat == 1111) break; //koniec programu

			std::cin.clear();
			std::cin.ignore(1000, '\n');
			std::cout << "Niepoprawny format danych\n";
			continue;
		}
        std::cout << "Podaj odleglosc lotu: ";
        std::cin >> dystans;
        if (std::cin.fail() || dystans <= 0)
		{
			std::cin.clear();
			std::cin.ignore(1000, '\n');
			std::cout << "Niepoprawny format danych\n";
			continue;
        }
        std::cout << "Podaj wysokosc lotu: ";
        std::cin >> wysokosc;
        if (std::cin.fail() || wysokosc <= 0)
		{
			std::cin.clear();
			std::cin.ignore(1000, '\n');
			std::cout << "Niepoprawny format danych\n";
			continue;
        }

        AnimacjaRuchu(kat, dystans, wysokosc);
    }
}

void Scena::AnimacjaRuchu(double deg, double dyst, double wys)
{
    //lec w gore
    double lKlatek = wys / scene::v;
    for (int i = 0; i < lKlatek; i++)
    {
        dron.lecPion(wys/lKlatek);
        dron.krecWirnikami();
        dron.rysuj();
        std::this_thread::sleep_for(std::chrono::milliseconds(scene::frameTime));
    }

    //obroc wokol Z
    lKlatek = deg / scene::vKat;
    for(int i = 0; i < lKlatek; i++)
    {
        dron.obrocZ(deg/lKlatek);
        dron.krecWirnikami();
        dron.rysuj();
        std::this_thread::sleep_for(std::chrono::milliseconds(scene::frameTime));
    }

    //lec do przodu
    lKlatek = dyst / scene::v;
    for (int i = 0; i < lKlatek; i++)
    {
        dron.lecPrzod(dyst/lKlatek);
        dron.rotacja(MacierzObr<3>{scene::pochyl,Y});
        dron.krecWirnikami();
        dron.rysuj();
        dron.rotacja(MacierzObr<3>{-scene::pochyl,Y});
        std::this_thread::sleep_for(std::chrono::milliseconds(scene::frameTime));
    }
    
    //lec w dol
    lKlatek = wys / scene::v;
    for (int i = 0; i < lKlatek; i++)
    {
        dron.lecPion(-(wys/lKlatek));
        dron.krecWirnikami();
        dron.rysuj();
        std::this_thread::sleep_for(std::chrono::milliseconds(scene::frameTime));
    }
}