#ifndef NUCI_HPP
#define NUCI_HPP

#include "fructe.hpp"

class Nuci : public Fructe // pretul final = cantitate/pret_100_grame
{
    int cantitate; // in grame
    int pret_100_grame;

public:
    Nuci();
    Nuci(int, int);
    Nuci(const Nuci &);

    Nuci &operator=(const Nuci &);
    void afisare();
    double getPretFinal();
    int ord();
};

#endif
