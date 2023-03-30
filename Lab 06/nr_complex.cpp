#include "nr_complex.hpp"

Nr_complex::Nr_complex() : real(0), imaginar(0)
{
}

Nr_complex::Nr_complex(int r, int i)
{
    this->real = r;
    this->imaginar = i;
}

Nr_complex::Nr_complex(const Nr_complex &obj)
{
    this->imaginar = obj.imaginar;
    this->real = obj.real;
}
Nr_complex::~Nr_complex()
{
}

void Nr_complex::afisareNC()
{
    std::cout << "Nr_complex: real: " << this->real << "\timaginar: " << this->imaginar << std::endl;
}

bool Nr_complex::operator>(const Nr_complex &obj)
{
    if (sqrt(this->real * this->real + this->imaginar * this->imaginar) > sqrt(obj.real * obj.real + obj.imaginar * obj.imaginar))
        return true;
    return false;
}

Nr_complex &Nr_complex::operator=(const Nr_complex &obj)
{
    if (this != &obj)
    {
        this->real = obj.real;
        this->imaginar = obj.imaginar;
    }
    return *this;
}

std::ostream &operator<<(std::ostream &out, const Nr_complex &obj)
{
    out << "Nr_complex: real: " << obj.real << "\timaginar: " << obj.imaginar << std::endl;
    return out;
}