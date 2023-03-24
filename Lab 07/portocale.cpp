#include "portocale.hpp"

Portocale::Portocale() : nr_kilograme(0), pret_kg(0)
{
}

Portocale::Portocale(int nr_k, int pret_k)
{
    this->nr_kilograme = nr_k;
    this->pret_kg = pret_k;
}

Portocale::Portocale(const Portocale &obj)
{
    this->nr_kilograme = obj.nr_kilograme;
    this->pret_kg = obj.pret_kg;
}

int Portocale::ord()
{
    return 2; // al doilea element ca ordine
}

double Portocale::getPretFinal()
{
    return (double)this->nr_kilograme / this->pret_kg;
}

Portocale &Portocale::operator=(const Portocale &obj)
{
    if (this != &obj)
    {
        this->nr_kilograme = obj.nr_kilograme;
        this->pret_kg = obj.pret_kg;
    }
    return *this;
}

void Portocale::afisare()
{
    std::cout << "\tPortocale: nr_kilograme: " << this->nr_kilograme << " pret_kg: " << this->pret_kg << std::endl;
}
