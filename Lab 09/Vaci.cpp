#include "Vaci.hpp"

Vaci::Vaci() : nr(0), nutPeZi(0)
{
}

Vaci::Vaci(int nr, int nutPeZi, int t1, int t2)
{
    this->nr = nr;
    this->nutPeZi = nutPeZi;
}

Vaci::~Vaci()
{
}

void Vaci::setData(int nr, int nutPeZi, int t1, int t2)
{
    this->nr = nr;
    this->nutPeZi = nutPeZi;
}

int Vaci::getNutPeZi()
{
    return this->nutPeZi;
}

int Vaci::getGrPeZi()
{
    return 0;
}

int Vaci::getIarPeZi()
{
    return 0;
}