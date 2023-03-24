#include "nuci.hpp"

Nuci::Nuci() : cantitate(0), pret_100_grame(0)
{
}

Nuci::Nuci(int nr_k, int pret_100_grame)
{
    this->cantitate = nr_k;
    this->pret_100_grame = pret_100_grame;
}

Nuci::Nuci(const Nuci &obj)
{
    this->cantitate = obj.cantitate;
    this->pret_100_grame = obj.pret_100_grame;
}

int Nuci::ord()
{
    return 4; // al patrulea element ca ordine
}

double Nuci::getPretFinal()
{
    return (double)this->cantitate / ((double)this->pret_100_grame / 100);
}

Nuci &Nuci::operator=(const Nuci &obj)
{
    if (this != &obj)
    {
        this->cantitate = obj.cantitate;
        this->pret_100_grame = obj.pret_100_grame;
    }
    return *this;
}

void Nuci::afisare()
{
    std::cout << "\tNuci: cantitate: " << this->cantitate << " pret_100_grame: " << this->pret_100_grame << std::endl;
}
