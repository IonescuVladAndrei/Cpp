#include "banana.hpp"

Banana::Banana() : pret_bucata(0)
{
}

Banana::Banana(int pret_bucata)
{
    this->pret_bucata = pret_bucata;
}

Banana::Banana(const Banana &obj)
{
    this->pret_bucata = obj.pret_bucata;
}

int Banana::ord()
{
    return 1; // primul element ca ordine
}

double Banana::getPretFinal()
{
    return (double)this->pret_bucata;
}

Banana &Banana::operator=(const Banana &obj)
{
    if (this != &obj)
    {
        this->pret_bucata = obj.pret_bucata;
    }
    return *this;
}

void Banana::afisare()
{
    std::cout << "\tBanana: pret_bucata: " << this->pret_bucata << std::endl;
}
