#include "Porci.hpp"

Porci::Porci() : nr(0), grPeZi(0), iarPeZi(0)
{
}

Porci::Porci(int nr, int t1, int grPeZi, int iarPeZi)
{
    this->nr = nr;
    this->grPeZi = grPeZi;
    this->iarPeZi = iarPeZi;
}

Porci::~Porci()
{
}

void Porci::setData(int nr, int t1, int grPeZi, int iarPeZi)
{
    this->nr = nr;
    this->grPeZi = grPeZi;
    this->iarPeZi = iarPeZi;
}

int Porci::getNutPeZi()
{
    return 0;
}

int Porci::getGrPeZi()
{
    return this->grPeZi;
}

int Porci::getIarPeZi()
{
    return this->iarPeZi;
}