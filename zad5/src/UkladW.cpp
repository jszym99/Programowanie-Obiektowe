#include "UkladW.hh"

UkladW UkladW::przeliczUklad(const UkladW & uklad_bazowy)
{
  UkladW koncowy{Wektor<3>{},MacierzObr<3>{}};
  koncowy.srodek = uklad_bazowy.orient * srodek + uklad_bazowy.srodek;
  koncowy.orient = uklad_bazowy.orient * orient;
  return koncowy;
}