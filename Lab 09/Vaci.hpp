#ifndef VACI_HPP
#define VACI_HPP

#include <iostream>
#include "Baza.hpp"

class Vaci : virtual public Baza
{
    int nr;
    int nutPeZi;

public:
    Vaci();
    Vaci(int, int, int, int); // nr, nutret, graunte, iarba
    ~Vaci();
    void setData(int, int, int, int); // nr, nutret, graunte, iarba
    int getNutPeZi();
    int getGrPeZi();
    int getIarPeZi();
};

#endif
