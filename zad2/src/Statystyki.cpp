#include "Statystyki.hh"

void Inicjuj (Statystyki & Staty)
{
    Staty.LPoprawnych = 0;
    Staty.LPytan = 0;
}

void DodajPoprawna (Statystyki & Staty)
{
    Staty.LPoprawnych++;
    Staty.LPytan++;
}

void DodajNiepoprawna (Statystyki & Staty)
{
    Staty.LPytan++;
}

double ObliczProcrnt(Statystyki & Staty)
{
    return 1.0*Staty.LPoprawnych/Staty.LPytan*100;
}

void Wyswielt (Statystyki & Staty)
{
    std::cout << "\n Liczba poprawnych odpowiedzi: " << Staty.LPytan << std::endl;
    std::cout << " Liczba poprawnych odpowiedzi: " << Staty.LPoprawnych << std::endl;
    std::cout << " Liczba blednych odpowiedzi: " << (Staty.LPytan-Staty.LPoprawnych) << std::endl;
    std::cout << " Wynik testu: " << ObliczProcrnt(Staty) << "%" << std::endl;
}