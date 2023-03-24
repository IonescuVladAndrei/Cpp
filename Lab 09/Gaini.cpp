#include "Gaini.hpp"

Gaini::Gaini() : nr(0), grPeZi(0)
{
}

Gaini::Gaini(int nr, int t1, int grPeZi, int t2)
{
    this->nr = nr;
    this->grPeZi = grPeZi;
}

Gaini::~Gaini()
{
}

void Gaini::setData(int nr, int nutPeZi, int t1, int t2)
{
    this->nr = nr;
    this->grPeZi = nutPeZi;
}

int Gaini::getNutPeZi()
{
    return 0;
}

int Gaini::getGrPeZi()
{
    return this->grPeZi;
}

int Gaini::getIarPeZi()
{
    return 0;
}