#ifndef WYRAZENIEZESP_HH
#define WYRAZENIEZESP_HH



#include "LZespolona.hh"

enum Operator
{
	Op_Dodaj,
	Op_Odejmij,
	Op_Mnoz,
	Op_Dziel
};

class WyrazenieZesp
{
private:

	LZespolona Arg1; // Pierwszy argument wyrazenia arytmetycznego
	Operator Op;	 // Opertor wyrazenia arytmetycznego
	LZespolona Arg2; // Drugi argument wyrazenia arytmetycznego
public:
	WyrazenieZesp (LZespolona LZ1, Operator Op, LZespolona LZ2);
	WyrazenieZesp ();

	void Wyswietl() const;
	LZespolona Oblicz() const;
	
	LZespolona get_Arg1() const {return Arg1;};
	Operator get_Op() const {return Op;};
	LZespolona get_Arg2() const {return Arg2;};
	void set_arg1(LZespolona arg1) {Arg1 = arg1;};
	void set_op(Operator op) {Op = op;};
	void set_arg2(LZespolona arg2) {Arg2 = arg2;};
};

std::istream & operator >> (std::istream & strm, Operator & Op);
std::istream & operator >> (std::istream & strm, WyrazenieZesp & Wyraz);
std::ostream & operator << (std::ostream & strm, const WyrazenieZesp & Wyraz);



/*
 * Stary kod
 */
/*!
 * Modeluje zbior operatorow arytmetycznych.
 */
/*enum Operator
{
	Op_Dodaj,
	Op_Odejmij,
	Op_Mnoz,
	Op_Dziel
};*/



/*
 * Modeluje pojecie dwuargumentowego wyrazenia zespolonego
 */
/*struct WyrazenieZesp
{
	LZespolona Arg1; // Pierwszy argument wyrazenia arytmetycznego
	Operator Op;	 // Opertor wyrazenia arytmetycznego
	LZespolona Arg2; // Drugi argument wyrazenia arytmetycznego
};



std::istream & operator >> (std::istream & strm, Operator & Op);
std::istream & operator >> (std::istream & strm, WyrazenieZesp & Wyraz);
std::ostream & operator << (std::ostream & strm, const WyrazenieZesp & Wyraz);*/


/*
 * Funkcje ponizej nalezy zdefiniowac w module.
 *
 */

/*void Wyswietl(const WyrazenieZesp & WyrZ);
LZespolona Oblicz(const WyrazenieZesp & WyrZ);*/

#endif
