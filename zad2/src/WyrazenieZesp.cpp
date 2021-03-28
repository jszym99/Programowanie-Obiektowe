#include "WyrazenieZesp.hh"


WyrazenieZesp::WyrazenieZesp (LZespolona LZ1, Operator Op, LZespolona LZ2): Arg1(LZ1), Op(Op), Arg2(LZ2) {}
//Do sprawdzenia
WyrazenieZesp::WyrazenieZesp (): Arg1(0,0), Op(Op_Dodaj), Arg2(0,0) {}

// Chyba nie potrzebne
//Realizuje wczytywanie znaku w wyrazeniu zespolonym z wejscia standardowego
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

//Realizuje wczytywanie wyrazenia zespolonego na wejsciu standardowym
std::istream & operator >> (std::istream & strm, WyrazenieZesp & Wyraz)
{
    LZespolona LZ1, LZ2;
    char znak;
    
    strm >> LZ1;

    strm >> znak;
    switch (znak)
    {
    case '+': Wyraz.set_op(Op_Dodaj); break;
    case '-': Wyraz.set_op(Op_Odejmij); break;
    case '*': Wyraz.set_op(Op_Mnoz); break;
    case '/': Wyraz.set_op(Op_Dziel); break;
    default: strm.setstate(std::ios::failbit);
    }

    strm >> LZ2;
    Wyraz.set_arg1(LZ1);
    Wyraz.set_arg2(LZ2);

    return strm;
}

//Realizuje wypisywanie wyrazenia zespolonego na wyjsciu standardowym
std::ostream & operator << (std::ostream & strm, const WyrazenieZesp & Wyraz)
{
    char znak;
    switch (Wyraz.get_Op())
    {
    case Op_Dodaj: znak = '+'; break;
    case Op_Odejmij: znak = '-'; break;
    case Op_Mnoz: znak = '*'; break;
    case Op_Dziel: znak = '/'; break;
    }

    strm << Wyraz.get_Arg1() << znak << Wyraz.get_Arg2();
    return strm;
}

//Funkcja wyswietla wyrazenie zespolone
void WyrazenieZesp::Wyswietl() const
{
    std::cout << *this;
}


//Funkcja oblicza wartosc wyrazenia zespolonego (liczba zespolona)
LZespolona WyrazenieZesp::Oblicz() const
{
    LZespolona Wynik;
    switch (Op)
    {
    case Op_Dodaj: Wynik = Arg1 + Arg2; break;
    case Op_Odejmij: Wynik = Arg1 - Arg2; break;
    case Op_Mnoz: Wynik = Arg1 * Arg2; break;
    case Op_Dziel: Wynik = Arg1 / Arg2; break;
    }
    return Wynik;
}