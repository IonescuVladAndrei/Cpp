#include "clasa.hpp"

Clasa::Clasa():nr_elevi(0)
{}

Clasa::Clasa(int nr_elevi)
{
    this->nr_elevi = nr_elevi;
}

Clasa::Clasa(const Clasa& obj)
{
    this->nr_elevi = obj.nr_elevi;
}

void Clasa::setNrElv(int nr_elevi)
{
    this->nr_elevi = nr_elevi;
}

Clasa &Clasa::operator=(const Clasa& obj)
{
    if(this != &obj)
        this->nr_elevi = obj.nr_elevi;
    return *this;
}

std::ostream &operator<<(std::ostream& out, const Clasa& obj)
{
    out << "\tClasa: nr_elevi: " << obj.nr_elevi;
    return out;
}