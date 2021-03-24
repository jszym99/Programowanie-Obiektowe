#include "Statystyki.hh"

//Funkcja inicjuje strukture zawierajaca statystyki testu
void Inicjuj (Statystyki & Staty)
{
    Staty.LPoprawnych = 0;
    Staty.LPytan = 0;
}

//Funkcja aktualizuje liczbe poprawnych odpowiedzi i liczbe pytan
void DodajPoprawna (Statystyki & Staty)
{
    Staty.LPoprawnych++;
    Staty.LPytan++;
}

//Funkcja aktualizuje liczbe pytan (i blednych odpowiedzi)
void DodajNiepoprawna (Statystyki & Staty)
{
    Staty.LPytan++;
}

//Funkcja oblicza wartosc procentowo poprawnych odpowiedzi
double ObliczProcent(Statystyki & Staty)
{
    return 1.0*Staty.LPoprawnych/Staty.LPytan*100;
}

//Funkcja wyswietla statystyki testu
void Wyswielt (Statystyki & Staty)
{
    std::cout << "\n Liczba poprawnych odpowiedzi: " << Staty.LPytan << std::endl;
    std::cout << " Liczba poprawnych odpowiedzi: " << Staty.LPoprawnych << std::endl;
    std::cout << " Liczba blednych odpowiedzi: " << (Staty.LPytan-Staty.LPoprawnych) << std::endl;
    std::cout << " Wynik testu: " << ObliczProcent(Staty) << "%" << std::endl;
}