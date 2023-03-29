#ifndef BAZA_HPP
#define BAZA_HPP

#include <iostream>

class Baza
{
public:
    ~Baza();
public:
    virtual void afisare() = 0;
    virtual int getDescLength() = 0;
};

#endif