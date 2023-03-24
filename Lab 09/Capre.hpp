#ifndef CAPRE_HPP
#define CAPRE_HPP

#include <iostream>
#include "Baza.hpp"
class Capre : public Baza
{
    int nr;
    int nutPeZi;

public:
    Capre();
    Capre(int, int, int, int); // nr, nutret, graunte, iarba
    ~Capre();
    void setData(int, int, int, int); // nr, nutret, graunte, iarba
    int getNutPeZi();
    int getGrPeZi();
    int getIarPeZi();
};

#endif