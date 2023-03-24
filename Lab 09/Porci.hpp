#ifndef PORCI_HPP
#define PORCI_HPP

#include <iostream>
#include "Baza.hpp"

class Porci : public Baza
{
    int nr;
    int grPeZi;
    int iarPeZi;
public:
    Porci();
    Porci(int, int, int, int); // nr, nutret, graunte, iarba
    ~Porci();
    void setData(int, int, int, int); // nr, nutret, graunte, iarba
    int getNutPeZi();
    int getGrPeZi();
    int getIarPeZi();
};

#endif