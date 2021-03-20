#ifndef STATYSTYKI_HH
#define STATYSTYKI_HH

#include <iostream>

struct Statystyki
{
    int LPoprawnych;
    int LPytan;
};

void Inicjuj (Statystyki & Staty);
void DodajPoprawna (Statystyki & Staty);
void DodajNiepoprawna (Statystyki & Staty);
double ObliczProcrnt(Statystyki & Staty);
void Wyswielt (Statystyki & Staty);


#endif