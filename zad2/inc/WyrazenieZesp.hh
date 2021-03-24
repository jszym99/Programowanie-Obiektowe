#ifndef WYRAZENIEZESP_HH
#define WYRAZENIEZESP_HH



#include "LZespolona.hh"
//#include <iostream>


/*!
 * Modeluje zbior operatorow arytmetycznych.
 */
enum Operator
{
	Op_Dodaj,
	Op_Odejmij,
	Op_Mnoz,
	Op_Dziel
};



/*
 * Modeluje pojecie dwuargumentowego wyrazenia zespolonego
 */
struct WyrazenieZesp
{
	LZespolona Arg1; // Pierwszy argument wyrazenia arytmetycznego
	Operator Op;	 // Opertor wyrazenia arytmetycznego
	LZespolona Arg2; // Drugi argument wyrazenia arytmetycznego
};



std::istream & operator >> (std::istream & strm, Operator & Op);
std::istream & operator >> (std::istream & strm, WyrazenieZesp & Wyraz);
std::ostream & operator << (std::ostream & strm, const WyrazenieZesp & Wyraz);


/*
 * Funkcje ponizej nalezy zdefiniowac w module.
 *
 */

void Wyswietl(const WyrazenieZesp & WyrZ);
LZespolona Oblicz(const WyrazenieZesp & WyrZ);

#endif
