#ifndef GAINI_HPP
#define GAINI_HPP

#include <iostream>
#include "Baza.hpp"

class Gaini : virtual public Baza
{
    int nr;
    int grPeZi;

public:
    Gaini();
    Gaini(int, int, int, int); // nr, nutret, graunte, iarba
    ~Gaini();
    void setData(int, int, int, int); // nr, nutret, graunte, iarba
    int getNutPeZi();
    int getGrPeZi();
    int getIarPeZi();
};

#endif
