#include "Statystyki.hh"

Statystyki::Statystyki (int LPop, int LPyt): LPoprawnych(LPop), LPytan(LPyt) {}

// Nie potrzebna
//Funkcja inicjuje strukture zawierajaca statystyki testu
/*void Inicjuj (Statystyki & Staty)
{
    Staty.LPoprawnych = 0;
    Staty.LPytan = 0;
}*/

//Funkcja aktualizuje liczbe poprawnych odpowiedzi i liczbe pytan
void Statystyki::DodajPoprawna()
{
    LPoprawnych++;
    LPytan++;
}

//Funkcja aktualizuje liczbe pytan (i blednych odpowiedzi)
void Statystyki::DodajNiepoprawna ()
{
    LPytan++;
}

//Funkcja oblicza wartosc procentowo poprawnych odpowiedzi
double Statystyki::ObliczProcent() const
{
    return 100*LPoprawnych/LPytan;
}

//Funkcja wyswietla statystyki testu
void Statystyki::Wyswielt () const
{
    std::cout << "\nLiczba poprawnych odpowiedzi: " << LPytan << std::endl;
    std::cout << "Liczba poprawnych odpowiedzi: " << LPoprawnych << std::endl;
    std::cout << "Liczba blednych odpowiedzi: " << (LPytan-LPoprawnych) << std::endl;
    std::cout << "Wynik testu: " << (*this).ObliczProcent() << "%" << std::endl;
}