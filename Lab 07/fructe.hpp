#ifndef FRUCTE_HPP
#define FRUCTE_HPP

#include <iostream>

class Fructe
{
public:
    virtual void afisare() = 0;
    ~Fructe();
    virtual int ord() = 0;
    virtual double getPretFinal() = 0;
};

#endif
