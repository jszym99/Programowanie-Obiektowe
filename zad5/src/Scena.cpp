#include "Scena.hh"

namespace scene
{
    unsigned int frameTime = 100; // milisekundy
}

Scena::Scena(std::shared_ptr<drawNS::Draw3DAPI> rys, std::string col)
{
    rysownik = rys;
    // Rysowanie powierzchni
    Powierzchnia(rys, "grey").rysuj();
    // Tworzenie poczatkowego drona
    std::shared_ptr<Dron> dron(new Dron(Wektor<3>{0, 0, 1}, MacierzObr<3>{}, rys, col));
    // Rysowanie poczatkowego drona
    dron->rysuj();
    drony.push_back(dron);
    // Tworzenie i rysowanie plaskowyzu prostopadlosciennego
    std::shared_ptr<PlaskowyzProst> PP1(new PlaskowyzProst(Wektor<3>{15, 15, 0}, MacierzObr<3>{}, rys, col, 10, 16, 12));
    PP1->rysuj();
    elemPowierzchni.push_back(PP1);
    // Tworzenie i rysowanie wzgorza
    std::shared_ptr<Wzgorze> W1(new Wzgorze(Wektor<3>{-15, 15, 0}, MacierzObr<3>{}, rys, col, 10, 16));
    W1->rysuj();
    elemPowierzchni.push_back(W1);
    // Tworzenie i rysowanie plaskowyzu
    std::shared_ptr<Plaskowyz> PL1(new Plaskowyz(Wektor<3>{-20, -20, 0}, MacierzObr<3>{}, rys, col, 12, 13));
    PL1->rysuj();
    elemPowierzchni.push_back(PL1);
}

void Scena::MenuDrona()
{
    unsigned int opcja = 0;
    do
    {
        // Wyswietlanie menu
        std::cout << "Menu drona:\n[1] Lot\n[2] Usun drona\n[3] Dodaj drona\n[0] Powrot do menu glownego\n";
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
                if (kat < -180 || kat > 180)
                    std::cout << "Kat poza zakresem";
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
                if (dystans <= 0)
                    std::cout << "Odleglosc musi byc dodatnia\n";
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
                if (wysokosc <= 0)
                    std::cout << "Wysokosc musi byc dodatnia\n";
                std::cin.clear();
                std::cin.ignore(1000, '\n');
                std::cout << "Niepoprawny format danych\n";
                continue;
            }

            // Rysowanie animacji ruchu drona
            AnimacjaRuchu(kat, dystans, wysokosc);
            break;
        case 2: // Usuwanie drona
            std::cout << "Ta funkcja jeszcze nie dziala\n";
            break;
        case 3: // Dodawanie drona
            std::cout << "Ta funkcja jeszcze nie dziala\n";
            break;
        case 0:
            break;
        default:
            std::cout << "Bledna opcja!" << std::endl;
            break;
        }

    } while (opcja != 0);
}

void Scena::MenuKrajobrazu()
{
    unsigned int opcja = 0;
    unsigned int elemId;
    unsigned int typElementu;
    do
    {
        std::cout << "Menu krajobrazu:\n[1] Usun element krajobrazu\n[2] Dodaj element krajobrazu\n[0] Powrot do menu glownego\n";
        std::cin >> opcja;
        // Sprawdzanie poprawnosci typu danych
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cout << "Niepoprawny format danych\n";
            continue;
        }

        char check;
        bool flaga = true;
        switch (opcja)
        {
        case 1: // Usuwanie elementow krajobrazu
            if (elemPowierzchni.size() == 0)
            {
                std::cout << "Brak elementow do usuniecia\n";
                break;
            }
            for (int i = 0; i < (int)elemPowierzchni.size(); i++)
            {
                std::cout << i << " - ";
                elemPowierzchni[i]->getInfo();
            }
            std::cout << "Podaj numer elementu krajobrazu do usuniecia: ";
            std::cin >> elemId;
            // Sprawdzanie poprawnosci typu danych
            if (std::cin.fail() || elemId < 0 || elemId >= elemPowierzchni.size())
            {
                if (elemId < 0 || elemId >= elemPowierzchni.size())
                    std::cout << "Element o tym numerze nie istnieje\n";
                std::cin.clear();
                std::cin.ignore(1000, '\n');
                std::cout << "Niepoprawny format danych\n";
                continue;
            }
            rysownik->change_shape_color(elemPowierzchni[elemId]->getId(), "red");
            do
            {
                std::cout << "Czy na pewno chcesz usunac ten element? [Y]es/[N]o: ";
                std::cin >> check;
                // Sprawdzanie poprawnosci typu danych
                if (std::cin.fail())
                {
                    std::cin.clear();
                    std::cin.ignore(1000, '\n');
                    std::cout << "Niepoprawny format danych\n";
                    continue;
                }
                // Potweirdzenie wyboru
                if (check == 'n' || check == 'N')
                {
                    rysownik->change_shape_color(elemPowierzchni[elemId]->getId(), "black");
                    flaga = false;
                }
                else if (check == 'y' || check == 'Y')
                {
                    rysownik->erase_shape(elemPowierzchni[elemId]->getId());
                    elemPowierzchni.erase(elemPowierzchni.begin() + elemId);
                    flaga = false;
                }
                else
                {
                    std::cout << "Bledna opcja\n";
                }
            }while(flaga);
            break;
        case 2: // Dodawanie elementow krajobrazu
            std::cout << "Podaj typ elementu do dodania:\n[1] Wzgorze\n[2] Plaskowyz\n[3] Plaskowyz prostopadloscienny\n";
            std::cin >> typElementu;
            // Sprawdzanie poprawnosci typu danych
            if (std::cin.fail())
            {
                std::cin.clear();
                std::cin.ignore(1000, '\n');
                std::cout << "Niepoprawny format danych\n";
                continue;
            }
            double wspX, wspY, prom, wys, dlugosc, szerokosc, kat;
            switch (typElementu)
            {
            case 1: // Wzgorze
            {
                // Pierwsza wspolrzedn
                std::cout << "Podaj wspolrzedna X srodka wzgorza: ";
                std::cin >> wspX;
                // Sprawdzanie poprawnosci typu danych
                if (std::cin.fail())
                {
                    std::cin.clear();
                    std::cin.ignore(1000, '\n');
                    std::cout << "Niepoprawny format danych\n";
                    continue;
                }
                // Druga wspolrzedna
                std::cout << "Podaj wspolrzedna Y srodka wzgorza: ";
                std::cin >> wspY;
                // Sprawdzanie poprawnosci typu danych
                if (std::cin.fail())
                {
                    std::cin.clear();
                    std::cin.ignore(1000, '\n');
                    std::cout << "Niepoprawny format danych\n";
                    continue;
                }
                // Maksymalny promien
                std::cout << "Podaj maksymalna odlegosc wierzcholka podstawy od srodka wzgorza (min 1): ";
                std::cin >> prom;
                // Sprawdzanie poprawnosci typu danych
                if (std::cin.fail() || prom < 1)
                {
                    std::cin.clear();
                    std::cin.ignore(1000, '\n');
                    std::cout << "Niepoprawny format danych\n";
                    continue;
                }
                // Wysokosc
                std::cout << "Podaj wysokosc wzgorza: ";
                std::cin >> wys;
                // Sprawdzanie poprawnosci typu danych
                if (std::cin.fail() || wys <= 0)
                {
                    if (wys >= 0)
                        std::cout << "Wysokosc musi byc wieksza od 0\n";
                    std::cin.clear();
                    std::cin.ignore(1000, '\n');
                    std::cout << "Niepoprawny format danych\n";
                    continue;
                }
                std::shared_ptr<Wzgorze> wzgorze(new Wzgorze(Wektor<3>{wspX, wspY, 0}, MacierzObr<3>{}, rysownik, "black", prom, wys));
                wzgorze->rysuj();
                elemPowierzchni.push_back(wzgorze);
            }
            break;
            case 2: // Plaskowyz
            {
                // Pierwsza wspolrzedn
                std::cout << "Podaj wspolrzedna X srodka plaskowyzu: ";
                std::cin >> wspX;
                // Sprawdzanie poprawnosci typu danych
                if (std::cin.fail())
                {
                    std::cin.clear();
                    std::cin.ignore(1000, '\n');
                    std::cout << "Niepoprawny format danych\n";
                    continue;
                }
                // Druga wspolrzedna
                std::cout << "Podaj wspolrzedna Y srodka plaskowyzu: ";
                std::cin >> wspY;
                // Sprawdzanie poprawnosci typu danych
                if (std::cin.fail())
                {
                    std::cin.clear();
                    std::cin.ignore(1000, '\n');
                    std::cout << "Niepoprawny format danych\n";
                    continue;
                }
                // Maksymalny promien
                std::cout << "Podaj maksymalna odlegosc wierzcholka podstawy od srodka plaskowyzu (min 1): ";
                std::cin >> prom;
                // Sprawdzanie poprawnosci typu danych
                if (std::cin.fail() || prom < 1)
                {
                    std::cin.clear();
                    std::cin.ignore(1000, '\n');
                    std::cout << "Niepoprawny format danych\n";
                    continue;
                }
                // Wysokosc
                std::cout << "Podaj wysokosc plaskowyzu: ";
                std::cin >> wys;
                // Sprawdzanie poprawnosci typu danych
                if (std::cin.fail() || wys <= 0)
                {
                    if (wys >= 0)
                        std::cout << "Wysokosc musi byc wieksza od 0\n";
                    std::cin.clear();
                    std::cin.ignore(1000, '\n');
                    std::cout << "Niepoprawny format danych\n";
                    continue;
                }
                std::shared_ptr<Plaskowyz> plaskowyz(new Plaskowyz(Wektor<3>{wspX, wspY, 0}, MacierzObr<3>{}, rysownik, "black", prom, wys));
                plaskowyz->rysuj();
                elemPowierzchni.push_back(plaskowyz);
            }
            break;
            case 3: // Plaskowyz prostopadloscienny
            {
                // Pierwsza wspolrzedn
                std::cout << "Podaj wspolrzedna X srodka plaskowyzu prostopadlosciennego: ";
                std::cin >> wspX;
                // Sprawdzanie poprawnosci typu danych
                if (std::cin.fail())
                {
                    std::cin.clear();
                    std::cin.ignore(1000, '\n');
                    std::cout << "Niepoprawny format danych\n";
                    continue;
                }
                // Druga wspolrzedna
                std::cout << "Podaj wspolrzedna Y srodka plaskowyzu prostopadlosciennego: ";
                std::cin >> wspY;
                // Sprawdzanie poprawnosci typu danych
                if (std::cin.fail())
                {
                    std::cin.clear();
                    std::cin.ignore(1000, '\n');
                    std::cout << "Niepoprawny format danych\n";
                    continue;
                }
                std::cout << "Podaj kat obrotu plaskowyzu prostopadlosciennego (w stopniach [-180;180]): ";
                std::cin >> kat;
                // Sprawdzanie poprawnosci typu danych
                if (std::cin.fail() || kat < -180 || kat > 180)
                {
                    if (kat < -180 || kat > 180)
                        std::cout << "Kat poza zakresem";
                    std::cin.clear();
                    std::cin.ignore(1000, '\n');
                    std::cout << "Niepoprawny format danych\n";
                    continue;
                }
                // Dlugosc boku
                std::cout << "Podaj dlugosc plaskowyzu prostopadlosciennego: ";
                std::cin >> dlugosc;
                // Sprawdzanie poprawnosci typu danych
                if (std::cin.fail() || dlugosc <= 0)
                {
                    if (dlugosc <= 0)
                        std::cout << "Dlugosc musi byc wieksza od 0\nn";
                    std::cin.clear();
                    std::cin.ignore(1000, '\n');
                    std::cout << "Niepoprawny format danych\n";
                    continue;
                }
                // Szerokosc boku
                std::cout << "Podaj szerokosc plaskowyzu prostopadlosciennego: ";
                std::cin >> szerokosc;
                // Sprawdzanie poprawnosci typu danych
                if (std::cin.fail() || szerokosc <= 0)
                {
                    if (szerokosc <= 0)
                        std::cout << "Dlugosc musi byc wieksza od 0\nn";
                    std::cin.clear();
                    std::cin.ignore(1000, '\n');
                    std::cout << "Niepoprawny format danych\n";
                    continue;
                }
                // Wysokosc
                std::cout << "Podaj wysokosc plaskowyzu prostopadlosciennego: ";
                std::cin >> wys;
                // Sprawdzanie poprawnosci typu danych
                if (std::cin.fail() || wys <= 0)
                {
                    if (wys <= 0)
                        std::cout << "Wysokosc musi byc wieksza od 0\n";
                    std::cin.clear();
                    std::cin.ignore(1000, '\n');
                    std::cout << "Niepoprawny format danych\n";
                    continue;
                }
                std::shared_ptr<PlaskowyzProst> plaskowyz(new PlaskowyzProst(Wektor<3>{wspX, wspY, 0}, MacierzObr<3>{kat}, rysownik, "black", dlugosc, szerokosc, wys));
                plaskowyz->rysuj();
                elemPowierzchni.push_back(plaskowyz);
            }
            break;
            default:
                std::cout << "Bledna opcja!" << std::endl;
                break;
            }

            break;
        case 0:
            break;
        default:
            std::cout << "Bledna opcja!" << std::endl;
            break;
        }
    } while (opcja != 0);
}

void Scena::Menu()
{
    //drony[0]->rysuj();

    unsigned int opcja = 0;
    do
    {
        // Wyswietlanie menu
        std::cout << "Menu glowne:\n[1] Dron\n[2] Elementy krajobrazu\n[0] Zakoncz program\n";
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
    } while (opcja != 0);
}

void Scena::AnimacjaRuchu(double deg, double dyst, double wys, unsigned int nrDrona)
{
    //lec w gore
    double lKlatek = wys / drony[nrDrona]->getPred();
    for (int i = 0; i < lKlatek; i++)
    {
        drony[nrDrona]->lecPion(wys / lKlatek);
        std::this_thread::sleep_for(std::chrono::milliseconds(scene::frameTime));
    }

    //obroc wokol Z
    lKlatek = abs(deg) / drony[nrDrona]->getPredObr();
    for (int i = 0; i < lKlatek; i++)
    {
        drony[nrDrona]->obrocZ(deg / lKlatek);
        std::this_thread::sleep_for(std::chrono::milliseconds(scene::frameTime));
    }

    //lec do przodu
    lKlatek = dyst / drony[nrDrona]->getPred();
    for (int i = 0; i < lKlatek; i++)
    {
        drony[nrDrona]->lecPrzod(dyst / lKlatek);
        std::this_thread::sleep_for(std::chrono::milliseconds(scene::frameTime));
    }

    //lec w dol
    lKlatek = wys / drony[nrDrona]->getPred();
    for (int i = 0; i < lKlatek; i++)
    {
        drony[nrDrona]->lecPion(-(wys / lKlatek));
        std::this_thread::sleep_for(std::chrono::milliseconds(scene::frameTime));
    }
}