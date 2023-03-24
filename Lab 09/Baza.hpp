#ifndef BAZA_HPP
#define BAZA_HPP

#include <iostream>

class Baza
{
public:
    ~Baza();
    virtual void setData(int, int, int, int) = 0;
    virtual int getNutPeZi() = 0;
    virtual int getGrPeZi() = 0;
    virtual int getIarPeZi() = 0;
};

#endif