#ifndef STATYSTYKI_HH
#define STATYSTYKI_HH

#include <iostream>


class Statystyki
{
private:
    int LPoprawnych;
    int LPytan;
public:
    //Konstruktor
    Statystyki (int LPop, int LPyt);
    //Metody
    void DodajPoprawna();
    void DodajNiepoprawna();
    double ObliczProcent() const;
    void Wyswielt() const;
};


// Stary kod
/*
 * Modeluje baze statystyk poprawnosci odpowiedzi uzytkownika
 */
/*struct Statystyki
{
    int LPoprawnych;
    int LPytan;
};

void Inicjuj (Statystyki & Staty);
void DodajPoprawna (Statystyki & Staty);
void DodajNiepoprawna (Statystyki & Staty);
double ObliczProcent(Statystyki & Staty);
void Wyswielt (Statystyki & Staty);*/


#endif