#include "morcovi.hpp"

Morcovi::Morcovi() : cantitate(0), pret_100_grame(0)
{
}

Morcovi::Morcovi(int nr_k, int pret_100_grame)
{
    this->cantitate = nr_k;
    this->pret_100_grame = pret_100_grame;
}

Morcovi::Morcovi(const Morcovi &obj)
{
    this->cantitate = obj.cantitate;
    this->pret_100_grame = obj.pret_100_grame;
}

int Morcovi::ord()
{
    return 3; // al treilea element ca ordine
}

double Morcovi::getPretFinal()
{
    return (double)this->cantitate / ((double)this->pret_100_grame / 100);
}

Morcovi &Morcovi::operator=(const Morcovi &obj)
{
    if (this != &obj)
    {
        this->cantitate = obj.cantitate;
        this->pret_100_grame = obj.pret_100_grame;
    }
    return *this;
}

void Morcovi::afisare()
{
    std::cout << "\tMorcovi: cantitate: " << this->cantitate << " pret_100_grame: " << this->pret_100_grame << std::endl;
}
