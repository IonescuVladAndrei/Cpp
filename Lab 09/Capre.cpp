#include "Capre.hpp"

Capre::Capre() : nr(0), nutPeZi(0)
{
}

Capre::Capre(int nr, int nutPeZi, int t1, int t2)
{
    this->nr = nr;
    this->nutPeZi = nutPeZi;
}

Capre::~Capre()
{
}

void Capre::setData(int nr, int nutPeZi, int t1, int t2)
{
    this->nr = nr;
    this->nutPeZi = nutPeZi;
}

int Capre::getNutPeZi()
{
    return this->nutPeZi;
}

int Capre::getGrPeZi()
{
    return 0;
}

int Capre::getIarPeZi()
{
    return 0;
}