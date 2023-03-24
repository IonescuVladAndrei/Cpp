#ifndef CAI_HPP
#define CAI_HPP

#include <iostream>
#include "Baza.hpp"

class Cai : public Baza
{
    int nr;
    int nutPeZi;

public:
    Cai();
    Cai(int, int, int, int); // nr, nutret, graunte, iarba
    ~Cai();
    void setData(int, int, int, int); // nr, nutret, graunte, iarba
    int getNutPeZi();
    int getGrPeZi();
    int getIarPeZi();
};

#endif