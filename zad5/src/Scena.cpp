#include "Scena.hh"

namespace scene
{
    double v = 0.5; // jednostki na klatke
    double vKat = 15; // stopnie na klatke
    unsigned int frameTime = 100; // milisekundy
    double pochyl = 15; //kat nachylenia podczas lotu
}

Scena::Scena(std::shared_ptr<drawNS::Draw3DAPI> rys, std::string col)
{
    drony.push_back(std::shared_ptr<Dron>(new Dron(Wektor<3>{0,0,1},MacierzObr<3>{},rys,col)));
    elemRysowalne.push_back(std::shared_ptr<InterfejsRysowania>(drony[0]));
    elemRysowalne.push_back(std::shared_ptr<InterfejsRysowania>(new Powierzchnia(rys, "grey")));
    elemRysowalne.push_back(std::shared_ptr<InterfejsRysowania>(new PlaskowyzProst(Wektor<3>{15,15,0},MacierzObr<3>{},rys,col,10,16,12)));
    elemRysowalne.push_back(std::shared_ptr<InterfejsRysowania>(new Wzgorze(Wektor<3>{-15,15,0},MacierzObr<3>{},rys,col,10,16)));
    elemRysowalne.push_back(std::shared_ptr<InterfejsRysowania>(new Plaskowyz(Wektor<3>{-20,-20,0},MacierzObr<3>{},rys,col,12,13)));

    // Rysowanie wszystkich elementow
    for (std::shared_ptr<InterfejsRysowania> element : elemRysowalne)
    {
        element->rysuj();
    }

}

void Scena::MenuDrona()
{
    unsigned int opcja = 0;
    do
    {
        // Wyswietlanie menu
        std::cout << "Menu:\n[1] Lot\n[2] Usun drona\n[3] Dodaj drona\n[0] Powrot do menu glownego\n";
        std::cin >> opcja;
        // Sprawdzanie poprawnosci typu danych
        if (std::cin.fail())
			{
				std::cin.clear();
				std::cin.ignore(1000, '\n');
				std::cout << "Niepoprawny format danych\n";
				continue;
			}

        switch (opcja)
        {
        case 1: // Interfjes lotu dronem

            //TODO: wybor drona

            double kat, dystans, wysokosc;
            // Przyjmowanie kata od uzytkownika
            std::cout << "Podaj kierunek lotu (w stopniach [-180;180]): ";
            std::cin >> kat;
            // Sprawdzanie poprawnosci typu danych
            if (std::cin.fail() || kat < -180 || kat > 180)
            {
                std::cin.clear();
                std::cin.ignore(1000, '\n');
                std::cout << "Niepoprawny format danych\n";
                continue;
            }
            // Przyjmowanie oldeglosci lotu od urzytkownika
            std::cout << "Podaj odleglosc lotu: ";
            std::cin >> dystans;
            // Sprawdzanie poprawnosci typu danych
            if (std::cin.fail() || dystans <= 0)
            {
                std::cin.clear();
                std::cin.ignore(1000, '\n');
                std::cout << "Niepoprawny format danych\n";
                continue;
            }
            // Przyjmowanie wysokosci lotu od urzytkownika
            std::cout << "Podaj wysokosc lotu: ";
            std::cin >> wysokosc;
            // Sprawdzanie poprawnosci typu danych
            if (std::cin.fail() || wysokosc <= 0)
            {
                std::cin.clear();
                std::cin.ignore(1000, '\n');
                std::cout << "Niepoprawny format danych\n";
                continue;
            }

            // Rysowanie animacji ruchu drona
            AnimacjaRuchu(kat, dystans, wysokosc);

        
        default:
            break;
        }

    }while(opcja != 0);
}

void Scena::MenuKrajobrazu()
{
    
}

void Scena::Menu()
{
    drony[0]->rysuj();

    unsigned int opcja = 0;
    do
    {
        // Wyswietlanie menu
        std::cout << "Menu:\n[1] Dron\n[2] Elementy krajobrazu\n[0] Zakoncz program\n";
        std::cin >> opcja;
        // Sprawdzanie poprawnosci typu danych
        if (std::cin.fail())
			{
				std::cin.clear();
				std::cin.ignore(1000, '\n');
				std::cout << "Niepoprawny format danych\n";
				continue;
			}
        
        switch (opcja)
        {
        case 1: // Opcje droan
            MenuDrona();
            break;
        case 2: // Opcje karjobrazu
            MenuKrajobrazu();
            break;
        case 0:
            break;
        default: // Bledan opcja
            std::cout << "Bledna opcja!" << std::endl;
            break;
        }
    }while(opcja != 0);
    
    /*while (true)
    {
        std::cout << Wektor<3>::get_suma() << std::endl;
        std::cout << Wektor<3>::get_aktualny() << std::endl;
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
        
    }*/
}

void Scena::AnimacjaRuchu(double deg, double dyst, double wys, unsigned int nrDrona)
{
    //lec w gore
    double lKlatek = wys / scene::v;
    for (int i = 0; i < lKlatek; i++)
    {
        drony[0]->lecPion(wys/lKlatek);
        drony[0]->krecWirnikami();
        drony[0]->rysuj();
        std::this_thread::sleep_for(std::chrono::milliseconds(scene::frameTime));
    }

    //obroc wokol Z
    lKlatek = deg / scene::vKat;
    for(int i = 0; i < lKlatek; i++)
    {
        drony[0]->obrocZ(deg/lKlatek);
        drony[0]->krecWirnikami();
        drony[0]->rysuj();
        std::this_thread::sleep_for(std::chrono::milliseconds(scene::frameTime));
    }

    //lec do przodu
    lKlatek = dyst / scene::v;
    for (int i = 0; i < lKlatek; i++)
    {
        drony[0]->lecPrzod(dyst/lKlatek);
        drony[0]->rotacja(MacierzObr<3>{scene::pochyl,Y});
        drony[0]->krecWirnikami();
        drony[0]->rysuj();
        drony[0]->rotacja(MacierzObr<3>{-scene::pochyl,Y});
        std::this_thread::sleep_for(std::chrono::milliseconds(scene::frameTime));
    }
    
    //lec w dol
    lKlatek = wys / scene::v;
    for (int i = 0; i < lKlatek; i++)
    {
        drony[0]->lecPion(-(wys/lKlatek));
        drony[0]->krecWirnikami();
        drony[0]->rysuj();
        std::this_thread::sleep_for(std::chrono::milliseconds(scene::frameTime));
    }
}