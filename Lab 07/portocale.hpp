#ifndef PORTOCALE_HPP
#define PORTOCALE_HPP

#include "fructe.hpp"

class Portocale : public Fructe // pretul final = nr_kilograme/pret_kg
{
    int nr_kilograme; // in kilograme
    int pret_kg;

public:
    Portocale();
    Portocale(int, int);
    Portocale(const Portocale &);

    Portocale &operator=(const Portocale &);
    void afisare();
    double getPretFinal();
    int ord();
};

#endif
