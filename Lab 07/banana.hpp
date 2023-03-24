#ifndef BANANA_HPP
#define BANANA_HPP

#include "fructe.hpp"

class Banana : public Fructe // pret final = pret bucata
{
    int pret_bucata; // in kilograme
public:
    Banana();
    Banana(int);
    Banana(const Banana &);

    Banana &operator=(const Banana &);
    void afisare();
    double getPretFinal();
    int ord();
};

#endif
