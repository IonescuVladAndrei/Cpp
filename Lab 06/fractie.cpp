#include "fractie.hpp"

Fractie::Fractie() : a(0), b(0)
{
}

Fractie::Fractie(int aa, int bb)
{
    this->a = aa;
    this->b = bb;
}

Fractie &Fractie::operator=(const Fractie &obj)
{
    if (this != &obj)
    {

        this->a = obj.a;
        this->b = obj.b;
        if (this->b == 0)
        {
            std::cout << "Atentie la numitor: 0!" << std::endl;
            exit(1);
        }
    }
    return (*this);
}

Fractie::~Fractie()
{
}

bool Fractie::operator>(const Fractie &obj)
{
    if (this->a * obj.b > this->b * obj.a)
        return true;
    return false;
}

std::ostream &operator<<(std::ostream &out, const Fractie &obj)
{
    out << "Fractie: numarator: " << obj.a << " numitor: " << obj.b << std::endl;
    return out;
}
