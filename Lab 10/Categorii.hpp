#ifndef CATEGORII_HPP
#define CATEGORII_HPP

#include "Baza.hpp"
#include <iostream>

class Categorii: virtual public Baza
{
    int categorie; // 1 = pui  2 = tanara  3 = matura
public:
    Categorii();
    Categorii(int);
    ~Categorii();

    Categorii &operator=(const Categorii &);
    friend std::ostream &operator<<(std::ostream &, const Categorii &);
    void setData(int, int);
    void afisare();
    int getDescLength();
};

#endif