#include "WyrazenieZesp.hh"

/*!
 * Przeciazenia operatorow
 */
std::istream & operator >> (std::istream & strm, Operator & Op)
{
    char znak;
    
    strm >> znak;

    switch (znak)
    {
    case '+': Op = Op_Dodaj; break;
    case '-': Op = Op_Odejmij; break;
    case '*': Op = Op_Mnoz; break;
    case '/': Op = Op_Dziel; break;
    default: strm.setstate(std::ios::failbit);
    }
    return strm;
}

std::istream & operator >> (std::istream & strm, WyrazenieZesp & Wyraz)
{
    strm >> Wyraz.Arg1 >> Wyraz.Op >> Wyraz.Arg2;
    return strm;
}

std::ostream & operator << (std::ostream & strm, const WyrazenieZesp & Wyraz)
{
    char znak;
    switch (Wyraz.Op)
    {
    case Op_Dodaj: znak = '+'; break;
    case Op_Odejmij: znak = '-'; break;
    case Op_Mnoz: znak = '*'; break;
    case Op_Dziel: znak = '/'; break;
    }

    strm << Wyraz.Arg1 << znak << Wyraz.Arg2;
    return strm;
}

void Wyswielt(const WyrazenieZesp & WyrZ)
{
    std::cout << WyrZ;
}

LZespolona Oblicz(const WyrazenieZesp & WyraZ)
{
    LZespolona Wynik;
    switch (WyraZ.Op)
    {
    case Op_Dodaj: Wynik = WyraZ.Arg1 + WyraZ.Arg2; break;
    case Op_Odejmij: Wynik = WyraZ.Arg1 - WyraZ.Arg2; break;
    case Op_Mnoz: Wynik = WyraZ.Arg1 * WyraZ.Arg2; break;
    case Op_Dziel: Wynik = WyraZ.Arg1 / WyraZ.Arg2; break;
    }
    return Wynik;
}