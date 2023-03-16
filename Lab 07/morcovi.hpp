#ifndef MORCOVI_HPP
#define MORCOVI_HPP

#include "fructe.hpp"

class Morcovi : public Fructe // pretul final = cantitate/pret_100_grame
{
  int cantitate; // in grame
  int pret_100_grame;

public:
  Morcovi();
  Morcovi(int, int);
  Morcovi(const Morcovi &);

  Morcovi &operator=(const Morcovi &);
  void afisare();
  double getPretFinal();
  int ord();
};

#endif