#include "UkladW.hh"

UkladW UkladW::przeliczenieUkladu (const UkladW & uklad_przeliczany, const UkladW & stary_uklad_bazowy)
{
  UkladW koncowy{Wektor<3>{},MacierzObr<3>{}};
  koncowy.srodek = stary_uklad_bazowy.orient * uklad_przeliczany.srodek + stary_uklad_bazowy.srodek;
  koncowy.orient = stary_uklad_bazowy.orient * uklad_przeliczany.orient;
  return koncowy;
}