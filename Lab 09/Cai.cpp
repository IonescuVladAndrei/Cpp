#include "Cai.hpp"

Cai::Cai() : nr(0), nutPeZi(0)
{
}

Cai::Cai(int nr, int nutPeZi, int t1, int t2)
{
    this->nr = nr;
    this->nutPeZi = nutPeZi;
}

Cai::~Cai()
{
}

void Cai::setData(int nr, int nutPeZi, int t1, int t2)
{
    this->nr = nr;
    this->nutPeZi = nutPeZi;
}

int Cai::getNutPeZi()
{
    return this->nutPeZi;
}

int Cai::getGrPeZi()
{
    return 0;
}

int Cai::getIarPeZi()
{
    return 0;
}