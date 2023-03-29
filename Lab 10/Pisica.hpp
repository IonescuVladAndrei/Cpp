#ifndef PISICA_HPP
#define PISICA_HPP

#include "Baza.hpp"
#include <iostream>
#include <string.h>

class Pisica: virtual public Baza
{
    int varsta; // in luni
    char *nume;
    char *descriere;
    bool vaccin;

public:
    Pisica();
    Pisica(int, char *, char *, bool);
    ~Pisica();

    void setData(int, char *, char *, bool);
    friend std::ostream &operator<<(std::ostream &, const Pisica &);
    bool operator<(const Pisica &);
    Pisica &operator=(const Pisica &);
    void afisare();
    int getDescLength();
};

#endif